#include <Wire.h>

#define SDA_PIN 8
#define SCL_PIN 9
#define MPU_ADDR 0x68

void writeReg(uint8_t reg, uint8_t data) {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(reg);
  Wire.write(data);
  Wire.endTransmission(true);
}

uint8_t readReg(uint8_t reg) {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(reg);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 1, true);
  return Wire.read();
}

void readBytes(uint8_t reg, uint8_t count, uint8_t* dest) {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(reg);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, count, true);
  for (uint8_t i = 0; i < count; i++) {
    dest[i] = Wire.read();
  }
}

void setup() {
  Serial.begin(115200);
  delay(3000);

  Wire.begin(SDA_PIN, SCL_PIN);
  Wire.setClock(100000);
  delay(200);

  writeReg(0x6B, 0x00);
  delay(100);

  writeReg(0x1B, 0x08);
  writeReg(0x1C, 0x10);
  writeReg(0x1A, 0x04);
}

void loop() {
  uint8_t raw[14];
  readBytes(0x3B, 14, raw);

  int16_t ax = (raw[0]  << 8) | raw[1];
  int16_t ay = (raw[2]  << 8) | raw[3];
  int16_t az = (raw[4]  << 8) | raw[5];
  int16_t temp_raw = (raw[6] << 8) | raw[7];
  int16_t gx = (raw[8]  << 8) | raw[9];
  int16_t gy = (raw[10] << 8) | raw[11];
  int16_t gz = (raw[12] << 8) | raw[13];

  float Ax = ax / 4096.0; float Ay = ay / 4096.0; float Az = az / 4096.0;
  float Gx = gx / 65.5;   float Gy = gy / 65.5;   float Gz = gz / 65.5;
  float Temp = (temp_raw / 340.0) + 36.53;

  Serial.println("--- Readings ---");
  Serial.print("Accel (g)  X: "); Serial.print(Ax, 3);
  Serial.print("  Y: "); Serial.print(Ay, 3);
  Serial.print("  Z: "); Serial.println(Az, 3);
  delay(500);
}
