int num ;
int incom ;

void setup() {
 Serial.begin(9600);
 Serial.println("enter number 2-9 ");
}

void loop() {
  if(Serial.available() > 0) {
 incom = Serial.read()-48;
  
  do {
    if (incom <2){
      break;
    }
    else if (incom >9){
      break;
    }
     num ++;
     Serial.print(incom);
     Serial.print("x");
     Serial.print(num);
     Serial.print("=");
     Serial.println(incom*num);
     delay(100);
     }
     while (num<12);
      if(num=12){
          num=0;
        }
         }
            }
          
