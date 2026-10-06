


#include "Arduino.h"

const int LIGHT_PIN = 33;
const unsigned long SAMPLE_INTERVAL_MS = 300;
const int ALERT_ON_THRESHOLD = 3000;
const int ALERT_OFF_THRESHOLD = 2500;

bool alertActive = false;
unsigned long lastSampleTime = 0;

void setup(void)
{
    Serial.begin(115200);
}


void loop(void)
{
    const unsigned long currentTime = millis();
    if (currentTime - lastSampleTime < SAMPLE_INTERVAL_MS) {
        return;
    }
    lastSampleTime = currentTime;

    const int reading = analogRead(LIGHT_PIN);
    if (!alertActive && reading > ALERT_ON_THRESHOLD) {
        alertActive = true;
        Serial.println("ALERT=1");
    } else if (alertActive && reading < ALERT_OFF_THRESHOLD) {
        alertActive = false;
        Serial.println("ALERT=0");
    }
}
