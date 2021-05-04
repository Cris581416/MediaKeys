import serial
import pyautogui as keyboard


commands = {"p": "playpause", "l": "prevtrack", "n": "nexttrack", "u": "volumeup", "d": "volumedown"}

ser = serial.Serial(port="COM4", timeout=1)
ser.flush()

while True:
    if ser.in_waiting:
        command = ser.read().decode('utf-8')
        print(command)
        keyboard.hotkey(commands[command])
