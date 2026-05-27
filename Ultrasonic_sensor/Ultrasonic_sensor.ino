#define TRIG_PIN 9    // Trigger pin
#define ECHO_PIN 10   // Echo pin

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.println("Ultrasonic Sensor Test Started");
}

void loop() {
  long duration;
  float distance_cm;
  float distance_inch;

  // Clear the trigger pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  
  // Send trigger pulse
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo time
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance
  distance_cm = duration * 0.0343 / 2;     // Speed of sound = 343 m/s
  distance_inch = distance_cm * 0.393701;

  // Print results
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.print(" cm | ");
  Serial.print(distance_inch);
  Serial.println(" inches");

  delay(500);  // Wait before next reading
}