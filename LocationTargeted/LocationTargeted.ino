#include "HCPCA9685.h" // Include the HCPCA9685 library created by Andrew Davies

#define I2CAdd 0x40 // Default address of the PCA9685 Module

int x_key1 = A0;
int y_key1 = A1; 

int x_key2 = A2; 
int y_key2 = A3;

//int key1 = 23;
//int key2 = 22;

// Used to store the mapping of the Joystick X and Y values
int x_pos1;
int x_pos2;
int y_pos1;
int y_pos2;

int locx1=0;
int locy1;

int locx2;
int locy2;

//int key1_state;
//int key2_state;

int pot = A4;
int pot_val;
int pot_pos;

int x_key1L = A5;  
int y_key1L = A6; 

int x_key2L = A7;                                        
int y_key2L = A8;

//int key1L = 24;
//int key2L = 25;

int x_pos1L;
int x_pos2L;
int y_pos1L;
int y_pos2L;

int locx1L;
int locy1L;

int locx2L;
int locy2L;


int potL = A9;
int pot_valL;
int pot_posL;

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


    int val1XL = analogRead(x_key1L); // Read current value of Joystick 1 X axis++
    int val1YL = analogRead(y_key1L); // Read current value of Joystick 1 Y axis
    
    int val2XL = analogRead(x_key2L); // Read current value of Joystick 1 X axis
    int val2YL = analogRead(y_key2L); // Read current value of Joystick 1 Y axis
    
    int pot_valL = analogRead( potL);
    
// Map Joystick Axis values to servo Min and Max position 
x_pos1 = map(val1X, 0, 1023, 3, -3); // Used to move Servo 0

  if(locx1<0 ){locx1=0;}
    if(locx1>180){locx1=180;}
    if((x_pos1 == 1)){x_pos1=0;}
    locx1+=x_pos1;
    
x_pos2 = map(val2X, 0, 1023, -3, 3); // Used to move Servo 12 inverted

     if(locx2<0 ){locx2=0;}
    if(locx2>180){locx2=180;}
    if((x_pos2 == 1)){x_pos2=0;}
    locx2+=x_pos2;
    
y_pos1 = map(val1Y, 0, 1023, 3,-3); // Used to move Servo 4

 if(locy1<0 ){locy1=0;}
    if(locy1>180){locy1=180;}
    if((y_pos1 == 1)){y_pos1=0;}
    locy1+=y_pos1;
    
y_pos2 = map(val2Y, 0, 1023, 3, -3); // Used to move Servo 8 inverted

     if(locy2<0 ){locy2=0;}
    if(locy2>180){locy2=180;}
    if((y_pos2 == 1)){y_pos2=0;}
    locy2+=y_pos2;
    
pot_pos = map(pot_val, 0, 1023 , 0, 50);

    x_pos1L = map(val1XL, 0, 1023, 3, -3); // Used to move Servo 0
    
    if(locx1L<0 ){locx1L=0;}
    if(locx1L>180){locx1L=180;}
    if((x_pos1L == 1)){x_pos1L=0;}
    locx1L+=x_pos1L;
    
    x_pos2L = map(val2XL, 0, 1023, -3, 3); // Used to move Servo 12 inverted

    if(locx2L<0 ){locx2L=0;}
    if(locx2L>180){locx2L=180;}
    if((x_pos2L == 1)){x_pos2L=0;}
    locx2L+=x_pos2L;
    
    y_pos1L = map(val1YL, 0, 1023, -3,3); // Used to move Servo 4
    
    if(locy1L<0 ){locy1L=0;}
    if(locy1L>180){locy1L=180;}
    if((y_pos1L == 1)){y_pos1L=0;}
    locy1L+=y_pos1L;
    
    y_pos2L = map(val2YL, 0, 1023, -3, 3); // Used to move Servo 8 inverted

    if(locy2L<0 ){locy2L=0;}
    if(locy2L>180){locy2L=180;}
    if((y_pos2L == 1)){y_pos2L=0;}
    locy2L+=y_pos2L;

    pot_posL = map(pot_valL, 0, 1023 , 0, 50);
// Move Servos to read postion from Joystick

HCPCA9685.Servo(0, locx2); // Move Servo 0 
HCPCA9685.Servo(3, locy1); // Move Servo 12
HCPCA9685.Servo(1, locy2); // Move Servo 4
HCPCA9685.Servo(2, locx1); // Move Servo 8
HCPCA9685.Servo(4, pot_pos); // Move Servo 8

HCPCA9685.Servo(5, locx2L); // Move Servo 0 
HCPCA9685.Servo(6, locy2L); // Move Servo 12
HCPCA9685.Servo(7, locx1L); // Move Servo 4
HCPCA9685.Servo(8, locy1L); // Move Servo 8
HCPCA9685.Servo(9, pot_posL); // Move Servo 8

delay(1);
}
