/*
void Move2()
{
  if((BackRight > minBR && BackRight < maxBR) && FrontRight < minFR && Center < minCT && FrontLeft < minFL && BackLeft < minBL)
    { 
        //หลังขวาเจอ
        CountBr++;
        if(CountBr < 500){ //800 600
            spinright(150,150);
            delay(30);
        }
        else 
        {
            spinright(255,255);
            delay(300);
            CountBr = 0;
        }
        //digitalWrite(PC13, LOW);
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
        //ShowSensor();
    }
    else if(BackRight < minBR && (FrontRight > minFR && FrontRight < maxFR) && Center < minCT && FrontLeft < minFL && BackLeft < minBL) //1700
    {
        //หน้าขวาเจอ
        CountFr++;
        if(CountFr < 500){
            spinright(150,150);
            delay(2);
        }
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
    }
    else if(BackRight < minBR && FrontRight < minFR && Center < minCT && FrontLeft < minFL && (BackLeft > minBL && BackLeft < maxBL))
    {
      //หลังซ้ายเจอ
      CountBl++;
      //Serial.print(CountBl);
      if(CountBl < 500){
          spinleft(150,150);
          delay(30);
      }
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
    }
    else if(BackRight < minBR && FrontRight < minFR && Center < minCT && (FrontLeft > minFL && FrontLeft < maxFL) &&  BackLeft < minBL)
    {
      //หน้าซ้ายเจอ
      CountFl++;
      if(CountFl < 500){
          spinleft(150,150);
          delay(2);
      }
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
    }
    // โจมตี case 0.9  Confirm เจอ
    else if(BackRight < minBR && FrontRight < minFR && (Confirm2 > AttackLimit-10) && FrontLeft < minFL && BackLeft < minBL)
    {
      countattack++;
      if(countattack < countattackInt){
        forward(80,80);
        //delay()
      digitalWrite(PB12, 1);
      digitalWrite(PB13, 0);
      digitalWrite(PB14, 0);
      digitalWrite(PB15, 1);
      }
      else{
        forward(attack,attack);
      digitalWrite(PB12, 1);
      digitalWrite(PB13, 1);
      digitalWrite(PB14, 1);
      digitalWrite(PB15, 1);
      }
        
      digitalWrite(PC13, LOW);
      Serial.println("โจมตี case 0.9  Confirm เจอ");
//      digitalWrite(PB12, 1);
//      digitalWrite(PB13, 1);
//      digitalWrite(PB14, 1);
//      digitalWrite(PB15, 1);
    }
    // โจมตี case 1  center เจอ
    else if(BackRight < minBR && FrontRight < minFR && (Center > minCT && Center < maxCT) && FrontLeft < minFL && BackLeft < minBL) //1700
    {
      if(Confirm > AttackLimit)
      {
        //forward(attack,attack);
        countattack++;
        if(countattack < countattackInt)
          forward(80,80);
        else
          forward(attack,attack);
      }
      else if(ATTACK_ON == true)
      {
        if(millis() - MoveHelpAttack >= MoveHelpAttack_interval) 
        {
          MoveHelpAttack  =  millis();
          Serial.println(".....ชนแม่ม.....");
         forward(attack,attack);// forward(attack,attack);
          delay(500);
          forward(0,0);
        }
      }
      else
        forward(80,80);//200
        
      digitalWrite(PC13, LOW);
      Serial.println("โจมตี case 1  center เจอ");
      digitalWrite(PB12, 1);
      digitalWrite(PB13, 1);
      digitalWrite(PB14, 1);
      digitalWrite(PB15, 1);
    }
    // โจมตี case 2 center and FrontRight เจอ   
    else if(BackRight < minBR && (FrontRight > minFR && FrontRight < maxFR) && (Center > minCT && Center < maxCT) && FrontLeft < minFL && BackLeft < minBL)
    {
      if(Confirm > AttackLimit)
      {
        //forward(attack,attack);
        countattack++;
        if(countattack < countattackInt)
          forward(80,80);
        else
          forward(attack,attack);
      }
      else if(ATTACK_ON == true)
      {
        if(millis() - MoveHelpAttack >= MoveHelpAttack_interval) 
        {
          MoveHelpAttack  =  millis();
          Serial.println(".....ชนแม่ม.....");
          forward(attack,attack);
          delay(500);
          forward(0,0);
        }
      }
      else
        forward(70,70); //190
        
      digitalWrite(PC13, LOW);
      Serial.println("โจมตี case 2 center and FrontRight เจอ");
      digitalWrite(PB12, 1);
      digitalWrite(PB13, 1);
      digitalWrite(PB14, 1);
      digitalWrite(PB15, 1);
    }
    // โจมตี case 3 center and FrontLeft เจอ
    else if(BackRight < minBR && FrontRight < minFR && (Center > minCT && Center < maxCT) && (FrontLeft > minFL && FrontLeft < maxFL) && BackLeft < minBL)
    {
      if(Center > AttackLimit)
      {
        //forward(attack,attack);
        countattack++;
        if(countattack < countattackInt)
          forward(80,80);
        else
          forward(attack,attack);
      }
      else if(ATTACK_ON == true)
      {
        if(millis() - MoveHelpAttack >= MoveHelpAttack_interval) 
        {
          MoveHelpAttack  =  millis();
          Serial.println(".....ชนแม่ม.....");
          forward(attack,attack);
          delay(500);
          forward(0,0);
        }
      }
      else
        forward(70,70); //190
        
      digitalWrite(PC13, LOW);
      Serial.println("โจมตี case 3 center and FrontLeft เจอ");
      digitalWrite(PB12, 1);
      digitalWrite(PB13, 1);
      digitalWrite(PB14, 1);
      digitalWrite(PB15, 1);
    }
    // โจมตี case 4 center FrontRight and FrontLeft เจอ
    else if(BackRight < minBR && (FrontRight > minFR && FrontRight < maxFR) && (Center > minCT && Center < maxCT) && (FrontLeft > minFL && FrontLeft < maxFL) && BackLeft < minBL)
    {
      if(Center > AttackLimit)
      {
        //forward(attack,attack);
        countattack++;
        if(countattack < countattackInt)
          forward(80,80);
        else
          forward(attack,attack);
      }
      else if(ATTACK_ON == true)
      {
        if(millis() - MoveHelpAttack >= MoveHelpAttack_interval) 
        {
          MoveHelpAttack  =  millis();
          Serial.println(".....ชนแม่ม.....");
          forward(attack,attack);
          delay(500);
          forward(0,0);
        }
      }
      else
        forward(70,70); //190
        
      digitalWrite(PC13, LOW);
      Serial.println(" โจมตี case 4 center FrontRight and FrontLeft เจอ");
      //Serial.println(Confirm);
      digitalWrite(PB12, 1);
      digitalWrite(PB13, 1);
      digitalWrite(PB14, 1);
      digitalWrite(PB15, 1);
    }
    else if(Back > DistanceBackLimit && LineRight > bw_detect && LineLeft > bw_detect && BackRight < minBR  && FrontRight < minFR && Center < minCT && FrontLeft < minFL && BackLeft < minBL)
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
//        countattack2++;
//        if(countattack2 >500)
//        {
//          forward(200,200);
//          delay(1000);
//          forward(0,0);
//          delay(1000);
//        }
        //Serial.println(".....ชนแม่ม.....");

        if(millis() - MoveHelpAttack >= MoveHelpAttack_interval) 
        {
          MoveHelpAttack  =  millis();
          Serial.println(".....ชนแม่ม.....");
          forward(attack,attack);
          delay(500);
          forward(0,0);
        }
      }
      else{
        
        //countattack2 = 0;
        Serial.println(".....ไม่เจอ.....");
        //Serial.println(Center);
      }
    }
}


/*
void Move2()
{
  if((BackRight > minBR && BackRight < maxBR) && FrontRight < minFR && Center < minCT && FrontLeft < minFL && BackLeft < minBL)
    { 
        //หลังขวาเจอ
        CountBr++;
        if(CountBr < 500){ //800 600
            spinright(100,100);
        }
        else 
        {
            spinright(255,255);
            delay(300);
            CountBr = 0;
        }
        //digitalWrite(PC13, LOW);
        //Serial.print("..... "); Serial.print(BackRight); Serial.print(" ..... "); 
        Serial.println("หลังขวาเจอ");
        CountFr = 0; 
        CountFl = 0; 
        CountBl = 0; 
        
        CountCF = 0;
        digitalWrite(PB12, 1);
        digitalWrite(PB13, 0);
        digitalWrite(PB14, 0);
        digitalWrite(PB15, 0);
    }
    else if(BackRight < minBR && (FrontRight > minFR && FrontRight < maxFR) && Center < minCT && FrontLeft < minFL && BackLeft < minBL)
    {
        //หน้าขวาเจอ
        CountFr++;
        if(CountFr < 500)
            spinright(100,100);
        else
        {
            spinright(255,255);
            delay(300);
            CountFr = 0;
        }
        //digitalWrite(PC13, LOW);
        //Serial.print("..... "); Serial.print(FrontRight); Serial.print(" ..... "); 
        Serial.println("หน้าขวาเจอ");
        CountBr = 0;  
        CountFl = 0; 
        CountBl = 0;

        CountCF = 0;
        digitalWrite(PB12, 0);
        digitalWrite(PB13, 1);
        digitalWrite(PB14, 0);
        digitalWrite(PB15, 0);
    }
    else if(BackRight < minBR && FrontRight < minFR && Center < minCT && FrontLeft < minFL && (BackLeft > minBL && BackLeft < maxBL))
    {
      //หลังซ้ายเจอ
      CountBl++;
      //Serial.print(CountBl);
      if(CountBl < 500)
          spinleft(100,100);
      else
      {
        spinleft(255,255);
        delay(300);
        CountBl = 0;
      }
      //digitalWrite(PC13, LOW);
      //Serial.print("..... "); Serial.print(BackLeft); Serial.print(" ..... "); 
      Serial.println("หลังซ้ายเจอ");
      CountBr = 0; 
      CountFr = 0; 
      CountFl = 0; 

      CountCF = 0;
      digitalWrite(PB12, 0);
      digitalWrite(PB13, 0);
      digitalWrite(PB14, 0);
      digitalWrite(PB15, 1);
    }
    else if(BackRight < minBR && FrontRight < minFR && Center < minCT && (FrontLeft > minFL && FrontLeft < maxFL) &&  BackLeft < minBL)
    {
      //หน้าซ้ายเจอ
      CountFl++;
      if(CountFl < 500)
          spinleft(100,100);
      else
      {
        spinleft(255,255);
        delay(300);
        CountFl = 0;
      }
      //digitalWrite(PC13, LOW);
      //Serial.print("..... "); Serial.print(FrontLeft); Serial.print(" ..... "); 
      Serial.println("หน้าซ้ายเจอ");
      CountBr = 0; 
      CountFr = 0;  
      CountBl = 0;

      CountCF = 0;
      digitalWrite(PB12, 0);
      digitalWrite(PB13, 0);
      digitalWrite(PB14, 1);
      digitalWrite(PB15, 0);
    }
    // โจมตี case 0.9  Confirm เจอ
    else if(BackRight < minBR && FrontRight < minFR && Confirm > AttackLimit && FrontLeft < minFL && BackLeft < minBL)
    {
      forward(attack,attack);
      digitalWrite(PC13, LOW);
      //delay(1);
      Serial.println("โจมตี case 0.9  Confirm เจอ");
      if( attackSpin == true)
      {
          for(int i = 0; i < 255; i++)
          {
            forward(i,i);
            delay(2);
          }
          forward(attack,attack);
          delay(delay1);
          reward(attack2,attack2);
          //delay(delay2);
          for(int i = 0; i < delay2 ; i++ )
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
           }StopRewardA : int A_1 = 0;
      }
      digitalWrite(PB12, 0);
      digitalWrite(PB13, 1);
      digitalWrite(PB14, 1);
      digitalWrite(PB15, 0);
    }
    else if(BackRight < minBR && FrontRight < minFR && Confirm > AttackCF && Center > AttackCT && FrontLeft < minFL && BackLeft < minBL)
    {
      forward(attack,attack);
      digitalWrite(PC13, LOW);
      Serial.println("โจมตี case 0.999  Confirm เจอ");
      if(attackSpin == true)
      {
          for(int i = 0; i < 255; i++)
          {
            forward(i,i);
            delay(2);
          }
          forward(attack,attack);
          delay(delay1);
          reward(attack2,attack2);
          //delay(delay2); 
          for(int i = 0; i < delay2 ; i++ )
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
           }StopRewardB : int B_1 = 0; 
      }
      digitalWrite(PB12, 0);
      digitalWrite(PB13, 1);
      digitalWrite(PB14, 1);
      digitalWrite(PB15, 0);
    }
    // โจมตี case 1  center เจอ
    else if(BackRight < minBR && FrontRight < minFR && (Center > minCT && Center < maxCT) && FrontLeft < minFL && BackLeft < minBL)
    {
      if(Confirm > AttackLimit)
      {
        forward(attack,attack);
        if(attackSpin == true)
        {
            for(int i = 0; i < 255; i++)
            {
              forward(i,i);
              delay(2);
            }
            forward(attack,attack);
            delay(delay1);
            reward(attack2,attack2);
            //delay(delay2);
            for(int i = 0; i < delay2 ; i++ )
            {
                delay(1); 
                LineRightBack   = analogRead(SensorLineRightBack);
                LineLeftBack    = analogRead(SensorLineLeftBack);
                if(LineRightBack < bw_back_detect && LineLeftBack > bw_back_detect)
                {
                  forward(240,240);
                  delay(10);
                  goto StopRewardC;
                }
                else if(LineLeftBack < bw_back_detect && LineRightBack > bw_back_detect)
                {
                  forward(240,240);
                  delay(10);
                  goto StopRewardC;
                }
           }StopRewardC : int C_1 = 0;
        }
        digitalWrite(PB12, 0);
        digitalWrite(PB13, 1);
        digitalWrite(PB14, 1);
        digitalWrite(PB15, 0);
      }
      else if(Confirm > AttackCF && Center > AttackCT)
      {
        forward(attack,attack);
        if(attackSpin == true)
        {
            for(int i = 0; i < 255; i++)
            {
              forward(i,i);
              delay(2);
            }
            forward(attack,attack);
            delay(delay1);
            reward(attack2,attack2);
            //delay(delay2);
            for(int i = 0; i < delay2 ; i++ )
            {
                delay(1); 
                LineRightBack   = analogRead(SensorLineRightBack);
                LineLeftBack    = analogRead(SensorLineLeftBack);
                if(LineRightBack < bw_back_detect && LineLeftBack > bw_back_detect)
                {
                  forward(240,240);
                  delay(10);
                  goto StopRewardD;
                }
                else if(LineLeftBack < bw_back_detect && LineRightBack > bw_back_detect)
                {
                  forward(240,240);
                  delay(10);
                  goto StopRewardD;
                }
           }StopRewardD : int D_1 = 0;
        }
        digitalWrite(PB12, 0);
        digitalWrite(PB13, 1);
        digitalWrite(PB14, 1);
        digitalWrite(PB15, 0);
      }
      else
      {
        forward(120,120);//120
        digitalWrite(PB12, 1);
        digitalWrite(PB13, 1);
        digitalWrite(PB14, 1);
        digitalWrite(PB15, 1);
      }
      digitalWrite(PC13, LOW);
      Serial.println("โจมตี case 1  center เจอ");
    }
    // โจมตี case 2 center and FrontRight เจอ   
    else if(BackRight < minBR && (FrontRight > minFR && FrontRight < maxFR) && (Center > minCT && Center < maxCT) && FrontLeft < minFL && BackLeft < minBL)
    {
      if(Confirm > AttackLimit)
      {
        forward(attack,attack);
        if(attackSpin == true)
        {
            for(int i = 0; i < 255; i++)
            {
              forward(i,i);
              delay(2);
            }
            forward(attack,attack);
            delay(delay1);
            reward(attack2,attack2);
            //delay(delay2);
            for(int i = 0; i < delay2 ; i++ )
            {
                delay(1); 
                LineRightBack   = analogRead(SensorLineRightBack);
                LineLeftBack    = analogRead(SensorLineLeftBack);
                if(LineRightBack < bw_back_detect && LineLeftBack > bw_back_detect)
                {
                  forward(240,240);
                  delay(10);
                  goto StopRewardE;
                }
                else if(LineLeftBack < bw_back_detect && LineRightBack > bw_back_detect)
                {
                  forward(240,240);
                  delay(10);
                  goto StopRewardE;
                }
           }StopRewardE : int E_1 = 0;   
        }
        digitalWrite(PB12, 0);
        digitalWrite(PB13, 1);
        digitalWrite(PB14, 1);
        digitalWrite(PB15, 0);
      }
      else if(Confirm > AttackCF && Center > AttackCT)
      {
        forward(attack,attack);
        if(attackSpin == true)
        {
            for(int i = 0; i < 255; i++)
            {
              forward(i,i);
              delay(2);
            }
            forward(attack,attack);
            delay(delay1);
            reward(attack2,attack2);
            //delay(delay2);
            for(int i = 0; i < delay2 ; i++ )
            {
                delay(1); 
                LineRightBack   = analogRead(SensorLineRightBack);
                LineLeftBack    = analogRead(SensorLineLeftBack);
                if(LineRightBack < bw_back_detect && LineLeftBack > bw_back_detect)
                {
                  forward(240,240);
                  delay(10);
                  goto StopRewardF;
                }
                else if(LineLeftBack < bw_back_detect && LineRightBack > bw_back_detect)
                {
                  forward(240,240);
                  delay(10);
                  goto StopRewardF;
                }
           }StopRewardF : int F_1 = 0;
        }
        digitalWrite(PB12, 0);
        digitalWrite(PB13, 1);
        digitalWrite(PB14, 1);
        digitalWrite(PB15, 0);
      }
      else
      {
        forward(120,120);
        digitalWrite(PB12, 1);
        digitalWrite(PB13, 1);
        digitalWrite(PB14, 1);
        digitalWrite(PB15, 1);
      }
        
      digitalWrite(PC13, LOW);
      Serial.println("โจมตี case 2 center and FrontRight เจอ");
    }
    // โจมตี case 3 center and FrontLeft เจอ
    else if(BackRight < minBR && FrontRight < minFR && (Center > minCT && Center < maxCT) && (FrontLeft > minFL && FrontLeft < maxFL) && BackLeft < minBL)
    {
      if(Confirm > AttackLimit)
      {
        forward(attack,attack);
        digitalWrite(PB12, 0);
        digitalWrite(PB13, 1);
        digitalWrite(PB14, 1);
        digitalWrite(PB15, 0);
        if(attackSpin == true)
        {
            for(int i = 0; i < 255; i++)
            {
              forward(i,i);
              delay(2);
            }
            forward(attack,attack);
            delay(delay1);
            reward(attack2,attack2);
            //delay(delay2);    
            for(int i = 0; i < delay2 ; i++ )
            {
                delay(1); 
                LineRightBack   = analogRead(SensorLineRightBack);
                LineLeftBack    = analogRead(SensorLineLeftBack);
                if(LineRightBack < bw_back_detect && LineLeftBack > bw_back_detect)
                {
                  forward(240,240);
                  delay(10);
                  goto StopRewardG;
                }
                else if(LineLeftBack < bw_back_detect && LineRightBack > bw_back_detect)
                {
                  forward(240,240);
                  delay(10);
                  goto StopRewardG;
                }
           }StopRewardG : int G_1 = 0;    
        }
      }
      else if(Confirm > AttackCF && Center > AttackCT)
      {
        forward(attack,attack);
        digitalWrite(PB12, 0);
        digitalWrite(PB13, 1);
        digitalWrite(PB14, 1);
        digitalWrite(PB15, 0);
        if(attackSpin == true)
        {
            for(int i = 0; i < 255; i++)
            {
              forward(i,i);
              delay(2);
            }
            forward(attack,attack);
            delay(delay1);
            reward(attack2,attack2);
            //delay(delay2);
            for(int i = 0; i < delay2 ; i++ )
            {
                delay(1); 
                LineRightBack   = analogRead(SensorLineRightBack);
                LineLeftBack    = analogRead(SensorLineLeftBack);
                if(LineRightBack < bw_back_detect && LineLeftBack > bw_back_detect)
                {
                  forward(240,240);
                  delay(10);
                  goto StopRewardH;
                }
                else if(LineLeftBack < bw_back_detect && LineRightBack > bw_back_detect)
                {
                  forward(240,240);
                  delay(10);
                  goto StopRewardH;
                }
           }StopRewardH : int H_1 = 0;
        }
      }
      else
      {
        forward(120,120);
        digitalWrite(PB12, 1);
        digitalWrite(PB13, 1);
        digitalWrite(PB14, 1);
        digitalWrite(PB15, 1);
      }
        
      digitalWrite(PC13, LOW);
      Serial.println("โจมตี case 3 center and FrontLeft เจอ");
    }
    // โจมตี case 4 center FrontRight and FrontLeft เจอ
    else if(BackRight < minBR && (FrontRight > minFR && FrontRight < maxFR) && (Center > minCT && Center < maxCT) && (FrontLeft > minFL && FrontLeft < maxFL) && BackLeft < minBL)
    {
      if(Confirm > AttackLimit)
      {
        forward(attack,attack);
        digitalWrite(PB12, 0);
        digitalWrite(PB13, 1);
        digitalWrite(PB14, 1);
        digitalWrite(PB15, 0);
        if(attackSpin == true)
        {
            for(int i = 0; i < 255; i++)
            {
              forward(i,i);
              delay(2);
            }
            forward(attack,attack);
            delay(delay1);
            reward(attack2,attack2);
            //delay(delay2);
            for(int i = 0; i < delay2 ; i++ )
            {
                delay(1); 
                LineRightBack   = analogRead(SensorLineRightBack);
                LineLeftBack    = analogRead(SensorLineLeftBack);
                if(LineRightBack < bw_back_detect && LineLeftBack > bw_back_detect)
                {
                  forward(240,240);
                  delay(10);
                  goto StopRewardI;
                }
                else if(LineLeftBack < bw_back_detect && LineRightBack > bw_back_detect)
                {
                  forward(240,240);
                  delay(10);
                  goto StopRewardI;
                }
           }StopRewardI : int I_1 = 0;
        }
      }
      else if(Confirm > AttackCF && Center > AttackCT)
      {
        forward(attack,attack);
        digitalWrite(PB12, 0);
        digitalWrite(PB13, 1);
        digitalWrite(PB14, 1);
        digitalWrite(PB15, 0);
        if(attackSpin == true)
        {
        for(int i = 0; i < 100 ; i++)
        {
          forward(i,i);
          delay(2);
        }
        forward(attack,attack);
        delay(delay1);
        reward(attack2,attack2);
        //delay(delay2);
        for(int i = 0; i < delay2 ; i++ )
          {
              delay(1); 
              LineRightBack   = analogRead(SensorLineRightBack);
              LineLeftBack    = analogRead(SensorLineLeftBack);
              if(LineRightBack < bw_back_detect && LineLeftBack > bw_back_detect)
              {
                forward(240,240);
                delay(10);
                goto StopRewardJ;
              }
              else if(LineLeftBack < bw_back_detect && LineRightBack > bw_back_detect)
              {
                forward(240,240);
                delay(10);
                goto StopRewardJ;
              }
           }StopRewardJ : int J_1 = 0;
        
        }
      }
      else
      {
        forward(120,120);
        digitalWrite(PB12, 1);
        digitalWrite(PB13, 1);
        digitalWrite(PB14, 1);
        digitalWrite(PB15, 1);
      }
      digitalWrite(PC13, LOW);
      Serial.println(" โจมตี case 4 center FrontRight and FrontLeft เจอ");
      //Serial.println(Confirm);
    }
    else if(Back == 1 && LineRight > bw_detect && LineLeft > bw_detect && BackRight < minBR  && FrontRight < minFR && Center < minCT && FrontLeft < minFL && BackLeft < minBL)
    { 
        //หลังเจอ ////
        reward(240,240);
        delay(100);
        spinright(254,254);
      //delay(200);
      for(int i = 0; i < 70 ; i++ )
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
    }
    else
    {
      digitalWrite(PC13, HIGH);
      digitalWrite(PB12, 0);
      // CountBr = 0; 
      // CountFr = 0; 
      // CountFl = 0; 
      // CountBl = 0;
      
      digitalWrite(PB12, 0);
      digitalWrite(PB13, 0);
      digitalWrite(PB14, 0);
      digitalWrite(PB15, 0);
    }
}
*/
