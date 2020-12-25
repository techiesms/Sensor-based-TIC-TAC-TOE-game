/*
 * 
 * This is code for the project called 
 * 
 * "Sensor based TIC-TAC-TOE Game"
 * 
 * developed by team techiesms for techiesms YouTube Channel.
 * 
 * To watch the full tutorial of this and many other projects, 
 * head on to our YouTube channel
 * 
 * https://www.youtube.com/techiesms
 * 
 * 
 */


// Variables
int tictac[10];
boolean s2_flag, s3_flag , s4_flag , s5_flag , s6_flag , s7_flag , s8_flag , s9_flag , s10_flag, winner_flag ;
int s2, s3, s4, s5, s6, s7, s8, s9, s10;
int count = 0 ;
String winner;
int P1_points = 0 , P2_points = 0 ;
char sx, control ;

#define ROWS 3
#define COLUMNS 3
#define RESET_PIN 12
#define buzzer 11


// Pin Definition

// GREEN LED
int G[ROWS][COLUMNS] =
{
  14 , 16 , 18 ,
  20 , 22 , 24,
  26 , 28 , 30
};


//RED LED
int R[ROWS][COLUMNS] =
{
  15 , 17 , 19 ,
  21 , 23 , 25,
  27 , 29 , 31
};



void setup()
{
  digitalWrite(RESET_PIN, HIGH);
  pinMode(RESET_PIN, OUTPUT);

  s2_flag = s3_flag = s4_flag = s5_flag = s6_flag = s7_flag = s8_flag = s9_flag = s10_flag = winner_flag = false ;

  for (int i = 0 ; i < 9 ; i++) //clearing the array on reset
    tictac[i] = 0 ;

  Serial.begin(115200);

  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(buzzer, OUTPUT);

  // defining all LED pins as output
  for (int i = 0; i < 3 ; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      pinMode(G[i][j], OUTPUT);
      pinMode(R[i][j], OUTPUT);

    }
  }


}

