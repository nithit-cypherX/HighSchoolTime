int red = 12;
int gre = 13;
int income  = 0;

void setup() {
 pinMode(12,OUTPUT);
 pinMode(13,OUTPUT);
 Serial.begin(9600);
}

void loop() {
  if(Serial.available()> 0){
    income = Serial.read()-48;
    Serial.println(income);    
    if((income%2) == 0){
      for(int i = 1 ; i <= income ; i ++){
        digitalWrite(red,HIGH);
        digitalWrite(gre,HIGH);
        delay(500);
        digitalWrite(gre,LOW);
        digitalWrite(red,LOW);
        delay(500);
        Serial.print(i);
        }
          }
      else{
        for(int i = 1; i <=income ;i++){
        digitalWrite(red,HIGH);
        delay(500);
        digitalWrite(red,LOW);
        delay(500);
        digitalWrite(gre,HIGH);
        delay(500);
        digitalWrite(gre,LOW);
        delay(500);
        Serial.print(i);  
          }
           }    
             }
                }
   
    
    
    




 
