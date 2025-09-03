import pyautogui
import time

# Definir a duração de cada movimento
duration = 0.5

# Definir o tamanho do lado do quadrado
side_length = 100

# Posições iniciais
start_x, start_y = 500, 500

# Movimentos para desenhar um quadrado
for _ in range(4):
    pyautogui.moveTo(start_x, start_y, duration=duration)
    start_x += side_length
    pyautogui.moveTo(start_x, start_y, duration=duration)
    start_y += side_length
    pyautogui.moveTo(start_x, start_y, duration=duration)
    start_x -= side_length
    pyautogui.moveTo(start_x, start_y, duration=duration)
    start_y -= side_length
