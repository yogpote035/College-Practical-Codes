import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM) #choose GPIO
GPIO.setwarnings(False)
PIR_input=21 #read PIR Output
BUZZ =20 #BUZZ for signaling motion detected
GPIO.setup(PIR_input, GPIO.IN)
GPIO.setup(BUZZ, GPIO.OUT)
GPIO.output(BUZZ, GPIO.LOW)
while True:
    if(GPIO.input(PIR_input)) : #when motion detected turn on BUZZ
        GPIO.output(BUZZ, GPIO.HIGH)
    else :
        GPIO.output(BUZZ, GPIO.LOW)