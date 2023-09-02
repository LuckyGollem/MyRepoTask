//Slave code

#include <Wire.h>
#define button1 2
#define button2 3


int toggle1 = 0;
int toggle2 = 0;


void setup()
{
  
  
  Wire.begin(10); //Entered the bus
  Wire.onRequest(miso);//miso stands for Master input Slave output
  
  //Initializing the pins
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  
  //Applying the interrupt when pressing the buttons
  attachInterrupt(digitalPinToInterrupt(button1),buttonToggle1,RISING);
  attachInterrupt(digitalPinToInterrupt(button2),buttonToggle2,RISING);
  
  
  Serial.begin(9600);
}

void loop()
{
 
  //Prints out the button toggles every second
  delay(1000);
  Serial.print(toggle1);
  Serial.println(toggle2);


}

//Queues the toggles in the buffer
void miso()
{
  
  
  Wire.write(toggle1);
  Wire.write(toggle2);

}


void buttonToggle1()
{
  
  
  if(digitalRead(button1) == HIGH)
  {
    delay(400);
    toggle1 = !toggle1; 
  }


}


void buttonToggle2()
{
  
  
  if(digitalRead(button2) == HIGH)
  {
    delay(400);
    toggle2 = !toggle2; 
  }


}
