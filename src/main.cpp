#include <Arduino.h>
#include <Wire.h>

void setup()
{
    Wire.begin();

    Serial.begin(115200);
    while(!Serial) {}

    Serial.println("I2C Scanner");
}

void loop()
{
    Serial.println("Scanning...");
    for (byte address = 1; address < 127; address++) {
        Wire.beginTransmission(address);
        if (Wire.endTransmission() == 0) {
            Serial.print("Found I2C device at address 0x");
            Serial.println(address, HEX);
        }
    }
    Serial.println("done");
    Serial.println();
    Serial.println();
    delay(5000);
}