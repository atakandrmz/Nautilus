#include <Servo.h>
//int pos=0;
//int val;
 int loc;
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

//int pos = 0;    // variable to store the servo position
int mid=0;
int a;
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(A0, INPUT);
  Serial.begin(9600);
  //int val = analogRead(A0); 
  //int pos = map(val,0,1023,50,0);
  //int loc = pos;
}

void loop() {
    int val = analogRead(A0); 
  int pos = map(val,0,1023,5,-5);
loc+=pos;
if(loc<0 ){loc=0;}
if(loc>180){loc=180;}

  Serial.print(val);
  Serial.print("\t");
Serial.print(pos);
 Serial.print("\t");
 // int loc = pos/100;
   Serial.println(loc);
  
  
  
  myservo.write(loc);              // tell servo to go to position in variable 'pos'
    delay(15);         
  
  /*for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
                  // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }*/
}
