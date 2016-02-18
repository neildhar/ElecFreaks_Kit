/* PART7 control a servo using a rotary encoder */
#include <Servo.h>

#define encodeB A0
#define servoPin 6
#define encodeA 2

Servo servo;      //create servo object
int angle = 90;   //set the initial servo angle

void setup() {
  pinMode(encodeB, INPUT); // initialize the encodeB pin as an input.
  servo.attach(servoPin); //attach the servo object to the servo pin
  attachInterrupt(digitalPinToInterrupt(encodeA), start, FALLING);
  Serial.begin(9600);
}

void loop(){}

void start() {
  if (digitalRead(encodeB) == HIGH)
    angle = constrain(angle - 30, 0, 180); //if encodeA is falling and encodeB is high, rotate clockwise by 30 degrees

  else
    angle = constrain(angle + 30, 0, 180); //if encodeA is falling and encodeB is low, rotate counterclockwise by 30 degrees
  Serial.println(angle);
  servo.write(angle);
}
