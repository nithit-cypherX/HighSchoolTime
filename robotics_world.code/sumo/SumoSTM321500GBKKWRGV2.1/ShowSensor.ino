void ShowSensor()
{
    Serial.print(BackRight);
    Serial.print(" : "); 
    Serial.print(FrontRight); 
    Serial.print(" : "); 
    Serial.print(Center);
    Serial.print(" : ");
    Serial.print(FrontLeft);
    Serial.print(" : "); 
    Serial.print(BackLeft); 
    Serial.print(" : ");
//
//    
    Serial.print(LineRight);
    Serial.print(" : "); 
    Serial.print(LineLeft); 
    Serial.print(" : ");
    Serial.print(LineRightBack);
    Serial.print(" : "); 
    Serial.print(LineLeftBack); 
    Serial.print(" : ");
    Serial.print(Back); 
    Serial.print(" : ");
    Serial.print(CurrentAttack); 
 
    Serial.println();
}

