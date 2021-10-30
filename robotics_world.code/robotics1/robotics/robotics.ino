//กำหนด pin ใช้งาน //
#include <HCSR04.h>
int PWM_L = 5;
int ML1 = 8;
int ML2 = 7;
int PWM_R = 6;
int MR1 = 4;
int MR2 = 9;
int trigPin = 9;    // Trigger
int echoPin = 10;    // Echo
long duration, cm ;
UltraSonicDistanceSensor distanceSensor(9,10);
int IRSenLeft = 3;
int IRSenRight = 2;

////////////////////////////////////////////////

void setup()
{
  Serial.begin(9600);
  motor();
  
  delay(1500);
}

void loop()
{
  ultra();
  IRsensor();

}

void forward(int Speed) // ตัวแปร speed ใช้งานได้ตั้งแต่ 0- 255
{
  Serial.println("FORWARD");
  analogWrite(PWM_R, Speed);
  digitalWrite(MR1, HIGH);
  digitalWrite(MR2, LOW);
  analogWrite(PWM_L, Speed);
  digitalWrite(ML1, HIGH);
  digitalWrite(ML2, LOW);
  Serial.println("ไก่");
  //  delay(10);

}

void backward(int Speed) // ตัวแปร speed ใช้งานได้ตั้งแต่ 0- 255
{
  Serial.println("BACKWARD");
  analogWrite(PWM_R, Speed);
  digitalWrite(MR1, LOW);
  digitalWrite(MR2, HIGH);
  analogWrite(PWM_L, Speed);
  digitalWrite(ML1, LOW);
  digitalWrite(ML2, HIGH);
  delay(200);
}

void turnright(int Speed)
{
  analogWrite(PWM_R, Speed);
  digitalWrite(MR1, LOW);
  digitalWrite(MR2, HIGH);
  analogWrite(PWM_L, Speed);
  digitalWrite(ML1, HIGH);
  digitalWrite(ML2, LOW);
  delay(400);
}

void turnleft(int Speed)
{
  analogWrite(PWM_R, Speed);
  digitalWrite(MR1, HIGH);
  digitalWrite(MR2, LOW);
  analogWrite(PWM_L, Speed);
  digitalWrite(ML1, LOW);
  digitalWrite(ML2, HIGH);
  delay(400);
}

void turnaround(int Speed)
{
  analogWrite(PWM_R, Speed);
  digitalWrite(MR1, HIGH);
  digitalWrite(MR2, LOW);
  analogWrite(PWM_L, Speed);
  digitalWrite(ML1, LOW);
  digitalWrite(ML2, HIGH);
  delay(1000);
}
void motor()
{
  pinMode(ML1, OUTPUT);
  pinMode(MR1, OUTPUT);
  pinMode(ML2, OUTPUT);
  pinMode(MR2, OUTPUT);
  pinMode(PWM_R, OUTPUT);
  pinMode(PWM_L, OUTPUT);
}

void IRsensor()
{ //0คือขาว 1คือดำ
  int sensor_Value_right = digitalRead(IRSenRight);
  Serial.print("IR Sensor right: Value = ");
  Serial.println(sensor_Value_right);
  int sensor_Value_left = digitalRead(IRSenLeft);
  Serial.print("IR Sensor left: Value = ");
  Serial.println(sensor_Value_left);
  if (sensor_Value_right == 1 && sensor_Value_left == 1) {
    forward(35.5);
    Serial.println("111111BACKWARD");
  }
  if (sensor_Value_right == 0 && sensor_Value_left == 0) {
    backward(100);
    turnright(80);
    Serial.println("222222BACKWARD");
  }
  if (sensor_Value_right == 0 && sensor_Value_left == 1) {
    backward(100);
    turnleft(75);
    Serial.println("333333BACKWARD");
  }
  if (sensor_Value_right == 1 && sensor_Value_left == 0) {
    backward(100);
    turnright(75);
    Serial.println("4444444BACKWARD");
  }
  Serial.println(" ");
}

void ultra(){
 int cm = distanceSensor.measureDistanceCm();
 Serial.println(cm);
  if (cm >=50){
    forward(50);
  }
  
  if (cm <=11){
    forward(155);

    
  }
}
