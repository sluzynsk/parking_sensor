/*
* Garage Parking Sensor - Published By Bob Torrence
* Original Project: https://www.hackster.io/Bcjams/garage-parking-assistant-11446b
* V1.1 by Steve Luzynski

* Changes:
*  More LEDs! 22 on each side which is right for the strips I see out there
* Todo:
*  Rather than triggering power, have the lights turn on with motion and go out after
 * 30 seconds of no motion. Fun to do with no clock but there's gotta be a way.
*/

#include <FastLED.h> 
#include <QuickStats.h> 

// defining the pins
#define LED_PIN 7
#define NUM_LEDS 22
const int trigPin = 9;
const int echoPin = 10;

// defining variables
CRGB leds[NUM_LEDS];
float duration;
float durationarray[NUM_LEDS];
int distance;
int stopdistance = 90; // parking position from sensor (CENTIMETERS)
int startdistance = 400; // distance from sensor to begin scan as car pulls in(CENTIMETERS)
int increment = ((startdistance - stopdistance) / NUM_LEDS);

int lastDistanceChange = 0;
int lastDistance = 0;
int motionDelta = 5;

QuickStats stats;

void setup() {
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    Serial.begin(9600); // Starts the serial communication
}

void loop() {
    for (int i = 0; i <= 21; i ++) { // Clears the trigPin
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        // Sets the trigPin on HIGH state for 10 micro seconds
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        // Reads the echoPin, returns the sound wave travel time in microseconds
        durationarray[i] = pulseIn(echoPin, HIGH);
        distance = durationarray[i] * 0.034 / 2;
        Serial.print(distance);
        Serial.print(" ");
    }
    duration = (stats.median(durationarray, 22));
    // Calculating the distance
    distance = duration * 0.034 / 2;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);

    if (abs(lastDistance - distance) > motionDelta) {
      lastDistanceChange = 0; // there's motion, reset the loop counter
    }
    else
    {
      lastDistanceChange += 1; // increment number of loops
      if (lastDistanceChange > 600) { // 600 loops should be around 30 seconds. 
        for (int i = 0; i <= NUM_LEDS-1; i++) {
          leds[i] = CRGB(0, 0, 0); // set them all off
        }
        FastLED.show();
        return;
      }
    }
    
    if (distance < stopdistance) {
        for (int i = 0; i <= 21; i ++) {
            leds[i] = CRGB(255, 0, 0);
            FastLED.show();
        }
    } else if (distance < stopdistance + increment) {
        for (int i = 1; i <= 21; i ++) {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 0; i ++) {
            leds[i] = CRGB(255, 255, 0);
        }
        FastLED.show();
        delay(50);
    } else if (distance < stopdistance + increment * 2) {
        for (int i = 2; i <= 21; i ++) {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 1; i ++) {
            leds[i] = CRGB(255, 255, 0);
        }
        FastLED.show();
        delay(50);
    } else if (distance < stopdistance + increment * 3) {
        for (int i = 3; i <= 21; i ++) {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 2; i ++) {
            leds[i] = CRGB(255, 255, 0);
        }
        FastLED.show();
        delay(50);
    } else if (distance < stopdistance + increment * 4) {
        for (int i = 4; i <= 21; i ++) {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 3; i ++) {
            leds[i] = CRGB(0, 255, 0);
        }
        FastLED.show();
        delay(50);
    } else if (distance < stopdistance + increment * 5) {
        for (int i = 5; i <= 21; i ++) {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 4; i ++) {
            leds[i] = CRGB(0, 255, 0);
        }
        FastLED.show();
        delay(50);
    } else if (distance < stopdistance + increment * 6) {
        for (int i = 6; i <= 21; i ++) {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 5; i ++) {
            leds[i] = CRGB(0, 255, 0);
        }
        FastLED.show();
        delay(50);
    } else if (distance < stopdistance + increment * 7) {
        for (int i = 7; i <= 21; i ++) {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 6; i ++) {
            leds[i] = CRGB(0, 255, 0);
        }
        FastLED.show();
        delay(50);
    } else if (distance < stopdistance + increment * 8) {
        for (int i = 8; i <= 21; i ++) {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 7; i ++) {
            leds[i] = CRGB(0, 255, 0);
        }
        FastLED.show();
        delay(50);
    } else if (distance < stopdistance + increment * 9) {
        for (int i = 9; i <= 21; i ++) {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 8; i ++) {
            leds[i] = CRGB(0, 255, 0);
        }
        FastLED.show();
        delay(50);
    } else if (distance < stopdistance + increment * 10) {
        for (int i = 10; i <= 21; i ++) {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 9; i ++) {
            leds[i] = CRGB(0, 255, 0);
        }
        FastLED.show();
        delay(50);
    } else if (distance < stopdistance + increment * 11) {
        for (int i = 11; i <= 21; i ++) {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 10; i ++) {
            leds[i] = CRGB(0, 255, 0);
        }
        FastLED.show();
        delay(50);
    } else if (distance < stopdistance + increment * 12) {
        for (int i = 12; i <= 21; i ++) {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 11; i ++) {
            leds[i] = CRGB(0, 255, 0);
        }
        FastLED.show();
        delay(50);
    } else if (distance < stopdistance + increment * 13) {
        for (int i = 13; i <= 21; i ++) {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 12; i ++) {
            leds[i] = CRGB(0, 255, 0);
        }
        FastLED.show();
        delay(50);
    } else if (distance < stopdistance + increment * 14) {
        for (int i = 14; i <= 21; i ++) {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 13; i ++) {
            leds[i] = CRGB(0, 255, 0);
        }
        FastLED.show();
        delay(50);
    } else if (distance < stopdistance + increment * 15) {
        for (int i = 15; i <= 21; i ++) {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 14; i ++) {
            leds[i] = CRGB(0, 255, 0);
        }
        FastLED.show();
        delay(50);
    } else if (distance < stopdistance + increment * 16) {
        for (int i = 16; i <= 21; i ++) {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 15; i ++) {
            leds[i] = CRGB(0, 255, 0);
        }
        FastLED.show();
        delay(50);
    } else if (distance < stopdistance + increment * 17) {
        for (int i = 17; i <= 21; i ++) {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 16; i ++) {
            leds[i] = CRGB(0, 255, 0);
        }
        FastLED.show();
        delay(50);
    } else if (distance < stopdistance + increment * 18) {
        for (int i = 18; i <= 21; i ++) {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 17; i ++) {
            leds[i] = CRGB(0, 255, 0);
        }
        FastLED.show();
        delay(50);
    } else if (distance < stopdistance + increment * 19) {
        for (int i = 19; i <= 21; i ++) {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 18; i ++) {
            leds[i] = CRGB(0, 255, 0);
        }
        FastLED.show();
        delay(50);
    } else if (distance < stopdistance + increment * 20) {
        for (int i = 20; i <= 21; i ++) {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 19; i ++) {
            leds[i] = CRGB(0, 255, 0);
        }
        FastLED.show();
        delay(50);
    } else if (distance < stopdistance + increment * 21) {
        for (int i = 21; i <= 21; i ++) {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 20; i ++) {
            leds[i] = CRGB(0, 255, 0);
        }
        FastLED.show();
        delay(50);
    } else if (distance >= stopdistance + increment * 21) {
        for (int i = 0; i <= 21; i ++) {
            leds[i] = CRGB(0, 255, 0);
        }
        FastLED.show();
        delay(50);
    }
}
