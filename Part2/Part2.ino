/* Part2 toggle LED with button */

#define btn A0
#define led 13

void setup() {
  pinMode(btn, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, LOW);
  while (digitalRead(btn) != HIGH); //wait until button is released
  while (digitalRead(btn) != LOW); //Wait until button is pressed
  
  digitalWrite(led, HIGH); //as soon as button is pressed light LED
  while (digitalRead(btn) != HIGH); //wait until button is released
  while (digitalRead(btn) != LOW); //wait until button is pressed again
}
