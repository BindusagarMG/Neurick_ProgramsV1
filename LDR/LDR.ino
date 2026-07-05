const int LDR_PIN = [MENTION_PIN_HERE]; 

void setup() {
  Serial.begin(115200);
  pinMode(LDR_PIN, INPUT);
  Serial.println("LDR Sensor Initialized");
}

void loop() {
  int lightValue = analogRead(LDR_PIN);
  Serial.print("Light Level: ");
  Serial.println(lightValue);
  delay(1000);
}
