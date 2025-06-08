import time
import win32gui
import pygetwindow as gw
import pyautogui
from interception import interception, MouseState

context = interception()
mouse = context.create_mouse()

def get_window_center(title):
    try:
        win = gw.getWindowsWithTitle(title)[0]
        x, y = win.left, win.top
        w, h = win.width, win.height
        return (x + w // 2, y + h // 2)
    except IndexError:
        print("Janela não encontrada.")
        return None

def click_at(x, y):
    # Salva posição atual do mouse
    current_x, current_y = pyautogui.position()

    # Move o mouse para a posição alvo
    pyautogui.moveTo(x, y)

    # Envia clique como mouse físico
    # Primeiro pressionar botão esquerdo
    mouse.send(MouseState(buttons=MouseState.LEFT_DOWN))

    # Depois soltar botão esquerdo
    mouse.send(MouseState(buttons=MouseState.LEFT_UP))

    # Volta o mouse pro lugar original
    pyautogui.moveTo(current_x, current_y)

# Loop infinito clicando a cada 0.2s no centro da janela Roblox
while True:
    pos = get_window_center("Roblox")
    if pos:
        click_at(*pos)
    time.sleep(0.2)
