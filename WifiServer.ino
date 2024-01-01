#include "WiFi.h"

#define redLedPin 23
#define greenLedPin 22
#define blueLedPin 2

void setup() {
  
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);  // Corrected to WiFi
  WiFi.disconnect();     // Corrected to WiFi
  delay(1000);
}

void loop() {
  Serial.println("Scanning Available Networks.....");
  digitalWrite(redLedPin, HIGH);
  digitalWrite(greenLedPin, LOW);
  int n = WiFi.scanNetworks();  // Corrected to WiFi
  if (n != 0) {
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    Serial.print(n);
    Serial.println(" Networks Found");
    for (int i = 0; i < n; i++) {
      Serial.print("network: "); Serial.print(i + 1); Serial.print(": ");
      Serial.print(WiFi.SSID(i)); 
      Serial.print(" ("); Serial.print(WiFi.RSSI(i)); Serial.print(") ");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " Open" : "***");
    }
  } else {
    Serial.println("No available Network");
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
  }
  Serial.println("\n-------------------------\n");
  delay(5000);
}
