#define LDR_PIN 36

void setup()
{
    Serial.begin(115200);
    delay(1000);
}

void loop()
{
    int ldrValue = analogRead(LDR_PIN);

    Serial.print("LDR Value: ");
    Serial.println(ldrValue);

    delay(500);
}