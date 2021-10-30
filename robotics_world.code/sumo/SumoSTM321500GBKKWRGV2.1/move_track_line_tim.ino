void MoveTrackLineTim()
{
  if(LineRight < bw_detect && LineLeft < bw_detect) //ขวาเจอ ซ้ายเจอ
    {
      Serial.println("...ขวาเจอ ซ้ายเจอ");
      reward(150,150); //100
      delay(370); //200
      spinleft(150,150);
      delay(150);
      countattack = 0;
      HelpAttack  =  millis();
      ATTACK_ON = false;
      digitalWrite(ResetCurrentPin,1);
      currentBoost = false;
      countattackCurrent = 0;
      currentBoostON_OFF = false;
      //delay();
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
      digitalWrite(ResetCurrentPin,1);
      currentBoost = false;
      countattackCurrent = 0;
      currentBoostON_OFF = false;
    }
    else
    {
      forward(NormalSpeed,NormalSpeed);
      CurrentAttack = CF.filterIn(analogRead(SensorConfirm))/4095.0 * 100.0;

      if(CurrentAttack < 50 && currentBoost == false)
      {
        forward(NormalSpeed,NormalSpeed);  //1500G 100
        //Serial.println("....TestRUN1.....");
        countattackCurrent = 0;
        currentBoostON_OFF = true;
        
      }
      else if(CurrentAttack > 50 && currentBoostON_OFF == true)
      {
        currentBoost = true;
        countattackCurrent++;
//        if(countattackCurrent > countattackCurrentInt)
//        {
//          digitalWrite(PB13, 1);
//          digitalWrite(PB14, 1);
//          forward(0,0);
//          delay(5000);
//        }
        //Serial.println("....TestRUN.....");
        int attack2 = map(countattackCurrent,0, countattackCurrentInt,NormalSpeed,attack);
        //Serial.print("....TestRUN.....");Serial.println(attack2);
        forward(attack2,attack2);
        if(attack2 == attack)
        {
          currentBoost = false;
          countattackCurrent = 0;
          delay(1000);
        }        
      }  
    }
}



