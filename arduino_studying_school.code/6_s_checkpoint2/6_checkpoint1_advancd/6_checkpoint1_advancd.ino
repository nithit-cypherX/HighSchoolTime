int led[] = {8 , 9 , 10}; 
int SW = 2;
int state = LOW;

void setup() {
  state = digitalRead(SW);
    pinMode(SW,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(SW), blink, RISING);
  Serial.begin(9600);
  for(int i =0 ;i<=2;i++){
    pinMode(led[i],OUTPUT);
    Serial.println("finish");
}
 }
void loop() {
  Serial.println(state);
  if (state == HIGH){
    for(int i =0 ;i<=2;i++){
    digitalWrite(led[i],HIGH);
    delay(250);
    digitalWrite(led[i],LOW);
    Serial.println("ติด");
  }
   }
   else{
    for(int i =2 ;i>=0;i++){
    digitalWrite(led[i+dir],HIGH);
    delay(1000);
    digitalWrite(led[i],LOW);
    Serial.println("ติดดดด");
    
   }
}
 }
void  blink(){
  state =!state;
}
