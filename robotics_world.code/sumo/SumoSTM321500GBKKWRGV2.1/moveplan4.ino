void Move4()
{
  if((BackRight > minBR && BackRight < maxBR) && FrontRight < minFR && Center < minCT && FrontLeft < minFL && BackLeft < minBL)
    { 
        //หลังขวาเจอ
        CountBr++;
        if(CountBr < 500){ //800 600
            spinright(150,150);
        }
        else 
        {
            spinright(255,255);
            delay(300);
            CountBr = 0;
        }
        Serial.println("หลังขวาเจอ");
        CountFr = 0; 
        CountFl = 0; 
        CountBl = 0; 
        countattack = 0;
        HelpAttack  =  millis();
        ATTACK_ON = false;
        digitalWrite(PB12, 1);
        digitalWrite(PB13, 0);
        digitalWrite(PB14, 0);
        digitalWrite(PB15, 0);
        digitalWrite(ResetCurrentPin,1);
        //ShowSensor();
        currentBoost = false;
        countattackCurrent = 0;
        currentBoostON_OFF = false;
        NormalStatus = true;
    }
    else if(BackRight < minBR && (FrontRight > minFR && FrontRight < maxFR) && Center < minCT && FrontLeft < minFL && BackLeft < minBL) 
    {
        //หน้าขวาเจอ
        CountFr++;
        if(CountFr < 500)
            spinright(150,150);
        else
        {
            spinright(255,255);
            delay(300);
            CountFr = 0;
        }
        //digitalWrite(PC13, LOW);
        Serial.println("หน้าขวาเจอ");
        CountBr = 0;  
        CountFl = 0; 
        CountBl = 0;
        countattack = 0;
        HelpAttack  =  millis();
        ATTACK_ON = false;
        digitalWrite(PB12, 0);
        digitalWrite(PB13, 1);
        digitalWrite(PB14, 0);
        digitalWrite(PB15, 0);
        digitalWrite(ResetCurrentPin,1);
        currentBoost = false;
        countattackCurrent = 0;
        currentBoostON_OFF = false;
        NormalStatus = true;
    }
    else if(BackRight < minBR && FrontRight < minFR && Center < minCT && FrontLeft < minFL && (BackLeft > minBL && BackLeft < maxBL))
    {
      //หลังซ้ายเจอ
      CountBl++;
      //Serial.print(CountBl);
      if(CountBl < 500)
          spinleft(150,150);
      else
      {
        spinleft(255,255);
        delay(300);
        CountBl = 0;
      }
      //digitalWrite(PC13, LOW);
      Serial.println("หลังซ้ายเจอ");
      CountBr = 0; 
      CountFr = 0; 
      CountFl = 0; 
      countattack = 0;
      HelpAttack  =  millis();
      ATTACK_ON = false;
      digitalWrite(PB12, 0);
      digitalWrite(PB13, 0);
      digitalWrite(PB14, 0);
      digitalWrite(PB15, 1);
      digitalWrite(ResetCurrentPin,1);
      currentBoost = false;
      countattackCurrent = 0;
      currentBoostON_OFF = false;
      NormalStatus = true;
    }
    else if(BackRight < minBR && FrontRight < minFR && Center < minCT && (FrontLeft > minFL && FrontLeft < maxFL) &&  BackLeft < minBL)
    {
      //หน้าซ้ายเจอ
      CountFl++;
      if(CountFl < 500)
          spinleft(150,150);
      else
      {
        spinleft(255,255);
        delay(300);
        CountFl = 0;
      }
      //digitalWrite(PC13, LOW);
      Serial.println("หน้าซ้ายเจอ");
      CountBr = 0; 
      CountFr = 0;  
      CountBl = 0;
      countattack = 0;
      HelpAttack  =  millis();
      ATTACK_ON = false;
      digitalWrite(PB12, 0);
      digitalWrite(PB13, 0);
      digitalWrite(PB14, 1);
      digitalWrite(PB15, 0);
      digitalWrite(ResetCurrentPin,1);
      currentBoost = false;
      countattackCurrent = 0;
      currentBoostON_OFF = false;
      NormalStatus = true;
    }
    // โจมตี case 1  center เจอ
    else if(BackRight < minBR && FrontRight < minFR && (Center > minCT && Center < maxCT) && FrontLeft < minFL && BackLeft < minBL && (LineRight > bw_detect && LineLeft > bw_detect)) 
    {
      if(Center > AttackLimit)
      {
        //forward(attack,attack);
        countattack++;
        if(countattack < countattackInt)
        {
          forward(100,100);
          digitalWrite(PC13, HIGH);
          //Serial.println("โจมตี case 1  center เจอ..................");
        }
        else
        {
          forward(attack,attack);
          digitalWrite(PC13, LOW);
        }
      }       
      digitalWrite(PC13, LOW);
      Serial.println("โจมตี case 1  center เจอ");
      digitalWrite(PB12, 1);
      digitalWrite(PB13, 1);
      digitalWrite(PB14, 1);
      digitalWrite(PB15, 1);
      digitalWrite(ResetCurrentPin, 0);
      currentBoost = false;
      countattackCurrent = 0;
      currentBoostON_OFF = false;
      HelpAttack  =  millis();
      ATTACK_ON = false;
      NormalStatus = true;
    }
    // โจมตี case 2 center and FrontRight เจอ   
    else if(BackRight < minBR && (FrontRight > minFR && FrontRight < maxFR) && (Center > minCT && Center < maxCT) && FrontLeft < minFL && BackLeft < minBL && (LineRight > bw_detect && LineLeft > bw_detect))
    {
      if(Center > AttackLimit)
      {
        countattack++;
        if(countattack < countattackInt)
        {
          forward(100,100);
          digitalWrite(PC13, HIGH);
        }
        else
        {
          forward(attack,attack);
          digitalWrite(PC13, LOW);
        }
      }
        
      digitalWrite(PC13, LOW);
      Serial.println("โจมตี case 2 center and FrontRight เจอ");
      digitalWrite(PB12, 1);
      digitalWrite(PB13, 1);
      digitalWrite(PB14, 1);
      digitalWrite(PB15, 1);
      digitalWrite(ResetCurrentPin, 0);
      currentBoost = false;
      countattackCurrent = 0;
      currentBoostON_OFF = false;
      HelpAttack  =  millis();
      ATTACK_ON = false;
      NormalStatus = true;
    }
    // โจมตี case 3 center and FrontLeft เจอ
    else if(BackRight < minBR && FrontRight < minFR && (Center > minCT && Center < maxCT) && (FrontLeft > minFL && FrontLeft < maxFL) && BackLeft < minBL && (LineRight > bw_detect && LineLeft > bw_detect))
    {
      if(Center > AttackLimit)
      {
        //forward(attack,attack);
        countattack++;
        if(countattack < countattackInt)
        {
          forward(100,100);
          digitalWrite(PC13, HIGH);
        }
        else
        {
          forward(attack,attack);
          digitalWrite(PC13, LOW);
        }
      }
        
      digitalWrite(PC13, LOW);
      Serial.println("โจมตี case 3 center and FrontLeft เจอ");
      digitalWrite(PB12, 1);
      digitalWrite(PB13, 1);
      digitalWrite(PB14, 1);
      digitalWrite(PB15, 1);
      digitalWrite(ResetCurrentPin, 0);
      currentBoost = false;
      countattackCurrent = 0;
      currentBoostON_OFF = false;
      HelpAttack  =  millis();
      ATTACK_ON = false;
      NormalStatus = true;
    }
    // โจมตี case 4 center FrontRight and FrontLeft เจอ
    else if(BackRight < minBR && (FrontRight > minFR && FrontRight < maxFR) && (Center > minCT && Center < maxCT) && (FrontLeft > minFL && FrontLeft < maxFL) && BackLeft < minBL && (LineRight > bw_detect && LineLeft > bw_detect))
    {
      if(Center > AttackLimit)
      {
        //forward(attack,attack);
        countattack++;
        if(countattack < countattackInt)
        {
          forward(100,100);
          digitalWrite(PC13, HIGH);
        }
        else
        {
          forward(attack,attack);
          digitalWrite(PC13, LOW);
        }
      }
        
      digitalWrite(PC13, LOW);
      Serial.println(" โจมตี case 4 center FrontRight and FrontLeft เจอ");
      //Serial.println(Confirm);
      digitalWrite(PB12, 1);
      digitalWrite(PB13, 1);
      digitalWrite(PB14, 1);
      digitalWrite(PB15, 1);
      digitalWrite(ResetCurrentPin, 0);
      currentBoost = false;
      countattackCurrent = 0;
      currentBoostON_OFF = false;
      HelpAttack  =  millis();
      ATTACK_ON = false;
      NormalStatus = true;
    }
    else if(Back == DistanceBackLimit && LineRight > bw_detect && LineLeft > bw_detect && BackRight < minBR  && FrontRight < minFR && Center < minCT && FrontLeft < minFL && BackLeft < minBL)
    { 
        //หลังเจอ ////
        //reward(240,240);
        //delay(30);
        spinleft(254,254);
      //delay(200);
      for(int i = 0; i < 30 ; i++ )
      {
        delay(1);
        
        LineRight   = analogRead(SensorLineRight);
        LineLeft    = analogRead(SensorLineLeft);
        if(LineRight < bw_detect && LineLeft > bw_detect)
        {
          reward(240,240);
          delay(10);
          goto StopRewardback;
        }
        else if(LineRight < bw_detect && LineLeft > bw_detect)
        {
          reward(240,240);
          delay(10);
          goto StopRewardback;
        }
      }StopRewardback : int B_B = 0;
      Serial.println(".....หลังเจอ.....");
      digitalWrite(ResetCurrentPin, 1);
      currentBoost = false;
      countattackCurrent = 0;
      currentBoostON_OFF = false;
      HelpAttack  =  millis();
      ATTACK_ON = false;
      NormalStatus = true;
    }
    else
    {
      digitalWrite(PC13, HIGH);
      digitalWrite(PB12, 0);
      digitalWrite(PB13, 0);
      digitalWrite(PB14, 0);
      digitalWrite(PB15, 0);
      if(ATTACK_ON == true)
      {
        countattackTimer++;
        int attack2 = map(countattackTimer,0, countattackTimerInt,NormalSpeed,attack);
        //Serial.print("....TestRUN countattackTimer .....");Serial.println(attack2);
        forward(attack2,attack2);
        if(attack2 == attack)
        {
          ATTACK_ON = false;
          countattackTimer = 0;
          delay(1500);
        }          
      
      }
      else{
        digitalWrite(ResetCurrentPin, 0);
        //countattack2 = 0;
        //Serial.println(".....No body.....");
        //Serial.println(Center);
      }
    }
}
