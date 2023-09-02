//Master code

#include <Wire.h>


int button1;
int button2;
long convertVal=2.55;//This converts 0-100 to 0-255


void setup()
{
  
  
  Wire.begin();//Enters the bus
  
  
  Serial.begin(9600);
  
  
  pinMode(9,OUTPUT);
  
  
}


void loop()
{
  
  //Initializing the buttons from the buffer
  if( Wire.available())
  {
    button1 = Wire.read();
  }
  
  
  Wire.requestFrom(10,sizeof(int));
  if( Wire.available())
  {
    button2 = Wire.read();
  }
  //end initializing
  
  /*//Prints the button values for debugging reasons
  delay(500);
  Serial.print(button1);
  Serial.print(",");
  Serial.println(button2);*/
  
  //Controls the led
  if(button1 == 0 && button2 == 0)
  {
    delay(400);
    analogWrite(9,0*convertVal);
  }
  
  
  if(button1 == 1 && button2 == 0)
  {
    delay(400);
    analogWrite(9,50*convertVal);
    Serial.print("Vector focused");
  }
  
  
  if(button1 == 0 && button2 == 1)
  {
    delay(400);
    analogWrite(9,75*convertVal);
    Serial.print("Vector distracted");
  }
  
  
  if(button1 == 1 && button2 == 1)
  {
    delay(400);
    analogWrite(9,100*convertVal);
    Serial.print("Glitch");
  }
  
  
}