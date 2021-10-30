int led1 = 8;
int led2 = 9;
int led3 = 10;
int but = 7;
int val = 0 ;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(but,INPUT);
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(but);
  Serial.println(val);
  if(val == 0){   
          digitalWrite(led3,HIGH);
          delay(250);
          digitalWrite(led3,LOW);
          digitalWrite(led2,HIGH);
          delay(250);
          digitalWrite(led2,LOW);
          digitalWrite(led1,HIGH);
          delay(250);
          digitalWrite(led1,LOW);
               
          Serial.println("finish");
      }
        
   else{
          digitalWrite(led1,HIGH);
          delay(250);
          digitalWrite(led1,LOW);
          digitalWrite(led2,HIGH);
          delay(250);
          digitalWrite(led2,LOW);
          digitalWrite(led3,HIGH);
          delay(250);
          digitalWrite(led3,LOW);
               
          Serial.println("fin");
      }
        
         }
           
