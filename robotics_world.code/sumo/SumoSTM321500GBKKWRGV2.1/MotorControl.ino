void forward(int speedRight, int speedLeft)
{
    analogWrite(IN1A, speedRight);
    analogWrite(IN2A, 0);
    digitalWrite(ENA, HIGH);
    
    analogWrite(IN1B, 0);
    analogWrite(IN2B, speedLeft);
    digitalWrite(ENB, HIGH);
}
void reward(int speedRight, int speedLeft)
{
    analogWrite(IN1A, 0);
    analogWrite(IN2A, speedRight);
    digitalWrite(ENA, HIGH);
    
    analogWrite(IN1B, speedLeft);
    analogWrite(IN2B, 0);
    digitalWrite(ENB, HIGH);
}

void spinright(int speedRight, int speedLeft)
{
    analogWrite(IN1A, 0);
    analogWrite(IN2A, speedRight);
    digitalWrite(ENA, HIGH);
    
    analogWrite(IN1B, 0);
    analogWrite(IN2B, speedLeft);
    digitalWrite(ENB, HIGH);
}
void spinleft(int speedRight, int speedLeft)
{
    analogWrite(IN1A, speedRight);
    analogWrite(IN2A, 0);
    digitalWrite(ENA, HIGH);
    
    analogWrite(IN1B, speedLeft);
    analogWrite(IN2B, 0);
    digitalWrite(ENB, HIGH);
}
