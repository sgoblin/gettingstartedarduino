// Copyright Ryan Meshulam
// Released under the GNU LGPL v3 http://www.gnu.org/licenses/lgpl.html
// Many thanks to Arduino for creating this great open hardware,
// Sparkfun for selling it with some examples and a manual,
// and the authors of the arduino examples for writing amazing examples.

//This imports the servo library; adding some code that was prewritten to make servos easier to use
#include <Servo.h>

//This assigns the number 10 to the constant integer variable motorPin
const int motorPin = 10;
//Basically the same thing
const int servoPin = 9;
//The pin that I am going to use for the knob
const int knobPin = 0;

//Creates a servo object from the servo library that
//has functions that will be used to control the servo
Servo myservo;

//This creates an empty integer variable that can be changed
int knobVal;

void setup()
{
  //This will set up the motor pin as an output
  pinMode(motorPin, OUTPUT);
  
  //This sets the servoPin as the pin that the servo is going to get info from
  myservo.attach(servoPin);
  
  //This sets up a serial port so thst you can control it from your computer
  Serial.begin(9600);
}

void loop()
{
  //Finds the value that the knob is giving
  knobVal = analogRead(knobPin);
  //Runs the servomove function
  servomove(knobVal);
  
  //Runs the motorSpeed function
  motorSpeed(knobVal);
}

void servomove(int knobval)
{
  //This code is from an arduino example that comes with the arduino SDK.
  //Thanks to Michal Rinott for some of this code.
  knobval = map(knobval, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 1 and 180) 
  myservo.write(knobval);                  // sets the servo position according to the scaled value   
  delay(15);                           // waits for the servo to get there (the number is in milliseconds)
}

void motorSpeed(int knobval)
{
  //This code was inspired by and based off of a Sparkfun Inventor's Kit project.
  //Sparkfun released this code into the public domain.
  //NOTE: The code that is greyed out here is the code that would send a speed to the motor.
  //int speedstart = analogRead(knobPin);
  ////This changing of knobVal doesn't affect the one in servomove because it is within a function.
  //int speed1 = map(speedstart, 65, (1023+65), 65, 255);  //This scales the value from the knob(0-1023) to a range between 0 and 255.
  //That is the range of speeds for the motor.
  //This puts the value (0-255) into the motor, and the speed changes accordingly.
  //analogWrite(motorPin, speed1);
  //Just a small delay to smooth things out.
  //delay(15);
  
  //The value coming from the knob can be from 1-1024
  //This just checks if it's below or equal to 512.
  //If it is, then it turns the motor off.
  if (knobval <= 512){
    digitalWrite(motorPin, LOW);//If it is anything else, it turns the motor on.
  }else{
    digitalWrite(motorPin, HIGH);
  }
}
  
 
