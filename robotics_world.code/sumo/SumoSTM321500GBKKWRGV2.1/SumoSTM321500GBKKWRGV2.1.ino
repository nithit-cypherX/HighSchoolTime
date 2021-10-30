#include <filters.h>

const float cutoff_freq   = 70.0;  //Cutoff frequency in Hz
const float sampling_time = 0.001; //Sampling time in seconds.
IIR::ORDER  order  = IIR::ORDER::OD3; // Order (OD1 to OD4)

// Low-pass filter
Filter BR(cutoff_freq, sampling_time, order);
Filter FR(cutoff_freq, sampling_time, order);
Filter CT(cutoff_freq, sampling_time, order);
Filter CF(cutoff_freq, sampling_time, order);
Filter FL(cutoff_freq, sampling_time, order);
Filter BL(cutoff_freq, sampling_time, order);


#define IN1A PB7
#define IN2A PB6
#define ENA PA8

#define IN1B PB9
#define IN2B PB8
#define ENB PB5


#define SensorBackRight   0    //PA0
#define SensorFrontRight  1    //PA1
#define SensorCenter      2    //PA2
#define SensorFrontLeft   3    //PA3
#define SensorBackLeft    6    //PA6
#define SensorConfirm     7    //PA7


#define SensorLineRight   5    //PA5
#define SensorLineLeft    4    //PA4
#define SensorLineRightBack   PB1    //PB1
#define SensorLineLeftBack    PB0    //PB0

#define SensorBack    PA11    //PA11
#define ResetCurrentPin PC15

//#define dipSwitch1 PB11
//#define dipSwitch2 PB10


//#define AttackLimit3 PB1
//#define AttackLimit4 PB0
boolean attackSpin = false;


int AttackLimit = 39; // ระยะโจมตี 
int DistanceBackLimit = 1;

int attack = 150;

int NormalSpeed = 25; //////////////////////////// วิ่งปกติ /////////////////////////
int NormalSpeed2 = 19;
boolean NormalStatus = false;
int NormalSpeed3 = 12;

int bw_detect = 1000; 
int bw_back_detect = 900; 



int plan = 0;
boolean _lineStart = false;
boolean _lineStart2 = false;

unsigned long long i = 0;
unsigned long long CountBr = 0, CountFr = 0, CountFl = 0, CountBl = 0, CountBS = 0; 
unsigned long CountCF = 0;
    int minBR = 30; //22
    int maxBR = 110;
    
    int minFR = 40; //30
    int maxFR = 110;
    
    int minCT = 38; //32
    int maxCT = 110;
    
    int minFL = 29; //21
    int maxFL = 110;
    
    int minBL = 29; //25
    int maxBL = 110;

    int dip1 = 0; // 0 ปกติ 1 โหด 0 หักหลบ 1 ลดค่า distance
    int dip2 = 0; // 0 ปิกติ 0 โหด 1 หักหลบ 1 ลดค่า distance


    float BackRight = 0; 
    float FrontRight = 0; 
    float Center = 0; 
    float CurrentAttack = 0;
    float FrontLeft = 0; 
    float BackLeft = 0; 

    int LineRight   = 0; 
    int LineLeft    = 0; 
    int LineRightBack   = 0; 
    int LineLeftBack    = 0; 
    int Back    =   0;  
    
#include <i2c_keypad.h>
#include <Wire.h>

//use IIC2
TwoWire WIRE2 (2,I2C_FAST_MODE);
#define Wire WIRE2

I2CKEYPAD key;
#define PCF_ADD 0x20
char addr_ = PCF_ADD;
    int kp_interval = 200;
    unsigned long kp_pv = 0; 
    unsigned char last_key=0xFF;
    KeypadEventCallback _callback[3] = { NULL, NULL, NULL };
    char keypad[4][1] = {{'3'},{'4'},{'1'},{'2'}};

boolean OneRound = false;
boolean LedStatus = false;

int countattack = 0;
int countattackInt = 140;

int countattackCurrent = 0;
int countattackCurrentInt = 1000;

int countattackTimer = 0;
int countattackTimerInt = 1000;

boolean currentBoost = false;
boolean currentBoostON_OFF = false;

