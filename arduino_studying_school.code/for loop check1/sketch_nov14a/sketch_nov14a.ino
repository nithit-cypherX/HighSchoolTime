void setup() {
  Serial.begin(9600);
  


}

void loop() {
     for(int i= 2 ; i<=20; i +=2){
            Serial.println(i);
            delay(300);
   
}
 }
