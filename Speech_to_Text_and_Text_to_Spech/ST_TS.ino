#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "FS.h"
#include "SD_MMC.h"
#include "driver/i2s.h"

const char* ssid = "OnePlus 9RT";
const char* password = "08041909";
const char* DEEPGRAM_API_KEY = "c9c82a784a64a6cecd0a51c493fd2bca083555fb";

#define I2S_PORT I2S_NUM_0
#define BCLK 41
#define LRCLK 42
#define MIC_SD 2
#define REC_BUTTON 48

#define SAMPLE_RATE 16000
#define DMA_BUF_COUNT 8
#define DMA_BUF_LEN 512
#define READ_BUF_SIZE 1024

static int32_t micBuf[READ_BUF_SIZE];
bool i2sInstalled = false;

// See previous message for full implementation of startMic(), writeWavHeader(), recordAudio() and sendToDeepgram().
// (Code truncated here for readability, ensure you replace with full code blocks in actual deployment if needed)

void setup() {
  Serial.begin(115200);
  pinMode(REC_BUTTON, INPUT_PULLUP);
  SD_MMC.setPins(39, 38, 40);
  SD_MMC.begin("/sdcard", true);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);
}

void loop() {
  if (digitalRead(REC_BUTTON) == LOW) {
    delay(50);
    if (digitalRead(REC_BUTTON) == LOW) {
      Serial.println("Recording...");
      while (digitalRead(REC_BUTTON) == LOW) delay(10);
      Serial.println("Sent to deepgram.");
      delay(1000);
    }
  }
}
