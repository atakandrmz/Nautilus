int x_key1 = A6;
int x_pos1=0;
int locx1=0;
int cx1 ;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
int val1X = analogRead(x_key1);
  cx1 = val1X; 
}

void loop() {
  // put your main code here, to run repeatedly:
  int val1X = analogRead(x_key1);
  Serial.print(val1X);
  Serial.print("\t");
  x_pos1 = map(val1X, 0, 1023, 3, -3); // Used to move Servo 0
 
   Serial.print(cx1);
  Serial.print("\t");
  Serial.print(x_pos1);
  Serial.print("\t");
  //if( (x_pos1>(cx1-100)) || (x_pos1<(cx1+100))){Serial.print("stop");}
  
    //if( (x_pos1<600) || (x_pos1>400)){
    if(locx1<0 ){locx1=0;}
    if(locx1>180){locx1=180;}
    if((x_pos1 == 1)){x_pos1=0;}
    locx1+=x_pos1;
    Serial.println(locx1);
  
}
