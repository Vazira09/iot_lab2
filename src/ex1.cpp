


#include "Arduino.h"

#define RED_LED_PIN 26
#define GREEN_LED_PIN 27
#define YELLOW_LED_PIN 12
#define BLUE_LED_PIN 14

const uint8_t ledPins[] = {
    RED_LED_PIN,
    GREEN_LED_PIN,
    YELLOW_LED_PIN,
    BLUE_LED_PIN,
    YELLOW_LED_PIN,
    GREEN_LED_PIN
};

const char *ledNames[] = {
    "RED",
    "GREEN",
    "YELLOW",
    "BLUE",
    "YELLOW",
    "GREEN"
};

const uint8_t chaseSteps = sizeof(ledPins) / sizeof(ledPins[0]);
uint8_t chaseStep = 0;

/****************************************************/
void setup(void) 
{
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_PIN, OUTPUT);

    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);

    Serial.begin(115200);
}


/****************************************************/
void loop(void) 
{
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);

    digitalWrite(ledPins[chaseStep], HIGH);
    Serial.print("chase=");
    Serial.println(ledNames[chaseStep]);
    delay(150);

    chaseStep = (chaseStep + 1) % chaseSteps;
}
