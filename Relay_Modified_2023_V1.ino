#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "HUAWEI Y5 2019";
const char* password = "0123456789";

// Define the pins to which the relays are connected
const int relayPins[] = {23, 22, 21, 19, 18, 5, 17, 16, 12, 13, 32, 33, 25, 26, 27, 14};
const int numRelays = sizeof(relayPins) / sizeof(relayPins[0]);

void setup() {
  Serial.begin(115200);

  // Set the pin modes for the relays
  for (int i = 0; i < numRelays; i++) {
    pinMode(relayPins[i], OUTPUT);
  }

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  // Make HTTP requests to get the states of the relays
  for (int i = 0; i < numRelays; i++) {
    String url = "http://192.168.43.101/PZEM-004T/relay.php?Relay_ID=" + String(i + 1);
    HTTPClient http;
    WiFiClient client;
    http.begin(client, url);
    int httpCode = http.GET();
    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.print("Relay ");
      Serial.print(i + 1);
      Serial.print(" state: ");
      Serial.println(payload);
      int state = payload.toInt();
      digitalWrite(relayPins[i], state);
    } else {
      Serial.print("HTTP request failed with error code ");
      Serial.println(httpCode);
    }
    http.end();
  }
  delay(1);
}
