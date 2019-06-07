#include "Kostka.h"
#include <stdio.h>
//#include <stddef.h>

class Algorytm{         // klasa algorytm - rozwiązująca kostkę
private: 
      static int tablica_k1[2];  // tablica przechowująca położenie układanego pola kostki
      static int tablica_k2[4]; // tablica przechowująca położenie pól znajdujących się na dolnej ściance  
      static int suma;  // suma ułożonych pół na dolnej ściance potrzebnych do ułożenia krzyża
      static int paramter;
      static int par2; // parametr do układania rogów dolnej ścianki 
public:
    

   static void solve(Kostka*& model) {         // metoda układająca kostkę

  
        //Krok 1  - ulozenie krzyza na scianie gornej
           for(int i = 0; i < 6; i++ ){          
                for(int j = 0 ; j < 9; j++){
                    if(model -> getKostka(i,j) == 2){  
                        if(i==0 && j==1){        //sprawdzenie pozycji pierwszego kwadratu
                    tablica_k1[0] = 64;
                    
                      tablica_k1[1]=64;
                      
                        }
                        else {
                        tablica_k1[0]=i;        // przypisanie współrzędnych kwadratu 1 do pól tablicy 
                        
                       tablica_k1[1]=j;
                        
                        }
                    }
                }
            }

      
   
                   if(tablica_k1[0] == 64){  // początek układania pierwszego kwadratu 

                         for(int i = 0; i < 6; i++ ){          
							 for(int j = 0 ; j < 9; j++){
								 if(model -> getKostka(i,j) == 4){  
									if(i==0 && j==3){        //sprawdzenie pozycji trzeciego kwadratu
									tablica_k1[0]=64;
									tablica_k1[1]=64;
									}
									else {
									tablica_k1[0]=i;        // przypisanie współrzędnych kwadratu 3 do pól tablicy 
									tablica_k1[1]=j;
                        
									}

								 }
							 }
						 }
                    
				   }


                    else if(tablica_k1[0] != 64){
                        if(tablica_k1[0] == 5 && tablica_k1[1] == 1){  //przeniesienia kwadratu 1 na górną ścianę w zależności od jego pozycji 
                            model -> D180();                            // gdy znajduje się na ścianie dolnej - numer 5
                            model -> B180();
                        }
                        else if(tablica_k1[0] == 5 && tablica_k1[1] ==3 ){
                            model -> Dprim();
                            model -> B180();
                        }
                        else if(tablica_k1[0] == 5 && tablica_k1[1] == 5){
                            model -> D();
                            model -> B180();
                        }
                        else if(tablica_k1[0] ==5 && tablica_k1[1] == 7){
                            model -> B180();
                        }

                        else if(tablica_k1[0] == 1 && tablica_k1[1] == 7){   // gdy znajduje się w dolnym położeniu ściany przedniej
                            model -> D();
                            model -> L();
                            model -> Rprim();
                            model -> B();
                            model -> Lprim();
                            model -> R();
                        }

                        else if(tablica_k1[0] == 2 && tablica_k1[1] == 7){  // gdy znajduje się w dolnym położeniu ściany prawej
                            model -> L();
                            model -> Rprim();
                            model -> B();
                            model -> Lprim();
                            model -> R();
                        }
                        else if(tablica_k1[0] == 3 && tablica_k1[1] == 7){ // gdy znajduje się w dolnym położeniu ściany tylnej
                            model -> Dprim();
                            model -> L();
                            model -> Rprim();
                            model -> B();
                            model -> Lprim();
                            model -> R();
                        }
                        else if(tablica_k1[0] == 4 && tablica_k1[1] == 7){  // gdy znajduje się w dolnym położeniu ściany lewej

                            model -> L();
                            model -> Rprim();
                            model -> Bprim();
                            model -> Lprim();
                            model -> R();
                        }

                        else if(tablica_k1[0] == 1 && tablica_k1[1] == 5){ // gdy znajduje się po prawej stronie przedniej ściany
                            model -> R();
                            model -> Uprim();
                        }
                        else if(tablica_k1[0] == 2 && tablica_k1[1] == 5){ // gdy znajduje się po prawej stronie prawej ściany
                            model -> B();
                        }
                         else if(tablica_k1[0] == 3 && tablica_k1[1] == 5){ // gdy znajduje się po prawej stronie tylnej ściany
                            model -> L();
                            model -> U();
                        }
                         else if(tablica_k1[0] == 4 && tablica_k1[1] == 5){ // gdy znajduje się po prawej stronie lewj ściany
                            model -> F();
                            model ->U180();
                        }
                         else if(tablica_k1[0] == 1 && tablica_k1[1] == 3){ // gdy znajduje się po lewej stronie przedniej ściany
                            model -> Lprim();
                            model -> U();
                        }
                        else  if(tablica_k1[0] == 2 && tablica_k1[1] == 3){ // gdy znajduje się po lewej stronie prawej ściany
                           model -> Fprim();
                           model -> U180();
                           }
                        else if(tablica_k1[0] == 3 && tablica_k1[1] == 3){ // gdy znajduje się po lewej stronie tylnej ściany
                           model -> Rprim();
                           model -> Uprim();
                           }
                        else if(tablica_k1[0] == 4 && tablica_k1[1] == 3){ // gdy znajduje się po lewej stronie lewej ściany
                           model -> Bprim();
                           }
                        else if(tablica_k1[0] == 1 && tablica_k1[1] == 1){ // gdy znajduje się w górnym położeniu przedniej ściany
                          model -> Fprim();
                          model -> Lprim();
                          model -> U();
                           }
                        else if(tablica_k1[0] == 2 && tablica_k1[1] == 1){ // gdy znajduje się w górnym położeniu prawej ściany
                          model -> R();
                          model -> B();
                           }
                        else if(tablica_k1[0] == 3 && tablica_k1[1] == 1){ // gdy znajduje się w górnym położeniu tylnej ściany
                         model -> Bprim();
                         model -> Rprim();
                         model -> Uprim();
                           }
                        else if(tablica_k1[0] == 4 && tablica_k1[1] == 1){ // gdy znajduje się w górnym położeniu lewej ściany
                         model -> Lprim();
                         model -> Bprim();
                           }


                        else if(tablica_k1[0] == 0 && tablica_k1[1] == 3){ // gdy znajduje się na górnej ściance w polu 3
                          model -> U();
                           }  
                          
                        else if(tablica_k1[0] == 0 && tablica_k1[1] == 5){ // gdy znajduje się na górnej ściance w polu 5
                          model -> Uprim();
                           }   
                           
                        else if(tablica_k1[0] == 0 && tablica_k1[1] == 7){ // gdy znajduje się na górnej ściance w polu 7
                          model -> U180();
                           }  

  //Serial.printf("\n ");
                            for(int j=0; j<6 ; j++){
                        for(int i=0 ; i < 9; i++){
                            // Serial.printf("%d   ",model -> getKostka(j,i));
                            
                        }
                     //   Serial.printf("\n ");}
               // Serial.printf("\n przed ulozeniem 1");
               
               // Serial.printf("\n ");
               // Serial.printf("%d\n", tablica_k1[0]);
               // Serial.printf("%d\n", tablica_k1[1]);
                                

                         for(int i = 0; i < 6; i++ ){          
                            for(int j = 0 ; j < 9; j++){
                             if(model -> getKostka(i,j) == 4){  
                        if(i==0 && j==3){        //sprawdzenie pozycji trzeciego kwadratu
                        tablica_k1[0]=64;
                        tablica_k1[1]=64;
                        }
                        else {
                        tablica_k1[0]=i;        // przypisanie współrzędnych kwadratu 3 do pól tablicy 
                        tablica_k1[1]=j;
                        
                        }
                             }
                            }
                         }

                
                        
                    } // koniec pierwszego klocka
//for(int j=0; j<6 ; j++){
                       // for(int i=0 ; i < 9; i++){
                           //  Serial.printf("%d   ",model -> getKostka(j,i));
                            
                       // }
                       // Serial.printf("\n ");}
           //    Serial.printf("\n pole 4 polozenie");
               // Serial.printf("\n ");
/*Serial.printf("%d\n ", tablica_k1[0]);
Serial.printf("%d\n ", tablica_k1[1]);
Serial.printf("\n ");*/
                     

                    if(tablica_k1[0] == 64){ // początek układaniua kwadratu 3
                          

                         for(int i = 0; i < 6; i++ ){          
                             for(int j = 0 ; j < 9; j++){
                                if(model -> getKostka(i,j) == 6){  
                                 if(i==0 && j==5){        //sprawdzenie pozycji piątego kwadratu
                                tablica_k1[0]=64;
                                tablica_k1[1]=64;
                            }
                                else {
                              tablica_k1[0]=i;        // przypisanie współrzędnych kwadratu 5 do pól tablicy 
                              tablica_k1[1]=j;
                        
                        }
                    }
                }
                         }
                    }
                 else if(tablica_k1[0] != 64){
                      if(tablica_k1[0] == 5 && tablica_k1[1] == 1){  //przeniesienia kwadratu 3 na górną ścianę w zależności od jego pozycji 
                            model -> Dprim()     ;                     // gdy znajduje się na ścianie dolnej - numer 5
                            model -> L180();
                        }
                        else if(tablica_k1[0] == 5 && tablica_k1[1] ==3 ){
                            
                            model -> L180();
                        }
                        else if(tablica_k1[0] == 5 && tablica_k1[1] == 5){
                            model -> D180();
                            model -> L180();
                        }
                        else if(tablica_k1[0] ==5 && tablica_k1[1] == 7){
                            model -> D();
                            model -> L180();
                        }

                        else if(tablica_k1[0] == 1 && tablica_k1[1] == 7){   // gdy znajduje się w dolnym położeniu ściany przedniej
                            model -> F();
                            model -> Lprim();
                        }

                        else if(tablica_k1[0] == 2 && tablica_k1[1] == 7){  // gdy znajduje się w dolnym położeniu ściany prawej
                            model -> Dprim();
                            model -> F();
                            model -> Lprim();
                        }
                        else if(tablica_k1[0] == 3 && tablica_k1[1] == 7){ // gdy znajduje się w dolnym położeniu ściany tylnej
                            model -> D180();
                            model -> F();
                            model -> Lprim();
                            
                        }
                        else if(tablica_k1[0] == 4 && tablica_k1[1] == 7){  // gdy znajduje się w dolnym położeniu ściany lewej

                            model -> D();
                            model -> F();
                            model -> Lprim();
                        }

                        else if(tablica_k1[0] == 1 && tablica_k1[1] == 5){ // gdy znajduje się po prawej stronie przedniej ściany
                            model -> F180();
                            model -> Lprim(); 
                        }
                        else if(tablica_k1[0] == 2 && tablica_k1[1] == 5){ // gdy znajduje się po prawej stronie prawej ściany
                            model -> B();
                            model -> Uprim();
                            model -> Bprim();


                        }
                        else  if(tablica_k1[0] == 3 && tablica_k1[1] == 5){ // gdy znajduje się po prawej stronie tylnej ściany
                            model -> L();
                        }
                        else  if(tablica_k1[0] == 4 && tablica_k1[1] == 5){ // gdy znajduje się po prawej stronie lewj ściany
                            model -> Uprim();
                            model -> F();
                            model -> U();
                        }
                        else if(tablica_k1[0] == 1 && tablica_k1[1] == 3){ // gdy znajduje się po lewej stronie przedniej ściany
                            model -> Lprim();
                            
                        }
                        else if(tablica_k1[0] == 2 && tablica_k1[1] == 3){ // gdy znajduje się po lewej stronie prawej ściany
                           model -> Uprim();
                           model -> Fprim();
                           model -> U();
                           }
                        else if(tablica_k1[0] == 3 && tablica_k1[1] == 3){ // gdy znajduje się po lewej stronie tylnej ściany
                           model -> U();
                           model -> B180();
                           model -> Uprim();
                           model -> L();
                           }
                        else if(tablica_k1[0] == 4 && tablica_k1[1] == 3){ // gdy znajduje się po lewej stronie lewej ściany
                           model -> U();
                           model -> Bprim();
                           model -> Uprim();
                           }
                        else if(tablica_k1[0] == 1 && tablica_k1[1] == 1){ // gdy znajduje się w górnym położeniu przedniej ściany
                          model -> Fprim();
                          model -> Lprim();
                          
                           }
                        else if(tablica_k1[0] == 2 && tablica_k1[1] == 1){ // gdy znajduje się w górnym położeniu prawej ściany
                          model -> Rprim();
                          model -> Uprim();
                          model -> Fprim();
                          model -> U();
                           }
                       //jest niemożliwym aby ten kwadrat znajdował się w górnym położeniu tylnej ściany, ponieważ na górnej ścianie znajduje się
                       // kwadrat numer 1
                        else if(tablica_k1[0] == 4 && tablica_k1[1] == 1){ // gdy znajduje się w górnym położeniu lewej ściany
                         model -> L();
                         model -> Uprim();
                         model -> F();
                         model -> U();
                           }
                          
                        else if(tablica_k1[0] == 0 && tablica_k1[1] == 5){ // gdy znajduje się na górnej ściance w polu 5
                         model -> R180();
                         model -> D180();
                         model -> L180();
                           }   
                           
                        else if(tablica_k1[0] == 0 && tablica_k1[1] == 7){ // gdy znajduje się na górnej ściance w polu 7
                        model -> F180();
                        model -> Dprim();
                        model -> L180();
                           }  


                                

                         for(int i = 0; i < 6; i++ ){          
                            for(int j = 0 ; j < 9; j++){
                             if(model -> getKostka(i,j) == 6){  
                        if(i==0 && j==5){        //sprawdzenie pozycji piątego kwadratu
                        tablica_k1[0]=64;
                        tablica_k1[1]=64;
                        }
                        else {
                        tablica_k1[0]=i;        // przypisanie współrzędnych kwadratu 5 do pól tablicy 
                        tablica_k1[1]=j;
                        
                        }
                             }
                            }
                         }
                    
                 } // koniec pola numer 3
   /* Serial.printf("\n ");
                            for(int j=0; j<6 ; j++){
                        for(int i=0 ; i < 9; i++){
                             Serial.printf("%d   ",model -> getKostka(j,i));
                            
                        }
                        Serial.printf("\n ");}
                Serial.printf("\n po ulozeniu  ulozeniem szosteczki");
                  Serial.printf("%d\n ", tablica_k1[0]);
                 Serial.printf("%d\n ", tablica_k1[1]);
                Serial.printf("\n ");*/
//for(int j=0; j<6 ; j++){
                   //     for(int i=0 ; i < 9; i++){
                       //      Serial.printf("%d   ",model -> getKostka(j,i));
                            
                        }
                       /* Serial.printf("\n ");}
               Serial.printf("\npo czworeczce");
                Serial.printf("\n ");
Serial.printf("%d\n ", tablica_k1[0]);
Serial.printf("%d\n ", tablica_k1[1]);
Serial.printf("\n ");*/

                    if(tablica_k1[0] == 64){ // początek układaniua kwadratu 5

                                for(int i = 0; i < 6; i++ ){          
                            for(int j = 0 ; j < 9; j++){
                             if(model -> getKostka(i,j) == 8){  
                        if(i==0 && j==1){        //sprawdzenie pozycji siódmego kwadratu
                        tablica_k1[0]=64;
                        tablica_k1[1]=64;
                        }
                        else {
                        tablica_k1[0]=i;        // przypisanie współrzędnych kwadratu 7 do pól tablicy 
                        tablica_k1[1]=j;
                        
                        }
                             }
                            }
                         }

                    }
                    else if(tablica_k1[0] != 64){
                        if(tablica_k1[0] == 0 && tablica_k1[1] == 7 ){
                            model -> F180();
                            model -> D();
                            model -> R180();
                        }
                        else if(tablica_k1[0] == 5 && tablica_k1[1] == 1){  //przeniesienia kwadratu 5 na górną ścianę w zależności od jego pozycji 
                            model -> D() ;                     // gdy znajduje się na ścianie dolnej - numer 5
                            model -> R180();
                        }
                        else if(tablica_k1[0] == 5 && tablica_k1[1] ==3 ){
                            model -> D180();
                            model -> R180();
                        }
                        else if(tablica_k1[0] == 5 && tablica_k1[1] == 5){
                         
                            model -> R180();
                        }
                        else if(tablica_k1[0] == 5 && tablica_k1[1] == 7){
                            model -> Dprim();
                            model -> R180();
                        }

                        else if(tablica_k1[0] == 1 && tablica_k1[1] == 7){   // gdy znajduje się w dolnym położeniu ściany przedniej
                            model -> Fprim();
                            model -> R();
                        }

                        else if(tablica_k1[0] == 2 && tablica_k1[1] == 7){  // gdy znajduje się w dolnym położeniu ściany prawej
                            model -> Dprim();
                            model -> Fprim();
                            model -> R();
                        }
                        else if(tablica_k1[0] == 3 && tablica_k1[1] == 7){ // gdy znajduje się w dolnym położeniu ściany tylnej
                            model -> D180();
                            model -> Fprim();
                            model -> R();
                            
                        }
                        else if(tablica_k1[0] == 4 && tablica_k1[1] == 7){  // gdy znajduje się w dolnym położeniu ściany lewej

                            model -> D();
                            model -> Fprim();
                            model -> R();
                        }

                        else if(tablica_k1[0] == 1 && tablica_k1[1] == 5){ // gdy znajduje się po prawej stronie przedniej ściany
                          model -> R();

                        }

                        else if(tablica_k1[0] == 2 && tablica_k1[1] == 5){ // gdy znajduje się po prawej stronie prawej ściany
                            model -> Uprim();
                            model -> B();
                            model -> U();


                        }
                        else  if(tablica_k1[0] == 3 && tablica_k1[1] == 5){ // gdy znajduje się po prawej stronie tylnej ściany
                            model -> U180();
                            model -> L();
                            model -> U180();
                        }
                        else if(tablica_k1[0] == 4 && tablica_k1[1] == 5){ // gdy znajduje się po prawej stronie lewj ściany
                            model -> U();
                            model -> F();
                            model -> Uprim();
                        }
                        else if(tablica_k1[0] == 1 && tablica_k1[1] == 3){ // gdy znajduje się po lewej stronie przedniej ściany
                            model -> U180();
                            model -> Lprim();
                            model -> U180();
                            
                        }
                        else if(tablica_k1[0] == 2 && tablica_k1[1] == 3){ // gdy znajduje się po lewej stronie prawej ściany
                           model -> U();
                           model -> Fprim();
                           model -> Uprim();
                           }
                        else if(tablica_k1[0] == 3 && tablica_k1[1] == 3){ // gdy znajduje się po lewej stronie tylnej ściany
                           model -> Rprim();
                           }
                        else if(tablica_k1[0] == 4 && tablica_k1[1] == 3){ // gdy znajduje się po lewej stronie lewej ściany
                           model -> Uprim();
                           model -> Bprim();
                           model -> U();
                           }
                        else if(tablica_k1[0] == 1 && tablica_k1[1] == 1){ // gdy znajduje się w górnym położeniu przedniej ściany
                         model -> F();
                         model -> R();
                          
                           }
                        else if(tablica_k1[0] == 2 && tablica_k1[1] == 1){ // gdy znajduje się w górnym położeniu prawej ściany
                          model -> R();
                          model -> Uprim();
                          model -> B();
                          model -> U();
                           }
                       //jest niemożliwym aby ten kwadrat znajdował się w górnym położeniu tylnej ściany, ponieważ na górnej ścianie znajduje się
                       // kwadrat numer 1
                        
                          //jest niemożliwym aby ten kwadrat znajdował się w górnym położeniu lewej ściany, ponieważ na górnej ścianie znajduje się
                       // kwadrat numer 3
                          
                      //jeżeli kwadrat znajdowałby się w położeniu 5 instrukcja nie zostałaby wykonana
                           
                       else if(tablica_k1[0] == 0 && tablica_k1[1] == 7){ // gdy znajduje się na górnej ściance w polu 7
                       model -> F();
                       model -> U();
                       model -> Fprim();
                       model -> Uprim();
                           } 



                        for(int i = 0; i < 6; i++ ){          
                            for(int j = 0 ; j < 9; j++){
                             if(model -> getKostka(i,j) == 8){  
                        if(i==0 && j==1){        //sprawdzenie pozycji siódmego kwadratu
                        tablica_k1[0]=64;
                        tablica_k1[1]=64;
                        }
                        else {
                        tablica_k1[0]=i;        // przypisanie współrzędnych kwadratu 7 do pól tablicy 
                        tablica_k1[1]=j;
                        
                        }
                             }
                            }
                         }

                      
                         

                    } // koniec układania kwadratu 5


                        if(tablica_k1[0]  == 64){ // początek układania kwadratu 7

                        }
                        else if(tablica_k1[1] != 64){

                        if(tablica_k1[0] == 5 && tablica_k1[1] == 1){  //przeniesienia kwadratu 7 na górną ścianę w zależności od jego pozycji 
                            model -> F180();                    // gdy znajduje się na ścianie dolnej - numer 5
                            
                        }
                        if(tablica_k1[0] == 5 && tablica_k1[1] ==3 ){
                            model -> D();
                            model -> F180();
                        }
                        else if(tablica_k1[0] == 5 && tablica_k1[1] == 5){
                            model -> Dprim();
                            model -> F180();
                        }
                        else if(tablica_k1[0] == 5 && tablica_k1[1] == 7){
                            model -> D180();
                            model -> F180();
                        }

                        else if(tablica_k1[0] == 1 && tablica_k1[1] == 7){   // gdy znajduje się w dolnym położeniu ściany przedniej
                            model -> Dprim();
                            model -> Lprim();
                            model -> F();
                            model -> L();
                        }

                        else if(tablica_k1[0] == 2 && tablica_k1[1] == 7){  // gdy znajduje się w dolnym położeniu ściany prawej
                            model -> R();
                            model -> Fprim();
                            model -> Rprim();
                        }
                        else if(tablica_k1[0] == 3 && tablica_k1[1] == 7){ // gdy znajduje się w dolnym położeniu ściany tylnej
                            model -> Dprim();
                            model -> R();
                            model -> Fprim();
                            model -> Rprim();
                            }
                        else if(tablica_k1[0] == 4 && tablica_k1[1] == 7){  // gdy znajduje się w dolnym położeniu ściany lewej
                            model -> Lprim();
                            model -> F();
                            model -> L();
                        }

                        else if(tablica_k1[0] == 1 && tablica_k1[1] == 5){ // gdy znajduje się po prawej stronie przedniej ściany
                          model -> Uprim();
                          model -> R();
                          model -> U();
                           }

                        else if(tablica_k1[0] == 2 && tablica_k1[1] == 5){ // gdy znajduje się po prawej stronie prawej ściany
                           model -> U180();
                           model -> B();
                           model -> U180();
                            }
                        else if(tablica_k1[0] == 3 && tablica_k1[1] == 5){ // gdy znajduje się po prawej stronie tylnej ściany
                            model -> U();
                            model -> L();
                            model -> Uprim();
                        }
                        else if(tablica_k1[0] == 4 && tablica_k1[1] == 5){ // gdy znajduje się po prawej stronie lewj ściany
                            model -> F();
                        }
                        else if(tablica_k1[0] == 1 && tablica_k1[1] == 3){ // gdy znajduje się po lewej stronie przedniej ściany
                            model -> U();
                            model -> Lprim();
                            model -> Uprim();
                            }
                        else if(tablica_k1[0] == 2 && tablica_k1[1] == 3){ // gdy znajduje się po lewej stronie prawej ściany
                           model -> Fprim();
                           }
                        else if(tablica_k1[0] == 3 && tablica_k1[1] == 3){ // gdy znajduje się po lewej stronie tylnej ściany
                           model -> Uprim();
                           model -> Rprim();
                           model -> U();
                           }
                        else if(tablica_k1[0] == 4 && tablica_k1[1] == 3){ // gdy znajduje się po lewej stronie lewej ściany
                           model -> U180();
                           model -> Bprim();
                           model -> U180();
                           }
                        else if(tablica_k1[0] == 1 && tablica_k1[1] == 1){ // gdy znajduje się w górnym położeniu przedniej ściany
                         model -> F();
                         model -> Uprim();
                         model -> R();
                         model -> U();
                          
                           }
                       


                       //jest niemożliwym aby ten kwadrat znajdował się w górnym położeniu tylnej ściany, ponieważ na górnej ścianie znajduje się
                       // kwadrat numer 1
                        
                          //jest niemożliwym aby ten kwadrat znajdował się w górnym położeniu lewej ściany, ponieważ na górnej ścianie znajduje się
                       // kwadrat numer 3
                          
                      //jest niemożliwym aby tetn kwadrat znajdował się w górnym polożeniu prawej ściany, ponieważ na górnej ścianie znajduje się
                      // kwadrat numer 5 
                           
                    // jeżeli kwadrat znajdował się górnym położeniu 7 algorytm nie zostałby wykonany

                        } // koiec układania kwadratu 7

                     

 // koniec  układania krzyża na górnej ściance 
                // Układanie rogów górnej ścianki --- METODA LBL


// układanie rogu  numer jeden 


                         for(int i = 0; i < 6; i++ ){          
                for(int j = 0 ; j < 9; j++){
                   
                    if(model -> getKostka(i,j) == 1){  
                        if(i==0 && j==0){        //sprawdzenie pozycji pierwszego kwadratu
                    tablica_k1[0] = 64;
                    
                      tablica_k1[1]=64;
                      
                        }
                        else {
                        tablica_k1[0]=i;        // przypisanie współrzędnych kwadratu 0 do pól tablicy 
                        
                       tablica_k1[1]=j;
                        
                        }
                    }
                }
            }
                 

  //Serial.printf("\n ");
                    /*        for(int j=0; j<6 ; j++){
                        for(int i=0 ; i < 9; i++){
                            // Serial.printf("%d   ",model -> getKostka(j,i));
                            
                        }*/
                       /* Serial.printf("\n ");}
                Serial.printf("\n przed ulozeniem 1");
               
                Serial.printf("\n ");
                Serial.printf("%d\n", tablica_k1[0]);
                Serial.printf("%d\n", tablica_k1[1]);*/
                 


                if(tablica_k1[0] == 64){
                         
                            for(int i = 0; i < 6; i++ ){          
                for(int j = 0 ; j < 9; j++){
                    if(model -> getKostka(i,j) == 3){  
                        if(i==0 && j==2){        //sprawdzenie pozycji trzeciego kwadratu
                    tablica_k1[0] = 64;
                    
                      tablica_k1[1]=64;
                      
                        }
                        else {
                        tablica_k1[0]=i;        // przypisanie współrzędnych kwadratu 2 do pól tablicy 
                        
                       tablica_k1[1]=j;
                        
                        }
                    }
                }
            }

                  

                 }         

            else if(tablica_k1[1] != 64){
                    if(tablica_k1[0] == 0 && tablica_k1[1] == 2 ){
                            model -> Bprim();
                            model -> Dprim();
                            model -> B();
                            model -> U();
                            model -> Bprim();
                            model -> D();
                            model -> B();
                            model -> Uprim();


                    }
                    else if(tablica_k1[0] == 0 && tablica_k1[1] == 6){
                        model -> Fprim();
                        model -> D();
                        model -> F();
                        model -> B();
                        model -> Dprim();
                        model -> Bprim();
                    }

                    else if(tablica_k1[0] == 0 && tablica_k1[1] == 8){
                        model -> Rprim();
                        model -> D();
                        model -> R();
                        model -> B();
                        model -> D180();
                        model -> Bprim();
                    }

                    else if(tablica_k1[0] == 1 && tablica_k1[1] == 0){
                        model -> Fprim();
                        model -> B();
                        model -> Dprim();
                        model -> Bprim();
                        model -> F();
                    }
                    else if(tablica_k1[0] == 1 && tablica_k1[1] == 2){
                        model -> F();
                        model -> D();
                        model -> Fprim();
                        model -> Lprim();
                        model -> D();
                        model -> L();
                    }
                    else if(tablica_k1[0] == 1 && tablica_k1[1] == 6){
                        model -> B();
                        model -> Dprim();
                        model -> Bprim();
                    }
             
                    else if(tablica_k1[0] == 1 && tablica_k1[1] == 8){
                         model -> Lprim();
                         model -> D180();
                         model -> L();
                    }

                    else if(tablica_k1[0] == 2 && tablica_k1[1] == 0){
                         model -> Rprim();
                         model -> Dprim();
                         model -> R(); 
                         model -> B();
                         model -> Dprim();
                         model -> Bprim();
                    }
                    
                    else if(tablica_k1[0] == 2 && tablica_k1[1] == 2){
                        model -> Bprim();
                        model -> D();
                        model -> B();
                        model -> Lprim();
                        model -> D();
                        model -> L();
                    }

                    else if(tablica_k1[0] == 2 && tablica_k1[1] == 6){
                        model -> D180();
                        model -> Lprim();
                        model -> Dprim();
                        model -> L();
                    }

                    else if(tablica_k1[0] == 2 && tablica_k1[1] == 8 ){
                        model -> Lprim();
                        model -> D();
                        model -> L();
                    }
                    else if(tablica_k1[0] == 3 && tablica_k1[1] == 0){
                        model -> R();
                        model -> Dprim();
                        model -> Rprim();
                        model -> D();
                        model -> Lprim();
                        model -> Dprim();
                        model -> L();
                    }
                    else if(tablica_k1[0] == 3 && tablica_k1[1] == 2){
                        model -> Lprim();
                        model -> D();
                        model -> L();
                        model -> Dprim();
                        model -> Lprim();
                        model -> D();
                        model -> L();
                    }

                    else if(tablica_k1[0] ==3 && tablica_k1[1] == 6 ){
                        model -> D();
                        model -> Lprim();
                        model -> Dprim();
                        model -> L();
                    }

                    else if(tablica_k1[0] == 3 && tablica_k1[1] == 8){
                        model -> Dprim();
                        model -> Lprim();
                        model -> D();
                        model -> L();
                    }
                    else if(tablica_k1[0] == 4 && tablica_k1[1] == 0){
                        model -> Lprim();
                        model -> Dprim();
                        model -> L();
                        model -> D();
                        model -> Lprim();
                        model -> Dprim();
                        model -> L();
                    }
                    else if(tablica_k1[0] == 4 && tablica_k1[1] == 2){
                        model -> L();
                        model -> D();
                        model -> L180();
                        model -> D180();
                        model -> L();

                        }
                    else if(tablica_k1[0] == 4 && tablica_k1[1] == 6 ){
                        model -> D();
                        model -> B();
                        model -> Dprim();
                        model -> Bprim();
                    }
                    else if(tablica_k1[0] ==4 && tablica_k1[1] == 8){
                        model -> D180();
                        model -> Lprim();
                        model -> D();
                        model -> L();
                    }
                    else if(tablica_k1[0] == 5 && tablica_k1[1] == 0){
                        model -> L();
                        model -> Dprim();
                        model -> L180();
                        model -> D();
                        model -> L();
                    }
                    else if(tablica_k1[0] == 5 && tablica_k1[1] ==2 ){
                        model -> Dprim();
                        model -> L();
                        model -> Dprim();
                        model -> L180();
                        model -> D();
                        model -> L(); 
                    }
                    else if(tablica_k1[0] == 5 && tablica_k1[1] == 6){
                        model -> D();
                        model -> L();
                        model -> Dprim();
                        model -> L180();
                        model -> D();
                        model -> L(); 
                    }
                    else if(tablica_k1[0] == 5 && tablica_k1[1] == 8){
                        model -> Bprim();
                        model -> D();
                        model -> B180();
                        model -> Dprim();
                        model -> Bprim();
                    }
                    
                    for(int i = 0; i < 6; i++ ){          
                for(int j = 0 ; j < 9; j++){
                    if(model -> getKostka(i,j) == 3){  
                        if(i==0 && j==2){        //sprawdzenie pozycji pierwszego kwadratu
                    tablica_k1[0] = 64;
                    
                      tablica_k1[1]=64;
                      
                        }
                        else {
                        tablica_k1[0]=i;        // przypisanie współrzędnych kwadratu 1 do pól tablicy 
                        
                       tablica_k1[1]=j;
                        
                        }
                    }
                }
            }


 // Serial.printf("\n ");
                          /*  for(int j=0; j<6 ; j++){
                        for(int i=0 ; i < 9; i++){
                             Serial.printf("%d   ",model -> getKostka(j,i));
                            
                        }
                        Serial.printf("\n ");}
                Serial.printf("\n po ulozeniu 1");
               
                Serial.printf("\n ");
                Serial.printf("%d\n", tablica_k1[0]);
                Serial.printf("%d\n", tablica_k1[1]);*/
                 
           
            } // koniec układania pierwszego rogu
            
            if(tablica_k1[0] == 64){  // początek układania drugiego rogu

                for(int i = 0; i < 6; i++ ){          
                for(int j = 0 ; j < 9; j++){
                    if(model -> getKostka(i,j) == 7){  
                        if(i==0 && j==6){        //sprawdzenie pozycji siódmego kwadratu
                    tablica_k1[0] = 64;
                    
                      tablica_k1[1]=64;
                      
                        }
                        else {
                        tablica_k1[0]=i;        // przypisanie współrzędnych kwadratu 7 do pól tablicy 
                        
                       tablica_k1[1]=j;
                        
                        }
                    }
                }
            }
            }
            
                  
            else if(tablica_k1[0] != 64){

                     
                  if(tablica_k1[0] == 0 && tablica_k1[1] == 6){
                        model -> Fprim();
                        model -> D();
                        model -> F();
                        model -> D180();
                        model -> Bprim();
                        model -> Dprim();
                        model -> B();
                    }

                    else if(tablica_k1[0] == 0 && tablica_k1[1] == 8){
                        model -> F();
                        model -> Dprim();
                        model -> Fprim();
                        model -> Bprim();
                        model -> D();
                        model -> B();
                    }

                    else if(tablica_k1[0] == 1 && tablica_k1[1] == 0){
                        model -> Fprim();
                        model -> Dprim();
                        model -> F();
                        model -> Dprim();
                        model -> Bprim();
                        model -> Dprim();
                        model -> B();
                    }
                    else if(tablica_k1[0] == 1 && tablica_k1[1] == 2){
                        model -> Rprim();
                        model -> D();
                        model -> R();
                        model -> Bprim();
                        model -> D();
                        model -> B();
                    }
                    else if(tablica_k1[0] == 1 && tablica_k1[1] == 6){
                        model -> D180();
                        model -> Bprim();
                        model -> Dprim();
                        model -> B();
                    }
             
                    else if(tablica_k1[0] == 1 && tablica_k1[1] == 8){
                         model -> Bprim();
                         model -> D(); 
                         model -> B();
                    }

                    else if(tablica_k1[0] == 2 && tablica_k1[1] == 0){
                         model -> Rprim();
                         model -> D180();
                         model -> R();
                         model -> Dprim();
                         model -> Bprim();
                         model -> Dprim();
                         model -> B();
                    }
                    
                    else if(tablica_k1[0] == 2 && tablica_k1[1] == 2){
                        model -> Bprim();
                        model -> D();
                        model -> B();
                        model -> Dprim();
                        model -> Bprim();
                        model -> D();
                        model -> B();
                    }

                    else if(tablica_k1[0] == 2 && tablica_k1[1] == 6){
                        model -> D();
                        model -> Bprim();
                        model -> Dprim();
                        model -> B();
                    }

                    else if(tablica_k1[0] == 2 && tablica_k1[1] == 8 ){
                        model -> Dprim();
                        model -> Bprim();
                        model -> D();
                        model -> B();
                    }
                    else if(tablica_k1[0] == 3 && tablica_k1[1] == 0){
                        model -> Bprim();
                        model -> Dprim();
                        model -> B();
                        model -> D();
                        model -> Bprim();
                        model -> Dprim();
                        model -> B();
                    }
                   // jest niemożliwym aby pole 3 znajdowało się w połozeniu (3,2), poniewaz na górnej ścianie znajduje się pole 1

                    else if(tablica_k1[0] ==3 && tablica_k1[1] == 6 ){
                        model -> Bprim();
                        model -> Dprim();
                        model -> B();
                    }

                    else if(tablica_k1[0] == 3 && tablica_k1[1] == 8){
                        model -> D180();
                        model -> Bprim();
                        model -> D();
                        model -> B();
                    }
                    // jest niemożliwym aby pole 3 znajdowało się w połozeniu (4,0), poniewaz na górnej ścianie znajduje się pole 1
                    else if(tablica_k1[0] == 4 && tablica_k1[1] == 2){
                        model -> L();
                        model -> D();
                        model -> Lprim();
                        model -> Bprim();
                        model -> D();
                        model -> B();
                        }

                    else if(tablica_k1[0] == 4 && tablica_k1[1] == 6 ){
                        model -> Dprim();
                        model -> Bprim();
                        model -> Dprim();
                        model -> B();
                    }
                    else if(tablica_k1[0] ==4 && tablica_k1[1] == 8){
                        model -> Bprim();
                        model -> D180();
                        model -> B();
                    }
                    else if(tablica_k1[0] == 5 && tablica_k1[1] == 0){
                        model -> Bprim();
                        model -> Dprim();
                        model -> B();
                        model -> Dprim();
                        model -> Bprim();
                        model -> D();
                        model -> B();
                    }
                    else if(tablica_k1[0] == 5 && tablica_k1[1] ==2 ){
                        model -> Bprim();
                        model -> D180();
                        model -> B();
                        model -> Dprim();
                        model -> Bprim();
                        model -> D();
                        model -> B();     
                    }
                    else if(tablica_k1[0] == 5 && tablica_k1[1] == 6){
                        model -> D(); 
                        model -> Bprim();
                        model -> Dprim();
                        model -> B();
                        model -> Dprim();
                        model -> Bprim();
                        model -> D();
                        model -> B();
                    }
                    else if(tablica_k1[0] == 5 && tablica_k1[1] == 8){
                        model -> D180();
                        model -> Bprim();
                        model -> Dprim();
                        model -> B();
                        model -> Dprim();
                        model -> Bprim();
                        model -> D();
                        model -> B();

                    }
                    
                    for(int i = 0; i < 6; i++ ){          
                for(int j = 0 ; j < 9; j++){
                    if(model -> getKostka(i,j) == 7){  
                        if(i==0 && j==6){        //sprawdzenie pozycji siódmego kwadratu
                    tablica_k1[0] = 64;
                    
                      tablica_k1[1]=64;
                      
                        }
                        else {
                        tablica_k1[0]=i;        // przypisanie współrzędnych kwadratu 7 do pól tablicy 
                        
                       tablica_k1[1]=j;
                        
                        }
                    }
                }
            }
                

            } // koniec układania drugiego rogu
             


            
                        if(tablica_k1[0] == 64){   // początek układania trzeciego rogu
                                for(int i = 0; i < 6; i++ ){          
                for(int j = 0 ; j < 9; j++){
                    if(model -> getKostka(i,j) == 9){  
                        if(i==0 && j==8){        //sprawdzenie pozycji dziewiategokwadratu
                    tablica_k1[0] = 64;
                    
                      tablica_k1[1]=64;
                      
                        }
                        else {
                        tablica_k1[0]=i;        // przypisanie współrzędnych kwadratu 9 do pól tablicy 
                        
                       tablica_k1[1]=j;
                        
                        }
                    }
                }
            }

                        }    
                else if(tablica_k1[0] != 64){
                          
                       

                 if(tablica_k1[0] == 0 && tablica_k1[1] == 8){
                        model -> Rprim();
                        model -> D();
                        model -> R();
                        model -> L();
                        model -> Dprim();
                        model -> Lprim();
                    }

                    else if(tablica_k1[0] == 1 && tablica_k1[1] == 0){
                        model -> Fprim();
                        model -> Dprim();
                        model -> F();
                        model -> D();
                        model -> Fprim();
                        model -> Dprim();
                        model -> F();
                    }
                    else if(tablica_k1[0] == 1 && tablica_k1[1] == 2){
                        model -> F();
                        model -> D180();
                        model -> F180();
                        model -> D();
                        model -> F();
                    }
                    else if(tablica_k1[0] == 1 && tablica_k1[1] == 6){
                        model -> Fprim();
                        model -> Dprim();
                        model -> F();
                    }
             
                    else if(tablica_k1[0] == 1 && tablica_k1[1] == 8){
                         model -> D180();
                         model -> Fprim();
                         model -> D();
                         model -> F();
                    }

                    else if(tablica_k1[0] == 2 && tablica_k1[1] == 0){
                         model -> Rprim();
                         model -> Dprim();
                         model -> R();
                         model -> Fprim();
                         model -> Dprim();
                         model -> F();
                    }
                    
                    // nie jest możliwe aby pole 7 znajdowało się w położeniu (2,2) ponieważ na górnej ścianie znajduje się pole 3

                    else if(tablica_k1[0] == 2 && tablica_k1[1] == 6){
                        model -> L();
                        model -> Dprim();
                        model -> Lprim();

                    }

                    else if(tablica_k1[0] == 2 && tablica_k1[1] == 8 ){
                        model -> Fprim();
                        model -> D180();
                        model -> F();
                    }
                   //jest niemożliwym aby pole 7 znajdowało się w położeniu (3,0), ponieważ na górnej ścianie znajdje się pole 3
                   // jest niemożliwym aby pole 7 znajdowało się w połozeniu (3,2), poniewaz na górnej ścianie znajduje się pole 1

                    else if(tablica_k1[0] ==3 && tablica_k1[1] == 6 ){
                        model -> D180();
                        model -> Fprim();
                        model -> Dprim();
                        model -> F();
                    }

                    else if(tablica_k1[0] == 3 && tablica_k1[1] == 8){
                        model -> Fprim();
                        model -> D();
                        model -> F();

                    }
                    // jest niemożliwym aby pole 7 znajdowało się w połozeniu (4,0), poniewaz na górnej ścianie znajduje się pole 1
                    else if(tablica_k1[0] == 4 && tablica_k1[1] == 2){
                        model -> Fprim();
                        model -> D();
                        model -> F();
                        model -> Dprim();
                        model -> Fprim();
                        model -> D();
                        model -> F();
                        }

                    else if(tablica_k1[0] == 4 && tablica_k1[1] == 6 ){
                        model -> D();
                        model -> Fprim();
                        model -> Dprim();
                        model -> F();
                    }
                    else if(tablica_k1[0] ==4 && tablica_k1[1] == 8){
                        model -> Dprim();
                        model -> Fprim();
                        model -> D();
                        model -> F();
                    }
                    else if(tablica_k1[0] == 5 && tablica_k1[1] == 0){
                        model -> D();
                        model -> F();
                        model -> Dprim();
                        model -> F180();
                        model -> D();
                        model -> F();
                    }
                    else if(tablica_k1[0] == 5 && tablica_k1[1] ==2 ){
                        model -> F();
                        model -> Dprim();
                        model -> F180();
                        model -> D();
                        model -> F();
                    }
                    else if(tablica_k1[0] == 5 && tablica_k1[1] == 6){
                        model -> D180();
                        model -> F();
                        model -> Dprim();
                        model -> F180();
                        model -> D();
                        model -> F();
                    }
                    else if(tablica_k1[0] == 5 && tablica_k1[1] == 8){
                         model -> Dprim();
                        model -> F();
                        model -> Dprim();
                        model -> F180();
                        model -> D();
                        model -> F();

                    }
                    
                    for(int i = 0; i < 6; i++ ){          
                for(int j = 0 ; j < 9; j++){
                    if(model -> getKostka(i,j) == 9){  
                        if(i==0 && j==8){        //sprawdzenie pozycji dziewiątego kwadratu
                    tablica_k1[0] = 64;
                    
                      tablica_k1[1]=64;
                    
                      
                        }
                        else {
                        tablica_k1[0]=i;        // przypisanie współrzędnych kwadratu 9 do pól tablicy 
                        
                       tablica_k1[1]=j;
                        
                        }
                    }
                }
            }
                }/*
Serial.printf("\n");
Serial.printf("%d\n", tablica_k1[0]);
Serial.printf("%d\n", tablica_k1[1]);
Serial.printf("DZIEWIATECZKA");
Serial.printf("\n");

for(int j=0; j<6 ; j++){
                        for(int i=0 ; i < 9; i++){
                             Serial.printf("%d   ",model -> getKostka(j,i));
                            
                        }
                        Serial.printf("\n ");}
               Serial.printf("\n pole 9 polozenie");
                Serial.printf("\n ");
Serial.printf("%d\n ", tablica_k1[0]);
Serial.printf("%d\n ", tablica_k1[1]);
Serial.printf("\n ");*/

                       if(tablica_k1[0] == 64){ // układanie ostatniego (czwartego rogu)

                              for(int i = 0; i < 6; i++ ){          
                for(int j = 0 ; j < 9; j++){
                    if(model -> getKostka(i,j) == 13){  
                        if(i == 1 && j == 3){        //sprawdzenie pozycji trzynastego kwadratu
                    tablica_k1[0] = 64;
                    
                      tablica_k1[1]=64;
                      
                        }
                        else {
                        tablica_k1[0]=i;        // przypisanie współrzędnych kwadratu 13 do pól tablicy 
                        
                       tablica_k1[1]=j;
                        
                        }
                    }
                }
            }
                        }
                     
                        else if(tablica_k1[0] != 64){


                     //jest niemożliwym aby kwadrat 9 znajdował się w polozeniu (1,0) ponieważ na górnej ścianie znajduje się kwadrat 7
                     if(tablica_k1[0] == 1 && tablica_k1[1] == 2){
                        model -> F();
                        model -> D180();
                        model -> Fprim();
                        model -> Rprim();
                        model -> D180();
                        model -> R();
                    }
                    else if(tablica_k1[0] == 1 && tablica_k1[1] == 6){
                        model -> D();
                        model -> Rprim();
                        model -> Dprim();
                        model -> R();
                    }
             
                    else if(tablica_k1[0] == 1 && tablica_k1[1] == 8){
                         model -> Dprim();
                         model -> Rprim();
                         model -> D();
                         model -> R();
                    }

                    else if(tablica_k1[0] == 2 && tablica_k1[1] == 0){
                         model -> Rprim();
                         model -> Dprim();
                         model -> R();
                         model -> D();
                         model -> Rprim();
                         model -> Dprim();
                         model -> R();
                    }
                    
                    // nie jest możliwe aby pole 7 znajdowało się w położeniu (2,2) ponieważ na górnej ścianie znajduje się pole 3

                    else if(tablica_k1[0] == 2 && tablica_k1[1] == 6){
                        model -> Rprim();
                        model -> Dprim();
                        model -> R();

                    }

                    else if(tablica_k1[0] == 2 && tablica_k1[1] == 8 ){
                      model -> D180();
                      model -> Rprim();
                      model -> D();
                      model -> R();
                    }
                   //jest niemożliwym aby pole 7 znajdowało się w położeniu (3,0), ponieważ na górnej ścianie znajdje się pole 3
                   // jest niemożliwym aby pole 7 znajdowało się w połozeniu (3,2), poniewaz na górnej ścianie znajduje się pole 1

                    else if(tablica_k1[0] ==3 && tablica_k1[1] == 6 ){
                        model -> Dprim();
                        model -> Rprim();
                        model -> Dprim();
                        model -> R();
                    }

                    else if(tablica_k1[0] == 3 && tablica_k1[1] == 8){
                        model -> Rprim();
                        model -> D180();
                        model -> R();

                    }
                    // jest niemożliwym aby pole 9 znajdowało się w połozeniu (4,0), poniewaz na górnej ścianie znajduje się pole 1
                    //jest niemożliwym aby pole 9 znajdowało się w połozeniu (4,2), ponieważ na górnej ścianie znajduje się pole 7

                    else if(tablica_k1[0] == 4 && tablica_k1[1] == 6 ){
                        model -> D180();
                        model -> Rprim();
                        model -> Dprim();
                        model -> R();
                    }
                    else if(tablica_k1[0] ==4 && tablica_k1[1] == 8){
                        model -> Rprim();
                        model -> D();
                        model -> R();
                    }
                    else if(tablica_k1[0] == 5 && tablica_k1[1] == 0){
                        model -> D();
                        model -> Rprim();
                        model -> D180();
                        model -> R();
                        model -> D();
                        model -> Rprim();
                        model -> Dprim();
                        model -> R();
                    }
                    else if(tablica_k1[0] == 5 && tablica_k1[1] ==2 ){
                       
                        model -> Rprim();
                        model -> D180();
                        model -> R();
                        model -> D();
                        model -> Rprim();
                        model -> Dprim();
                        model -> R();
                    }
                    else if(tablica_k1[0] == 5 && tablica_k1[1] == 6){
                        model -> D180();
                         model -> Rprim();
                        model -> D180();
                        model -> R();
                        model -> D();
                        model -> Rprim();
                        model -> Dprim();
                        model -> R();
                    }
                    else if(tablica_k1[0] == 5 && tablica_k1[1] == 8){
                        model -> Dprim();
                        model -> Rprim();
                        model -> D180();
                        model -> R();
                        model -> D();
                        model -> Rprim();
                        model -> Dprim();
                        model -> R();

                    }
                    
                    for(int i = 0; i < 6; i++ ){          
                for(int j = 0 ; j < 9; j++){
                    if(model -> getKostka(i,j) == 13){  
                        if(i==1 && j==3){        //sprawdzenie pozycji 13 kwadratu
                    tablica_k1[0] = 64;
                    
                      tablica_k1[1]=64;
                      
                        }
                        else {
                        tablica_k1[0]=i;        // przypisanie współrzędnych kwadratu 13 do pól tablicy 
                        
                       tablica_k1[1]=j;
                        
                        }
                    }
                }
            }



                    }

/*for(int j=0; j<6 ; j++){
                        for(int i=0 ; i < 9; i++){
                             Serial.printf("%d   ",model -> getKostka(j,i));
                            
                        }
                        Serial.printf("\n ");}
               Serial.printf("\n pole 13 polozenie");
                Serial.printf("\n ");
Serial.printf("%d\n ", tablica_k1[0]);
Serial.printf("%d\n ", tablica_k1[1]);
Serial.printf("\n ");*/

                 

                    if(tablica_k1[0] == 64){
                        for(int i = 0; i < 6; i++ ){          
                for(int j = 0 ; j < 9; j++){
                    if(model -> getKostka(i,j) == 15){  
                        if(i==1 && j==5){        //sprawdzenie pozycji 15 kwadratu
                    tablica_k1[0] = 64;
                    
                      tablica_k1[1]=64;
                      
                        }
                        else {
                        tablica_k1[0]=i;        // przypisanie współrzędnych kwadratu 15 do pól tablicy 
                        
                       tablica_k1[1]=j;
                        
                        }
                    }
                }
            }

      

                    }

                else if(tablica_k1[0]  != 64){
                    if(tablica_k1[0] == 5 && tablica_k1[1] == 1){
                        model -> D180();
                        model -> Fprim();
                        model -> D();
                        model -> F();
                        model -> D();
                        model -> L();
                        model -> Dprim();
                        model -> Lprim();
                    }

                    if(tablica_k1[0] == 5 && tablica_k1[1] == 3){
                        model -> Dprim();
                        model -> Fprim();
                        model -> D();
                        model -> F();
                        model -> D();
                        model -> L();
                        model -> Dprim();
                        model -> Lprim(); 
                    }
                    if(tablica_k1[0] == 5 && tablica_k1[1] == 5){
                        model -> D();
                        model -> Fprim();
                        model -> D();
                        model -> F();
                        model -> D();
                        model -> L();
                        model -> Dprim();
                        model -> Lprim(); 
                    }
                    if(tablica_k1[0] == 5 && tablica_k1[1] == 7){
                        model -> Fprim();
                        model -> D();
                        model -> F();
                        model -> D();
                        model -> L();
                        model -> Dprim();
                        model -> Lprim();
                    }
                    if(tablica_k1[0] == 1 && tablica_k1[1] == 7){
                        model -> D();
                        model -> L();
                        model -> Dprim();
                        model -> Lprim();
                        model -> Dprim();
                        model -> Fprim();
                        model -> D();
                        model -> F();
                    }
                    if(tablica_k1[0] == 2 && tablica_k1[1] == 7){
                        model -> L();
                        model -> Dprim();
                        model -> Lprim();
                        model -> Dprim();
                        model -> Fprim();
                        model -> D();
                        model -> F();
                    }
                     if(tablica_k1[0] == 3 && tablica_k1[1] == 7){
                        model -> Dprim();
                        model -> L();
                        model -> Dprim();
                        model -> Lprim();
                        model -> Dprim();
                        model -> Fprim();
                        model -> D();
                        model -> F();
                    }
                     if(tablica_k1[0] == 4 && tablica_k1[1] == 7){
                        model -> D180();
                        model -> L();
                        model -> Dprim();
                        model -> Lprim();
                        model -> Dprim();
                        model -> Fprim();
                        model -> D();
                        model -> F();
                    }
                    if(tablica_k1[0] == 1 && tablica_k1[1] == 5){
                        model -> Rprim();
                        model -> D();
                        model -> R();
                        model -> D();
                        model -> F();
                        model -> Dprim();
                        model -> Fprim();

                        model -> Fprim();
                        model -> D();
                        model -> F();
                        model -> D();
                        model -> L();
                        model -> Dprim();
                        model -> Lprim();

                    }
                    if(tablica_k1[0] == 2 && tablica_k1[1] == 3 ){
                        model -> Rprim();
                        model -> D();
                        model -> R();
                        model -> D();
                        model -> F();
                        model -> Dprim();
                        model -> Fprim();

                        model -> Dprim();
                        model -> L();
                        model -> Dprim();
                        model -> Lprim();
                        model -> Dprim();
                        model -> Fprim();
                        model -> D();
                        model -> F();
                    }
                    if(tablica_k1[0] == 2 && tablica_k1[1] == 5){
                        model -> Bprim();
                        model -> D();
                        model -> B();
                        model -> D();
                        model -> R();
                        model -> Dprim();
                        model -> Rprim();

                        model -> Dprim();
                        model -> Fprim();
                        model -> D();
                        model -> F();
                        model -> D();
                        model -> L();
                        model -> Dprim();
                        model -> Lprim(); 
                    }

                   if(tablica_k1[0] == 3 && tablica_k1[1] == 3){
                        model -> Bprim();
                        model -> D();
                        model -> B();
                        model -> D();
                        model -> R();
                        model -> Dprim();
                        model -> Rprim();

                        model -> D180();
                        model -> L();
                        model -> Dprim();
                        model -> Lprim();
                        model -> Dprim();
                        model -> Fprim();
                        model -> D();
                        model -> F();


                   }
                   if(tablica_k1[0] == 3 && tablica_k1[1] == 5){
                       model -> Lprim();
                       model -> D();
                       model -> L();
                       model -> D();
                       model -> B();
                       model -> Dprim();
                       model -> Bprim();

                       model -> D180();
                       model -> Fprim();
                       model -> D();
                       model -> F();
                       model -> D();
                       model -> L();
                       model -> Dprim();
                       model -> Lprim();
                   }

                   if(tablica_k1[0] == 4 && tablica_k1[1] == 3){
                       model -> B();
                       model -> Dprim();
                       model -> Bprim();
                       model -> Dprim();
                       model -> Lprim();
                       model -> D();
                       model -> L();

                        model -> D();
                        model -> Fprim();
                        model -> D();
                        model -> F();
                        model -> D();
                        model -> L();
                        model -> Dprim();
                        model -> Lprim();

                   } 

                   if(tablica_k1[0] == 4 && tablica_k1[1] == 5){
                       model -> Lprim();
                       model -> F();
                       model -> L();
                       model -> Fprim();

                       model -> L();
                       model -> Dprim();
                       model -> Lprim();
                       model -> D();
                       model -> L();
                       model -> Dprim();
                       model -> Lprim();
                       model -> D180();
                       model -> L();
                       model -> Dprim();
                       model -> Lprim();
                   }



                   for(int i = 0; i < 6; i++ ){          
                for(int j = 0 ; j < 9; j++){
                    if(model -> getKostka(i,j) == 15){  
                        if(i==1 && j==5){        //sprawdzenie pozycji 15 kwadratu
                    tablica_k1[0] = 64;
                    
                      tablica_k1[1]=64;
                      
                        }
                        else {
                        tablica_k1[0]=i;        // przypisanie współrzędnych kwadratu 15 do pól tablicy 
                        
                       tablica_k1[1]=j;
                        
                        }
                    }
                }
            }

                       
            
                }


        /*    for(int j=0; j<6 ; j++){
                        for(int i=0 ; i < 9; i++){
                             Serial.printf("%d   ",model -> getKostka(j,i));
                            
                        }
                        Serial.printf("\n ");}
               Serial.printf("\n pole 13 polozenie po sorcie");
                Serial.printf("\n ");*/

                 if(tablica_k1[0] == 64){  // układanie kwadratu 15
                            for(int i = 0; i < 6; i++ ){          
                for(int j = 0 ; j < 9; j++){
                    if(model -> getKostka(i,j) == 24){  
                        if(i==2 && j==5){        //sprawdzenie pozycji 24 kwadratu
                    tablica_k1[0] = 64;
                    
                      tablica_k1[1]=64;
                      
                        }
                        else {
                        tablica_k1[0]=i;        // przypisanie współrzędnych kwadratu 24 do pól tablicy 
                        
                       tablica_k1[1]=j;
                        
                        }
                    }
                }
            }

                 }

                else if( tablica_k1[0] != 64){
                        if(tablica_k1[0] == 5  && tablica_k1[1] == 1){
                            model -> D180();
                            model -> F();
                            model -> Dprim();
                            model -> Fprim();
                            model -> Dprim();
                            model -> Rprim();
                            model -> D();
                            model -> R();
                        }
                        else if(tablica_k1[0] == 5 && tablica_k1[1] == 3){
                            model -> Dprim();
                            model -> F();
                            model -> Dprim();
                            model -> Fprim();
                            model -> Dprim();
                            model -> Rprim();
                            model -> D();
                            model -> R();

                        }
                        else if(tablica_k1[0] == 5 && tablica_k1[1] == 5){
                            model -> D();
                            model -> F();
                            model -> Dprim();
                            model -> Fprim();
                            model -> Dprim();
                            model -> Rprim();
                            model -> D();
                            model -> R();
                        }
                        else if(tablica_k1[0] == 5 && tablica_k1[1] == 7){
                            model -> F();
                            model -> Dprim();
                            model -> Fprim();
                            model -> Dprim();
                            model -> Rprim();
                            model -> D();
                            model -> R();
                        }
                        else if(tablica_k1[0] == 1 && tablica_k1[1] == 7 ){
                            model -> Dprim();
                            model -> Rprim();
                            model -> D();
                            model -> R();
                            model -> D();
                            model -> F();
                            model -> Dprim();
                            model -> Fprim();
                            
                            }
                        else if( tablica_k1[0] == 2 && tablica_k1[1] == 7){
                            model -> D180();
                            model -> Rprim();
                            model -> D();
                            model -> R();
                            model -> D();
                            model -> F();
                            model -> Dprim();
                            model -> Fprim();
                        }    
                        else if(tablica_k1[0] == 3 && tablica_k1[1] == 7){
                            model -> D();
                            model -> Rprim();
                            model -> D();
                            model -> R();
                            model -> D();
                            model -> F();
                            model -> Dprim();
                            model -> Fprim();
                        }
                        else if(tablica_k1[0] == 4 && tablica_k1[1] == 7){
                            model -> Rprim();
                            model -> D();
                            model -> R();
                            model -> D();
                            model -> F();
                            model -> Dprim();
                            model -> Fprim();

                        }
                        else if(tablica_k1[0] == 2 && tablica_k1[1] == 3){
                            model -> Fprim();
                            model -> R();
                            model -> F();
                            model -> Rprim();

                            model -> F();
                            model -> Dprim();
                            model -> Fprim();
                            model -> D();
                            model -> F();
                            model -> Dprim();
                            model -> Fprim();
                            model -> D180();
                            model -> F();
                            model -> Dprim();
                            model -> Fprim();
                        }
                        else if(tablica_k1[0] == 2 && tablica_k1[1] == 5){
                            model -> Bprim();
                            model -> D();
                            model -> B();
                            model -> D();
                            model -> R();
                            model -> Dprim();
                            model -> Rprim();
                            
                            model -> Dprim();
                            model -> F();
                            model -> Dprim();
                            model -> Fprim();
                            model -> Dprim();
                            model -> Rprim();
                            model -> D();
                            model -> R();    
                        }
                        else if(tablica_k1[0] == 3 && tablica_k1[1] == 3){
                            model -> Bprim();
                            model -> D();
                            model -> B();
                            model -> D();
                            model -> R();
                            model -> Dprim();
                            model -> Rprim();

                            model -> Rprim();
                            model -> D();
                            model -> R();
                            model -> D();
                            model -> F();
                            model -> Dprim();
                            model -> Fprim();
                        }

                        else if(tablica_k1[0] == 3 && tablica_k1[1] == 5){
                            model -> Lprim();
                            model -> D();
                            model -> L();
                            model -> D();
                            model -> B();
                            model -> Dprim();
                            model -> Bprim();

                            model -> D180();
                            model -> F();
                            model -> Dprim();
                            model -> Fprim();
                            model -> Dprim();
                            model -> Rprim();
                            model -> D();
                            model -> R();
                        }
                        else if(tablica_k1[0] == 4 && tablica_k1[1] == 3){
                            model -> Lprim();
                            model -> D();
                            model -> L();
                            model -> D();
                            model -> B();
                            model -> Dprim();
                            model -> Bprim();

                            model -> Dprim();
                            model -> Rprim();
                            model -> D();
                            model -> R();
                            model -> D();
                            model -> F();
                            model -> Dprim();
                            model -> Fprim();
                        }

                         for(int i = 0; i < 6; i++ ){          
                for(int j = 0 ; j < 9; j++){
                    if(model -> getKostka(i,j) == 24){  
                        if(i==2 && j==5){        //sprawdzenie pozycji 24 kwadratu
                    tablica_k1[0] = 64;
                    
                      tablica_k1[1]=64;
                      
                        }
                        else {
                        tablica_k1[0]=i;        // przypisanie współrzędnych kwadratu 24 do pól tablicy 
                        
                       tablica_k1[1]=j;
                        
                        }
                    }
                }
        }
          
         


                      } 
                      // koniec układania kwadratu 15

                        // Serial.printf("%d\n ", tablica_k1[0]);
                       //     Serial.printf("%d\n ", tablica_k1[1]);


                   if(tablica_k1[0] == 64){

                         for(int i = 0; i < 6; i++ ){          
                for(int j = 0 ; j < 9; j++){
                    if(model -> getKostka(i,j) == 33){  
                        if(i==3 && j==5){        //sprawdzenie pozycji 33 kwadratu
                    tablica_k1[0] = 64;
                    
                      tablica_k1[1]=64;
                      
                        }
                        else {
                        tablica_k1[0]=i;        // przypisanie współrzędnych kwadratu 33 do pól tablicy 
                        
                       tablica_k1[1]=j;
                        
                        }
                    }
                }
            }
                    }


                  else if(tablica_k1[1] != 64){
                        if(tablica_k1[0] == 5 && tablica_k1[1] == 1){
                            model -> Dprim();
                            model -> R();
                            model -> Dprim();
                            model -> Rprim();
                            model -> Dprim();
                            model -> Bprim();
                            model -> D();
                            model -> B();
                        }
                        else if(tablica_k1[0] == 5 && tablica_k1[1] == 3){
                                
                                model -> R();
                                model -> Dprim();
                                 model -> Rprim();
                                model -> Dprim();
                                model -> Bprim();
                                model -> D();
                                model -> B();
                        }
                        else if(tablica_k1[0] == 5 && tablica_k1[1] == 5){
                            model -> D180();
                            model -> R();
                            model -> Dprim();
                            model -> Rprim();
                            model -> Dprim();
                            model -> Bprim();
                            model -> D();
                            model -> B();
                        }
                        else if(tablica_k1[0] == 5 && tablica_k1[1] == 7){
                            model -> D();
                            model -> R();
                            model -> Dprim();
                            model -> Rprim();
                            model -> Dprim();
                            model -> Bprim();
                            model -> D();
                            model -> B();
                        }
                        else if(tablica_k1[0] == 1 && tablica_k1[1] == 7){
                            model -> Bprim();
                            model -> D();
                            model -> B();
                            model -> D();
                            model -> R();
                            model -> Dprim();
                            model -> Rprim();
                        }
                        else if(tablica_k1[0] == 2 && tablica_k1[1] == 7){
                            model -> Dprim();
                            model -> Bprim();
                            model -> D();
                            model -> B();
                            model -> D();
                            model -> R();
                            model -> Dprim();   
                            model -> Rprim();
                        }
                        else if(tablica_k1[0] == 3 && tablica_k1[1] == 7){
                            model -> D180();
                            model -> Bprim();
                            model -> D();
                            model -> B();
                            model -> D();
                            model -> R();
                            model -> Dprim();
                            model -> Rprim();
                        }
                        else if(tablica_k1[0] == 4 && tablica_k1[1] == 7){
                            model -> D();
                            model -> Bprim();
                            model -> D();
                            model -> B();
                            model -> D();
                            model -> R();
                            model -> Dprim();
                            model -> Rprim();
                        }
                        else if(tablica_k1[0] == 3 && tablica_k1[1] == 3 ){
                                model -> Rprim();
                                model -> B();
                                model -> R();
                                model -> Bprim();

                                model -> R();
                                model -> Dprim();
                                model -> Rprim();
                                model -> D();
                                model -> R();
                                model -> Dprim();
                                model -> Rprim();
                                model -> D180();
                                model -> R();
                                model -> Dprim();
                                model -> Rprim();
                        }

                      else if(tablica_k1[0] == 3 && tablica_k1[1] == 5){
                                model -> Lprim();
                                model -> D();
                                model -> L();
                                model -> D();
                                model -> B();
                                model -> Dprim();
                                model -> Bprim();

                                model -> Dprim();
                                model -> R();
                                model -> Dprim();
                                model -> Rprim();
                                model -> Dprim();
                                model -> Bprim();
                                model -> D();
                                model -> B();
                      }

                       else if(tablica_k1[0] == 4 && tablica_k1[1] == 3){
                            model -> Lprim();
                            model -> D();
                            model -> L();
                            model -> D();
                            model -> B();
                            model -> Dprim();
                            model -> Bprim();

                            
                            model -> Bprim();
                            model -> D();
                            model -> B();
                            model -> D();
                            model -> R();
                            model -> Dprim();
                            model -> Rprim();
                        }


                  

                              for(int i = 0; i < 6; i++ ){          
                for(int j = 0 ; j < 9; j++){
                    if(model -> getKostka(i,j) == 33){  
                        if(i==3 && j==5){        //sprawdzenie pozycji 33 kwadratu
                    tablica_k1[0] = 64;
                    
                      tablica_k1[1]=64;
                      
                        }
                        else {
                        tablica_k1[0]=i;        // przypisanie współrzędnych kwadratu 33 do pól tablicy 
                        
                       tablica_k1[1]=j;
                        
                        }
                    }
                }
            }

                                 
                         

   

                      }

                   if(tablica_k1[0] != 64){
                        if(tablica_k1[0] == 5 && tablica_k1[1] == 1){
                            model -> B();
                            model -> Dprim();
                            model -> Bprim();
                            model -> Dprim();
                            model -> Lprim();
                            model -> D();
                            model -> L();

                        }

                        else if(tablica_k1[0] == 5 && tablica_k1[1] == 3){
                            model -> D();
                            model -> B();
                            model -> Dprim();
                            model -> Bprim();
                            model -> Dprim();
                            model -> Lprim();
                            model -> D();
                            model -> L();
                        }

                        else if(tablica_k1[0] == 5 && tablica_k1[1] == 5){
                            model -> Dprim();
                            model -> B();
                            model -> Dprim();
                            model -> Bprim();
                            model -> Dprim();
                            model -> Lprim();
                            model -> D();
                            model -> L();
                        }

                        else if(tablica_k1[0] == 5 && tablica_k1[1] == 7){
                            model -> D180();
                            model -> B();
                            model -> Dprim();
                            model -> Bprim();
                            model -> Dprim();
                            model -> Lprim();
                            model -> D();
                            model -> L();
                        }

                        else if(tablica_k1[0] == 1 && tablica_k1[1] == 7){
                            model -> D();
                            model -> Lprim();
                            model -> D();
                            model -> L();
                            model -> D();
                            model -> B();
                            model -> Dprim();
                            model -> Bprim();
                        }

                        else if(tablica_k1[0] == 2 && tablica_k1[1] == 7){
                            model -> Lprim();
                            model -> D();
                            model -> L();
                            model -> D();
                            model -> B();
                            model -> Dprim();
                            model -> Bprim();
                        }

                        else if(tablica_k1[0] == 3 && tablica_k1[1] == 7){
                            model -> Dprim();
                            model -> Lprim();
                            model -> D();
                            model -> L();
                            model -> D();
                            model -> B();
                            model -> Dprim();
                            model -> Bprim();
                        }

                        else if(tablica_k1[0] == 4 && tablica_k1[1] == 7){
                            model -> D180();
                            model -> Lprim();
                            model -> D();
                            model -> L();
                            model -> D();
                            model -> B();
                            model -> Dprim();
                            model -> Bprim();
                        }

                        else if(tablica_k1[0] == 4 && tablica_k1[1] == 3){
                            model -> Bprim();
                            model -> L();
                            model -> B();
                            model -> Lprim();

                            model -> B();
                            model -> Dprim();
                            model -> Bprim();
                            model -> D();
                            model -> B();
                            model -> Dprim();
                            model -> Bprim();
                            model -> D180();
                            model -> B();
                            model -> Dprim();
                            model -> Bprim();
                        }


                       

                    } // koniec układania rogów

                


                      suma =0;

                       for( int i=0 ; i <4; i++){
                           if(model -> getKostka(5, 1+2*i) == 47 || model -> getKostka(5, 1+2*i) == 49 || model -> getKostka(5, 1+2*i) == 51 || model -> getKostka(5, 1+2*i) == 53 ){
                               tablica_k2[i] = 1;
                           }
                           else {
                               tablica_k2[i] =0;
                           }
                       }
                        
                                                           
					   // sprawdzanie pozycji pól krzyża na dolnej ścianie
                    
                    for(int k=0; k<4; k++){
                        suma =suma + tablica_k2[k];
                        
                    }
                    
                
      

                   if(suma == 0 ){
                        model -> F();
                        model -> L();
                        model -> D();
                        model -> Lprim();
                        model -> Dprim();
                        model -> Fprim();
                        
                    
                    
             for( int i=0 ; i <4; i++){
                           if(model -> getKostka(5, 1+2*i) == 47 || model -> getKostka(5, 1+2*i) == 49 || model -> getKostka(5, 1+2*i) == 51 || model -> getKostka(5, 1+2*i) == 53 ){
                               tablica_k2[i] = 1;
                           }
                           else {
                               tablica_k2[i] =0;
                           }
                       }
                        
                                                             // sprawdzanie pozycji pól krzyża na dolnej ścianie
                    
						for(int k=0; k<4; k++){
						 suma =suma + tablica_k2[k];
						}

                    }

                    
                   if(suma == 2){
                        if(tablica_k2[0] == 1 && tablica_k2[1] == 1){  //kk
                        model -> B();
                        model -> R();
                        model -> D();
                        model -> Rprim();
                        model -> Dprim();
                        model -> Bprim();
                        
                        model -> B();
                        model -> R();
                        model -> D();
                        model -> Rprim();
                        model -> Dprim();
                        model -> Bprim();
                        suma =4;
                        }
                        else if(tablica_k2[0] == 1 && tablica_k2[2] == 1){ // kk
                            model -> L();
                            model -> B();
                            model -> D();
                            model -> Bprim();
                            model -> Dprim();
                            model -> Lprim();

                            model -> L();
                            model -> B();
                            model -> D();
                            model -> Bprim();
                            model -> Dprim();
                            model -> Lprim();
                            suma =4;
                        }
                        else if(tablica_k2[0] == 1 && tablica_k2[3] == 1){ //kk
                            model -> R();
                            model -> F();
                            model -> D();
                            model -> Fprim();
                            model -> Dprim();
                            model -> Rprim();


                            suma =4;
                        }
                        else if(tablica_k2[2] == 1 && tablica_k2[3] == 1){//kk
                                model -> F();
                                model -> L();
                                model -> D();
                                model -> Lprim();
                                model -> Dprim();
                                model -> Fprim();

                                model -> F();
                                model -> L();
                                model -> D();
                                model -> Lprim();
                                model -> Dprim();
                                model -> Fprim();
                                suma =4;
                        }
                        else if(tablica_k2[1] == 1 && tablica_k2[3] == 1){//kk
                                model -> R();
                                model -> F();
                                model -> D();
                                model -> Fprim();
                                model -> Dprim();
                                model -> Rprim();

                                model -> R();
                                model -> F();
                                model -> D();
                                model -> Fprim();
                                model -> Dprim();
                                model -> Rprim();
                                suma =4;
                        }
                        else if(tablica_k2[1] == 1 && tablica_k2[2] == 1){ //kk
                            model -> F();
                            model -> L();
                            model -> D();
                            model -> Lprim();
                            model -> Dprim();
                            model -> Fprim();
                             suma =4;
                        }
                    }

                        
              


            



                    if(suma == 4){
                        for(int i = 0; i< 4 ; i++){
                            if(model -> getKostka(5, 1+ 2*i) == 47){
                                tablica_k1[0] = 5;
                                tablica_k1[1] = 1+ 2*i;
                                }
                        }
                      //  Serial.printf("%d\n ", tablica_k1[1]);
                    }

                        if(tablica_k1[1] == 1){

                        }   
                        else if(tablica_k1[1] == 3){
                            model -> D();
                        } 
                        else if(tablica_k1[1] == 5){
                            model -> Dprim();
                          }
                        else if(tablica_k1[1] == 7){
                            model -> D180();
                        }  // koniec układania krzyża


 /*Serial.printf("\n  po ulozeniue");
 Serial.printf("\n ");
                       for(int j=0; j<6 ; j++){
                        for(int i=0 ; i < 9; i++){
                             Serial.printf("%d   ",model -> getKostka(j,i));
                            
                        }
                        Serial.printf("\n ");
                        }
                          Serial.printf("\n ");*/
                        
                    
                    if(model -> getKostka(5,3) == 49 && model -> getKostka(5,5) == 51 && model -> getKostka(5,7) == 53 ){  
						// umieszczanie poł krzyża we właściwym miejscu

                    }
                    else if(model -> getKostka(5,3) == 49){  
                        model -> F();
                        model -> D();
                        model -> Fprim();
                        model -> D();
                        model -> F();
                        model -> D180();
                        model -> Fprim();
                        model -> D();
                    }
                    else if(model -> getKostka(5,5) == 51){
                        model -> R();
                        model -> D();
                        model -> Rprim();
                        model -> D();
                        model -> R();
                        model -> D180();
                        model -> Rprim();
                        model -> D();
                    }
                    else if(model -> getKostka(5,3) == 53 && model -> getKostka(5,7) == 51){
                        model -> Dprim();
                        model -> B();
                        model -> D();
                        model -> Bprim();
                        model -> D();
                        model -> B();
                        model -> D180();
                        model -> Bprim();
                        model -> D();
                    }
                    else if(model -> getKostka(5,5) == 53 && model -> getKostka(5,7) == 49){
                        model -> D();
                        model -> L();
                        model -> D();
                        model -> Lprim();
                        model -> D();
                        model -> L();
                        model -> D180();
                        model -> Lprim();
                        model -> D();
                    }
                    else if(model -> getKostka(5,7) == 53){
                        model -> F();
                        model -> D();
                        model -> Fprim();
                        model -> D();
                        model -> F();
                        model -> D180();
                        model -> Fprim();
                        model -> D180();

                        model -> L();
                        model -> D();
                        model -> Lprim();
                        model -> D();
                        model -> L();
                        model -> D180();
                        model -> Lprim();
                        model -> D();
                    }  // koniec przemieszczania pól krzyża
                    




                

                            /*for(int j=0; j<6 ; j++){
                        for(int i=0 ; i < 9; i++){
                             Serial.printf("%d   ",model -> getKostka(j,i));
                            
                        }
                        Serial.printf("\n ");}/
               Serial.printf("\n po krzyżu");
                Serial.printf("\n ");
                  Serial.printf("\n ");*/
               
                   if(model -> getKostka(5,0) == 46 && model -> getKostka(5,2) == 48 && model -> getKostka(5,6) == 52){
                       //Serial.printf("\n");
              /*for(int j=0; j<6 ; j++){
                        for(int i=0 ; i < 9; i++){
                           //  Serial.printf("%d   ",model -> getKostka(j,i));
                            
                        }
                       // Serial.printf("\n ");
                        }*/
                    }
				   else if ((model->getKostka(5, 0) != 16 || model->getKostka(5, 0) != 45 || model->getKostka(5, 0) != 46) &&
					   (model->getKostka(5, 2) != 18 || model->getKostka(5, 0) != 25 || model->getKostka(5, 0) != 48) &&
					   (model->getKostka(5, 6) != 36 || model->getKostka(5, 6) != 43 || model->getKostka(5, 0) != 52) &&
					   (model->getKostka(5, 8) != 27 || model->getKostka(5, 8) != 34 || model->getKostka(5, 8) != 54)) {
					   while ((model->getKostka(5, 0) != 16 && model->getKostka(5, 0) != 45 && model->getKostka(5, 0) != 46) &&
						   (model->getKostka(5, 2) != 18 && model->getKostka(5, 2) != 25 && model->getKostka(5, 2) != 48) &&
						   (model->getKostka(5, 6) != 36 && model->getKostka(5, 6) != 43 && model->getKostka(5, 6) != 52) &&
						   (model->getKostka(5, 8) != 27 && model->getKostka(5, 8) != 34 && model->getKostka(5, 8) != 54)) {
						   model->D();
						   model->B();
						   model->Dprim();
						   model->Fprim(); // pomieszanie rogów kostki
						   model->D();
						   model->Bprim();
						   model->Dprim();
						   model->F();
					   }


					   /*  for(int j=0; j<6 ; j++){
					for(int i=0 ; i < 9; i++){
						 Serial.printf("%d   ",model -> getKostka(j,i));

					}
					Serial.printf("\n ");}
		   Serial.printf("\n pomieszanie rogów");
			Serial.printf("\n ");
			  Serial.printf("\n ");*/

					   if (model->getKostka(5, 0) == 16 || model->getKostka(5, 0) == 45 || model->getKostka(5, 0) == 46) {
						   while ((model->getKostka(5, 2) != 18 && model->getKostka(5, 2) != 25 && model->getKostka(5, 2) != 48) ||
							   (model->getKostka(5, 6) != 36 && model->getKostka(5, 6) != 43 && model->getKostka(5, 6) != 52) ||
							   (model->getKostka(5, 8) != 27 && model->getKostka(5, 8) != 34 && model->getKostka(5, 8) != 54)) {
							   model->D();
							   model->L();
							   model->Dprim();
							   model->Rprim();
							   model->D();
							   model->Lprim();
							   model->Dprim();
							   model->R();
							   for (int j = 0; j < 6; j++) {
								   for (int i = 0; i < 9; i++) {
									   // Serial.printf("%d   ",model -> getKostka(j,i));

								   }
								   //  Serial.printf("\n ");
							   }

						   }
						   if (model->getKostka(5, 0) != 46) {
							   while (model->getKostka(5, 0) != 46) {
								   model->Lprim();
								   model->Uprim();
								   model->L();
								   model->U();
							   }
						   }

						   model->Dprim();

						   if (model->getKostka(5, 0) != 48) {
							   while (model->getKostka(5, 0) != 48) {
								   model->Lprim();
								   model->Uprim();
								   model->L();
								   model->U();
							   }
						   }

						   model->Dprim();

						   if (model->getKostka(5, 0) != 54) {
							   while (model->getKostka(5, 0) != 54) {
								   model->Lprim();
								   model->Uprim();
								   model->L();
								   model->U();
							   }
						   }

						   model->Dprim();

						   if (model->getKostka(5, 0) != 52) {
							   while (model->getKostka(5, 0) != 52) {
								   model->Lprim();
								   model->Uprim();
								   model->L();
								   model->U();
							   }
						   }

						   model->Dprim();
					   }

					   else   if (model->getKostka(5, 2) == 18 || model->getKostka(5, 2) == 25 || model->getKostka(5, 2) == 48) {
						   while ((model->getKostka(5, 0) != 16 && model->getKostka(5, 0) != 45 && model->getKostka(5, 0) != 46) ||
							   (model->getKostka(5, 6) != 36 && model->getKostka(5, 6) != 43 && model->getKostka(5, 6) != 52) ||
							   (model->getKostka(5, 8) != 27 && model->getKostka(5, 8) != 34 && model->getKostka(5, 8) != 54)) {
							   model->D();
							   model->F();
							   model->Dprim();
							   model->Bprim();
							   model->D();
							   model->Fprim();
							   model->Dprim();
							   model->B();

							   /* for(int j=0; j<6 ; j++){
					  for(int i=0 ; i < 9; i++){
						 //  Serial.printf("%d   ",model -> getKostka(j,i));

					  }
					//  Serial.printf("\n ");
								}*/
						   }

						   if (model->getKostka(5, 0) != 46) {
							   while (model->getKostka(5, 0) != 46) {
								   model->Lprim();
								   model->Uprim();
								   model->L();
								   model->U();


							   }
						   }

						   model->Dprim();


						   if (model->getKostka(5, 0) != 48) {
							   while (model->getKostka(5, 0) != 48) {
								   model->Lprim();
								   model->Uprim();
								   model->L();
								   model->U();
							   }
						   }

						   model->Dprim();

						   if (model->getKostka(5, 0) != 54) {
							   while (model->getKostka(5, 0) != 54) {
								   model->Lprim();
								   model->Uprim();
								   model->L();
								   model->U();
							   }
						   }

						   model->Dprim();

						   if (model->getKostka(5, 0) != 52) {
							   while (model->getKostka(5, 0) != 52) {
								   model->Lprim();
								   model->Uprim();
								   model->L();
								   model->U();
							   }
						   }

						   model->Dprim();

					   }

					   else if (model->getKostka(5, 6) == 36 || model->getKostka(5, 6) == 43 || model->getKostka(5, 6) == 52) {
						   while ((model->getKostka(5, 0) != 16 && model->getKostka(5, 0) != 45 && model->getKostka(5, 0) != 46) ||
							   (model->getKostka(5, 2) != 18 && model->getKostka(5, 2) != 25 && model->getKostka(5, 2) != 48) ||
							   (model->getKostka(5, 8) != 27 && model->getKostka(5, 8) != 34 && model->getKostka(5, 8) != 54)) {
							   model->D();
							   model->B();
							   model->Dprim();
							   model->Fprim();
							   model->D();
							   model->Bprim();
							   model->Dprim();
							   model->F();

						   }

						   if (model->getKostka(5, 0) != 46) {
							   while (model->getKostka(5, 0) != 46) {
								   model->Lprim();
								   model->Uprim();
								   model->L();
								   model->U();
							   }
						   }

						   model->Dprim();

						   if (model->getKostka(5, 0) != 48) {
							   while (model->getKostka(5, 0) != 48) {
								   model->Lprim();
								   model->Uprim();
								   model->L();
								   model->U();
							   }
						   }

						   model->Dprim();

						   if (model->getKostka(5, 0) != 54) {
							   while (model->getKostka(5, 0) != 54) {
								   model->Lprim();
								   model->Uprim();
								   model->L();
								   model->U();
							   }
						   }

						   model->Dprim();

						   if (model->getKostka(5, 0) != 52) {
							   while (model->getKostka(5, 0) != 52) {
								   model->Lprim();
								   model->Uprim();
								   model->L();
								   model->U();
							   }
						   }

						   model->Dprim();


					   }
				   
                      else   if(model -> getKostka(5,8) == 27 || model -> getKostka(5,8) == 34 || model -> getKostka(5,8) == 54){
                         while((model -> getKostka(5,0) != 16 && model -> getKostka(5,0) != 45 && model -> getKostka(5,0) !=46)||
                        (model -> getKostka(5,2) != 18 && model -> getKostka(5,2) != 25 && model -> getKostka(5,2) !=48)||
                        (model -> getKostka(5,6) != 36 && model -> getKostka(5,6) != 43 && model -> getKostka(5,6) !=52)) {
                                     model -> D();
                                     model -> R();
                                     model -> Dprim();
                                     model -> Lprim();
                                     model -> D();
                                     model -> Rprim();
                                     model -> Dprim();
                                     model -> L();

                        }
                         if(model -> getKostka(5,0) != 46){
                                    while(model -> getKostka(5,0) != 46){
                                        model -> Lprim();
                                        model -> Uprim();
                                        model -> L();
                                        model -> U();
                                    }
                                }

                                model -> Dprim();

                                if(model -> getKostka(5,0) != 48){
                                    while(model -> getKostka(5,0) != 48){
                                        model -> Lprim();
                                        model -> Uprim();
                                        model -> L();
                                        model -> U();
                                    }
                                }

                                model -> Dprim();

                                if(model -> getKostka(5,0) != 54){
                                    while(model -> getKostka(5,0) != 54){
                                        model -> Lprim();
                                        model -> Uprim();
                                        model -> L();
                                        model -> U();
                                    }
                                }

                                model -> Dprim();

                                if(model -> getKostka(5,0) != 52){
                                    while(model -> getKostka(5,0) != 52){
                                        model -> Lprim();
                                        model -> Uprim();
                                        model -> L();
                                        model -> U();
                                    }
                                }

                                model -> Dprim();
                      }
                         }

                       else if(model -> getKostka(5,0) == 16 || model -> getKostka(5,0) == 45 || model -> getKostka(5,0) == 46){
                         while((model -> getKostka(5,2) != 18 && model -> getKostka(5,2) != 25 && model -> getKostka(5,2) !=48)||
                        (model -> getKostka(5,6) != 36 && model -> getKostka(5,6) != 43 && model -> getKostka(5,6) !=52)||
                        (model -> getKostka(5,8) != 27 && model -> getKostka(5,8) != 34 && model -> getKostka(5,8) !=54)) {
                                                model -> D();
                                                model -> L();
                                                model -> Dprim();
                                                model -> Rprim();
                                                model -> D();
                                                model -> Lprim();
                                                model -> Dprim();
                                                model -> R();
                         }
                                if(model -> getKostka(5,0) != 46){
                                    while(model -> getKostka(5,0) != 46){
                                        model -> Lprim();
                                        model -> Uprim();
                                        model -> L();
                                        model -> U();
                                    }
                                }

                                model -> Dprim();

                                if(model -> getKostka(5,0) != 48){
                                    while(model -> getKostka(5,0) != 48){
                                        model -> Lprim();
                                        model -> Uprim();
                                        model -> L();
                                        model -> U();
                                    }
                                }

                                model -> Dprim();

                                if(model -> getKostka(5,0) != 54){
                                    while(model -> getKostka(5,0) != 54){
                                        model -> Lprim();
                                        model -> Uprim();
                                        model -> L();
                                        model -> U();
                                    }
                                }

                                model -> Dprim();

                                if(model -> getKostka(5,0) != 52){
                                    while(model -> getKostka(5,0) != 52){
                                        model -> Lprim();
                                        model -> Uprim();
                                        model -> L();
                                        model -> U();
                                    }
                                }

                                model -> Dprim();
                     }
                      else   if(model -> getKostka(5,2) == 18 || model -> getKostka(5,2) == 25 || model -> getKostka(5,2) == 48){
                         while((model -> getKostka(5,0) != 16 && model -> getKostka(5,0) != 45 && model -> getKostka(5,0) !=46)||
                        (model -> getKostka(5,6) != 36 && model -> getKostka(5,6) != 43 && model -> getKostka(5,6) !=52)||
                        (model -> getKostka(5,8) != 27 && model -> getKostka(5,8) != 34 && model -> getKostka(5,8) !=54)) {   
                                     model -> D();
                                     model -> F();
                                     model -> Dprim();
                                     model -> Bprim();
                                     model -> D();
                                     model -> Fprim();
                                     model -> Dprim();
                                     model -> B(); 

                                 
                             }

                            if(model -> getKostka(5,0) != 46){
                                    while(model -> getKostka(5,0) != 46){
                                        model -> Lprim();
                                        model -> Uprim();
                                        model -> L();
                                        model -> U();

                                         
                                    }
                                }

                                model -> Dprim();

                           
                                if(model -> getKostka(5,0) != 48){
                                    while(model -> getKostka(5,0) != 48){
                                        model -> Lprim();
                                        model -> Uprim();
                                        model -> L();
                                        model -> U();
                                    }
                                }

                                model -> Dprim();

                                if(model -> getKostka(5,0) != 54){
                                    while(model -> getKostka(5,0) != 54){
                                        model -> Lprim();
                                        model -> Uprim();
                                        model -> L();
                                        model -> U();
                                    }
                                }

                                model -> Dprim();

                                if(model -> getKostka(5,0) != 52){
                                    while(model -> getKostka(5,0) != 52){
                                        model -> Lprim();
                                        model -> Uprim();
                                        model -> L();
                                        model -> U();
                                    }
                                }

                                model -> Dprim();

                    }
                     else   if(model -> getKostka(5,6) == 36 || model -> getKostka(5,6) == 43 || model -> getKostka(5,6) == 52){
                         while((model -> getKostka(5,0) != 16 && model -> getKostka(5,0) != 45 && model -> getKostka(5,0) !=46)||
                        (model -> getKostka(5,2) != 18 && model -> getKostka(5,2) != 25 && model -> getKostka(5,2) !=48)||
                        (model -> getKostka(5,8) != 27 && model -> getKostka(5,8) != 34 && model -> getKostka(5,8) !=54)) {
                                     model -> D();
                                     model -> B();
                                     model -> Dprim();
                                     model -> Fprim();
                                     model -> D();
                                     model -> Bprim();
                                     model -> Dprim();
                                     model -> F();

                        }

                        if(model -> getKostka(5,0) != 46){
                                    while(model -> getKostka(5,0) != 46){
                                        model -> Lprim();
                                        model -> Uprim();
                                        model -> L();
                                        model -> U();
                                    }
                                }

                                model -> Dprim();

                                if(model -> getKostka(5,0) != 48){
                                    while(model -> getKostka(5,0) != 48){
                                        model -> Lprim();
                                        model -> Uprim();
                                        model -> L();
                                        model -> U();
                                    }
                                }

                                model -> Dprim();

                                if(model -> getKostka(5,0) != 54){
                                    while(model -> getKostka(5,0) != 54){
                                        model -> Lprim();
                                        model -> Uprim();
                                        model -> L();
                                        model -> U();
                                    }
                                }

                                model -> Dprim();

                                if(model -> getKostka(5,0) != 52){
                                    while(model -> getKostka(5,0) != 52){
                                        model -> Lprim();
                                        model -> Uprim();
                                        model -> L();
                                        model -> U();
                                    }
                                }

                                model -> Dprim();


                     }
                      else   if(model -> getKostka(5,8) == 27 || model -> getKostka(5,8) == 34 || model -> getKostka(5,8) == 54){
                         while((model -> getKostka(5,0) != 16 && model -> getKostka(5,0) != 45 && model -> getKostka(5,0) !=46)||
                        (model -> getKostka(5,2) != 18 && model -> getKostka(5,2) != 25 && model -> getKostka(5,2) !=48)||
                        (model -> getKostka(5,6) != 36 && model -> getKostka(5,6) != 43 && model -> getKostka(5,6) !=52)) {
                                     model -> D();
                                     model -> R();
                                     model -> Dprim();
                                     model -> Lprim();
                                     model -> D();
                                     model -> Rprim();
                                     model -> Dprim();
                                     model -> L();

                        }
                         if(model -> getKostka(5,0) != 46){
                                    while(model -> getKostka(5,0) != 46){
                                        model -> Lprim();
                                        model -> Uprim();
                                        model -> L();
                                        model -> U();
                                    }
                                }

                                model -> Dprim();

                                if(model -> getKostka(5,0) != 48){
                                    while(model -> getKostka(5,0) != 48){
                                        model -> Lprim();
                                        model -> Uprim();
                                        model -> L();
                                        model -> U();
                                    }
                                }

                                model -> Dprim();

                                if(model -> getKostka(5,0) != 54){
                                    while(model -> getKostka(5,0) != 54){
                                        model -> Lprim();
                                        model -> Uprim();
                                        model -> L();
                                        model -> U();
                                    }
                                }

                                model -> Dprim();

                                if(model -> getKostka(5,0) != 52){
                                    while(model -> getKostka(5,0) != 52){
                                        model -> Lprim();
                                        model -> Uprim();
                                        model -> L();
                                        model -> U();
                                    }
                                }

                                model -> Dprim();
                      }



                 
              
   }      

                   
   
};
