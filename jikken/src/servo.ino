#include<Servo.h>
#define H_SERVO 2

// タップを実現させるためのパラメータ調整

Servo servo;

void setup(){
	// servo.attach(H_SERVO, 500, 2400);
	servo.attach(H_SERVO);
	Serial.begin(9600);
	servo.write(0);
	delay(1000);
	servo.write(30);
	delay(80); // このあたりが理想かも?
	servo.write(0);
}

void loop(){
	delay(1000);
	// servo.write(0);
	// delay(1000);
	// servo.write(90);
	// delay(1000);
	// servo.write(180);
	// delay(1000);
	// servo.write(90);
	// delay(1000);
}
