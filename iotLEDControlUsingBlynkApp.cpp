#define BLYNK_TEMPLATE_ID "TMPL30MawYmTE"
#define BLYNK_TEMPLATE_NAME "espTest"
#define BLYNK_AUTH_TOKEN "FmHXAfTye65NdFtt9WRgeiVP03ZwYLnl"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "GRIITSKNL";
char pass[] = "1234567888";

#define LED_PIN 2

void setup()
{
    Serial.begin(115200);

    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

BLYNK_WRITE(V0)
{
    int pinValue = param.asInt();
    digitalWrite(LED_PIN, pinValue);
}

void loop()
{
    Blynk.run();
}