void MoveTrackLineTimTim()
{
  if(LineRight < bw_detect && LineLeft < bw_detect) //ขวาเจอ ซ้ายเจอ
    {
      Serial.println("...ขวาเจอ ซ้ายเจอ");
      reward(100,100); //100
      delay(200); //200
      spinleft(150,150);
      delay(150);
      countattack = 0;
      HelpAttack  =  millis();
      ATTACK_ON = false;
      digitalWrite(ResetCurrentPin,1);
      currentBoost = false;
      countattackCurrent = 0;
      currentBoostON_OFF = false;
    }
    else if(LineRight < bw_detect && LineLeft > bw_detect) //ขวาเจอ
    {
      Serial.println("...ขวาเจอ");
      reward(100,100); //100
      //delay(400);
      for(int i = 0; i < 120 ; i++ )
      {
        delay(1);
         
        LineRightBack   = analogRead(SensorLineRightBack);
        LineLeftBack    = analogRead(SensorLineLeftBack);
        if(LineRightBack < bw_back_detect && LineLeftBack > bw_back_detect)
        {
          forward(140,140);
          delay(10);
          goto StopRewardA;
        }
        else if(LineLeftBack < bw_back_detect && LineRightBack > bw_back_detect)
        {
          forward(140,140);
          delay(10);
          goto StopRewardA;
        }
      } StopRewardA : int AA = 0;
      
      spinleft(150,150);
      //delay(200);
      for(int i = 0; i < 150 ; i++ )
      {
        delay(1);
         
        LineRightBack   = analogRead(SensorLineRightBack);
        LineLeftBack    = analogRead(SensorLineLeftBack);
        if(LineRightBack < bw_back_detect && LineLeftBack > bw_back_detect)
        {
          forward(140,140);
          delay(10);
          goto StopRewardB;
        }
        else if(LineLeftBack < bw_back_detect && LineRightBack > bw_back_detect)
        {
          forward(140,140);
          delay(10);
          goto StopRewardB;
        }
        
      } StopRewardB : int AB = 0;
      countattack = 0;
      HelpAttack  =  millis();
      ATTACK_ON = false;
      digitalWrite(ResetCurrentPin,1);
      currentBoost = false;
      countattackCurrent = 0;
      currentBoostON_OFF = false;
    }
    else if(LineRight > bw_detect && LineLeft < bw_detect) // ซ้ายเจอ
    {
      Serial.println("...ซ้ายเจอ");
      reward(100,100); //100
      //delay(400);
      for(int i = 0; i < 120 ; i++ )
      {
        delay(1);
         
        LineRightBack   = analogRead(SensorLineRightBack);
        LineLeftBack    = analogRead(SensorLineLeftBack);
        if(LineRightBack < bw_back_detect && LineLeftBack > bw_back_detect)
        {
          forward(140,140);
          delay(10);
          goto StopReward1;
        }
        else if(LineLeftBack < bw_back_detect && LineRightBack > bw_back_detect)
        {
          forward(140,140);
          delay(10);
          goto StopReward1;
        }
      }StopReward1 : int B_1 = 0;
      spinright(150,150);
      //delay(200);
      for(int i = 0; i < 150 ; i++ )
      {
        delay(1);
         
        LineRightBack   = analogRead(SensorLineRightBack);
        LineLeftBack    = analogRead(SensorLineLeftBack);
        if(LineRightBack < bw_back_detect && LineLeftBack > bw_back_detect)
        {
          forward(140,140);
          delay(10);
          goto StopReward2;
        }
        else if(LineLeftBack < bw_back_detect && LineRightBack > bw_back_detect)
        {
          forward(140,140);
          delay(10);
          goto StopReward2;
        }
      }StopReward2 : int B_2 = 0;
      countattack = 0;
      HelpAttack  =  millis();
      ATTACK_ON = false;
      digitalWrite(ResetCurrentPin,1);
      currentBoost = false;
      countattackCurrent = 0;
      currentBoostON_OFF = false;
    }
    else
    {
      forward(NormalSpeed2,NormalSpeed2);
    }
}


