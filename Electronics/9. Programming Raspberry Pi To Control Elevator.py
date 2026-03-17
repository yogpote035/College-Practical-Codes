import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
#LED PINS
LED_UP = 14
LED_DOWN = 15
GPIO.setup(LED_UP, GPIO.OUT)
GPIO.setup(LED_DOWN, GPIO.OUT)
time.sleep(1)
GPIO.output(LED_UP,GPIO.LOW)
GPIO.output(LED_DOWN,GPIO.LOW)
#BUTTON PINS
buttons = {
1:[5,19], #outside , Cabin
2:[6,26],
3:[13,21]
}
for pins in buttons.values():
    for pin in pins:
        GPIO.setup(pin, GPIO.IN, pull_up_down=GPIO.PUD_UP)
#SSD select line
DIGIT_0 = 2
DIGIT_1 = 3

GPIO.setup(DIGIT_0, GPIO.OUT)
GPIO.setup(DIGIT_1, GPIO.OUT)
def display_floor(floor):
    if floor == 1: #01 for '1'
        GPIO.output(DIGIT_0,False)
        GPIO.output(DIGIT_1,True)
    elif floor == 2: #10 for '2'
        GPIO.output(DIGIT_0,True)
        GPIO.output(DIGIT_1,False)
    else : #11 for '3'
        GPIO.output(DIGIT_0,True)
        GPIO.output(DIGIT_1,True)

#--------ELEVATOR LOGIC-----------#
current_floor = 1
display_floor(current_floor)
def move_lift(target):
    global current_floor
    print(current_floor)
    if target == current_floor:
        return
    if target > current_floor:
        GPIO.output(LED_UP,False)
        GPIO.output(LED_DOWN,True)
        step = 1
    else:
        GPIO.output(LED_UP,True)
        GPIO.output(LED_DOWN,False)
        step = -1
    while current_floor != target:
        time.sleep(2) #travel time
        current_floor += step # update current floor
        display_floor(current_floor)
    GPIO.output(LED_UP,True)
    GPIO.output(LED_DOWN,True)
#-------------MAIN LOOP----------------#
try:
    while True:
     for floor,pins in buttons.items():
         for pin in pins:
             if GPIO.input(pin) == False:
                   move_lift(floor)
                   time.sleep(0.5)
except KeyboardInterrupt:
    GPIO.cleanup()