/*

Author: Ilan Rajpar
Date: March 31st 2024
Description: fridge door detector using ultrasonic sensor 


current
*/ 

// pin declarations
const int buzzPin = 3; 
const int trigPin = 9;
const int echoPin = 10;

unsigned long duration; 
unsigned long distance;

bool lastFridgeState = false;   // state of the fridge, false = closed
bool currentFridgeState = false;  // last state of the frdige

const int doorDist = 30;    // if ultrasonic sensor detects distance >door dist, the door is open
const int leftOpenTime = 30000;   // if the door is open for longer than leftOpenTime, the alarm goes
const int closeDelay = 3000;      // the door must be closed for closeDelay seconds to turn off the alarm
const int pulseTime = 300;        // how long the intermittent buzzing is 

unsigned long startOpened = 0;    // used to track when the door was last opened
unsigned long startClosed = 0;    // used to track how long the door has been closed after being opened
unsigned long lastTimeBuzz = 0;    // used to get an intermittent beeping of the buzzer

bool alarmOn = false;     // used to turn track when the alarm should be on or off
bool buzzerOn = false;    // used to track when to turn the buzzer on and off when beeping




void setup() 
{

  pinMode(buzzPin, OUTPUT); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);

}




void loop() 
{
  
  // find the distance using the ultrasonic sensor 
  digitalWrite(trigPin, LOW);   // clear the trigPin 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);    // send the pulse 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH);    // read the duration and calculate the distance 
  distance = (duration * 0.034)/2.0; 

  // print the results to the screen (cm)
  Serial.print("Distance: "); 
  Serial.println(distance); 


  // check if the fridge is opened or closed based on the distance 
  if (distance > doorDist && currentFridgeState == false)
  {
    startOpened = millis(); 
    currentFridgeState = true; 
  }

  // false means that the fridge is closed 
  else if (distance < doorDist) currentFridgeState = false; 

  // if door has been left open for too long, sound alarm
  if (millis() - startOpened > leftOpenTime && currentFridgeState == true) alarmOn = true; 


  // track when the fridge door is closed 
  if (lastFridgeState != currentFridgeState && alarmOn == true && currentFridgeState == false)
  {
    startClosed = millis();
  }

  // if the alarm is on and the door has now been closed for more than a given amount of time, turn it off
  if (millis() - startClosed > closeDelay && alarmOn == true && currentFridgeState == false) alarmOn = false; 

  // when the alarm is supposed to be on, make it an intermittent beeping without using any delays 
  if (alarmOn == true)
  {
    
    if (buzzerOn == false && millis()-lastTimeBuzz > pulseTime)
    {
      Serial.println("LED ON ==============================");
      digitalWrite(buzzPin, HIGH);
      lastTimeBuzz = millis(); 
      buzzerOn = true; 
  
    }

    else if (buzzerOn == true && millis()- lastTimeBuzz > pulseTime)
    {
      Serial.println("LED OFF //////////////////////////");
      digitalWrite(buzzPin, LOW);
      lastTimeBuzz = millis();
      buzzerOn = false;
    }

  }

  // when the alarm is off, simply turn the buzzer off 
  else if (alarmOn == false) digitalWrite(buzzPin, LOW); 
  


  lastFridgeState = currentFridgeState; 
  delay(100);

}