void loop()
{
  //Reading status of the sensors
  s2 = !digitalRead(2) ;
  s3 = !digitalRead(3) ;
  s4 = !digitalRead(4) ;
  s5 = !digitalRead(5) ;
  s6 = !digitalRead(6) ;
  s7 = !digitalRead(7) ;
  s8 = !digitalRead(8) ;
  s9 = !digitalRead(9) ;
  s10 = !digitalRead(10) ;


  // Which ever sensor is triggerd, that particular IF condition will get satisfied

  if (s2 == HIGH && s2_flag == false )
  {
    s2_flag = true ;
    count ++;

    if (count % 2 == 0 ) // if count is even, it's GREEN
    {
      tictac[0] = 5 ; // O
      digitalWrite(G[0][0], HIGH);
      Serial.println("Green 00");
      beep(); // buzzing the buzzer
    }
    else  // if count is odd, it's RED
    {
      tictac[0] = 1 ;
      digitalWrite(R[0][0], HIGH);
      Serial.println("Red 00");
      beep();
    }
  }

  else if (s3 == HIGH && s3_flag == false )
  {
    s3_flag = true ;
    count ++ ;
    if (count % 2 == 0 )
    {
      tictac[1] = 5 ; // O
      digitalWrite(G[1][0], HIGH);
      Serial.println("Green 10");
      beep();
    }
    else
    {
      tictac[1] = 1 ; // X
      digitalWrite(R[1][0], HIGH);
      Serial.println("REd 10");
      beep();
    }
  }

  else if (s4 == HIGH && s4_flag == false )
  {
    s4_flag = true ;
    count ++ ;
    if (count % 2 == 0 )
    {
      tictac[2] = 5 ; // O
      digitalWrite(G[2][0], HIGH);
      Serial.println("Green 20");
      beep();
    }
    else
    {
      tictac[2] = 1 ; // X
      digitalWrite(R[2][0], HIGH);
      Serial.println("Red 20");
      beep();
    }
  }

  else if (s5 == HIGH && s5_flag == false )
  {
    s5_flag = true ;
    count ++ ;
    if (count % 2 == 0 )
    {
      tictac[3] = 5 ; // O
      digitalWrite(G[0][1], HIGH);
      Serial.println("Green 01");
      beep();
    }
    else
    {
      tictac[3] = 1 ; // X
      digitalWrite(R[0][1], HIGH);
      Serial.println("REd 01");
      beep();
    }
  }

  else if (s6 == HIGH && s6_flag == false )
  {
    s6_flag = true ;
    count ++ ;
    if (count % 2 == 0 )
    {
      tictac[4] = 5 ; // O
      digitalWrite(G[1][1], HIGH);
      Serial.println("Green 11");
      beep();
    }
    else
    {
      tictac[4] = 1 ; // X
      digitalWrite(R[1][1], HIGH);
      Serial.println("Red 11");
      beep();
    }
  }

  else if (s7 == HIGH && s7_flag == false )
  {
    s7_flag = true ;
    count ++ ;
    if (count % 2 == 0 )
    {
      tictac[5] = 5 ; // O
      digitalWrite(G[2][1], HIGH);
      Serial.println("Green 21");
      beep();
    }
    else
    {
      tictac[5] = 1 ; // X
      digitalWrite(R[2][1], HIGH);
      Serial.println("REd 21");
      beep();
    }
  }

  else if (s8 == HIGH && s8_flag == false )
  {
    s8_flag = true ;
    count ++ ;
    if (count % 2 == 0 )
    {
      tictac[6] = 5 ; // O
      digitalWrite(G[0][2], HIGH);
      Serial.println("Green 02");
      beep();
    }

    else
    {
      tictac[6] = 1 ; // X
      digitalWrite(R[0][2], HIGH);
      Serial.println("Red 02");
      beep();
    }
  }

  else if (s9 == HIGH && s9_flag == false )
  {
    s9_flag = true ;
    count ++ ;
    if (count % 2 == 0 )
    {
      tictac[7] = 5 ; // O
      digitalWrite(G[1][2], HIGH);
      Serial.println("Green 12");
      beep();
    }
    else
    {
      tictac[7] = 1 ; // X
      digitalWrite(R[1][2], HIGH);
      Serial.println("Red 12");
      beep();
    }
  }

  else if (s10 == HIGH && s10_flag == false )
  {
    s10_flag = true ;
    count ++ ;
    if (count % 2 == 0 )
    {
      tictac[8] = 5 ; // O
      digitalWrite(G[2][2], HIGH);
      Serial.println("Green 22");
      beep();
    }
    else
    {
      tictac[8] = 1 ; // X
      digitalWrite(R[2][2], HIGH);
      Serial.println("Red 22");
      beep();
    }
  }



  winner = check(); // Checking if anyone won the match


  if (winner == "r1")
  {

    Serial.println("RED wins ! ");

    for (int i = 0; i < 5; i++)
    {


      RED_WIN_1();

    }


    winner_flag = true  ;
  }

  if (winner == "r2")
  {

    Serial.println("RED wins ! ");

    for (int i = 0; i < 5; i++)
      RED_WIN_2();

    winner_flag = true  ;
  }

  if (winner == "r3")
  {

    Serial.println("RED wins ! ");

    for (int i = 0; i < 5; i++)
      RED_WIN_3();

    winner_flag = true  ;
  }

  if (winner == "r4")
  {

    Serial.println("RED wins ! ");

    for (int i = 0; i < 5; i++)
      RED_WIN_4();

    winner_flag = true  ;
  }

  if (winner == "r5")
  {

    Serial.println("RED wins ! ");

    for (int i = 0; i < 5; i++)
      RED_WIN_5();

    winner_flag = true  ;
  }

  if (winner == "r6")
  {

    Serial.println("RED wins ! ");

    for (int i = 0; i < 5; i++)
      RED_WIN_6();

    winner_flag = true  ;
  }

  if (winner == "r7")
  {

    Serial.println("RED wins ! ");

    for (int i = 0; i < 5; i++)
      RED_WIN_7();

    winner_flag = true  ;
  }

  if (winner == "r8")
  {
    Serial.println("RED wins ! ");

    for (int i = 0; i < 5; i++)
      RED_WIN_8();

    winner_flag = true  ;
  }




  if (winner == "g1")
  {

    Serial.println("GREEN wins ! ");

    for (int i = 0; i < 5; i++)
      GREEN_WIN_1();

    winner_flag = true  ;
  }

  if (winner == "g2")
  {

    Serial.println("GREEN wins ! ");

    for (int i = 0; i < 5; i++)
      GREEN_WIN_2();

    winner_flag = true  ;
  }

  if (winner == "g3")
  {

    Serial.println("GREEN wins ! ");

    for (int i = 0; i < 5; i++)
      GREEN_WIN_3();

    winner_flag = true  ;
  }

  if (winner == "g4")
  {

    Serial.println("GREEN wins ! ");

    for (int i = 0; i < 5; i++)
      GREEN_WIN_4();

    winner_flag = true  ;
  }

  if (winner == "g5")
  {

    Serial.println("GREEN wins ! ");

    for (int i = 0; i < 5; i++)
      GREEN_WIN_5();

    winner_flag = true  ;
  }

  if (winner == "g6")
  {

    Serial.println("GREEN wins ! ");

    for (int i = 0; i < 5; i++)
      GREEN_WIN_6();

    winner_flag = true  ;
  }

  if (winner == "g7")
  {

    Serial.println("GREEN wins ! ");

    for (int i = 0; i < 5; i++)
      GREEN_WIN_7();

    winner_flag = true  ;
  }

  if (winner == "g8")
  {

    Serial.println("GREEN wins ! ");

    for (int i = 0; i < 5; i++)
      GREEN_WIN_8();

    winner_flag = true  ;
  }

  // ---------------------------------------------  It's a DRAW match
  if (winner == "0" && count == 9 )
  {
    Serial.println(" Draw match !! ") ;
    winner_flag = true ;
    for (int k = 0 ; k < 7 ; k++)
    {
      for (int i = 0; i < 3 ; i++)
      {
        for (int j = 0; j < 3; j++)
        {
          digitalWrite(G[i][j], HIGH);
          digitalWrite(R[i][j], HIGH);

        }
      }
      beep();
      for (int i = 0; i < 3 ; i++)
      {
        for (int j = 0; j < 3; j++)
        {
          digitalWrite(G[i][j], LOW);
          digitalWrite(R[i][j], LOW);

        }
      }
      beep();
    }
    Serial.println("resetting..");
    resett();
  }

  if (winner_flag == true )
  { Serial.println("resetting..");
    resett();
  }

}



