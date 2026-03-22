#include <Servo.h>

Servo servoH;  // horizontal motor
Servo servoV;  // vertical motor

int posH = 90;
int posV = 90;

void setup() {
  Serial.begin(9600);

  servoH.attach(6);   // horizontal axis
  servoV.attach(9);   // vertical axis

  servoH.write(posH);
  servoV.write(posV);
}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read();

    // HORIZONTAL CONTROL
    if (input == 'a') posH -= 5;   // left
    if (input == 'd') posH += 5;   // right

    // VERTICAL CONTROL
    if (input == 'w') posV += 5;   // up
    if (input == 's') posV -= 5;   // down

    // CENTER BOTH
    if (input == 'c') {
      posH = 90;
      posV = 90;
    }

    // constrain values
    posH = constrain(posH, 0, 180);
    posV = constrain(posV, 0, 180);

    // write to motors
    servoH.write(posH);
    servoV.write(posV);

    Serial.print("H: ");
    Serial.print(posH);
    Serial.print(" | V: ");
    Serial.println(posV);
  }
}