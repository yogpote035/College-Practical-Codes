import RPi.GPIO as GPIO
import time
# Below are LCD GPIO PIN Numbers
LCD_RS = 21 # Register Select 0 for Command 1 for Data
LCD_E = 20 # Enable pin High to Low signal
LCD_D4 = 14 # Data Pins
LCD_D5 = 15
LCD_D6 = 18
LCD_D7 = 23
LCD_WIDTH = 16
LCD_CHR = True
LCD_CMD = False
LCD_LINE_1 = 0X80
LCD_LINE_2 = 0XC0
E_PULSE = 0.0005
E_DELAY = 0.0005
def lcd_init():
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(LCD_E, GPIO.OUT)
    GPIO.setup(LCD_RS, GPIO.OUT)
    GPIO.setup(LCD_D4, GPIO.OUT)
    GPIO.setup(LCD_D5, GPIO.OUT)
    GPIO.setup(LCD_D6, GPIO.OUT)
    GPIO.setup(LCD_D7, GPIO.OUT)
    lcd_byte(0X33, LCD_CMD)
    lcd_byte(0X32, LCD_CMD)
    lcd_byte(0X28, LCD_CMD)
    lcd_byte(0X0C, LCD_CMD)
    lcd_byte(0X06, LCD_CMD)
    lcd_byte(0X01, LCD_CMD) # clear LCD
def lcd_string(msg):
    msg = msg.ljust(LCD_WIDTH, ' ')
    for i in range(LCD_WIDTH):
        lcd_byte(ord(msg[i]),LCD_CHR)
def lcd_byte(bits, mode):
    set4bitMSB(bits, mode)
    set4bitMSB(bits << 4, mode)

def set4bitMSB(bits,mode):
    GPIO.output(LCD_RS, mode)
    GPIO.output(LCD_D4, False)
    GPIO.output(LCD_D5, False)
    GPIO.output(LCD_D6, False)
    GPIO.output(LCD_D7, False)
    if bits&0x10==0x10:
        GPIO.output(LCD_D4, True)
    if bits&0x20==0x20:
        GPIO.output(LCD_D5, True)
    if bits&0x40==0x40:
        GPIO.output(LCD_D6, True)
    if bits&0x80==0x80:
        GPIO.output(LCD_D7, True)
    time.sleep(E_DELAY)
    GPIO.output(LCD_E, True)
    time.sleep(E_PULSE)
    GPIO.output(LCD_E, False)
    time.sleep(E_DELAY)
# Main Program
lcd_init()
lcd_byte(LCD_LINE_1, LCD_CMD)
lcd_string("* Modern Pune *")
lcd_byte(LCD_LINE_2, LCD_CMD)
lcd_string(" :Electronics: ")
time.sleep(2)