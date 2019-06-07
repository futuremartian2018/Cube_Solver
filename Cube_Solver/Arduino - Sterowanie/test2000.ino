#include <Stepper.h>

const int stepsPerRevolution = 200;  // ilość kroków na obrót
int a = 1;
int b = 2;
void turn(int x, int stepPin){
            if( x < 2){
            digitalWrite (stepPin,HIGH);
            delayMicroseconds (450);
            digitalWrite (stepPin,LOW);
            delayMicroseconds (450);
            }
            if( x < 4 && x >= 2 ){
            digitalWrite (stepPin,HIGH);
            delayMicroseconds (400);
            digitalWrite (stepPin,LOW);
            delayMicroseconds (400);
            }
            if( x < 6 && x >= 4){
            digitalWrite (stepPin,HIGH);
            delayMicroseconds (350);
            digitalWrite (stepPin,LOW);
            delayMicroseconds (350);
            }
            if( x < 8 && x >= 6 ){
            digitalWrite (stepPin,HIGH);
            delayMicroseconds (250);
            digitalWrite (stepPin,LOW);
            delayMicroseconds (250);
            }
            if( x < 192 && x >= 8 ){
            digitalWrite (stepPin,HIGH);
            delayMicroseconds (200);
            digitalWrite (stepPin,LOW);
            delayMicroseconds (200);
            }
            else if( x < 194 && x >= 192){
            digitalWrite (stepPin,HIGH);
            delayMicroseconds (250);
            digitalWrite (stepPin,LOW);
            delayMicroseconds (250);
            }
            else if( x < 196 && x >= 194){
            digitalWrite (stepPin,HIGH);
            delayMicroseconds (350);
            digitalWrite (stepPin,LOW);
            delayMicroseconds (350);
            }
            else if( x < 198 && x >= 196){
            digitalWrite (stepPin,HIGH);
            delayMicroseconds (350);
            digitalWrite (stepPin,LOW);
            delayMicroseconds (350);
            }
            else if( x < 200 && x >= 198){
            digitalWrite (stepPin,HIGH);
            delayMicroseconds (400);
            digitalWrite (stepPin,LOW);
            delayMicroseconds (400);
            }
               
            }

       void turn180(int x, int stepPin){
            if( x < 2){
            digitalWrite (stepPin,HIGH);
            delayMicroseconds (450);
            digitalWrite (stepPin,LOW);
            delayMicroseconds (450);
            }
            if( x < 4 && x >= 2 ){
            digitalWrite (stepPin,HIGH);
            delayMicroseconds (400);
            digitalWrite (stepPin,LOW);
            delayMicroseconds (400);
            }
            if( x < 6 && x >= 4){
            digitalWrite (stepPin,HIGH);
            delayMicroseconds (350);
            digitalWrite (stepPin,LOW);
            delayMicroseconds (350);
            }
            if( x < 8 && x >= 6 ){
            digitalWrite (stepPin,HIGH);
            delayMicroseconds (250);
            digitalWrite (stepPin,LOW);
            delayMicroseconds (250);
            }
            if( x < 392 && x >= 8 ){
            digitalWrite (stepPin,HIGH);
            delayMicroseconds (200);
            digitalWrite (stepPin,LOW);
            delayMicroseconds (200);
            }
            else if( x < 394 && x >= 392){
            digitalWrite (stepPin,HIGH);
            delayMicroseconds (250);
            digitalWrite (stepPin,LOW);
            delayMicroseconds (250);
            }
            else if( x < 396 && x >= 394){
            digitalWrite (stepPin,HIGH);
            delayMicroseconds (350);
            digitalWrite (stepPin,LOW);
            delayMicroseconds (350);
            }
            else if( x < 398 && x >= 396){
            digitalWrite (stepPin,HIGH);
            delayMicroseconds (350);
            digitalWrite (stepPin,LOW);
            delayMicroseconds (350);
            }
            else if( x < 400 && x >= 398){
            digitalWrite (stepPin,HIGH);
            delayMicroseconds (400);
            digitalWrite (stepPin,LOW);
            delayMicroseconds (400);
            }
             
            }     
  

