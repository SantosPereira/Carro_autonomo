'''    API de controle e monitoramento do carro    '''

import serial
from time import sleep

serial = serial.Serial('COM5', 9600)

while True:
    sleep(0.2)
    print(serial.read().decode('utf-8'), end='')
    print(serial.read().decode('utf-8'), end='')
    print(serial.read().decode('utf-8'), end='')
    print(serial.read().decode('utf-8'))
