import RPi.GPIO as GPIO # import GPIO library
import time # import time library
GPIO.setmode(GPIO.BCM) #use BCM pin numbers
GPIO.setwarnings(False)
LED1=14
LED2=15
GPIO.setup(LED1,GPIO.OUT) # setup pin 14 as output
GPIO.setup(LED2,GPIO.OUT) #setup pin15 as output
time.sleep(1) #time delay for 1sec
GPIO.output(LED1,True) # set LED1 high
GPIO.output(LED2,False) # set LED2 low
time.sleep(1) # time delay for1 sec
GPIO.output(LED1,False) # set LED1 low
GPIO.output(LED2,True) # set LED2 high
time.sleep(1)
GPIO.output(LED1,True) #set LED1 high
GPIO.output(LED2,False) #set LED2 low
time.sleep(1)
GPIO.cleanup() #clear all pins