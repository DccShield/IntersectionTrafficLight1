//------------------------------------------------------------------
// IntersectionTrafficLight sketch2
// 交差点用信号機のスケッチ
// 状態遷移（ステートマシーン）を使用しないバージョン
// 2020/1/26 aya
//------------------------------------------------------------------

#define SouthNorthBlueLed   3     // SothNroth信号機の青LEDの出力ポート設定
#define SouthNorthYellowLed 5     // SothNroth信号機の黄LEDの出力ポート設定
#define SouthNorthRedLed    6     // SothNroth信号機の赤LEDの出力ポート設定
#define EastWestBlueLed     9     // EastWest信号機の青LEDの出力ポート設定
#define EastWestYellowLed   10    // EastWest信号機の黄LEDの出力ポート設定
#define EastWestRedLed      11    // EastWest信号機の赤LEDの出力ポート設定

#define BLE 1
#define YEW 2
#define RED 4

unsigned char gLightTime[]={20, 5, 1, 30, 5, 1};   // 点灯順序に対する点灯継続時間sec

//------------------------------------------------------------------
// Arduino固有の関数 setup() :初期設定
//------------------------------------------------------------------
void setup() {
  pinMode(SouthNorthBlueLed, OUTPUT);     // 南北の信号機の初期化
  digitalWrite(SouthNorthBlueLed, LOW);
  pinMode(SouthNorthYellowLed , OUTPUT);
  digitalWrite(SouthNorthYellowLed , LOW);  
  pinMode(SouthNorthRedLed , OUTPUT);
  digitalWrite(SouthNorthRedLed , LOW);

  pinMode(EastWestBlueLed , OUTPUT);      // 東西の信号機の初期化
  digitalWrite(EastWestBlueLed , LOW);
  pinMode(EastWestYellowLed , OUTPUT);
  digitalWrite(EastWestYellowLed , LOW);
  pinMode(EastWestRedLed , OUTPUT);
  digitalWrite(EastWestRedLed , LOW);
  
 // Serial.begin(115200);
}

//---------------------------------------------------------------------
// Arduino main loop
//---------------------------------------------------------------------
void loop() {
  BYR_LedCont(BLE,RED);                   // 南北の信号機の通行
  delay(gLightTime[0]*1000);
  BYR_LedCont(YEW,RED);  
  delay(gLightTime[1]*1000);
  BYR_LedCont(RED,RED);  
  delay(gLightTime[2]*1000);

  BYR_LedCont(RED,BLE);                   // 東西の信号機の通行
  delay(gLightTime[3]*1000);
  BYR_LedCont(RED,YEW);  
  delay(gLightTime[4]*1000);
  BYR_LedCont(RED,RED);  
  delay(gLightTime[5]*1000);
}

/* DEBUG用
void xdigitalWrite( char a, char b){
  char temp[20];
  sprintf(temp, "digitalWrite(%d, %d)",a, b);
  Serial.println(temp);
}
*/
//---------------------------------------------------------------------
// 信号機点灯消灯処理
// 三項演算子という方法を使ってプログラムをスマート（わかりずらく）にしています
//---------------------------------------------------------------------
void BYR_LedCont(char SNLed , char EWLed){
  digitalWrite(SouthNorthBlueLed,   SNLed & BLE ? HIGH:LOW);
  digitalWrite(SouthNorthYellowLed ,SNLed & YEW ? HIGH:LOW);  
  digitalWrite(SouthNorthRedLed ,   SNLed & RED ? HIGH:LOW);

  digitalWrite(EastWestBlueLed ,    EWLed & BLE ? HIGH:LOW);
  digitalWrite(EastWestYellowLed ,  EWLed & YEW ? HIGH:LOW);
  digitalWrite(EastWestRedLed ,     EWLed & RED ? HIGH:LOW);
}
