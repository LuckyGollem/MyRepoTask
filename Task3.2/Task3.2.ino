//Giving intuitive names to the pins
const int pingPin4 = 9; 
const int echoPin4 = 8;
const int pingPin3 = 7; 
const int echoPin3 = 6;
const int pingPin2 = 5; 
const int echoPin2 = 4;
const int pingPin1 = 3; 
const int echoPin1 = 2; 

void setup() {
   Serial.begin(9600);
  //initiaoizing all the pins
   pinMode(pingPin1, OUTPUT);
   pinMode(echoPin1, INPUT);
   pinMode(pingPin2, OUTPUT);
   pinMode(echoPin2, INPUT);
   pinMode(pingPin3, OUTPUT);
   pinMode(echoPin3, INPUT);
   pinMode(pingPin4, OUTPUT);
   pinMode(echoPin4, INPUT);
}

void loop() {
  //initiaoizing all the variables
  int x,y;
  long sensor0,sensor90,sensor180,sensor270;
  //Taking in the sensor readings
  sensor0 = altrasonicSensor(pingPin1, echoPin1);
  sensor90 = altrasonicSensor(pingPin2, echoPin2); 
  sensor180 = altrasonicSensor(pingPin3, echoPin3); 
  sensor270 = altrasonicSensor(pingPin4, echoPin4); 
  //Taking the avr. of the opposit sensors to reduce noise 
  x = (sensor180+5-sensor0)/2;
  y = (sensor270+6-sensor90)/2;
   
   delay(100);
   //Printing out the position
   Serial.print(x);
   Serial.print(",");
   Serial.println(y);
}


long altrasonicSensor(int pingPin,int echoPin)
{
   long duration, cm;
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   return duration / 29 / 2 / 100;
}