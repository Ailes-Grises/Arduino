# コマンドラインでArduino の開発を行う

 - 当初，Arduino のIDE を使用しないで，C言語で実行ファイルを作ってシリアル通信でArduino に送信すれば行けるのでは? と思っていたが，実際にはダメだった．
 - まずArduino のCPU に合わせたクロスコンパイルが必要なのと，Arduino にはOSが無いので，ただ実行ファイルを送っても意味がない．つまり，半導体に焼き付けないといけないのだが，これを行うにはROM焼き機が必要になる．
 - つまり，既存のツールを使わないでやろうとすると，完全に組み込み開発の工程を踏む必要が出てくるため，流石にちょっと厳しい．
 - そこで，ここではCUI ツールのplatformio で開発を行うことにする．ino というツールが有名だが，結局IDE を入れないと使えないため，platformio の方が手軽である．

参考サイト : https://blog.emattsan.org/entry/2017/12/31/094954

# インストール
```
// /opt にリポジトリをクローンする
cd /opt
git clone https://github.com/platformio/platformio.git
sudo pip install platformio
sudo pip install scons
```

# 開発工程
```
cd ~
mkdir sample && cd sample

// ボードの名前を調べる．今回はUNO なので，uno に絞って検索．
platformio boards | grep uno

// プロジェクトの作成．git init 的な．
platformio init --board=uno

// Arduino のシリアルポート番号を./platformio.init に追記する．
// Ubuntu の場合は大抵/dev/ttyACM0, Mac の場合はtty.usbserial-* のことが多い．
echo -e "\n upload_port = /dev/ttyACM0" >> platformio.ini

// 必要なライブラリをインストールする．
// Arduino の公式リポジトリに色々載っているので，適宜インストールすること．
// 例 : Servo.h のインストール
git clone https://github.com/arduino-libraries/Servo

// ソースコードを書いて./src に配置する．
vim ./src/sample.ino

// ビルド & アップロード
platformio run -t upload
```

以上が開発の流れである．手っ取り早く試すならば，やはりLED点滅をやってみるのが良いだろう．デジタルの13番ピンに抵抗を噛ませてからLED のアノードを接続し，GND ピンにLED のカソード側を接続する．抵抗器を挟まないと過大電流でLED が破損するため，注意すること．

```
  _______________________________________________________
  |                                                      |
  |                                                      |
  |  [13] ---- [5.1k resistor] ---- A[LED]K ---- [GND]   |
  |                                                      |
  |______________________________________________________|

                        回路図
```

# 開発言語について
C++ の文法が完全に使用可能である．
あとはArduino 独自のAPI を使えば良い．