// ดึ๊บๆ
int move2_interval = 3000;
unsigned long move2 = 0; 

unsigned long HelpAttack_interval = 50000;
unsigned long HelpAttack = 0; 

int countGard = 0;
int countGardInt = 500;


boolean ATTACK_ON = false;

void setup() {
    Serial.begin(115200);
    Serial.println();Serial.println(".");Serial.println("START");Serial.println(".");Serial.println();
    Wire.begin();
    pinMode(SensorBackRight,  INPUT_ANALOG);
    pinMode(SensorFrontRight, INPUT_ANALOG);
    pinMode(SensorCenter,     INPUT_ANALOG);
    pinMode(SensorFrontLeft,  INPUT_ANALOG);
    pinMode(SensorBackLeft,   INPUT_ANALOG);
    pinMode(SensorLineRight,  INPUT_ANALOG);
    pinMode(SensorLineLeft,   INPUT_ANALOG);
    pinMode(SensorConfirm,   INPUT_ANALOG);
    pinMode(SensorLineRightBack,  INPUT_ANALOG);
    pinMode(SensorLineLeftBack, INPUT_ANALOG);
    pinMode(SensorBack, INPUT);

      // Enable pull-ups if necessary
    digitalWrite(SensorBackRight, HIGH);
    digitalWrite(SensorFrontRight, HIGH);
    digitalWrite(SensorCenter, HIGH);
    digitalWrite(SensorConfirm, HIGH);
    digitalWrite(SensorFrontLeft, HIGH);
    digitalWrite(SensorBackLeft, HIGH);
  

   // digitalWrite(SensorBackRight, HIGH);
    
//    pinMode(dipSwitch1,INPUT);
//    pinMode(dipSwitch2,INPUT);
    
    pinMode(IN1A, PWM);
    pinMode(IN2A, PWM);
    pinMode(IN1B, PWM);
    pinMode(IN2B, PWM);

    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(PC13, OUTPUT);

    pinMode(PB12, OUTPUT);
    pinMode(PB13, OUTPUT);
    pinMode(PB14, OUTPUT);
    pinMode(PB15, OUTPUT);
    pinMode(ResetCurrentPin, OUTPUT);

    digitalWrite(PC13, 1);
    digitalWrite(PB12, 0);
    digitalWrite(PB13, 0);
    digitalWrite(PB14, 0);
    digitalWrite(PB15, 0);
    digitalWrite(ResetCurrentPin, 0);

    //digitalWrite(SensorBack,HIGH);
}

