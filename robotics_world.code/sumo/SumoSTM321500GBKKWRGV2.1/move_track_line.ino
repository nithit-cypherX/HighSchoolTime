void MoveTrackLine()
{
  if(LineRight < bw_detect && LineLeft < bw_detect) //ขวาเจอ ซ้ายเจอ
    {
      Serial.println("...ขวาเจอ ซ้ายเจอ");
      reward(250,250); //100
      delay(270); //200
      spinleft(150,150);
      delay(150);
    }
    else if(LineRight < bw_detect && LineLeft > bw_detect) //ขวาเจอ
    {
      Serial.println("...ขวาเจอ");
      reward(250,250); //100
      //delay(400);
      for(int i = 0; i < 220 ; i++ )
      {
        delay(1);
         
        LineRightBack   = analogRead(SensorLineRightBack);
        LineLeftBack    = analogRead(SensorLineLeftBack);
        if(LineRightBack < bw_back_detect && LineLeftBack > bw_back_detect)
        {
          forward(240,240);
          delay(10);
          goto StopRewardA;
        }
        else if(LineLeftBack < bw_back_detect && LineRightBack > bw_back_detect)
        {
          forward(240,240);
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
          forward(240,240);
          delay(10);
          goto StopRewardB;
        }
        else if(LineLeftBack < bw_back_detect && LineRightBack > bw_back_detect)
        {
          forward(240,240);
          delay(10);
          goto StopRewardB;
        }
        
      } StopRewardB : int AB = 0;
    }
    else if(LineRight > bw_detect && LineLeft < bw_detect) // ซ้ายเจอ
    {
      Serial.println("...ซ้ายเจอ");
      reward(250,250); //100
      //delay(400);
      for(int i = 0; i < 220 ; i++ )
      {
        delay(1);
         
        LineRightBack   = analogRead(SensorLineRightBack);
        LineLeftBack    = analogRead(SensorLineLeftBack);
        if(LineRightBack < bw_back_detect && LineLeftBack > bw_back_detect)
        {
          forward(240,240);
          delay(10);
          goto StopReward1;
        }
        else if(LineLeftBack < bw_back_detect && LineRightBack > bw_back_detect)
        {
          forward(240,240);
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
          forward(240,240);
          delay(10);
          goto StopReward2;
        }
        else if(LineLeftBack < bw_back_detect && LineRightBack > bw_back_detect)
        {
          forward(240,240);
          delay(10);
          goto StopReward2;
        }
      }StopReward2 : int B_2 = 0;
    }
    else
    {
      CurrentAttack = CF.filterIn(analogRead(SensorConfirm))/4095.0 * 100.0;

      if(CurrentAttack < 50)
      {
        forward(60,60);  //1500G 100
        Serial.println("....TestRUN1.....");
      }
      else
      {
        Serial.println("....TestRUN.....");
        forward(attack,attack);
//        delay(3000);
//        forward(0,0);
//        delay(3000);
        
      }
      
    }
}

