def renas_ordenadas(renas):
    return sorted(renas,key=lambda r:(-r[1],r[2],r[3],r[0]))   

T=int(input("escreva o numero de casos teste na tela: "))
for i in range(1, T+1):
    N=int(input("Digite o N: "))
    M=int(input("Digite a quant de vagas: "))
    renas = []
    for j in range(N):
        nome = input("escreva o nome: \n").upper()
        peso = int(input("escreva o peso: \n"))
        idade = int(input("digite a idade: \n"))
        altura = float(input("escreva a altura: \n"))
        renas.append((nome,peso,idade,altura))
    renas_ordenadas = renas_ordenadas(renas)
    print(f"CENARIO {{{i}}}")
    for m in range (M):
        print(f"{m + 1} - {renas_ordenadas[m][0]}")
    print() 



   