// Checking if anyone won the match
String check ()
{

  // ---------------------------------------------  RED WINS
  if ( (tictac[0] + tictac[1] + tictac[2]) == 3 )
  {
    return "r1";
  }
  if ((tictac[3] + tictac[4] + tictac[5]) == 3 )
  {
    return "r2";
  }
  if ((tictac[6] + tictac[7] + tictac[8]) == 3 )
  {
    return "r3";
  }
  if ((tictac[0] + tictac[3] + tictac[6]) == 3 )
  {
    return "r4";
  }
  if ((tictac[1] + tictac[4] + tictac[7]) == 3 )
  {
    return "r5";
  }
  if ((tictac[2] + tictac[5] + tictac[8]) == 3 )
  {
    return "r6";
  }
  if ((tictac[0] + tictac[4] + tictac[8]) == 3 )
  {
    return "r7";
  }
  if ((tictac[2] + tictac[4] + tictac[6]) == 3 )
  {
    return "r8";
  }




  // ---------------------------------------------  GREEN WINS

  if ((tictac[0] + tictac[1] + tictac[2]) == 15 )
  {
    return "g1";
  }

  if ((tictac[3] + tictac[4] + tictac[5]) == 15 )
  {
    return "g2";
  }
  if ((tictac[6] + tictac[7] + tictac[8]) == 15 )
  {
    return "g3";
  }
  if ((tictac[0] + tictac[3] + tictac[6]) == 15 )
  {
    return "g4";
  }
  if ((tictac[1] + tictac[4] + tictac[7]) == 15 )
  {
    return "g5";
  }
  if ((tictac[2] + tictac[5] + tictac[8]) == 15 )
  {
    return "g6";
  }
  if ((tictac[0] + tictac[4] + tictac[8]) == 15 )
  {
    return "g7";
  }
  if ((tictac[2] + tictac[4] + tictac[6]) == 15 )
  {
    return "g8";
  }


  // --------------------------------------------- Now one WON Yet
  else
    return "0" ;

}



