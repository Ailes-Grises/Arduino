// メトロノームのような機能を使った方が良い(time.h系)
// システムコールは使えないかも知れない
// delay() の単位はミリ秒
#include<Servo.h>
#define RAD 10 // サーボの回転角度
#define SERVO0 0 // サーボモータのピン番号(繋ぎ変えを想定してマクロにした)
#define SERVO1 1
#define SERVO2 2
#define SERVO3 3
#define SERVO4 4
#define SERVO5 5
#define SERVO6 6
#define SERVO7 7
#define SERVO8 8

#define TAP_DELAY 80 // タップの際，タッチしてから元に戻すまでに挟む非常に短い遅延時間

#define BPM 127 // 後で専用ソフトで解析したほうが良い
#define ONE_TONE 60/BPM // 四分音符1個の長さ(単位はsec)
#define ONE_SECTION 4*ONE_TONE // 1小節の長さ

// 'j'をトリガとして入力された角度だけサーボを回転させる
class myservo_t : public Servo{
	public:
	myservo_t(){
	};
	~myservo_t(){
	};
	void tap(){
		this->write(RAD);
		delay(TAP_DELAY);
		this->write(0);
		delay(ONE_TONE); // ここの微調節が命．タップ操作の合計時間がちょうど1小節分でないと譜面が崩れる．
	};
	void half_tap(){
		this->write(RAD);
		delay(TAP_DELAY);
		this->write(0);
		delay(ONE_TONE/2);
	};
	void long_tap(int time){
		this->write(RAD);
		delay(time);
		this->write(0);
		delay(ONE_TONE);
	};
};

void double_tap(myservo_t &arg1, myservo_t &arg2){
	arg1.write(RAD);
	arg2.write(RAD);
	arg1.write(0);
	arg2.write(0);
	delay(1); // ちゃんと補正すること．
}

myservo_t servo[9];


void private_wars(){
	delay(4*ONE_SECTION); // 冒頭4小節は休み
	/* Aメロ */
	servo[3].tap();
	servo[1].tap();
	servo[2].tap();
	delay(ONE_TONE);
	servo[6].tap();
	servo[8].tap();
	servo[7].tap();
	delay(ONE_TONE);
	servo[0].tap();
	servo[2].tap();
	servo[1].tap();
	delay(ONE_TONE);
	servo[8].tap();
	servo[6].tap();
	servo[7].tap();
	delay(ONE_TONE);
	servo[1].tap();
	servo[3].tap();
	servo[2].tap();
	delay(ONE_TONE);
	servo[7].tap();
	servo[5].tap();
	servo[6].tap();
	delay(ONE_TONE);
	servo[2].tap();
	servo[0].tap();
	servo[1].tap();
	delay(ONE_TONE);
	servo[6].tap();
	servo[8].tap();
	servo[7].tap();
	servo[6].tap();
	servo[5].tap();

	/* Bメロ */
	delay(ONE_SECTION + 3*ONE_TONE);
	double_tap(servo[0], servo[8]);
	delay(ONE_SECTION + 3*ONE_TONE);
	servo[3].tap();
	delay(ONE_SECTION + 3*ONE_TONE);
	double_tap(servo[0], servo[8]);
	delay(ONE_SECTION + 3*ONE_TONE); // wow!
	double_tap(servo[2], servo[6]);     // 孤独の切
	delay(2*ONE_TONE);
	servo[3].tap();                  // なさ
	servo[2].tap();
	delay(2*ONE_TONE);
	servo[5].tap();                  // けど
	servo[6].tap();
	delay(ONE_TONE);
	servo[4].tap();                  // 言葉を
	delay(ONE_TONE);
	servo[3].long_tap(3*ONE_TONE);   // 交わし合っ
	delay(ONE_TONE);                 // て
	double_tap(servo[2], servo[6]);     // お互いの
	delay(2*ONE_TONE);
	servo[5].tap();                  // 所で
	servo[6].tap();
	delay(2*ONE_TONE);
	servo[3].tap();                  // (お)もい
	servo[2].tap();
	delay(ONE_TONE);
	servo[4].tap();
	delay(ONE_TONE);
	servo[5].long_tap(3*ONE_TONE);   // てー

	/* Cメロ(サビ) */
	delay(ONE_TONE);                 // わっちゃ
	servo[2].tap();                  // どぅー
	delay(ONE_TONE);                 // わっちゃ
	servo[0].tap();                  // どぅー
	delay(ONE_TONE);                 // わっちゃ
	servo[7].tap();
	servo[6].tap();
	servo[1].tap();
	servo[2].tap();
	servo[6].tap();
	delay(ONE_TONE);
	servo[8].tap();
	delay(ONE_TONE);
	servo[1].tap();
	servo[2].tap();
	servo[7].tap();
	servo[6].tap();                  // わっちゃ
	servo[1].tap();                  // どぅー
	delay(ONE_TONE);                 // わっちゃ
	double_tap(servo[5], servo[3]);     // どぅー
	delay(ONE_TONE);                 // わっちゃ
	servo[6].tap();
	servo[2].tap();
	servo[8].tap();
	servo[0].tap();                  // ほら
	servo[7].tap();                  // 人
	delay(ONE_TONE);                 // 生
	double_tap(servo[5], servo[3]);     // ちょっ
	delay(ONE_TONE);                 // との
	servo[2].tap();                  // 勇
	servo[6].tap();                  // 気と
	servo[3].tap();                  // 情
	servo[5].half_tap();             // 熱
	servo[5].half_tap();             // さ

	/* Outro */
	servo[3].tap();                  // Can
	servo[1].tap();                  // I
	servo[2].tap();                  // do
	delay(ONE_TONE);
	servo[5].tap();
	servo[7].tap();
	servo[6].tap();
	delay(ONE_TONE);
	servo[0].tap();
	servo[2].tap();
	servo[1].tap();
	delay(ONE_TONE);
	servo[8].tap();
	servo[6].tap();
	servo[7].tap();
	delay(ONE_TONE);
	servo[1].tap();
	servo[3].tap();
	double_tap(servo[2], servo[6]);
	delay(ONE_TONE);
	servo[7].tap();
	servo[5].tap();
	servo[6].tap();
	delay(ONE_TONE);
	servo[2].tap();
	servo[0].tap();
	double_tap(servo[1], servo[7]);
	delay(2*ONE_TONE);
	servo[4].half_tap();
	servo[4].half_tap();
	servo[4].tap();

	/* The end */
}

void setup(){
	Serial.begin(9600);
	servo[0].attach(SERVO0); // サーボ0の信号ピンを0番に接続する
	servo[1].attach(SERVO1);
	servo[2].attach(SERVO2);
	servo[3].attach(SERVO3);
	servo[4].attach(SERVO4);
	servo[5].attach(SERVO5);
	servo[6].attach(SERVO6);
	servo[7].attach(SERVO7);
	servo[8].attach(SERVO8);

	// 角度の初期化
	servo[0].write(0);
	servo[1].write(0);
	servo[2].write(0);
	servo[3].write(0);
	servo[4].write(0);
	servo[5].write(0);
	servo[6].write(0);
	servo[7].write(0);
	servo[8].write(0);
}

void loop(){
	private_wars();
	/*
	int signal;
	if((signal = Serial.read()) != - 1){
		switch(signal){
			case 'j' : 
				private_wars();
				break;
			default: // 本当は強制終了の割り込み処理を実装したほうが良い．
				break;
		}
	}
	*/

}
