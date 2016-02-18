/* Part4 Passive infrared motion detection to trigger fan */

#define pir A0
#define motor 6

void setup() {
  pinMode(pir, INPUT);
  pinMode(motor, OUTPUT);
}

void loop() {
  if(digitalRead(pir) == HIGH){ //if PIR sensor is detecting motion, switch on the fan
    analogWrite(motor, 500);
    delay(5000);
    digitalWrite(motor, LOW);
  }

}
