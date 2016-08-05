/*
Adafruit Arduino - Lesson 13. DC Motor
*/


int motorPin = 11;
 
void setup() 
{ 
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(9, 0);  // start with the "dot" off
} 
 
 
void loop() 
{ 
  if (Serial.available())
  {
    int speed = Serial.parseInt();
    int percentspeed = speed / 25.5;
    Serial.print("Speed: " );
    Serial.println(speed);
    Serial.print("Percent: " );
    Serial.println(percentspeed);
    if (speed >= 0 && speed <= 255)
    {
      
      analogWrite(motorPin, speed);
      //percentspeed=speed/26;
      if (percentspeed < 1)
      {
         // write '0'
         digitalWrite(2, 1);
         digitalWrite(3, 1);
         digitalWrite(4, 1);
         digitalWrite(5, 1);
         digitalWrite(6, 1);
         digitalWrite(7, 1);
         digitalWrite(8, 0);
      }
      else if (percentspeed < 2)
      {
         // write '1'
         digitalWrite(2, 0);
         digitalWrite(3, 1);
         digitalWrite(4, 1);
         digitalWrite(5, 0);
         digitalWrite(6, 0);
         digitalWrite(7, 0);
         digitalWrite(8, 0);
      }
      else if (percentspeed < 3)
      {
          // write '2'
         digitalWrite(2, 1);
         digitalWrite(3, 1);
         digitalWrite(4, 0);
         digitalWrite(5, 1);
         digitalWrite(6, 1);
         digitalWrite(7, 0);
         digitalWrite(8, 1);
      }
      else if (percentspeed <4)
      {
          // write '3'
         digitalWrite(2, 1);
         digitalWrite(3, 1);
         digitalWrite(4, 1);
         digitalWrite(5, 1);
         digitalWrite(6, 0);
         digitalWrite(7, 0);
         digitalWrite(8, 1);
      }
      else if (percentspeed <5)
      {
          // write '4'
         digitalWrite(2, 0);
         digitalWrite(3, 1);
         digitalWrite(4, 1);
         digitalWrite(5, 0);
         digitalWrite(6, 0);
         digitalWrite(7, 1);
         digitalWrite(8, 1);
      }
      else if (percentspeed <6)
      {
          // write '5'
         digitalWrite(2, 1);
         digitalWrite(3, 0);
         digitalWrite(4, 1);
         digitalWrite(5, 1);
         digitalWrite(6, 0);
         digitalWrite(7, 1);
         digitalWrite(8, 1);
      }
      else if (percentspeed <7)
      {
          // write '6'
         digitalWrite(2, 1);
         digitalWrite(3, 0);
         digitalWrite(4, 1);
         digitalWrite(5, 1);
         digitalWrite(6, 1);
         digitalWrite(7, 1);
         digitalWrite(8, 1);
      }
      else if (percentspeed <8)
      {
          // write '7'
         digitalWrite(2, 1);
         digitalWrite(3, 1);
         digitalWrite(4, 1);
         digitalWrite(5, 0);
         digitalWrite(6, 0);
         digitalWrite(7, 0);
         digitalWrite(8, 0);
      }
      else if (percentspeed <9)
      {
          // write '8'
         digitalWrite(2, 1);
         digitalWrite(3, 1);
         digitalWrite(4, 1);
         digitalWrite(5, 1);
         digitalWrite(6, 1);
         digitalWrite(7, 1);
         digitalWrite(8, 1);
      }
      else 
      {
           // write '9'
           digitalWrite(2, 1);
           digitalWrite(3, 1);
           digitalWrite(4, 1);
           digitalWrite(5, 0);
           digitalWrite(6, 0);
           digitalWrite(7, 1);
           digitalWrite(8, 1);
      }
    }
  }
}
