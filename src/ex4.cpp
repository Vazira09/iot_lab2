


#include "Arduino.h"

const int BUTTON_PIN = 25;
const int LED_PINS[] = {26, 27, 12, 14};
const unsigned long DEBOUNCE_INTERVAL_MS = 50;

int pressCount = 0;
int buttonState = LOW;
int lastButtonReading = LOW;
unsigned long lastButtonChangeTime = 0;

void setup(void)
{
    Serial.begin(115200);

    pinMode(BUTTON_PIN, INPUT);
    for (int i = 0; i < 4; ++i) {
        pinMode(LED_PINS[i], OUTPUT);
        digitalWrite(LED_PINS[i], LOW);
    }

    buttonState = digitalRead(BUTTON_PIN);
    lastButtonReading = buttonState;
    lastButtonChangeTime = millis();
}


void loop(void)
{
    const unsigned long currentTime = millis();
    const int buttonReading = digitalRead(BUTTON_PIN);

    if (buttonReading != lastButtonReading) {
        lastButtonReading = buttonReading;
        lastButtonChangeTime = currentTime;
    }

    if (buttonReading != buttonState &&
        currentTime - lastButtonChangeTime >= DEBOUNCE_INTERVAL_MS) {
        buttonState = buttonReading;
        if (buttonState == HIGH) {
            pressCount = (pressCount + 1) % 5;

            for (int i = 0; i < 4; ++i) {
                digitalWrite(LED_PINS[i], i < pressCount ? HIGH : LOW);
            }

            Serial.printf("count=%d\n", pressCount);
        }
    }
}
