import RPi.GPIO as GPIO
import time
segments = [14,15,18,23,24,25,21]
#segments: a,b,c,d,e,f,g
num = [ [0,0,0,0,0,0,1], #’0’
[1,0,0,1,1,1,1], #’1’
[0,0,1,0,0,1,0], #’2’
[0,0,0,0,1,1,0], #’3’
[1,0,0,1,1,0,0], #’4’
[0,1,0,0,1,0,0], #’5’
[0,1,0,0,0,0,0], #’6’
[0,0,0,1,1,1,1], #’7’
[0,0,0,0,0,0,0], #’8’
[0,0,0,1,1,0,0] ] #’9’
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
for segment in segments:
    GPIO.setup(segment,GPIO.OUT)
    GPIO.output(segment,GPIO.HIGH)
def display_digit(digit):
    pattern = num[digit]
    for i in range(7):
        GPIO.output(segments[i],pattern[i])
while True:
    for i in range(10):
        print("Displaying ",i)
        display_digit(i)
        time.sleep(1)