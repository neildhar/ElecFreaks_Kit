/* Part5 Light dependent resistor to trigger fan */

#define ldr A0
#define motor 6

int fanSpeed;

void setup() {
  pinMode(ldr, INPUT);
  pinMode(motor, OUTPUT);
}

void loop() {
  fanSpeed = analogRead(ldr)*2; //set the fanspeed to be double of the LDR value
  analogWrite(motor, fanSpeed);
}
