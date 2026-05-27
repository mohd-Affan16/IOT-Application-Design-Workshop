const int RELAY_PIN = 27;           // GPIO used for relay module signal
const bool RELAY_ACTIVE_LOW = true; // true if module turns ON when signal is LOW

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  // Ensure relay is OFF at startup
  digitalWrite(RELAY_PIN, RELAY_ACTIVE_LOW ? HIGH : LOW);
  Serial.println("Relay auto test started");
}

void loop() {
  // Turn relay ON
  Serial.println("Relay ON");
  digitalWrite(RELAY_PIN, RELAY_ACTIVE_LOW ? LOW : HIGH);
  delay(10000);

  // Turn relay OFF
  Serial.println("Relay OFF");
  digitalWrite(RELAY_PIN, RELAY_ACTIVE_LOW ? HIGH : LOW);
  delay(10000);
}