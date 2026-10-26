#include <Servo.h>

const int irPin = 4;
const int servoPin = 5;

Servo myServo;

void setup()
{
    pinMode(irPin, INPUT);
    myServo.attach(servoPin);
    myServo.write(0);
    Serial.begin(9600);
}

void loop()
{
    int irValue = digitalRead(irPin);

    if (irValue == LOW)
    {
        Serial.println("Object detected!");
        myServo.write(90);
        delay(1000);
    }
    else
    {
        Serial.println("No object.");
        myServo.write(0);
        delay(500);
    }
}