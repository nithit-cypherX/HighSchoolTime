long r_num ;
int incom = 0; 
 
 void setup() {
 randomSeed(analogRead(0));
 r_num =random(10);
 Serial.begin(9600);
 Serial.println(r_num);
 Serial.println("please press key");
 }
void loop() {
if(Serial.available() > 0) {
 incom = Serial.read()-48;
  Serial.println(incom);
    if (incom == r_num ){
    Serial.println("You win!!!");
    }
   else if (incom < r_num ){
    Serial.println("Too small ");
     }
  else if (incom > r_num){
    Serial.println("Too large");
     }
  r_num = random(10);
 Serial.println(r_num);
  
   
      }
}
   
