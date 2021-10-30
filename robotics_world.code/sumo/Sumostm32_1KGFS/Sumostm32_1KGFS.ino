////////// Motor Control /////////////////////////////////////////////////
#define IN1A PB8
#define IN2A PB5
#define ENA PB9

#define IN1B PA8
#define IN2B PB6
#define ENB PB7
///////////////////////////////////////////////////////////////////////////

////////// Distance Sensor เซนเซอร์ค้นหาคู่ต่อสู้ ////////////////////////////////
#define SensorBackRight   0    //PA0
#define SensorFrontRight  1    //PA1
#define SensorCenter      2    //PA2
#define SensorFrontLeft   3    //PA3
#define SensorBackLeft    6    //PA6
#define SensorConfirm     7    //PA7
///////////////////////////////////////////////////////////////////////////

//////////////////// line sensor เซนเซอร์ตรวจจับเส้นขาวดำ ////////////////////
#define SensorLineRight   5           //PA5
#define SensorLineLeft    4           //PA4
#define SensorLineRightBack   PB1     //PB0
#define SensorLineLeftBack    PB0     //PB1
///////////////////////////////////////////////////////////////////////////

////////////////// Digital sensor /////////////////////////////////////////
#define SensorX    PA11    //PA11
///////////////////////////////////////////////////////////////////////////

////////////////// dip switch /////////////////////////////////////////////
#define dipSwitch1 PB11
#define dipSwitch2 PB10
///////////////////////////////////////////////////////////////////////////

////////////////// LED ////////////////////////////////////////////////////
#define LED1 PB12
#define LED2 PB13
#define LED3 PB14
#define LED4 PB15
///////////////////////////////////////////////////////////////////////////

#define Show_Sensor_value true // true = show , false = not show

void setup() {
  
    Serial.begin(115200);
    
    // Distance Sensor
    pinMode(SensorBackRight,  INPUT_ANALOG); //กำหนดชนิดการทำงานของ pin นั้นๆ
    pinMode(SensorFrontRight, INPUT_ANALOG);
    pinMode(SensorCenter,     INPUT_ANALOG);
    pinMode(SensorConfirm,   INPUT_ANALOG);
    pinMode(SensorFrontLeft,  INPUT_ANALOG);
    pinMode(SensorBackLeft,   INPUT_ANALOG);
    // line sensor
    pinMode(SensorLineRight,  INPUT_ANALOG);
    pinMode(SensorLineLeft,   INPUT_ANALOG);
    pinMode(SensorLineRightBack, INPUT_ANALOG);
    pinMode(SensorLineLeftBack, INPUT_ANALOG);
    // Motor
    pinMode(IN1A, OUTPUT);
    pinMode(IN2A, OUTPUT);
    pinMode(IN1B, OUTPUT);
    pinMode(IN2B, OUTPUT);
    pinMode(ENA, PWM);
    pinMode(ENB, PWM);
    // LED
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
    // LED ON
    digitalWrite(PB12, HIGH);
    digitalWrite(PB13, HIGH);
    digitalWrite(PB14, HIGH);
    digitalWrite(PB15, HIGH);
    for(int i = 0; i < 50; i++)
    {
      delay(100);
    }

}

void loop() {

    int BackRight = analogRead(SensorBackRight);
    int FrontRight = analogRead(SensorFrontRight);
    int Center = analogRead(SensorCenter);
    int Confirm = analogRead(SensorConfirm);
    int FrontLeft = analogRead(SensorFrontLeft);
    int BackLeft = analogRead(SensorBackLeft);

    int LineRight   = analogRead(SensorLineRight);
    int LineLeft    = analogRead(SensorLineLeft);
    int LineRightBack   = analogRead(SensorLineRightBack);
    int LineLeftBack    = analogRead(SensorLineLeftBack);
    
      if(LineRight and LineLeft and LineRightBack and LineLeftBack >=1500){
        forward(80,80);
        
      }
      if (LineRight and LineLeft <= 500){
        reward(100,100);
        delay(500);
      }

}

void forward(int speedRight, int speedLeft)
{
    analogWrite(ENA, speedRight);
    digitalWrite(IN1A, 1);
    digitalWrite(IN2A, 0);
    
    analogWrite(ENB, speedLeft);
    digitalWrite(IN1B, 1);
    digitalWrite(IN2B, 0);
    
}
void reward(int speedRight, int speedLeft)
{
    analogWrite(ENA, speedRight);
    digitalWrite(IN1A, 0);
    digitalWrite(IN2A, 1);
    
    analogWrite(ENB, speedLeft);
    digitalWrite(IN1B, 0);
    digitalWrite(IN2B, 1);
}
