const int MOISTURE_PIN = [MENTION_PIN_HERE];

void setup() {
  Serial.begin(115200);
  pinMode(MOISTURE_PIN, INPUT);
  Serial.println("Soil Moisture Sensor Ready");
}

void loop() {
  int moistureLevel = analogRead(MOISTURE_PIN);

  Serial.print("Moisture Level: ");
  Serial.println(moistureLevel);
  delay(1000);
}
