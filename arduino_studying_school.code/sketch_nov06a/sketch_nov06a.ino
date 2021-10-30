int pin = 2;
int led = 13;
int led2 = 12;
int led3 = 11;
void setup() {
pinMode(pin, INPUT);
pinMode(led , OUTPUT);
pinMode(led2 , OUTPUT);
pinMode(led3 , OUTPUT);
Serial.begin(9600);   
attachInterrupt(2,loop,CHANGE);

}

void loop() {
  int state = 0;
  state = digitalRead(pin);

  if (state == HIGH){
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    digitalWrite(led3,HIGH);
    delay(1000);
    digitalWrite(led3,LOW);
    digitalWrite(led2,HIGH);
    delay(1000);
    digitalWrite(led2,LOW);
    Serial.println("HIGH");
      }
  else  {
    digitalWrite(led2,HIGH);
    delay(1000);
    digitalWrite(led2,LOW);
    delay(1000);
    Serial.println("LOW");
  }

}