// DEFINICJA PINÓW
  // Sinik 1 
    #define stepPin1  45
    #define dirPin1   43
    #define MS1  41
    #define EN1 39

  // Silnik 2
    #define stepPin2  24
    #define dirPin2   22
    #define MS2  25
    #define EN2 23

  // Silnik 3
    #define stepPin3  32
    #define dirPin3   30
    #define MS3  28
    #define EN3 26

  // Silnik 4
    #define stepPin4  48
    #define dirPin4   46 
    #define MS4  44
    #define EN4 42

  // Silnik 5
    #define stepPin5  40
    #define dirPin5   38 
    #define MS5  36
    #define EN5 34

  //SILNIK 6
    #define IN1 31
    #define IN2 33
    #define IN3 35
    #define IN4 37
    #define EN 29
    #define speedMotor 200
    Stepper myStepper2(stepsPerRevolution,IN4,IN3,IN2,IN1);
    int i =0;
 int c[] = {17,12,16,15,16,5,7,1,13,2,14,16,13,17,14,16,13,16,11,17,10,17,11,16,10,18,5,16,4,17,13,17,14,17,5,16,4,18,8,16,7,16,4,17,5,18,10,17,11,17,14,16,13,7,4,16,5,17,8,7,4,16,5,17,8,17,4,16,5,16,4,18,5,18,13,16,14,16,13,18,14,16,16,10,17,5,16,11,17,4,16,4,17,11,16,5,17,10,16,4,17,11,16,5,17,10,14,2,13,1,14,2,13,1,17,14,2,13,1,14,2,13,1,17,17,14,2,13,1,14,2,13,1,17};
void setup() {
  // USTAWIANIE PINÓW
    // SILNIK 1
      pinMode (stepPin1,OUTPUT);
      pinMode (dirPin1,OUTPUT);
      pinMode (MS1,OUTPUT);
      pinMode (EN1,OUTPUT);
      digitalWrite (MS1,HIGH);
      digitalWrite (EN1,HIGH);

    // SILNIK 2
      pinMode (stepPin2,OUTPUT);
      pinMode (dirPin2,OUTPUT);
      pinMode (MS2,OUTPUT);
      pinMode (EN2,OUTPUT);
      digitalWrite (MS2,HIGH);
      digitalWrite (EN2,HIGH);

    // SILNIK 3
      pinMode (stepPin3,OUTPUT);
      pinMode (dirPin3,OUTPUT);
      pinMode (MS3,OUTPUT);
      pinMode (EN3,OUTPUT);
      digitalWrite (MS3,HIGH);
      digitalWrite (EN3,HIGH);

     // SILNIK 4
      pinMode (stepPin4,OUTPUT);
      pinMode (dirPin4,OUTPUT);
      pinMode (MS4,OUTPUT);
      pinMode (EN4,OUTPUT);
      digitalWrite (MS4,HIGH);
      digitalWrite (EN4,HIGH);

     // SILNIK 5
      pinMode (stepPin5,OUTPUT);
      pinMode (dirPin5,OUTPUT);
      pinMode (MS5,OUTPUT);
      pinMode (EN5,OUTPUT);
      digitalWrite (MS5,HIGH);
      digitalWrite (EN5,HIGH);

     //SILNIK 6
      myStepper2.setSpeed(speedMotor); //Prędkość silnika
      Serial.begin(9600);
      pinMode(EN,OUTPUT);
      digitalWrite(EN,LOW); 
      delay(7000);
}