/*
void MoveTrackLineTim_Tim()
{
  if(LineRight < bw_detect && LineLeft < bw_detect) //ขวาเจอ ซ้ายเจอ
    {
      Serial.println("...ขวาเจอ ซ้ายเจอ");
      reward(100,100); //100
      delay(370); //200
      spinleft(150,150);
      delay(150);
      countattack = 0;
      HelpAttack  =  millis();
      ATTACK_ON = false;
    }
    else if(LineRight < bw_detect && LineLeft > bw_detect) //ขวาเจอ
    {
      Serial.println("...ขวาเจอ");
      reward(100,100); //100
      //delay(400);
      for(int i = 0; i < 320 ; i++ )
      {
        delay(1);
         
        LineRightBack   = analogRead(SensorLineRightBack);
        LineLeftBack    = analogRead(SensorLineLeftBack);
        if(LineRightBack < bw_back_detect && LineLeftBack > bw_back_detect)
        {
          forward(140,140);
          delay(10);
          goto StopRewardA;
        }
        else if(LineLeftBack < bw_back_detect && LineRightBack > bw_back_detect)
        {
          forward(140,140);
          delay(10);
          goto StopRewardA;
        }
      } StopRewardA : int AA = 0;
      
      spinleft(150,150);
      //delay(200);
      for(int i = 0; i < 150 ; i++ )
      {
        delay(1);
         
        LineRightBack   = analogRead(SensorLineRightBack);
        LineLeftBack    = analogRead(SensorLineLeftBack);
        if(LineRightBack < bw_back_detect && LineLeftBack > bw_back_detect)
        {
          forward(140,140);
          delay(10);
          goto StopRewardB;
        }
        else if(LineLeftBack < bw_back_detect && LineRightBack > bw_back_detect)
        {
          forward(140,140);
          delay(10);
          goto StopRewardB;
        }
        
      } StopRewardB : int AB = 0;
      countattack = 0;
      HelpAttack  =  millis();
      ATTACK_ON = false;
    }
    else if(LineRight > bw_detect && LineLeft < bw_detect) // ซ้ายเจอ
    {
      Serial.println("...ซ้ายเจอ");
      reward(100,100); //100
      //delay(400);
      for(int i = 0; i < 320 ; i++ )
      {
        delay(1);
         
        LineRightBack   = analogRead(SensorLineRightBack);
        LineLeftBack    = analogRead(SensorLineLeftBack);
        if(LineRightBack < bw_back_detect && LineLeftBack > bw_back_detect)
        {
          forward(140,140);
          delay(10);
          goto StopReward1;
        }
        else if(LineLeftBack < bw_back_detect && LineRightBack > bw_back_detect)
        {
          forward(140,140);
          delay(10);
          goto StopReward1;
        }
      }StopReward1 : int B_1 = 0;
      spinright(150,150);
      //delay(200);
      for(int i = 0; i < 150 ; i++ )
      {
        delay(1);
         
        LineRightBack   = analogRead(SensorLineRightBack);
        LineLeftBack    = analogRead(SensorLineLeftBack);
        if(LineRightBack < bw_back_detect && LineLeftBack > bw_back_detect)
        {
          forward(140,140);
          delay(10);
          goto StopReward2;
        }
        else if(LineLeftBack < bw_back_detect && LineRightBack > bw_back_detect)
        {
          forward(140,140);
          delay(10);
          goto StopReward2;
        }
      }StopReward2 : int B_2 = 0;
      countattack = 0;
      HelpAttack  =  millis(); 
      ATTACK_ON = false;
    }
    else
    {
     //forward(40,40);  //1500G 100
     if(millis() - move2 >= move2_interval) 
     {
      move2  =  millis();
      //Serial.println("ดึ๊บๆๆๆๆ");
      forward(40,40);
      delay(100);
      reward(40,40);
      delay(100);
     }
     forward(0,0);
    }
}
*/
