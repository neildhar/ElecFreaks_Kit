/* Part3 play sound when vibration sensed */
#define buzz 6
#define vib A0

void setup() {
  pinMode(vib, INPUT_PULLUP);
  pinMode(buzz, OUTPUT);
}

void loop() {
  while(digitalRead(vib) != HIGH); //wait for vibration
  analogWrite(buzz, 200); //sound buzzer for one second
  delay(1000);
  analogWrite(buzz, 0);

}
