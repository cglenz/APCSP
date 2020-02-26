
import serial
import time

port = '/dev/ttyACM0'

ser = serial.Serial(port, 9600, timeout=5)

while True:
    time.sleep(1)
    data = ser.readline()
    print(data)
    
