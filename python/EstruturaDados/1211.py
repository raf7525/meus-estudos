import sys

def calcular_economia(numeros):
    economia = 0
    for i in range(1, len(numeros)):
        anterior, atual = numeros[i - 1], numeros[i]
        prefixo_comum = 0
        for a, b in zip(anterior, atual):
            if a == b:
                prefixo_comum += 1
            else:
                break
        economia += prefixo_comum
    return economia

def main():
    try:
        while True:
            n = int(sys.stdin.readline().strip())
            numeros = [sys.stdin.readline().strip() for _ in range(n)]
            print(calcular_economia(numeros))
    except EOFError:
        pass

if __name__ == "__main__":
    main()
