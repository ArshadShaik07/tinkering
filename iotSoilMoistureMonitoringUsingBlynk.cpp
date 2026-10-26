#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_TEMPLATE_NAME "SoilMoistureMonitor"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "YourWiFiName";
char pass[] = "YourWiFiPassword";

int soilPin = A0;

BlynkTimer timer;

void sendSoilMoisture()
{
    int soilValue = analogRead(soilPin);
    int moisturePercent = map(soilValue, 1023, 0, 0, 100);

    Serial.print("Soil Moisture Raw: ");
    Serial.print(soilValue);
    Serial.print(" --> Moisture: ");
    Serial.print(moisturePercent);
    Serial.println("%");

    Blynk.virtualWrite(V0, moisturePercent);
}

void setup()
{
    Serial.begin(9600);
    Blynk.begin(auth, ssid, pass);

    timer.setInterval(2000L, sendSoilMoisture);
}

void loop()
{
    Blynk.run();
    timer.run();
}