#include <Servo.h>

// Create servo objects
Servo servoX;   // Left / Right
Servo servoY;   // Up / Down

// Joystick pins
const int joyX = A0;
const int joyY = A1;

// Servo pins
const int servoXPin = 9;
const int servoYPin = 10;

void setup() {
  servoX.attach(servoXPin);
  servoY.attach(servoYPin);
  
  pinMode(joyX, INPUT);
  pinMode(joyY, INPUT);
}

void loop() {
  // Read joystick values (0–1023)
  int xValue = analogRead(joyX);
  int yValue = analogRead(joyY);

  // Map joystick to servo angles (0–180)
  int servoXAngle = map(xValue, 0, 1023, 0, 130);
  int servoYAngle = map(yValue, 0, 1023, 0, 100);

  // Move servos
  servoX.write(servoXAngle);
  servoY.write(servoYAngle);

  delay(15); // Smooth movement
}




