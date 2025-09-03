import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler, OneHotEncoder
from sklearn.compose import ColumnTransformer
from sklearn.pipeline import Pipeline
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_absolute_error, r2_score
import numpy as np

# A função haversine_distance continua a mesma
def haversine_distance(lat1, lon1, lat2, lon2):
    R = 6371
    lat1, lon1, lat2, lon2 = map(pd.to_numeric, [lat1, lon1, lat2, lon2])
    dlat = np.radians(lat2 - lat1)
    dlon = np.radians(lon2 - lon1)
    a = np.sin(dlat / 2)**2 + np.cos(np.radians(lat1)) * np.cos(np.radians(lat2)) * np.sin(dlon / 2)**2
    c = 2 * np.arctan2(np.sqrt(a), np.sqrt(1 - a))
    distance = R * c
    return distance

try:
    # --- 1. Carregamento dos 3 Datasets ---
    print("Carregando os 3 datasets...")
    df1 = pd.read_csv('deliverytime.csv')
    df2 = pd.read_csv('Food_Delivery_Times.csv')
    # Este novo arquivo tem problemas com o separador decimal, vamos corrigir na leitura
    df3 = pd.read_csv('Food_Time new.csv', decimal='.')
    print("Datasets carregados.")

    # --- 2. Limpeza e Padronização ---

    # Dataset 1: deliverytime.csv
    df1.rename(columns={'Time_taken(min)': 'Time_taken_min'}, inplace=True)
    df1['distance_km'] = haversine_distance(df1['Restaurant_latitude'], df1['Restaurant_longitude'], df1['Delivery_location_latitude'], df1['Delivery_location_longitude'])
    df1['Weather'] = 'Unknown' # Adiciona colunas faltantes
    df1['Traffic_Level'] = 'Unknown'

    # Dataset 2: Food_Delivery_Times.csv
    df2.rename(columns={'Distance_km': 'distance_km', 'Vehicle_Type': 'Type_of_vehicle', 'Delivery_Time_min': 'Time_taken_min', 'Weather': 'Weather', 'Traffic_Level': 'Traffic_Level'}, inplace=True)
    df2['Type_of_order'] = 'Unknown' # Adiciona colunas faltantes

    # Dataset 3: Food_Time new.csv
    df3.rename(columns={'TARGET': 'Time_taken_min', 'weather_description': 'Weather'}, inplace=True)
    # Corrigindo problema de formatação das coordenadas (ex: '12.939.496' -> 12.939496)
    for col in ['Restaurant_latitude', 'Restaurant_longitude', 'Delivery_location_latitude', 'Delivery_location_longitude']:
        if df3[col].dtype == 'object':
            df3[col] = df3[col].str.replace('.', '', regex=False).str.replace(',', '.', regex=False)
            df3[col] = pd.to_numeric(df3[col], errors='coerce')
            # Heurística para corrigir a escala
            df3[col] = df3[col] / 1_000_000

    df3['distance_km'] = haversine_distance(df3['Restaurant_latitude'], df3['Restaurant_longitude'], df3['Delivery_location_latitude'], df3['Delivery_location_longitude'])


    # --- 3. Seleção e União dos Dados ---
    # Definindo as colunas que queremos manter de cada dataset para a união
    cols_para_manter = ['Delivery_person_Age', 'Delivery_person_Ratings', 'distance_km', 'Type_of_vehicle', 'Time_taken_min', 'Weather', 'Traffic_Level', 'Type_of_order']
    
    # Garantindo que todas as colunas existem em todos os dataframes antes de selecionar
    for df in [df1, df2, df3]:
        for col in cols_para_manter:
            if col not in df.columns:
                df[col] = np.nan # Adiciona coluna com nulos se não existir

    df1_clean = df1[cols_para_manter].copy()
    df2_clean = df2[cols_para_manter].copy()
    df3_clean = df3[cols_para_manter].copy()

    print("Combinando os datasets...")
    df_final = pd.concat([df1_clean, df2_clean, df3_clean], ignore_index=True)

    # --- 4. Limpeza Final e Preenchimento de Dados Faltantes (Imputação) ---
    # Convertendo colunas para numérico
    for col in ['Delivery_person_Age', 'Delivery_person_Ratings', 'Time_taken_min', 'distance_km']:
        df_final[col] = pd.to_numeric(df_final[col], errors='coerce')

    # Removendo linhas onde o alvo (Time_taken_min) ou a distância são nulos
    df_final.dropna(subset=['Time_taken_min', 'distance_km'], inplace=True)
    
    # Preenchendo (imputando) valores nulos restantes com a média (para numéricos) ou moda (para categóricos)
    df_final['Delivery_person_Age'] = df_final['Delivery_person_Age'].fillna(df_final['Delivery_person_Age'].mean())
    df_final['Delivery_person_Ratings'] = df_final['Delivery_person_Ratings'].fillna(df_final['Delivery_person_Ratings'].mean())

    for col in ['Type_of_vehicle', 'Weather', 'Traffic_Level', 'Type_of_order']:
        # Usamos 'Unknown' como um valor padrão para categóricos faltantes
        df_final[col] = df_final[col].fillna('Unknown')



    print(f"Dataset final criado com {len(df_final)} registros.")

    # --- 5. Preparação para o Modelo (com as novas features) ---
    # Adicionamos as novas features categóricas à nossa lista
    features = ['Delivery_person_Age', 'Delivery_person_Ratings', 'distance_km', 'Type_of_vehicle', 'Weather', 'Traffic_Level', 'Type_of_order']
    target = 'Time_taken_min'

    X = df_final[features]
    y = df_final[target]

    numeric_features = ['Delivery_person_Age', 'Delivery_person_Ratings', 'distance_km']
    categorical_features = ['Type_of_vehicle', 'Weather', 'Traffic_Level', 'Type_of_order']

    preprocessor = ColumnTransformer(
        transformers=[
            ('num', StandardScaler(), numeric_features),
            ('cat', OneHotEncoder(handle_unknown='ignore', drop='first'), categorical_features) # drop='first' para evitar multicolinearidade
        ])

    # --- 6. Construção e Treinamento do Modelo ---
    model_pipeline = Pipeline(steps=[('preprocessor', preprocessor),
                                     ('regressor', RandomForestRegressor(n_estimators=100, random_state=42, n_jobs=-1))])

    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

    print("Treinando o modelo final com dados de clima e trânsito...")
    model_pipeline.fit(X_train, y_train)
    print("Treinamento concluído!")

    # --- 7. Avaliação do Modelo Final ---
    y_pred = model_pipeline.predict(X_test)
    mae = mean_absolute_error(y_test, y_pred)
    r2 = r2_score(y_test, y_pred)

    print("\n--- Avaliação do Modelo Final ---")
    print(f"Erro Médio Absoluto (MAE): {mae:.2f} minutos")
    print(f"Coeficiente de Determinação (R²): {r2:.2f}")

except FileNotFoundError as e:
    print(f"Erro: Arquivo não encontrado. Verifique se '{e.filename}' está no diretório correto.")
except Exception as e:
    print(f"Ocorreu um erro inesperado: {e}")