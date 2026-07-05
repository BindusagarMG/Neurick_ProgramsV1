#define M1 48
#define M2 47
#define M3 21
#define M4 14
#define M5 13
#define M6 12
#define M7 11
#define M8 10

void setup() {
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  pinMode(M5, OUTPUT);
  pinMode(M6, OUTPUT);
  pinMode(M7, OUTPUT);
  pinMode(M8, OUTPUT);
  Serial.begin(115200);
  Serial.println("Motor Driver Initialized");
}

void motorA_forward() { digitalWrite(M1, HIGH); digitalWrite(M2, LOW); }
void motorA_backward() { digitalWrite(M1, LOW); digitalWrite(M2, HIGH); }
void motorA_stop() { digitalWrite(M1, LOW); digitalWrite(M2, LOW); }

void motorB_forward() { digitalWrite(M3, HIGH); digitalWrite(M4, LOW); }
void motorB_backward() { digitalWrite(M3, LOW); digitalWrite(M4, HIGH); }
void motorB_stop() { digitalWrite(M3, LOW); digitalWrite(M4, LOW); }

void loop() {
  Serial.println("Moving Forward");
  motorA_forward(); motorB_forward(); delay(3000);

  Serial.println("Stopping");
  motorA_stop(); motorB_stop(); delay(2000);

  Serial.println("Reversing");
  motorA_backward(); motorB_backward(); delay(3000);

  Serial.println("Stopping");
  motorA_stop(); motorB_stop(); delay(2000);
}