void loop() {
  // RUCH SILNIKÓW
    // SILNIK 1
 
 
   if(c[i] == 0)
   {
    digitalWrite (EN1,HIGH);
    digitalWrite (EN2,HIGH);
    digitalWrite (EN3,HIGH);
    digitalWrite (EN4,HIGH);
    digitalWrite (EN5,HIGH);
    digitalWrite(EN,LOW); 
   }



  else if(c[i] >0){
    
      if(c[i] == 1)
      {
        digitalWrite (EN1,LOW);
        digitalWrite ( dirPin1, HIGH ) ;
        for ( int x = 0 ; x < 200 ; x ++ ) 
        {
          turn(x, stepPin1);
         
        }
        delay(a);
        digitalWrite (EN1,HIGH);
      }
      else if(c[i] == 2)
      {
        digitalWrite (EN1,LOW);
        digitalWrite ( dirPin1, LOW ) ;
        for ( int x = 0 ; x < 200 ; x ++ ) 
        { 
         turn(x, stepPin1);
         
        }
        delay(a);
        
        digitalWrite (EN1,HIGH);
      }
      else if(c[i] == 3)
      {
        digitalWrite (EN1,LOW);
        digitalWrite ( dirPin1, HIGH ) ;
        for ( int x = 0 ; x < 400 ; x ++ ) 
        { 
          turn180(x, stepPin1);
          
        }
        delay(b);
        digitalWrite (EN1,HIGH);
      }
      // SILNIK 2
      else if(c[i] == 4)
      {
        digitalWrite (EN2,LOW);
        digitalWrite ( dirPin2, HIGH ) ;
        for ( int x = 0 ; x < 200 ; x ++ ) 
        { 
         turn(x, stepPin2);
        }
        delay(a);
        digitalWrite (EN2,HIGH);
      }
      else if(c[i] == 5)
      {
        digitalWrite (EN2,LOW);
        digitalWrite ( dirPin2, LOW ) ;
        for ( int x = 0 ; x < 200 ; x ++ ) 
        { 
          turn(x, stepPin2);
        }
        delay(a);
        digitalWrite (EN2,HIGH);
      }
      else if(c[i] == 6)
      {
        digitalWrite (EN2,LOW);
        digitalWrite ( dirPin2, HIGH ) ;
        for ( int x = 0 ; x < 400 ; x ++ ) 
        { 
          turn180(x, stepPin2);
        }
        delay(b);
        digitalWrite (EN2,HIGH);
      } 
    // SILNIK 3
      else if(c[i] == 7)
      {
        digitalWrite (EN3,LOW);
        digitalWrite ( dirPin3, LOW ) ;
        for ( int x = 0 ; x < 200 ; x ++ ) 
        { 
          turn(x, stepPin3);
        }
        delay(a);
        digitalWrite (EN3,HIGH);
      }
      else if(c[i] == 8)
      {
        digitalWrite (EN3,LOW);
        digitalWrite ( dirPin3, HIGH ) ;
        for ( int x = 0 ; x < 200 ; x ++ ) 
        { 
          turn(x, stepPin3);
        }
        delay(a);
        digitalWrite (EN3,HIGH);
      }
      else if(c[i] == 9)
      {
        digitalWrite (EN3,LOW);
        digitalWrite ( dirPin3, HIGH ) ;
        for ( int x = 0 ; x < 400 ; x ++ ) 
        { 
          turn180(x, stepPin3);
        }
        delay(b);
        digitalWrite (EN3,HIGH);
      } 
     // SILNIK 4
      else if(c[i] == 10)
      {
        digitalWrite (EN4,LOW);
        digitalWrite ( dirPin4, HIGH ) ;
        for ( int x = 0 ; x < 200 ; x ++ ) 
        { 
          turn(x, stepPin4);
        }
        delay(a);
        digitalWrite (EN4,HIGH);
      }
      else if(c[i] == 11)
      {
        digitalWrite (EN4,LOW);
        digitalWrite ( dirPin4, LOW ) ;
        for ( int x = 0 ; x < 200 ; x ++ ) 
        { 
          turn(x, stepPin4);
        }
        delay(a);
        digitalWrite (EN4,HIGH);
      }
      else if(c[i] == 12)
      {
        digitalWrite (EN4,LOW);
        digitalWrite ( dirPin4, HIGH ) ;
        for ( int x = 0 ; x < 400 ; x ++ ) 
        { 
          turn180(x, stepPin4);
        }
        delay(b);
        digitalWrite (EN4,HIGH);
      } 
     // SILNIK 5
      else if(c[i] == 13)
      {
        digitalWrite (EN5,LOW);
        digitalWrite ( dirPin5, LOW ) ;
        for ( int x = 0 ; x < 200 ; x ++ ) 
        { 
          turn(x, stepPin5);
        }
        delay(a);
        digitalWrite (EN5,HIGH);
      }
      else if(c[i] == 14)
      {
        digitalWrite (EN5,LOW);
        digitalWrite ( dirPin5, HIGH ) ;
        for ( int x = 0 ; x < 200 ; x ++ ) 
        { 
          turn(x, stepPin5);
        }
        delay(a);
        digitalWrite (EN5,HIGH);
      }
      else if(c[i] == 15)
      {
        digitalWrite (EN5,LOW);
        digitalWrite ( dirPin5, HIGH ) ;
        for ( int x = 0 ; x < 400 ; x ++ ) 
        { 
          turn180(x, stepPin5);
        }
        delay(b);
        digitalWrite (EN5,HIGH);
      } 
      else if(c[i] == 16)
      {
        digitalWrite(EN,HIGH);
        myStepper2.step(-50);
        digitalWrite(EN,LOW);      
        delay(a);
      }
      else if(c[i] == 17)
      {
        digitalWrite(EN,HIGH);
        myStepper2.step(50);
        digitalWrite(EN,LOW);
        delay(a);      
      }
      else if(c[i] == 18)
      {
        digitalWrite(EN,HIGH);
        myStepper2.step(100);
        digitalWrite(EN,LOW);      
        delay(b);
      }
      i++;

  }
}
