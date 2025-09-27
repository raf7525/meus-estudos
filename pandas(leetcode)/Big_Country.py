import pandas as pd

def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    condicao_populacao = world['population'] >= 25000000
    condicao_area = world['area'] >= 3000000
    df_filtrado = world[condicao_populacao | condicao_area]
    return df_filtrado[['name', 'population', 'area']]