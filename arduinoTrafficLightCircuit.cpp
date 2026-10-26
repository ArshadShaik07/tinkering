void setup()
{
    pinMode(7, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(13, OUTPUT);
}

void loop()
{
    digitalWrite(7, HIGH);
    digitalWrite(13, LOW);
    delay(1000);

    digitalWrite(7, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(13, LOW);
    delay(1000);

    digitalWrite(7, LOW);
    digitalWrite(10, LOW);
    digitalWrite(13, HIGH);
    delay(1000);
}