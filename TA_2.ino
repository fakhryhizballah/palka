#include <WiFi.h>
#include "EspMQTTClient.h"
#include "DHT.h"
#include <ArduinoJson.h>
#include <Arduino_JSON.h>

#define DHTPIN 4     // Digital pin connected to the DHT sensor
// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
DHT dht(DHTPIN, DHTTYPE);

const unsigned int TRIG_PIN = D0; // Pin untuk sensor jarak
const unsigned int ECHO_PIN = D3; // Pin untuk sensor jarak


EspMQTTClient client(
  "WifiSSID",    // Wifi SSID
  "WifiPassword",   // Wifi password
  "test.mosquitto.org",  // MQTT Broker server ip
  // "MQTTUsername",   // Can be omitted if not needed
  // "MQTTPassword",   // Can be omitted if not needed
  "TestClient"      // Client name that uniquely identify your device
);


void setup() {
   Serial.begin(115200);
   dht.begin();

   pinMode(TRIG_PIN, OUTPUT);
   pinMode(ECHO_PIN, INPUT);
}

void loop() {
  client.loop();
}

void onConnectionEstablished() {

  client.subscribe("mytopic/test", [] (const String &payload)  {
    Serial.println(payload);
    StaticJsonDocument<192> doc;

    DeserializationError error = deserializeJson(doc, input);

if (error) {
  Serial.print("deserializeJson() failed: ");
  Serial.println(error.c_str());
  return;
}

const char* jenis = doc["jenis"]; // "Kubus"
int tonase = doc["tonase"]; // 1234
int a, b, h, l;
double hx ;
if(jenis = "Kubus"){
  a= doc["a"]; // Panjang
  b= doc["b"]; // Lebar
  h= doc["h"]; // Tinggi
}
if (jenis = "Trapezoidal"){
  a= doc["a"]; // Sisi Atas
  b= doc["b"]; // sisi Bawah
  h= doc["h"]; // Tinggi max
  l= doc["l"]; // lebar
    }
  });

  
}

double volumeKubus(double a, double b, double h, double hx) {
  // Serial.println(a*b*c);
  return;
}

double volumeTrapezoidal(double a, double b, double h, double l, double hx) {
  // Serial.println((a+b)/2*h);
  return;
}

double Temp(){
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  return t;
}


double mersure(double temp){
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Menghitung kecepatan suara berdasarkan suhu
  double v = 331,4 + (0,6 x temp)

  const unsigned long duration = pulseIn(ECHO_PIN, HIGH);
    // Calculating the distance
  // distance = duration * 0.034 / 2;
  double distance = duration / v / 2;
  return distance;
}