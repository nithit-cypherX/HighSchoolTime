
#include "Wire.h"
#include <I2Cdev.h>
#include "MPU6050.h"
#include <SerialESP8266wifi.h>   //#include <ESP8266WiFi.h>
#include <MicroGear.h>
//#include <WiFiClientSecureAxTLS.h>//กรณีขึ้น error ให้เอาบรรทัดนี้ออก
void Line_Notify(String message);
#define LINE_TOKEN ""
String message= "=HELP.!.!.!.!";//ArduinoLDE เวอร์ชันใหม่ๆใส่ภาษาไทยลงไปได้
const char* ssid ="HUAWEI nova 2i";
const char* password ="markzakung";
#define APPID "ECS01"
#define KEY "bubm2kMICANslsc"//ไม่แน่ใจตัว i หรือ l 
#define SECRET "IVdeTZI60T8DSngAnSbgRIZxf"
#define AlIas "esp8266"
WiFiClient client;
int timer =0;
MicroGear microgear(client);
MPU6050 mpu;//ประกาศตัวแปร mpu เป็นตัวแปรจาก Libraly
int16_t ax,ay,az;
int16_t gx,gy,gz;
int pax,pay,paz;
int count =0;
void onMsghandler(char*topic,uint8_t*msg,unsigned int msglen){
  Serial.print("Incoming message-->");
  msg[msglen] = '\0';
  Serial.println((char*)msg);
}
void onConnected(char*attribute,uint8_t*msg,unsigned int msglen){
  Serial.println("Connectd to NETPIE...");
  /*Set the alias of this microgear ALIAS*/
  microgear.setAlias(AlIas);
}
void setup()
{
  microgear.on(MESSAGE,onMsghandler);
  microgear.on(CONNECTED,onConnected);
  Wire.begin();
  Serial.begin(115200);
  Serial.println("Starting...");
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED)
 {
  delay(250);
  Serial.print(".");
 }
Serial.println("WiFi connected");
Serial.println("IP address:");
microgear.init(KEY,SECRET,AlIas);
microgear.connect(APPID);
pinMode(D3,OUTPUT);
digitalWrite(D3,HIGH);
Serial.println("Initialize MPU");
mpu.initialize();
Serial.println(mpu.testConnection()?"Connected":"Connection failed");
mpu.getMotion6(&ax,&ay,&az,&gx,&gy,&gz);
ax=map(ax,-18000,18000,0,180);
ay=map(ay,-18000,18000,0,180);
az=map(az,-18000,18000,0,180);
pax=ax;pay=ay;paz=az;
}
void loop()//รับค่าและแสดงผลแกนต่างๆไปเรื่อยๆ
{
  /*if(count>=6){
   while(count>=6)delay(10);
   Serial.printIn("Enter!");
   Line_Notify(message);
   //Serial.printIn();
}
delay(10);*/
if(microgear.connected()){
  microgear.loop();
  mpu.getMotion6(&ax,&ay,&az,&gx,&gy,&gz);
  //คำสั่งรับค่าต่างๆจาก library //ใช้คำสั่ง map ในการบีบช่วงค่าแคบลง
  //map (ตัวแปร,ค่าต่ำสุดเดิม,ค่าสูงสุดเดิม,ค่าต่ำสุดใหม่,ค่าสุงสุดใหม่)
  ax=map(ax,-18000,18000,0,180);
  ay=map(ay,-18000,18000,0,180);
  az=map(az,-18000,18000,0,180);
  //gx=map(gx,-18000,18000,0,180);
  //gy=map(gy,-18000,18000,0,180);
  //gz=map(gz,-18000,18000,0,180);
  Serial.print("Axyz\t");
  //Serial.print(pax);Serial.print("\t");
  Serial.print(ax);Serial.print("\t");
  Serial.print(ay);Serial.print("\t");
  Serial.print(az);Serial.print("\n");
  //Serial.print("Gxyz\t");
  //Serial.print(gx);Serial.print("\t");
  //Serial.print(gy);Serial.print("\t");
  //Serial.print(gz);
  pax=ax;
  microgear.publish("/ax",String(ax));
  microgear.publish("/ay",String(ay));
  microgear.publish("/az",String(az));
  delay(500);//หน่วงเวลาสักหน่อย
  if(abs(pax-ax)>30,abs(pay-ay)>30,abs(paz-az)>30)count+=1;//หาตัวขีดเส้นตรงไม่เจอ
  else count=0;
  //Serial.printIn("count");
  if (count>=6){
   digitalWrite(D3,LOW);
   Line_Notify(message);
   Serial.print("help!!!..........");//Serial.printIn(count);
   microgear.publish("/IsShock","STABLE:)",true);
  }
  else{
    digitalWrite(D3,HIGH);
    microgear.publish("/IsShock","STABLE:)",true);
  }
}
else{
  Serial.println("connection lost,reconnect...");
  if(timer>=50000){
    microgear.connect(APPID);
    timer=0;
  }
  else timer +=100;
}
delay(100);
}
void Line_Notify(String message) {
  //axTLS::WiFiClientSecure client; // กรณีขึ้น Error ให้ลบ axTLS:: ข้างหน้าทิ้ง 

  if (!client.connect("notify-api.line.me", 443)) {
    Serial.println("connection failed");
    return;   
  }

  String req = "";
  req += "POST /api/notify HTTP/1.1\r\n";
  req += "Host: notify-api.line.me\r\n";
  req += "Authorization: Bearer " + String(LINE_TOKEN) + "\r\n";
  req += "Cache-Control: no-cache\r\n";
  req += "User-Agent: ESP8266\r\n";
  req += "Connection: close\r\n";
  req += "Content-Type: application/x-www-form-urlencoded\r\n";
  req += "Content-Length: " + String(String("message=" + message).length()) + "\r\n";
  req += "\r\n";
  req += "message=" + message;
  // Serial.println(req);
  client.print(req);
    
  delay(20);

  // Serial.println("-------------");
  while(client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
    //Serial.println(line);
  }
  // Serial.println("-------------");
}
