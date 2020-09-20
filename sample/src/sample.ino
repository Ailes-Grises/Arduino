#include<Arduino.h>
#define LED_PIN 13

void setup(){
	pinMode(LED_PIN, OUTPUT);
	Serial.begin(9600);
}

// LED点滅
void loop(){
	Serial.println("Hello Arduino\n");
	digitalWrite(LED_PIN, HIGH); delay(900);
	digitalWrite(LED_PIN, LOW); delay(900);
}
