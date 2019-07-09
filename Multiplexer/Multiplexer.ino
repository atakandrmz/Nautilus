int val = 0;         // variable to store the read value

int A_zero = 8;       
int A_one = 9;
int A_two = 10;
int A_three = 11;

int z = 12;

void setup()
{
  
  pinMode(z, INPUT);      // sets the digital pin "z" as input

  pinMode(A_zero, OUTPUT);      // sets the digital pin "A_zero" as output
  pinMode(A_one, OUTPUT);       // sets the digital pin "A_one" as output
  pinMode(A_two, OUTPUT);       // sets the digital pin "A_two" as output
  pinMode(A_three, OUTPUT);     // sets the digital pin "A_three" as output
  
  Serial.begin(9600);

}

void loop()
{
  // Select address 0000  
  digitalWrite(A_zero, LOW);    
  digitalWrite(A_one, LOW);     
  digitalWrite(A_two, LOW);     
  digitalWrite(A_three, LOW);   
  if(digitalRead(z)==1)
  {         
    Serial.println("Switch pressed is 1");  
    delay(50);
  }

  // Select address 0001  
  digitalWrite(A_zero, HIGH);   
  digitalWrite(A_one, LOW);     
  digitalWrite(A_two, LOW);     
  digitalWrite(A_three, LOW);  
  if(digitalRead(z)==1)
  {         
    Serial.println("Switch pressed is 2");  
    delay(50);
  }

  // Select address 0010  
  digitalWrite(A_zero, LOW);   
  digitalWrite(A_one, HIGH);     
  digitalWrite(A_two, LOW);     
  digitalWrite(A_three, LOW);  
  if(digitalRead(z)==1)
  {         
    Serial.println("Switch pressed is 3");
    delay(50);  
  }

  // Select address 0011  
  digitalWrite(A_zero, HIGH);   
  digitalWrite(A_one, HIGH);     
  digitalWrite(A_two, LOW);     
  digitalWrite(A_three, LOW);  
  if(digitalRead(z)==1)
  {         
    Serial.println("Switch pressed is 4");
    delay(50);  
  }

  // Select address 0100  
  digitalWrite(A_zero, LOW);   
  digitalWrite(A_one, LOW);     
  digitalWrite(A_two, HIGH);     
  digitalWrite(A_three, LOW);  
  if(digitalRead(z)==1)
  {         
    Serial.println("Switch pressed is 5");
    delay(50);  
  }  

  // Select address 0101  
  digitalWrite(A_zero, HIGH);   
  digitalWrite(A_one, LOW);     
  digitalWrite(A_two, HIGH);     
  digitalWrite(A_three, LOW);  
  if(digitalRead(z)==1)
  {         
    Serial.println("Switch pressed is 6");
    delay(50);  
  }  

  // Select address 0110  
  digitalWrite(A_zero, LOW);   
  digitalWrite(A_one, HIGH);     
  digitalWrite(A_two, HIGH);     
  digitalWrite(A_three, LOW);  
  if(digitalRead(z)==1)
  {         
    Serial.println("Switch pressed is 7");
    delay(50);  
  }  

  // Select address 0111  
  digitalWrite(A_zero, HIGH);   
  digitalWrite(A_one, HIGH);     
  digitalWrite(A_two, HIGH);     
  digitalWrite(A_three, LOW);  
  if(digitalRead(z)==1)
  {         
    Serial.println("Switch pressed is 8");
    delay(50);  
  }  

  // Select address 1000  
  digitalWrite(A_zero, LOW);   
  digitalWrite(A_one, LOW);     
  digitalWrite(A_two, LOW);     
  digitalWrite(A_three, HIGH);  
  if(digitalRead(z)==1)
  {         
    Serial.println("Switch pressed is 9");
    delay(50);  
  }  

  // Select address 1001  
  digitalWrite(A_zero, HIGH);   
  digitalWrite(A_one, LOW);     
  digitalWrite(A_two, LOW);     
  digitalWrite(A_three, HIGH);  
  if(digitalRead(z)==1)
  {         
    Serial.println("Switch pressed is 10");
    delay(50);  
  }

  // Select address 1010  
  digitalWrite(A_zero, LOW);   
  digitalWrite(A_one, HIGH);     
  digitalWrite(A_two, LOW);     
  digitalWrite(A_three, HIGH);  
  if(digitalRead(z)==1)
  {         
    Serial.println("Switch pressed is 11");
    delay(50);  
  }

  // Select address 1011  
  digitalWrite(A_zero, HIGH);   
  digitalWrite(A_one, HIGH);     
  digitalWrite(A_two, LOW);     
  digitalWrite(A_three, HIGH);  
  if(digitalRead(z)==1)
  {         
    Serial.println("Switch pressed is 12");
    delay(50);  
  }

  // Select address 1100  
  digitalWrite(A_zero, LOW);   
  digitalWrite(A_one, LOW);     
  digitalWrite(A_two, HIGH);     
  digitalWrite(A_three, HIGH);  
  if(digitalRead(z)==1)
  {         
    Serial.println("Switch pressed is 13");
    delay(50);  
  }

  // Select address 1101  
  digitalWrite(A_zero, HIGH);   
  digitalWrite(A_one, LOW);     
  digitalWrite(A_two, HIGH);     
  digitalWrite(A_three, HIGH);  
  if(digitalRead(z)==1)
  {         
    Serial.println("Switch pressed is 14");
    delay(50);  
  }

  // Select address 1110  
  digitalWrite(A_zero, LOW);   
  digitalWrite(A_one, HIGH);     
  digitalWrite(A_two, HIGH);     
  digitalWrite(A_three, HIGH);  
  if(digitalRead(z)==1)
  {         
    Serial.println("Switch pressed is 15");
    delay(50);  
  }

  // Select address 1111  
  digitalWrite(A_zero, HIGH);   
  digitalWrite(A_one, HIGH);     
  digitalWrite(A_two, HIGH);     
  digitalWrite(A_three, HIGH);  
  if(digitalRead(z)==1)
  {         
    Serial.println("Switch pressed is 16");
    delay(50);  
  }
}