void loop() {
  
    BackRight = BR.filterIn(analogRead(SensorBackRight))/4095.0 * 100.0;
    FrontRight = FR.filterIn(analogRead(SensorFrontRight))/4095.0 * 100.0;
    Center = CT.filterIn(analogRead(SensorCenter))/4095.0 * 100.0;
    //Back = CF.filterIn(analogRead(SensorConfirm))/4095.0 * 100.0;
    CurrentAttack = CF.filterIn(analogRead(SensorConfirm))/4095.0 * 100.0;
    FrontLeft = FL.filterIn(analogRead(SensorFrontLeft))/4095.0 * 100.0;
    BackLeft = BL.filterIn(analogRead(SensorBackLeft))/4095.0 * 100.0;

    LineRight   = analogRead(SensorLineRight);
    LineLeft    = analogRead(SensorLineLeft);
    LineRightBack   = analogRead(SensorLineRightBack);
    LineLeftBack    = analogRead(SensorLineLeftBack);

    
    Back    =   digitalRead(SensorBack); //detect == 1    
        
  if(plan == 0)
  {
    scand();
  }
  else if(plan == 1)
  {
    if(OneRound == false)
    { 
      digitalWrite(PB12, 1);
      for(int i = 0; i < 53; i++)
      {
          delay(100);
      }
      digitalWrite(PB12, 0);
      OneRound = true;
      HelpAttack  =  millis();
      
    }
    
    if(ATTACK_ON == false && (millis() - HelpAttack >= HelpAttack_interval)) 
    {
      HelpAttack  =  millis();
      ATTACK_ON = true;
    }
   
    ShowSensor();

    //Move1();
    //MoveTrackLineTim();



    //MoveTestDistance();
    //reward(0,50);
    //delay(1000);
    //forward(0,50);
    //delay(1000);
    //Serial.println(Center);
  }
  else if(plan == 2) //S Left
  {
    if(OneRound == false)
    {
      digitalWrite(PB14, 1);
      for(int i = 0; i < 53; i++)
      {
          delay(100);
      }
      digitalWrite(PB14, 0);
      OneRound = true;

//      forward(80,80); 
//      delay(370);
//      forward(120,0); 
//      delay(300);
//      forward(50,50);
//      delay(200); 
//      reward(150,150);
//      delay(500);
//      forward(0,0); 
      //delay(10000);
    }
   // ShowSensor();
   Move1();
   MoveTrackLineGard();
    /*if(_lineStart == false)
      {
        move_track_line_start();
      }
    if(_lineStart == true && _lineStart2 == false)
      {
//        forward(0,80);
//        delay(500);
//        forward(80,80); 
//        delay(200);
//        forward(0,0);
        _lineStart2 = true;
      }
    if(_lineStart2 == true){
        //Move2();
        //MoveTrackLineTim_Tim();
    }
    */
  }
// else if(plan == 3) //S Right
//  {
//    if(OneRound == false)
//    {
//      digitalWrite(PB13, 1);
//      for(int i = 0; i < 53; i++)
//      {
//          delay(100);
//      }
//      digitalWrite(PB13, 0);
//      OneRound = true;
//      forward(80,80); 
//      delay(370);
//      forward(0,120); 
//      delay(300);
//      forward(50,50);
//      delay(200); 
//      reward(150,150);
//      delay(500);
//      forward(0,0);
//    }
//   Move1();
//   MoveTrackLineTim();
//    
//  }  
  else if(plan == 3) //ออกตัวช้า
  {
      if(OneRound == false)
      {
        digitalWrite(PB15, 1);
        for(int i = 0; i < 53; i++)
        {
            delay(100);
        }
        digitalWrite(PB15, 0);
        OneRound = true;
      }

      if(NormalStatus == false)
      {
        HelpAttack_interval = 30000;
        MoveTrackLineTimTim();
        Move4();
      }
      else
      {
        Move1();
        MoveTrackLineTim();
      }
  }
 /* 
//reward(55,55);
//delay(1000);
//forward(55,55);
//delay(1000);
*/
 delay(1);
}

void scand() {
  if (millis() - kp_pv >= kp_interval) {
    char row = 0, col = 0;
    // row scanning
    if(LedStatus == false)
      LedStatus = true;
    else
      LedStatus = false;
      
    digitalWrite(PB15, LedStatus);
    
    Wire.beginTransmission(addr_);   
    Wire.write(0x0F);               
    Wire.endTransmission();
    Wire.requestFrom(addr_, 1);
    while(Wire.available()) {
      switch(Wire.read()) {
        case 0x0E : row = 1; break;
        case 0x0D : row = 2; break;
        case 0x0B : row = 3; break;
        case 0x07 : row = 4; break;
        default : row = 0;
      }
    }

    // column scanning
    Wire.beginTransmission(addr_);
    Wire.write(0xF0);
    Wire.endTransmission();
    Wire.requestFrom(addr_, 1);
    while(Wire.available()) {
      switch(Wire.read()) {
        case 0xE0 : col = 1; break;
        //case 0xD0 : col = 2; break;
        //case 0xB0 : col = 3; break;
        //case 0x70 : col = 4; break;
        default : col = 0;
      }
    }
    kp_pv  =  millis();
    
    if(row > 0 && col > 0) {
      if(last_key == 0xFF) {
        if (_callback[PRESS]) _callback[PRESS](keypad[row-1][col-1]);
      }
      if (last_key =- keypad[row-1][col-1]) {
        if (_callback[DO]) _callback[DO](keypad[row-1][col-1]);
      }
      last_key = keypad[row-1][col-1];
      plan = keypad[row-1][col-1]-48;
      digitalWrite(PB15,0);
      //Serial.print(" ===== "); Serial.println(plan);
    } else {
      if(last_key != 0xFF) {
        if (_callback[RELEASE]) _callback[RELEASE](last_key);
        last_key = 0xFF;
      }
    }
  }
}
