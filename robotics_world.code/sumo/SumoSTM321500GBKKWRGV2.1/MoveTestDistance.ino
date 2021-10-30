/*void MoveTestDistance()
{
  if((BackRight > minBR && BackRight < maxBR) && FrontRight < minFR && Center < minCT && FrontLeft < minFL && BackLeft < minBL)
    { 
        //หลังขวาเจอ
        CountBr++;
        if(CountBr < 500){ //800 600
            spinrightT(100,100);
        }
        else 
        {
            spinrightT(255,255);
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
            spinrightT(100,100);
        else
        {
            spinrightT(255,255);
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
          spinleftT(100,100);
      else
      {
        spinleftT(255,255);
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
          spinleftT(100,100);
      else
      {
        spinleftT(255,255);
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
      forwardT(attack,attack);
      digitalWrite(PC13, LOW);
      //delay(1);
      Serial.println("โจมตี case 0.9  Confirm เจอ");
      digitalWrite(PB12, 0);
      digitalWrite(PB13, 1);
      digitalWrite(PB14, 1);
      digitalWrite(PB15, 0);
    }
    else if(BackRight < minBR && FrontRight < minFR && Confirm > AttackCF && Center > AttackCT && FrontLeft < minFL && BackLeft < minBL)
    {
      forwardT(attack,attack);
      digitalWrite(PC13, LOW);
      Serial.println("โจมตี case 0.999  Confirm เจอ");
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
        forwardT(attack,attack);
        digitalWrite(PB12, 0);
        digitalWrite(PB13, 1);
        digitalWrite(PB14, 1);
        digitalWrite(PB15, 0);
      }
      else if(Confirm > AttackCF && Center > AttackCT)
      {
        forwardT(attack,attack);
        digitalWrite(PB12, 0);
        digitalWrite(PB13, 1);
        digitalWrite(PB14, 1);
        digitalWrite(PB15, 0);
      }
      else
      {
        forwardT(120,120);//120
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
        forwardT(attack,attack);
        digitalWrite(PB12, 0);
        digitalWrite(PB13, 1);
        digitalWrite(PB14, 1);
        digitalWrite(PB15, 0);
      }
      else if(Confirm > AttackCF && Center > AttackCT)
      {
        forwardT(attack,attack);
        digitalWrite(PB12, 0);
        digitalWrite(PB13, 1);
        digitalWrite(PB14, 1);
        digitalWrite(PB15, 0);
      }
      else
      {
        forwardT(120,120);
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
        forwardT(attack,attack);
        digitalWrite(PB12, 0);
        digitalWrite(PB13, 1);
        digitalWrite(PB14, 1);
        digitalWrite(PB15, 0);
      }
      else if(Confirm > AttackCF && Center > AttackCT)
      {
        forwardT(attack,attack);
        digitalWrite(PB12, 0);
        digitalWrite(PB13, 1);
        digitalWrite(PB14, 1);
        digitalWrite(PB15, 0);
      }
      else
      {
        forwardT(120,120);
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
        forwardT(attack,attack);
        digitalWrite(PB12, 0);
        digitalWrite(PB13, 1);
        digitalWrite(PB14, 1);
        digitalWrite(PB15, 0);
      }
      else if(Confirm > AttackCF && Center > AttackCT)
      {
        forwardT(attack,attack);
        digitalWrite(PB12, 0);
        digitalWrite(PB13, 1);
        digitalWrite(PB14, 1);
        digitalWrite(PB15, 0);
      }
      else
      {
        forwardT(120,120);
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
        rewardT(240,240);
        delay(100);
        spinrightT(254,254);
      //delay(200);
      for(int i = 0; i < 70 ; i++ )
      {
        delay(1);
        
        LineRight   = analogRead(SensorLineRight);
        LineLeft    = analogRead(SensorLineLeft);
        if(LineRight < bw_detect && LineLeft > bw_detect)
        {
          rewardT(240,240);
          delay(10);
          goto StopRewardback;
        }
        else if(LineRight < bw_detect && LineLeft > bw_detect)
        {
          rewardT(240,240);
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

