#include <ESP32Servo.h>

// For ESP32-1:
const int SERVO_A_PIN = 4;
const int SERVO_B_PIN = 5;

// For ESP32-2:
// const int SERVO_A_PIN = 1;
// const int SERVO_B_PIN = 40;

Servo servoA;
Servo servoB;

void setup() {
  Serial.begin(115200);

  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);

  servoA.setPeriodHertz(50);
  servoB.setPeriodHertz(50);

  servoA.attach(SERVO_A_PIN, 500, 2400);
  servoB.attach(SERVO_B_PIN, 500, 2400);

  Serial.println("Servos Ready!");
}

void loop() {
  for (int pos = 0; pos <= 180; pos += 1) {
    servoA.write(pos);
    servoB.write(pos);
    delay(15);
  }
  for (int pos = 180; pos >= 0; pos -= 1) {
    servoA.write(pos);
    servoB.write(pos);
    delay(15);
  }
}
