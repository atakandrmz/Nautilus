int x_key1 = A0;  
int y_key1 = A1; 

int x_key2 = A2;                                        
int y_key2 = A3;

int pot = A4;

int key1 = 23;
int key2 = 22;

int x_pos1;
int x_pos2;
int y_pos1;
int y_pos2;
int key1_state;
int key2_state;

int pot_val;

#include "HCPCA9685.h" // Include the HCPCA9685 library
#define I2CAdd 0x40 // Default address of the PCA9685 Module
HCPCA9685 HCPCA9685(I2CAdd); // Define Library to use I2C communication


void setup() {
  // put your setup code here, to run once:



HCPCA9685.Init(SERVO_MODE); // Set to Servo Mode

HCPCA9685.Sleep(false); // Wake up PCA9685 module


}

void loop() {
  // put your main code here, to run repeatedly:
x_pos1 =map(analogRead (x_key1),0,1023,10,0)  ; 
x_pos2 = map(analogRead (x_key2),0,1023,10,0) ; 
y_pos1 = map(analogRead (y_key1),0,1023,0,10) ; 
y_pos2 = map(analogRead (y_key2),0,1023,0,10) ; 

key1_state = digitalRead (key1) ; 
key2_state = digitalRead (key2) ; 

pot_val = analogRead( pot);

Serial.println("Loop first part is done");

// Move Servos to read postion from Joystick
HCPCA9685.Servo(11, pot_val); // Move Servo 0 
HCPCA9685.Servo(12,y_pos2 ); // Move Servo 12
HCPCA9685.Servo(13, x_pos1); // Move Servo 4
HCPCA9685.Servo(14, y_pos1); // Move Servo 8
HCPCA9685.Servo(15,x_pos2); // Move Servo 8
delay(1);

Serial.println("Loop second part is done");

Serial.print(x_pos1);
Serial.print("\t");
Serial.print(y_pos1);
Serial.print("\t");
Serial.print("////");
Serial.print("\t");
Serial.print(x_pos2);
Serial.print("\t");
Serial.print(y_pos2);
Serial.print("\t");
Serial.print("////");
Serial.print("\t");
Serial.print(key1_state);
Serial.print("\t");
Serial.print(key2_state);
Serial.print("\t");
Serial.print("////");
Serial.print("\t");
Serial.println(pot_val);

}
