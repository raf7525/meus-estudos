import sys

while True:
    x, y, p = map(int, sys.stdin.readline().split())
    
    if x == 0 and y == 0 and p == 0:
        break

    campo = [[0] * y for _ in range(x)]

    q = int(sys.stdin.readline())

    resultados = []
    
    for _ in range(q):
        dados = sys.stdin.readline().split()
        tipo = dados[0]

        if tipo == "A":
            n = int(dados[1])
            a = int(dados[2])
            b = int(dados[3])
            campo[a][b] += n

        elif tipo == "P":
            c = int(dados[1])
            d = int(dados[2])
            e = int(dados[3])
            f = int(dados[4])

            if c > e:
                c, e = e, c
            if d > f:
                d, f = f, d
        else:
            break       

            soma = sum(campo[i][j] for i in range(c, e + 1) for j in range(d, f + 1))
            resultados.append(str(soma * p))

    sys.stdout.write("\n".join(resultados) + "\n\n")
