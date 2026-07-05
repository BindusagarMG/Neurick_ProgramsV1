// ==================== Direction Pins ====================
#define M1 48    // Motor A IN1
#define M2 47    // Motor A IN2

#define M3 21    // Motor B IN1
#define M4 14    // Motor B IN2

// Unused (Motor C & D)
#define M5 13
#define M6 12
#define M7 11
#define M8 10

// ==================== PWM Pins ====================
// Replace these with your actual PWM pins
#define ENA 9      // Motor A PWM
#define ENB 8      // Motor B PWM

// PWM Configuration
const int PWM_FREQ = 1000;      // 1 kHz
const int PWM_RESOLUTION = 8;   // 8-bit (0-255)

const int ENA_CHANNEL = 0;
const int ENB_CHANNEL = 1;

void setup()
{
  Serial.begin(115200);

  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);

  // Configure PWM Channels
  ledcAttachChannel(ENA, PWM_FREQ, PWM_RESOLUTION, ENA_CHANNEL);
  ledcAttachChannel(ENB, PWM_FREQ, PWM_RESOLUTION, ENB_CHANNEL);

  Serial.println("Motor Driver Initialized");
}

//=========================================================
// Motor A
//=========================================================

void motorA_forward(uint8_t speed)
{
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  ledcWrite(ENA, speed);
}

void motorA_backward(uint8_t speed)
{
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  ledcWrite(ENA, speed);
}

void motorA_stop()
{
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  ledcWrite(ENA, 0);
}

//=========================================================
// Motor B
//=========================================================

void motorB_forward(uint8_t speed)
{
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
  ledcWrite(ENB, speed);
}

void motorB_backward(uint8_t speed)
{
  digitalWrite(M3, LOW);
  digitalWrite(M4, HIGH);
  ledcWrite(ENB, speed);
}

void motorB_stop()
{
  digitalWrite(M3, LOW);
  digitalWrite(M4, LOW);
  ledcWrite(ENB, 0);
}

void loop()
{
  Serial.println("Forward - 30%");
  motorA_forward(80);
  motorB_forward(80);
  delay(3000);

  Serial.println("Forward - 60%");
  motorA_forward(150);
  motorB_forward(150);
  delay(3000);

  Serial.println("Forward - 100%");
  motorA_forward(255);
  motorB_forward(255);
  delay(3000);

  Serial.println("Stop");
  motorA_stop();
  motorB_stop();
  delay(2000);

  Serial.println("Reverse - 50%");
  motorA_backward(128);
  motorB_backward(128);
  delay(3000);

  Serial.println("Stop");
  motorA_stop();
  motorB_stop();
  delay(2000);
}
