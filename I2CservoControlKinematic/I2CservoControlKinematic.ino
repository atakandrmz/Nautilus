#include "HCPCA9685.h" // Include the HCPCA9685 library created by Andrew Davies

#define I2CAdd 0x40 // Default address of the PCA9685 Module

#define JoyX A0 // Joystick X pin connected to A0 on the UNO
#define JoyY A1 // Joystick Y pin connected to A1 on the UNO

// Used to store the mapping of the Joystick X and Y values
int ServoXforward;
int ServoXbackward;
int ServoYforward;
int ServoYbackward;

HCPCA9685 HCPCA9685(I2CAdd); // Define Library to use I2C communication

void setup() 
{
HCPCA9685.Init(SERVO_MODE); // Set to Servo Mode

HCPCA9685.Sleep(false); // Wake up PCA9685 module
}


void loop() 
{
int val1X = analogRead(JoyX); // Read current value of Joystick 1 X axis
int val1Y = analogRead(JoyY); // Read current value of Joystick 1 Y axis

// Map Joystick Axis values to servo Min and Max position 
ServoXforward = map(val1X, 0, 1023, 420, 10); // Used to move Servo 0
ServoXbackward = map(val1X, 0, 1023, 10, 420); // Used to move Servo 12 inverted

ServoYforward = map(val1Y, 0, 1023, 10, 420); // Used to move Servo 4
ServoYbackward = map(val1Y, 0, 1023, 420, 10); // Used to move Servo 8 inverted

// Move Servos to read postion from Joystick
HCPCA9685.Servo(0, ServoXforward); // Move Servo 0 
HCPCA9685.Servo(12, ServoXbackward); // Move Servo 12
HCPCA9685.Servo(4, ServoYforward); // Move Servo 4
HCPCA9685.Servo(8, ServoYbackward); // Move Servo 8
delay(1);
}
