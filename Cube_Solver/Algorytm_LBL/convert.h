#include "algorytm.h"
#include "obrot.h"

class Convert{
private: 
        static int indykator_d;
        static int indykator_p;
public:
        static void konwertuj(Kostka*& model){
            indykator_d = 0;
            indykator_p = 1;
          //  Serial.printf("%d\n to jest liczba ruchow  ", model -> getRozmiar());
             Serial.printf("\n");
         Serial.printf("%d\n", indykator_d);
         Serial.printf("%d\n", indykator_p);
         Serial.printf("\n");
                for(int i=0; i < model -> getRozmiar(); i++){
                    Serial.printf("%d ",i ); 
                    Serial.printf("%d\n " , model -> getRuchy(i));
                    Serial.printf("\n");
                    if(model -> getRuchy(i)  == 1 || model -> getRuchy(i) == 2 || model -> getRuchy(i) ==3){
                            if(indykator_d == 0){  // kostka leży na górnej ściance
                               
                            }
                            else if(indykator_d == 1 && indykator_p ==0 ){ // kostka leży na przedniej ściance, z przodu znajduje się ściana górna
                                Obrot::przerzuc();
                                indykator_d = 0;
                                indykator_p = 3;
                            }
                            else if(indykator_d == 1 && indykator_p ==2 ){ // kostka leży na przedniej ściance, z przodu znajduje się ściana prawa
                                Obrot::uciekaj();
                                Obrot::obrot_90L();
                                Obrot::zlap();
                                Obrot::przerzuc(); 
                               
                                indykator_d = 0;
                                indykator_p = 3;
                            }
                            else if(indykator_d == 1 && indykator_p ==5 ){ // kostka leży na przedniej ściance, z przodu znajduje się ściana dolna
                                Obrot::uciekaj();
                                Obrot::obrot_180();
                                Obrot::zlap();
                                Obrot::przerzuc();
                                 indykator_d = 0;
                                indykator_p = 3;
                            }
                            else if(indykator_d == 1 && indykator_p ==4 ){ // kostka leży na przedniej ściance, z przodu znajduje się ściana lewa
                                Obrot::uciekaj();
                                Obrot::obrot_90P();
                                Obrot::zlap();
                                Obrot::przerzuc();
                                 indykator_d = 0;
                                indykator_p = 3;
                            }
                            else if(indykator_d == 2 && indykator_p ==0 ){ // kostka leży na prawej ściance, z przodu znajduje się ściana górna
                                Obrot::przerzuc();
                                 indykator_d = 0;
                                indykator_p = 4;
                            }
                            else if(indykator_d == 2 && indykator_p ==3 ){ // kostka leży na prawej ściance, z przodu znajduje się ściana tylna
                                Obrot::uciekaj();
                                Obrot::obrot_90L();
                                Obrot::zlap();
                                Obrot::przerzuc();
                                 indykator_d = 0;
                                indykator_p = 4;
                            }
                            else if(indykator_d == 2 && indykator_p ==5 ){ // kostka leży na prawej ściance, z przodu znajduje się ściana dolna
                                Obrot::uciekaj();
                                Obrot::obrot_180();
                                Obrot::zlap();
                                Obrot::przerzuc();
                                 indykator_d = 0;
                                indykator_p = 4;
                            } 
                            else if(indykator_d == 2 && indykator_p ==1 ){ // kostka leży na pprawej ściance, z przodu znajduje się ściana przednia
                                Obrot::uciekaj();
                                Obrot::obrot_90P();
                                Obrot::zlap();
                                Obrot::przerzuc();
                                indykator_d = 0;
                                indykator_p = 4;
                            }
                            else if(indykator_d == 3 && indykator_p ==0 ){ // kostka leży na tylnej ściance, z przodu znajduje się ściana górna
                                Obrot::przerzuc();
                                indykator_d = 0;
                                indykator_p = 1;
                            }
                            else if(indykator_d == 3 && indykator_p ==4 ){ // kostka leży na pprawej ściance, z przodu znajduje się ściana lewa
                                Obrot::uciekaj();
                                Obrot::obrot_90L();
                                Obrot::zlap();
                                Obrot::przerzuc();
                                indykator_d = 0;
                                indykator_p = 1;
                            }
                            else if(indykator_d == 3 && indykator_p ==5 ){ // kostka leży na pprawej ściance, z przodu znajduje się ściana dolna
                                Obrot::uciekaj();
                                Obrot::obrot_180();
                                Obrot::zlap();
                                Obrot::przerzuc();
                                indykator_d = 0;
                                indykator_p = 1;
                            }
                            else if(indykator_d == 3 && indykator_p ==2 ){ // kostka leży na pprawej ściance, z przodu znajduje się ściana prawa
                                Obrot::uciekaj();
                                Obrot::obrot_90P();
                                Obrot::zlap();
                                Obrot::przerzuc();
                                indykator_d = 0;
                                indykator_p = 1;
                            }
                             else if(indykator_d == 4 && indykator_p ==0 ){ // kostka leży na lewej ściance, z przodu znajduje się ściana górna
                                Obrot::przerzuc();
                                 indykator_d = 0;
                                indykator_p = 2;
                            }
                               else if(indykator_d == 4 && indykator_p ==1 ){ // kostka leży na lewej ściance, z przodu znajduje się ściana przednia
                                Obrot::uciekaj();
                                Obrot::obrot_90L();
                                Obrot::zlap();
                                Obrot::przerzuc();
                                indykator_d = 0;
                                indykator_p = 2;
                            } 
                               else if(indykator_d == 4 && indykator_p ==5 ){ // kostka leży na pprawej ściance, z przodu znajduje się dolna
                                Obrot::uciekaj();
                                Obrot::obrot_180();
                                Obrot::zlap();
                                Obrot::przerzuc();
                                indykator_d = 0;
                                indykator_p = 2;
                            }
                               else if(indykator_d == 4 && indykator_p ==3 ){ // kostka leży na pprawej ściance, z przodu znajduje się ściana 
                                Obrot::uciekaj();
                                Obrot::obrot_90P();
                                Obrot::zlap();
                                Obrot::przerzuc();
                                indykator_d = 0;
                                indykator_p = 2;
                            }
                             else if(indykator_d == 5 && indykator_p ==1 ){ // kostka leży na dolnej ściance, z przodu znajduje się ściana przednia
                                Obrot::przerzuc();
                                Obrot::przerzuc();
                                 indykator_d = 0;
                                indykator_p = 3;
                            }
                             else if(indykator_d == 5 && indykator_p ==2 ){ // kostka leży na dolnej ściance, z przodu znajduje się ściana prawa
                                Obrot::przerzuc();
                                Obrot::przerzuc();
                                 indykator_d = 0;
                                indykator_p = 4;
                            }
                             else if(indykator_d == 5 && indykator_p ==3 ){ // kostka leży na dolnej ściance, z przodu znajduje się ściana tylna
                                Obrot::przerzuc();
                                Obrot::przerzuc();
                                 indykator_d = 0;
                                indykator_p = 1;
                            }
                             else if(indykator_d == 5 && indykator_p ==4 ){ // kostka leży na dolnej ściance, z przodu znajduje się ściana przednia
                                Obrot::przerzuc();
                                Obrot::przerzuc();
                                 indykator_d = 0;
                                indykator_p = 2;
                            }
                            
// ------------------- sprawdzono ---------------------------//2
                             if(model -> getRuchy(i) == 1){   // obrót kostki w zadaną stronę  
                                    Obrot::obrot_90L();
                                }
                                else if(model -> getRuchy(i) == 2){
                                    Obrot::obrot_90P();
                                }
                                else if(model -> getRuchy(i) == 3){
                                    Obrot::obrot_180();
                                }
                           
                    }
                    else  if(model -> getRuchy(i)  == 4 || model -> getRuchy(i) == 5 || model -> getRuchy(i) ==6){
                                if(indykator_d == 1){

                                }
                                else if(indykator_d == 0 && indykator_p == 1 ){
                                    Obrot::przerzuc();
                                    indykator_d = 1;
                                    indykator_p = 5;
                                }
                                else if(indykator_d == 0 && indykator_p == 4 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90L();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 1;
                                    indykator_p = 5;
                                }
                                 else if(indykator_d == 0 && indykator_p == 3 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_180();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 1;
                                    indykator_p = 5;
                                }
                                 else if(indykator_d == 0 && indykator_p == 2 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90P();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 1;
                                    indykator_p = 5;
                                }
                                 else if(indykator_d == 2 && indykator_p == 1 ){
                      //2              
                                    Obrot::przerzuc();
                                    indykator_d = 1;
                                    indykator_p = 4;
                                }
                                 else if(indykator_d == 2 && indykator_p == 0 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90L();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 1;
                                    indykator_p = 4;
                                }
                                 else if(indykator_d == 2 && indykator_p == 3 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_180();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 1;
                                    indykator_p = 4;
                                }
                                 else if(indykator_d == 2 && indykator_p == 5 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90P();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 1;
                                    indykator_p = 4;
                                }
                                else if(indykator_d == 3 && indykator_p == 0){
                                    Obrot::przerzuc();
                                    Obrot::przerzuc();
                                    indykator_d = 1;
                                    indykator_p = 5;
                                }
                                else if(indykator_d == 3 && indykator_p == 4){
                                    Obrot::przerzuc();
                                    Obrot::przerzuc();
                                    indykator_d = 1;
                                    indykator_p = 2;
                                }
                                else if(indykator_d == 3 && indykator_p == 5){
                                    Obrot::przerzuc();
                                    Obrot::przerzuc();
                                    indykator_d = 1;
                                    indykator_p = 0;
                                }
                                else if(indykator_d == 3 && indykator_p == 2){
                                    Obrot::przerzuc();
                                    Obrot::przerzuc();
                                    indykator_d = 1;
                                    indykator_p = 4;
                                }
                                else if(indykator_d == 4 && indykator_p == 1){
                                    Obrot::przerzuc();
                                    indykator_d = 1;
                                    indykator_p = 2;
                                }
                                 else if(indykator_d == 4 && indykator_p == 5 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90L();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 1;
                                    indykator_p = 2;
                                }
                                 else if(indykator_d == 4 && indykator_p == 3 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_180();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 1;
                                    indykator_p = 2;
                                }
                                 else if(indykator_d == 4 && indykator_p == 0 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90P();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 1;
                                    indykator_p = 2;
                                }
                                //------------------sprawdzone--------------------//2
                                else if(indykator_d == 5 && indykator_p == 1){
                                    Obrot::przerzuc();
                                    indykator_d = 1;
                                    indykator_p = 0;  
                                }
                                 else if(indykator_d == 5 && indykator_p == 2 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90L();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 1;
                                    indykator_p = 0;
                                }
                                 else if(indykator_d == 5 && indykator_p == 3 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_180();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 1;
                                    indykator_p = 0;
                                }
                                 else if(indykator_d == 5 && indykator_p == 4 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90P();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 1;
                                    indykator_p = 0;
                                }

                                if(model -> getRuchy(i) == 4){   // obrót kostki w zadaną stronę
                                    Obrot::obrot_90L();
                                }
                                else if(model -> getRuchy(i) == 5){
                                    Obrot::obrot_90P();
                                }
                                else if(model -> getRuchy(i) == 6){
                                    Obrot::obrot_180();
                                }
//-------------------sprawdzone -------------------------------//2
                                

                    }
                    else if(model -> getRuchy(i)  == 7 || model -> getRuchy(i) == 8 || model -> getRuchy(i) ==9){
                        if(indykator_d == 2){

                        }
                        else if(indykator_d == 0 && indykator_p == 2){
                            Obrot::przerzuc();
                            indykator_d = 2;
                            indykator_p = 5;
                        }
                        else if(indykator_d == 0 && indykator_p == 1 ){
                            Obrot::uciekaj();
                            Obrot::obrot_90L();
                            Obrot::zlap();
                            Obrot::przerzuc();
                            indykator_d = 2;
                            indykator_p = 5;
                            }
                          else if(indykator_d == 0 && indykator_p == 4 ){
                            Obrot::uciekaj();
                            Obrot::obrot_180();
                            Obrot::zlap();
                            Obrot::przerzuc();
                            indykator_d = 2;
                            indykator_p = 5;
                        }
                          else if(indykator_d == 0 && indykator_p == 3 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90P();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 2;
                                    indykator_p = 5;
                        }

                        // sprawdzone
                        else if(indykator_d == 1 && indykator_p == 2){
                            Obrot::przerzuc();
                            indykator_d = 2;
                            indykator_p = 3;
                        }
                          else if(indykator_d == 1 && indykator_p == 5 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90L();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 2;
                                    indykator_p = 3;
                                }
                        else if(indykator_d == 1 && indykator_p == 4 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_180();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 2;
                                    indykator_p = 3;
                                }
                         else if(indykator_d == 1 && indykator_p == 0 ){// WT...
                                    Obrot::uciekaj();
                                    Obrot::obrot_90P();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 2;
                                    indykator_p = 3;
                                }
                         else if(indykator_d == 3 && indykator_p == 2){
                                Obrot::przerzuc();
                                indykator_d = 2;
                                indykator_p = 1;
                         }
                           else if(indykator_d == 3 && indykator_p == 0 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90L();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 2;
                                    indykator_p = 1;
                                }
                       else if(indykator_d == 3 && indykator_p == 4 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_180();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 2;
                                    indykator_p = 1;
                                }
                          else if(indykator_d == 3 && indykator_p == 5 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90P();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 2;
                                    indykator_p = 1;
                                }
                        else if(indykator_d == 4 && indykator_p == 0){
                            Obrot::przerzuc();
                            Obrot::przerzuc();
                            indykator_d = 2;
                            indykator_p =5;
                        }
                        else if (indykator_d == 4 && indykator_p == 1){
                            Obrot::przerzuc();
                            Obrot::przerzuc();
                            indykator_d = 2;
                            indykator_p = 3;
                        }
                        else if(indykator_d == 4 && indykator_p == 5){
                            Obrot::przerzuc();
                            Obrot::przerzuc();
                            indykator_d = 2;
                            indykator_p = 0;
                        }
                        else if(indykator_d == 4 && indykator_p == 3){
                            Obrot::przerzuc();
                            Obrot::przerzuc();
                            indykator_d = 2;
                            indykator_p = 1;
                        }
                        else if(indykator_d == 5 && indykator_p == 2){
                            Obrot::przerzuc();
                            indykator_d = 2;
                            indykator_p = 0;
                        }
                          else if(indykator_d == 5 && indykator_p == 3 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90L();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 2;
                                    indykator_p = 0;
                                }
                          else if(indykator_d == 5 && indykator_p == 4 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_180();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 2;
                                    indykator_p = 0;
                                }
                            else if(indykator_d == 5 && indykator_p == 1 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90P();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 2;
                                    indykator_p = 0;
                                }

                                  if(model -> getRuchy(i) == 7){   // obrót kostki w zadaną stronę
                                    Obrot::obrot_90L();
                                }
                                else if(model -> getRuchy(i) == 8){
                                    Obrot::obrot_90P();
                                }
                                else if(model -> getRuchy(i) == 9){
                                    Obrot::obrot_180();
                                }                        

                    }

                    //-----------------------------sprawdzone --------------------//2
                    else if(model -> getRuchy(i) == 10 || model -> getRuchy(i) == 11 || model -> getRuchy(i) == 12){ // obroty tylnej ścianki
                            if(indykator_d == 0 && indykator_p == 3){
                                Obrot::przerzuc();
                                indykator_d = 3;
                                indykator_p = 5;
                            }
                            else if(indykator_d == 0 && indykator_p == 2 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90L();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 3;
                                    indykator_p = 5;
                                }
                            else if(indykator_d == 0 && indykator_p == 1 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_180();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 3;
                                    indykator_p = 5;
                                }
                            else if(indykator_d == 0 && indykator_p == 4 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90P();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 3;
                                    indykator_p = 5;
                                }

                                //s
                            else if(indykator_d == 1 && indykator_p == 0 ){
                                    Obrot::przerzuc();
                                    Obrot::przerzuc();
                                    indykator_d = 3;
                                    indykator_p =5;
                                }    
                            else if(indykator_d == 1 && indykator_p == 2){
                                Obrot::przerzuc();
                                Obrot::przerzuc();
                                indykator_d = 3;
                                indykator_p =4;
                            }//s
                            else if(indykator_d == 1 && indykator_p == 5){
                                Obrot::przerzuc();
                                Obrot::przerzuc();
                                indykator_d = 3;
                                indykator_p = 0;
                            }
                            else if(indykator_d == 1 && indykator_p == 4){
                                Obrot::przerzuc();
                                Obrot::przerzuc();
                                indykator_d = 3;
                                indykator_p = 2;
                            } // sprawdzone
                            else if(indykator_d == 2 && indykator_p == 3){
                                Obrot::przerzuc();
                                indykator_d = 3;
                                indykator_p = 4;
                            }
                            else if(indykator_d == 2 && indykator_p == 5 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90L();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 3;
                                    indykator_p = 4;
                                }
                            else if(indykator_d == 2 && indykator_p == 1 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_180();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 3;
                                    indykator_p = 4;
                                }
                            else if(indykator_d == 2 && indykator_p == 0 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90P();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 3;
                                    indykator_p = 4;
                                }//s//////////////////////////
                            else if(indykator_d == 4 && indykator_p == 3){
                                Obrot::przerzuc();
                                indykator_d = 3;
                                indykator_p = 2;
                            }    
                            else if(indykator_d == 4 && indykator_p == 0 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90L();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 3;
                                    indykator_p = 2;
                                }
                            else if(indykator_d == 4 && indykator_p == 1 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_180();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 3;
                                    indykator_p = 2;
                                }
                            else if(indykator_d == 4 && indykator_p == 5 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90P();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 3;
                                    indykator_p = 2;
                                }
                            else if(indykator_d == 5 && indykator_p == 3){
                                Obrot::przerzuc();
                                indykator_d = 3;
                                indykator_p =0;
                            }
                            else if(indykator_d == 5 && indykator_p == 4 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90L();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 3;
                                    indykator_p = 0;
                                }
                            else if(indykator_d == 5 && indykator_p == 1 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_180();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 3;
                                    indykator_p = 0;
                                }
                            else if(indykator_d == 5 && indykator_p == 2 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90P();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 3;
                                    indykator_p = 0;
                                }                
                            
                    
                                if(model -> getRuchy(i) == 10){   // obrót kostki w zadaną stronę
                                    Obrot::obrot_90L();
                                }
                                else if(model -> getRuchy(i) == 11){
                                    Obrot::obrot_90P();
                                }
                                else if(model -> getRuchy(i) == 12){
                                    Obrot::obrot_180();
                                }  

                    } // ---------------------------sprawdzone --------------------------// 2
                    else if(model -> getRuchy(i) == 13 || model -> getRuchy(i) == 14 || model -> getRuchy(i) == 15){
                        if(indykator_d == 0 && indykator_p == 4){
                            Obrot::przerzuc();
                            indykator_d = 4;
                            indykator_p = 5;
                        }
                         else if(indykator_d == 0 && indykator_p == 3 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90L();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 4;
                                    indykator_p = 5;
                                }
                         else if(indykator_d == 0 && indykator_p == 2 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_180();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 4;
                                    indykator_p = 5;
                                }  
                         else if(indykator_d == 0 && indykator_p == 1 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90P();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 4;
                                    indykator_p = 5;
                                }//ss
                        else if(indykator_d == 1 && indykator_p == 4){
                                    Obrot::przerzuc();
                                    indykator_d = 4;
                                    indykator_p =3;
                        }
                         else if(indykator_d == 1 && indykator_p == 0 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90L();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 4;
                                    indykator_p = 3;
                                }
                         else if(indykator_d == 1 && indykator_p == 2 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_180();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 4;
                                    indykator_p = 3;
                                }
                         else if(indykator_d == 1 && indykator_p == 5 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90P();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 4;
                                    indykator_p = 3;
                                } //ss
                          else if(indykator_d == 2 && indykator_p == 0){
                              Obrot::przerzuc();
                              Obrot::przerzuc();
                              indykator_d = 4;
                              indykator_p = 5;
                          } 
                          else if(indykator_d == 2 && indykator_p == 3){
                              Obrot::przerzuc();
                              Obrot::przerzuc();
                              indykator_d = 4;
                              indykator_p = 1;
                          }//s
                          else if(indykator_d == 2 && indykator_p == 5){
                              Obrot::przerzuc();
                              Obrot::przerzuc();
                              indykator_d = 4;
                              indykator_p = 0;
                          } 
                          else if(indykator_d == 2 && indykator_p == 1){
                              Obrot::przerzuc();
                              Obrot::przerzuc();
                              indykator_d = 4;
                              indykator_p = 3;
                          }//l
                          else if(indykator_d == 3 && indykator_p == 4){
                              Obrot::przerzuc();
                              indykator_d = 4;
                              indykator_p = 1;
                          }
                          else if(indykator_d == 3 && indykator_p == 5 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90L();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 4;
                                    indykator_p = 1;
                                }
                           else if(indykator_d == 3 && indykator_p == 2 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_180();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 4;
                                    indykator_p = 1;
                                }
                             else if(indykator_d == 3 && indykator_p == 0 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90P();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 4;
                                    indykator_p = 1;
                                }//p
                             else if(indykator_d == 5 && indykator_p == 4){
                              Obrot::przerzuc();
                              indykator_d = 4;
                              indykator_p = 0;
                          }
                          else if(indykator_d == 5 && indykator_p == 1 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90L();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 4;
                                    indykator_p = 0;
                                }
                           else if(indykator_d == 5 && indykator_p == 2 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_180();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 4;
                                    indykator_p = 0;
                                }
                             else if(indykator_d == 5 && indykator_p == 3 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90P();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 4;
                                    indykator_p = 0;
                                }

                                 if(model -> getRuchy(i) == 13){   // obrót kostki w zadaną stronę
                                    Obrot::obrot_90L();
                                }
                                else if(model -> getRuchy(i) == 14){
                                    Obrot::obrot_90P();
                                }
                                else if(model -> getRuchy(i) == 15){
                                    Obrot::obrot_180();
                                }    
//------------------------sprawdzone ------------------------//2
                                          
                    }
                     else if(model -> getRuchy(i) == 16 || model -> getRuchy(i) == 17 || model -> getRuchy(i) == 18){
                          if(indykator_d == 0 && indykator_p ==1 ){
                              Obrot::przerzuc();
                              Obrot::przerzuc();
                              indykator_d = 5;
                              indykator_p = 3;
                          }  
                          else if(indykator_d == 0 && indykator_p == 4){
                              Obrot::przerzuc();
                              Obrot::przerzuc();
                              indykator_d = 5;
                              indykator_p = 2;
                          }
                          else if(indykator_d == 0 && indykator_p == 3){
                              Obrot::przerzuc();
                              Obrot::przerzuc();
                              indykator_d = 5;
                              indykator_p = 1;
                          }
                          else if(indykator_d == 0 && indykator_p == 2){
                              Obrot::przerzuc();
                              Obrot::przerzuc();
                              indykator_d = 5;
                              indykator_p = 4;
                          } // sprawdzone

                        else if(indykator_d == 1 && indykator_p == 5){
                            Obrot::przerzuc();
                            indykator_d = 5;
                            indykator_p = 3;
                        }
                         else if(indykator_d == 1 && indykator_p == 4 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90L();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 5;
                                    indykator_p = 3;
                                }
                         else if(indykator_d == 1 && indykator_p == 0 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_180();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 5;
                                    indykator_p = 3;
                                }  
                         else if(indykator_d == 1 && indykator_p == 2 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90P();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 5;
                                    indykator_p = 3;
                                }
//ss
                                 else if(indykator_d == 2 && indykator_p == 5){
                            Obrot::przerzuc();
                            indykator_d = 5;
                            indykator_p = 4;
                        }
                         else if(indykator_d == 2 && indykator_p == 1 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90L();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 5;
                                    indykator_p = 4;
                                }
                         else if(indykator_d == 2 && indykator_p == 0 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_180();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 5;
                                    indykator_p = 4;
                                }  
                         else if(indykator_d == 2 && indykator_p == 3 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90P();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 5;
                                    indykator_p = 4; // tu byl blad
                                }

                         else if(indykator_d == 3 && indykator_p == 5){
                            Obrot::przerzuc();
                            indykator_d = 5;
                            indykator_p = 1;
                        }
                         else if(indykator_d == 3 && indykator_p == 2 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90L();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 5;
                                    indykator_p = 1;
                                }
                         else if(indykator_d == 3 && indykator_p == 0 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_180();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 5;
                                    indykator_p = 1;
                                }  
                         else if(indykator_d == 3 && indykator_p == 4 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90P();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 5;
                                    indykator_p = 1;
                                }

                         else if(indykator_d == 4 && indykator_p == 5){
                            Obrot::przerzuc();
                            indykator_d = 5;
                            indykator_p = 2;
                        }
                         else if(indykator_d == 4 && indykator_p == 3 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90L();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 5;
                                    indykator_p = 2;
                                }
                         else if(indykator_d == 4 && indykator_p == 0 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_180();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 5;
                                    indykator_p = 2;
                                }  
                         else if(indykator_d == 4 && indykator_p == 1 ){
                                    Obrot::uciekaj();
                                    Obrot::obrot_90P();
                                    Obrot::zlap();
                                    Obrot::przerzuc();
                                    indykator_d = 5;
                                    indykator_p = 2;
                                }                
                     }

                        if(model -> getRuchy(i) == 16){   // obrót kostki w zadaną stronę
                                    Obrot::obrot_90L();
                                }
                                else if(model -> getRuchy(i) == 17){
                                    Obrot::obrot_90P();
                                }
                                else if(model -> getRuchy(i) == 18){
                                    Obrot::obrot_180();
                                }    
                    

                }

//--------- sprawdzone-//2

                }
        

};