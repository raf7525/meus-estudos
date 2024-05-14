import random

continuar = input("Quer continuar? S ou N: ")

while continuar.upper() == "S":
    number = random.randint(1, 10)  # Gerar um número aleatório entre 1 e 10
    guess = int(input("Silly game: adivinhe um número entre 1 e 10: "))

    if guess == number:
        print("Você acertou! Parabéns!")
    else:
        print(f"Você errou! O número correto era {number}.")

    continuar = input("Quer continuar? S ou N: ")
