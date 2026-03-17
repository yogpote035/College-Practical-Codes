# Program A
from picamera import Picamera
import time
camera = Picamera()
camera.start_preview()
time.sleep(5)
camera.stop_preview()


# Program B
import RPi.GPIO as GPIO
from picamera import Picamera
import time
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
BUTTON =21
LED =20
GPIO.setup(BUTTON,GPIO.IN,pull_up_down=GPIO.PUD_UP)
GPIO.setup(LED, GPIO.OUT)
def capture_image():
    camera.start_preview()
    time.sleep(5)
    camera.capture("/home/pi/Desktop/image.jpg")
    camera.stop_preview()
camera = Picamera()
while True :
    GPIO.output(LED,False)
    read_input = GPIO.input(BUTTON)
    if read_input == False:
        GPIO.output(LED,True)
        time.sleep(0.5)
        capture_image()
        time.sleep(0.5)