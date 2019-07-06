#include "HCPCA9685.h" // Include the HCPCA9685 library created by Andrew Davies

#define I2CAdd 0x40 // Default address of the PCA9685 Module

int x_key1 = A0;  
int y_key1 = A1; 

int x_key2 = A2;                                        
int y_key2 = A3;

int key1 = 23;
int key2 = 22;

// Used to store the mapping of the Joystick X and Y values
int x_pos1;
int x_pos2;
int y_pos1;
int y_pos2;

int key1_state;
int key2_state;

int pot = A4;
int pot_val;
int pot_pos;

HCPCA9685 HCPCA9685(I2CAdd); // Define Library to use I2C communication

void setup() 
{
HCPCA9685.Init(SERVO_MODE); // Set to Servo Mode

HCPCA9685.Sleep(false); // Wake up PCA9685 module

}


void loop() 
{
int val1X = analogRead(x_key1); // Read current value of Joystick 1 X axis++
int val1Y = analogRead(y_key1); // Read current value of Joystick 1 Y axis

int val2X = analogRead(x_key2); // Read current value of Joystick 1 X axis
int val2Y = analogRead(y_key2); // Read current value of Joystick 1 Y axis

int pot_val = analogRead( pot);
// Map Joystick Axis values to servo Min and Max position 
x_pos1 = map(val1X, 0, 1023, 250, 0); // Used to move Servo 0
x_pos2 = map(val2X, 0, 1023, 0, 250); // Used to move Servo 12 inverted

y_pos1 = map(val1Y, 0, 1023, 250,0); // Used to move Servo 4
y_pos2 = map(val2Y, 0, 1023, 250, 0); // Used to move Servo 8 inverted

pot_pos = map(pot_val, 0, 1023 , 0, 250);

// Move Servos to read postion from Joystick
HCPCA9685.Servo(0, x_pos2); // Move Servo 0 
HCPCA9685.Servo(3, y_pos1); // Move Servo 12
HCPCA9685.Servo(1, y_pos2); // Move Servo 4
HCPCA9685.Servo(2, x_pos1); // Move Servo 8
HCPCA9685.Servo(4, pot_pos); // Move Servo 8
delay(1);
}
