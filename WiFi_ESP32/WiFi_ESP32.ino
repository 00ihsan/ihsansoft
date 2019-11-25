#include <WiFi.h>
const char* ssid = "NSA, kijk je mee?";
const char* password = "201920182017";
const int onboardLED = 2;

void Wifi_init()
{
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    digitalWrite(onboardLED, 1);
    delay(500);
    digitalWrite(onboardLED, 0);
    delay(500);
  }
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("");
    Serial.print("Connected to: ");
    Serial.println(ssid);
    Serial.println(WiFi.localIP());
    digitalWrite(onboardLED, 1);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("");
  pinMode(onboardLED, OUTPUT);
  Serial.print("Connecting to: ");
  Serial.println(ssid);
  Wifi_init();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (WiFi.status() != WL_CONNECTED)
  {
    Wifi_init();
  }
}
