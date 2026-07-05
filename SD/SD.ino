#include "FS.h"
#include "SD_MMC.h"

void setup() {
  Serial.begin(115200);
  delay(2000);

  Serial.println("Starting SD Card Test");

  SD_MMC.setPins(39, 38, 40);

  if (!SD_MMC.begin("/sdcard", true)) {
    Serial.println("❌ SD Card Mount Failed");
    return;
  }

  uint8_t cardType = SD_MMC.cardType();
  if (cardType == CARD_NONE) {
    Serial.println("❌ No SD card detected");
    return;
  }

  Serial.println("✅ SD Card detected");

  uint64_t cardSize = SD_MMC.cardSize() / (1024 * 1024);
  Serial.print("Card Size: ");
  Serial.print(cardSize);
  Serial.println(" MB");

  File file = SD_MMC.open("/test.txt", FILE_WRITE);
  if (!file) {
    Serial.println("❌ File creation failed");
    return;
  }

  file.println("ESP32 SD Card Working");
  file.close();

  Serial.println("✅ File written successfully");

  file = SD_MMC.open("/test.txt");
  if (!file) {
    Serial.println("❌ File open failed");
    return;
  }

  Serial.println("Reading file:");
  while (file.available()) {
    Serial.write(file.read());
  }
  file.close();
}

void loop() {}
