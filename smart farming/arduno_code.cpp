#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "DHT.h"

const char* ssid = "WIFI_NAME";
const char* password = "WIFI_PASSWORD";

#define DHTPIN D4
#define DHTTYPE DHT11
#define SOIL_PIN A0
#define RELAY_PIN D1

DHT dht(DHTPIN, DHTTYPE);
ESP8266WebServer server(80);

int threshold = 500;

void handleData() {
  int soil = analogRead(SOIL_PIN);
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  bool pump = soil < threshold;
  digitalWrite(RELAY_PIN, pump ? HIGH : LOW);

  String json = "{";
  json += "\"soil\":" + String(soil) + ",";
  json += "\"temperature\":" + String(temp) + ",";
  json += "\"humidity\":" + String(hum) + ",";
  json += "\"pump\":\"" + String(pump ? "ON" : "OFF") + "\"";
  json += "}";

  server.send(200, "application/json", json);
}

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  dht.begin();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);

  Serial.println(WiFi.localIP());

  server.on("/data", handleData);
  server.begin();
}

void loop() {
  server.handleClient();
}
