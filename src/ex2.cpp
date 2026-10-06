


#include "Arduino.h"

const int LIGHT_PIN = 33;
const unsigned long SAMPLE_INTERVAL_MS = 1000;

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

    int minimum = 4095;
    int maximum = 0;
    int total = 0;

    for (int sample = 0; sample < 10; ++sample) {
        const int reading = analogRead(LIGHT_PIN);
        if (reading < minimum) {
            minimum = reading;
        }
        if (reading > maximum) {
            maximum = reading;
        }
        total += reading;
    }

    Serial.printf("min=%d max=%d avg=%d\n", minimum, maximum, total / 10);
}
