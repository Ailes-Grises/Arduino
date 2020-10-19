#include<Servo.h>
#define H_SERVO 3 // サーボモータのピン番号

// 最大3桁の数字を読み取り，'x'をトリガとして入力された角度だけサーボを回転させる

int rad = 0; // 角度rad の初期化

Servo head_servo;

void setup(){
	head_servo.attach(H_SERVO); // サーボの信号ピンを3番に接続する
	Serial.begin(9600);
	head_servo.write(90); // サーボを回転
}

void loop(){
	int ch;

	if(ch != - 1){
		ch = Serial.read();

		switch(ch){
			case '0'...'9':
				rad = rad*10 + ch - '0'; break;
			case 'x':
				head_servo.write(rad);
				delay(15);
				rad = 0;
				break;
			default:
				break;
		}
	}
}
