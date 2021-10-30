void move_track_line_start()
{
  if(LineRight < bw_detect && LineLeft < bw_detect) //ขวาเจอ ซ้ายเจอ
    {
      Serial.println("...ขวาเจอ ซ้ายเจอ");
      reward(100,100); //100
      delay(470); //200
      spinleft(150,150);
      delay(250);
      _lineStart = true;
    }
    else if(LineRight < bw_detect && LineLeft > bw_detect) //ขวาเจอ
    {
      Serial.println("...ขวาเจอ");
      reward(100,100); //100
      //delay(400);
      for(int i = 0; i < 420 ; i++ )
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
      for(int i = 0; i < 250 ; i++ )
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
      
      _lineStart = true;
    }
    else if(LineRight > bw_detect && LineLeft < bw_detect) // ซ้ายเจอ
    {
      Serial.println("...ซ้ายเจอ");
      reward(100,100); //100
      //delay(400);
      for(int i = 0; i < 420 ; i++ )
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
      for(int i = 0; i < 250 ; i++ )
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
      
      _lineStart = true;
    }
    else
    {
     forward(80,80);  //1500G 100
    }
}
