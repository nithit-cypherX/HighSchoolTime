 int buzzerPin = 6;
int sw = 7;
 int stat;

void setup()
{
  //Setup pin modes
  pinMode(buzzerPin, OUTPUT);
  pinMode(sw,INPUT);
  Serial.begin(9600);
   
}
 
void loop()
{

 

     Serial.println(stat);
      if (digitalRead(sw) == LOW) {
           stat = !stat;
    
      }
      if (stat == HIGH){
        tone (buzzerPin,1000,500);
        }
      else{
        noTone(buzzerPin);}

}
 
 

  


  