// ---------------------------------------------  Resetting the Board after the Games gets over
void resett()
{

  digitalWrite(RESET_PIN,LOW);

}


// ---------------------------------------------  Short Beep
void beep()
{
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
}

// ---------------------------------------------  Long Beep
void long_beep()
{
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);
}



// Below are the functions used for Flashing particular 3 boxes who won the match


void RED_WIN_1()
{
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(R[i][0], HIGH);
  }
  long_beep();
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(R[i][0], LOW);
  }
  delay(500);
}

void RED_WIN_2()
{
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(R[i][1], HIGH);
  }
  long_beep();
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(R[i][1], LOW);
  }
  delay(500);
}

void RED_WIN_3()
{
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(R[i][2], HIGH);
  }
  long_beep();
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(R[i][2], LOW);
  }
  delay(500);
}

void RED_WIN_4()
{
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(R[0][i], HIGH);
  }
  long_beep();
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(R[0][i], LOW);
  }
  delay(500);
}

void RED_WIN_5()
{
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(R[1][i], HIGH);
  }
  long_beep();
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(R[1][i], LOW);
  }
  delay(500);
}

void RED_WIN_6()
{
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(R[2][i], HIGH);
  }
  long_beep();
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(R[2][i], LOW);
  }
  delay(500);
}

void RED_WIN_7()
{
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(R[i][i], HIGH);
  }
  long_beep();
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(R[i][i], LOW);
  }
  delay(500);
}

void RED_WIN_8()
{
  for (int i = 0; i < 3 ; i++)
  {
    digitalWrite(R[i][2 - i], HIGH);
  }
  long_beep();
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(R[i][2 - i], LOW);
  }
  delay(500);
}







void GREEN_WIN_1()
{
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(G[i][0], HIGH);
  }
  long_beep();
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(G[i][0], LOW);
  }
  delay(500);
}

void GREEN_WIN_2()
{
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(G[i][1], HIGH);
  }
  long_beep();
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(G[i][1], LOW);
  }
  delay(500);
}

void GREEN_WIN_3()
{
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(G[i][2], HIGH);
  }
  long_beep();
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(G[i][2], LOW);
  }
  delay(500);
}

void GREEN_WIN_4()
{
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(G[0][i], HIGH);
  }
  long_beep();
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(G[0][i], LOW);
  }
  delay(500);
}

void GREEN_WIN_5()
{
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(G[1][i], HIGH);
  }
  long_beep();
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(G[1][i], LOW);
  }
  delay(500);
}

void GREEN_WIN_6()
{
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(G[2][i], HIGH);
  }
  long_beep();
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(G[2][i], LOW);
  }
  delay(500);
}

void GREEN_WIN_7()
{
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(G[i][i], HIGH);
  }
  long_beep();
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(G[i][i], LOW);
  }
  delay(500);
}

void GREEN_WIN_8()
{
  for (int i = 0; i < 3 ; i++)
  {
    digitalWrite(G[i][2 - i], HIGH);
  }
  long_beep();
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(G[i][2 - i], LOW);
  }
  delay(500);
}
