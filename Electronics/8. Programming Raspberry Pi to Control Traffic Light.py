import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
NORTH_R = 14
NORTH_Y = 15
NORTH_G = 18
SOUTH_R = 16
SOUTH_Y = 20
SOUTH_G = 21
GPIO.setup(NORTH_G,GPIO.OUT)
GPIO.setup(NORTH_Y,GPIO.OUT)
GPIO.setup(NORTH_R,GPIO.OUT)
GPIO.setup(SOUTH_G,GPIO.OUT)
GPIO.setup(SOUTH_Y,GPIO.OUT)
GPIO.setup(SOUTH_R,GPIO.OUT)
time.sleep(1)
GPIO.output(NORTH_R,True)
GPIO.output(SOUTH_R,True)
GPIO.output(NORTH_Y,False)
GPIO.output(SOUTH_Y,False)
GPIO.output(NORTH_G,False)
GPIO.output(SOUTH_G,False)
time.sleep(5)
while True:
    #North
    GPIO.output(NORTH_R,False)
    GPIO.output(NORTH_G,True)
    time.sleep(4)
    3
    GPIO.output(NORTH_G,False)
    GPIO.output(NORTH_Y,True)
    time.sleep(2)
    GPIO.output(NORTH_Y,False)
    GPIO.output(NORTH_R,True)
    #SOUTH
    GPIO.output(SOUTH_R,False)
    GPIO.output(SOUTH_G,True)
    time.sleep(4)
    GPIO.output(SOUTH_G,False)
    GPIO.output(SOUTH_Y,True)
    time.sleep(2)
    GPIO.output(SOUTH_Y,False)
    GPIO.output(SOUTH_R,True)