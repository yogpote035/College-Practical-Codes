import RPi.GPIO as GPIO
import time
IN1 = 14
IN2 = 15
IN3 = 23
IN4 = 24
delay = 0.25 # time to settle
GPIO.setmode(GPIO.BCM)
GPIO.setup(IN1, GPIO.OUT)
GPIO.setup(IN2, GPIO.OUT)
GPIO.setup(IN3, GPIO.OUT)
GPIO.setup(IN4, GPIO.OUT)
def forwardStep():
    setStepper(1, 0, 0, 1)
    setStepper(0, 1, 0, 1)
    setStepper(0, 1, 1, 0)
    setStepper(1, 0, 1, 0)
def backwardStep():
    setStepper(1, 0, 1, 0)
    setStepper(0, 1, 1, 0)
    setStepper(0, 1, 0, 1)
    setStepper(1, 0, 0, 1)
def setStepper(A, B, C, D):
    GPIO.output(IN1, A)
    GPIO.output(IN2, B)
    GPIO.output(IN3, C)
    GPIO.output(IN4, D)
    time.sleep(delay)
while True:
    print ("forward")
    for i in range(13):
        forwardStep()
    print ("backward")
    for i in range(13):
        backwardStep()