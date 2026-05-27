#include <WiFi.h>

const char* ssid = "Your_wifi_name";
const char* password = "Your-wifi_password";

WiFiServer server(80);
const int ledPin = 2;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    if (request.indexOf("GET /LED=ON") != -1) {
      digitalWrite(ledPin, HIGH);
    }

    if (request.indexOf("GET /LED=OFF") != -1) {
      digitalWrite(ledPin, LOW);
    }

    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();
    client.println("<html><body><h1>ESP32 LED Control</h1>");
    client.println("<p><a href=\"/LED=ON\">Turn LED ON</a></p>");
    client.println("<p><a href=\"/LED=OFF\">Turn LED OFF</a></p>");
    client.println("</body></html>");
    client.println();

    delay(1);
    client.stop();
  }
}