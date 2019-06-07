
using namespace std;
#include <vector>
class Kostka{  // utworzenie klasy Kostka
private:	
 int  kosstka[6][9];  // prywatne pole reprezentujące aktualny stan kostki
 int bufor_1[9];               //utworzenie bufora  ściany
 static vector<int> ruchy;  // utworzenie tablicy zapisującej wykonane ruchy podczas układania
 int bufor_2[3];           // utworzenie bufora pól bocznych ścianek związanych ze  ścianą górną

public:


	int getRuchy(int a){   // odczytanie dowolnego pola wektora ruchy
		return ruchy[a];
	}

	void setRuchy(int a){                 // dodanie nowego pola pola wektora ruchy
			ruchy.push_back(a);
	}

	int getRozmiar(){                                 // odczytanie rozmiaru wektora ruchy
		return ruchy.size();
	}

	void clearRuchy(){   // wyczyszczenie wekotra ruchy
		ruchy.clear();
	}

   int getKostka(int a, int b){
	   return kosstka[a][b];
	  
   }
   Kostka() {

   }
   Kostka(int dane[6][9]) {  // konstruktor z paramterem - tablicą reprezentującą wyjściowy stan kostki

	   for (int j = 0; j < 6; j++) {  // wypełnienie tablicy kosstka na podstawie zadanego stanu przy pomocy pętli for
		   for (int k = 0; k < 9; k++) {
			   kosstka[j][k] = dane[j][k];
		   }
	   }
   }


	void U(){ // metoda powodująca obrót górnej ścianki kostki (U - upper)
        
			   
		for(int i=0 ; i<9 ; i++){    // przypisanie buforowi pół górnej ściany przy pomocy pętli for
			bufor_1[i] = kosstka[0][i];
			
		}

		kosstka[0][0] = bufor_1[6];     
		kosstka[0][1] = bufor_1[3];
		kosstka[0][2] = bufor_1[0];
        kosstka[0][3] = bufor_1[7];  // zmiana orientacji górnej ścianki względem ścian bocznych
		kosstka[0][5] = bufor_1[1];
		kosstka[0][6] = bufor_1[8];
		kosstka[0][7] = bufor_1[5];
		kosstka[0][8] = bufor_1[2];
		   
		for(int i=0 ; i<9 ; i++){    // przypisanie buforowi pól górnej ściany przy pomocy pętli for
			bufor_1[i] = kosstka[0][i];
		}
	
		bufor_2[0] = kosstka[1][0];  // przypisanie buforowi pól jednej z bocznych ścian związanych ze  scianą górną
		bufor_2[1] = kosstka[1][1];
		bufor_2[2] = kosstka[1][2];

		 for(int j=1 ; j < 4 ; j++){
			kosstka[j][0] = kosstka[j+1][0];  
			kosstka[j][1] = kosstka[j+1][1];  // zmiana pól zgodnie z obrotem
			kosstka[j][2] = kosstka[j+1][2];  

		 }

		kosstka[4][0] = bufor_2[0];
		kosstka[4][1] = bufor_2[1];      // przypisanie pól do odpowiedniej ze ścian na podstawie bufora  
		kosstka[4][2] = bufor_2[2];
			
			ruchy.push_back(1);  // zapisanie obroru do tablicy ruchy
	}

	void Uprim(){ // metoda powodująca obrót górnej ścianki przeciwnie do ruchu wskazówek zegara

		   
		for(int i=0 ; i<9 ; i++){    // przypisanie buforowi pół górnej ściany przy pomocy pętli for
			bufor_1[i] = kosstka[0][i];
		}
		kosstka[0][0] = bufor_1[2];     
		kosstka[0][1] = bufor_1[5];
		kosstka[0][2] = bufor_1[8];
        kosstka[0][3] = bufor_1[1];  // zmiana orientacji górnej ścianki względem ścian bocznych
		kosstka[0][5] = bufor_1[7];
		kosstka[0][6] = bufor_1[0];
		kosstka[0][7] = bufor_1[3];
		kosstka[0][8] = bufor_1[6];



		
		bufor_2[0] = kosstka[4][0];  // przypisanie buforowi pól jednej z bocznych ścian związanych ze  scianą górną
		bufor_2[1] = kosstka[4][1];
		bufor_2[2] = kosstka[4][2];

		 for(int j=4 ; j > 1 ; j--){
			kosstka[j][0] = kosstka[j-1][0];  
			kosstka[j][1] = kosstka[j-1][1];  // zmiana pól zgodnie z obrotem
			kosstka[j][2] = kosstka[j-1][2];  

		 }

		kosstka[1][0] = bufor_2[0];
		kosstka[1][1] = bufor_2[1];   // przypisanie pól do odpowiedniej ze ścian na podstawie bufora  
		kosstka[1][2] = bufor_2[2];

	ruchy.push_back(2);  // zapisanie obroru do tablicy ruchy
	}


void U180(){ // metoda powodująca obrót przedniej górnej kostki (U - upper) o 180 stipni
        
			   
		for(int i=0 ; i<9 ; i++){    // przypisanie buforowi pół górnej ściany przy pomocy pętli for
			bufor_1[i] = kosstka[0][i];
		}

		kosstka[0][0] = bufor_1[8];     
		kosstka[0][1] = bufor_1[7];
		kosstka[0][2] = bufor_1[6];
        kosstka[0][3] = bufor_1[5];  // zmiana orientacji górnej ścianki względem ścian bocznych
		kosstka[0][5] = bufor_1[3];
		kosstka[0][6] = bufor_1[2];
		kosstka[0][7] = bufor_1[1];
		kosstka[0][8] = bufor_1[0];
		   
		
	
		bufor_2[0] = kosstka[1][0];  // przypisanie buforowi pól jednej z bocznych ścian związanych ze  scianą górną
		bufor_2[1] = kosstka[1][1];
		bufor_2[2] = kosstka[1][2];
        
		kosstka[1][0] = kosstka[3][0];
		kosstka[1][1] = kosstka[3][1];
		kosstka[1][2] = kosstka[3][2];

		kosstka[3][0] = bufor_2[0];
		kosstka[3][1] = bufor_2[1];      // przypisanie pól do odpowiedniej ze ścian na podstawie bufora  
		kosstka[3][2] = bufor_2[2];

		bufor_2[0] = kosstka[2][0];  // przypisanie buforowi pól jednej z bocznych ścian związanych ze  scianą górną
		bufor_2[1] = kosstka[2][1];
		bufor_2[2] = kosstka[2][2];

		kosstka[2][0] = kosstka[4][0];
		kosstka[2][1] = kosstka[4][1];
		kosstka[2][2] = kosstka[4][2];

		kosstka[4][0] = bufor_2[0];
		kosstka[4][1] = bufor_2[1];      // przypisanie pól do odpowiedniej ze ścian na podstawie bufora  
		kosstka[4][2] = bufor_2[2];
			ruchy.push_back(3);  // zapisanie obroru do tablicy ruchy
	}
/**/


	void F(){ //metoda pozwalająca na obrót ściany przedniej (F - front) zgodnie z ruchem wskazówek zegara

for(int i=0 ; i<9 ; i++){    // przypisanie buforowi pól przedniej  ściany przy pomocy pętli for
			bufor_1[i] = kosstka[1][i];
		}
		kosstka[1][0] = bufor_1[6];     
		kosstka[1][1] = bufor_1[3];
		kosstka[1][2] = bufor_1[0];
        kosstka[1][3] = bufor_1[7];  // zmiana orientacji przedniej ścianki względem ścian bocznych
		kosstka[1][5] = bufor_1[1];
		kosstka[1][6] = bufor_1[8];
		kosstka[1][7] = bufor_1[5];
		kosstka[1][8] = bufor_1[2];
		   
	    bufor_2[0] = kosstka[0][6];  // przypisanie buforowi pól jednej z bocznych ścian związanych ze  scianą górną
		bufor_2[1] = kosstka[0][7];
		bufor_2[2] = kosstka[0][8];

		kosstka[0][6] = kosstka[4][8];
		kosstka[0][7] = kosstka[4][5];  
		kosstka[0][8] = kosstka[4][2];

		kosstka[4][2] = kosstka[5][0];
		kosstka[4][5] = kosstka[5][1];  // zmiana pól zgodnie z obrotem
		kosstka[4][8] = kosstka[5][2];

		kosstka[5][0] = kosstka[2][6];
		kosstka[5][1] = kosstka[2][3];
		kosstka[5][2] = kosstka[2][0];

		kosstka[2][0] = bufor_2[0];
		kosstka[2][3] = bufor_2[1];      // przypisanie pól do odpowiedniej ze ścian na podstawie bufora  
		kosstka[2][6] = bufor_2[2];
			
		ruchy.push_back(4);  // zapisanie obroru do tablicy ruchy

	}


		void Fprim(){ //metoda pozwalająca na obrót ściany przedniej (F - front) przeciwnie do ruchu wskazówek zegara

for(int i=0 ; i<9 ; i++){    // przypisanie buforowi pól górnej ściany przy pomocy pętli for
			bufor_1[i] = kosstka[1][i];
		}
		kosstka[1][0] = bufor_1[2];     
		kosstka[1][1] = bufor_1[5];
		kosstka[1][2] = bufor_1[8];
        kosstka[1][3] = bufor_1[1];  // zmiana orientacji górnej ścianki względem ścian bocznych
		kosstka[1][5] = bufor_1[7];
		kosstka[1][6] = bufor_1[0];
		kosstka[1][7] = bufor_1[3];
		kosstka[1][8] = bufor_1[6];
		   
	    bufor_2[0] = kosstka[0][6];  // przypisanie buforowi pól jednej z bocznych ścian związanych ze  scianą górną
		bufor_2[1] = kosstka[0][7];
		bufor_2[2] = kosstka[0][8];

		kosstka[0][6] = kosstka[2][0];	
		kosstka[0][7] = kosstka[2][3];  
		kosstka[0][8] = kosstka[2][6];

        kosstka[2][0] = kosstka[5][2];
		kosstka[2][3] = kosstka[5][1];     
		kosstka[2][6] = kosstka[5][0] ;

        kosstka[5][0] = kosstka[4][2];
		kosstka[5][1] = kosstka[4][5];
		kosstka[5][2] = kosstka[4][8];

		kosstka[4][2] = bufor_2[2];
		kosstka[4][5] = bufor_2[1]; // przypisanie pól do odpowiedniej ze ścian na podstawie bufora
		kosstka[4][8] = bufor_2[0];

		ruchy.push_back(5);  // zapisanie obroru do tablicy ruchy
			
	}
void F180(){ // metoda powodująca obrót przedniej ścianki kostki (U - upper) o 180 stopni
        
			   
		for(int i=0 ; i<9 ; i++){    // przypisanie buforowi pół przedniej ściany przy pomocy pętli for
			bufor_1[i] = kosstka[1][i];
		}

		kosstka[1][0] = bufor_1[8];     
		kosstka[1][1] = bufor_1[7];
		kosstka[1][2] = bufor_1[6];
        kosstka[1][3] = bufor_1[5];  // zmiana orientacji przedniej ścianki względem ścian bocznych
		kosstka[1][5] = bufor_1[3];
		kosstka[1][6] = bufor_1[2];
		kosstka[1][7] = bufor_1[1];
		kosstka[1][8] = bufor_1[0];
		   
		
	
		bufor_2[0] = kosstka[0][6];  // przypisanie buforowi pól jednej z bocznych ścian związanych ze  scianą górną
		bufor_2[1] = kosstka[0][7];
		bufor_2[2] = kosstka[0][8];
        
		kosstka[0][6] = kosstka[5][2];
		kosstka[0][7] = kosstka[5][1];
		kosstka[0][8] = kosstka[5][0];

		kosstka[5][0] = bufor_2[2];
		kosstka[5][1] = bufor_2[1];      // przypisanie pól do odpowiedniej ze ścian na podstawie bufora  
		kosstka[5][2] = bufor_2[0];

		bufor_2[0] = kosstka[2][0];  // przypisanie buforowi pól jednej z bocznych ścian związanych ze  scianą górną
		bufor_2[1] = kosstka[2][3];
		bufor_2[2] = kosstka[2][6];

		kosstka[2][0] = kosstka[4][8];
		kosstka[2][3] = kosstka[4][5];
		kosstka[2][6] = kosstka[4][2];

		kosstka[4][8] = bufor_2[0];
		kosstka[4][5] = bufor_2[1];      // przypisanie pól do odpowiedniej ze ścian na podstawie bufora  
		kosstka[4][2] = bufor_2[2];
			
		ruchy.push_back(6);  // zapisanie obroru do tablicy ruchy
	}



		void L(){ //metoda pozwalająca na obrót ściany lewej (F - front) zgodnie z ruchem wskazówek zegara

for(int i=0 ; i<9 ; i++){    // przypisanie buforowi pól lewej  ściany przy pomocy pętli for
			bufor_1[i] = kosstka[4][i];
		}
		kosstka[4][0] = bufor_1[6];     
		kosstka[4][1] = bufor_1[3];
		kosstka[4][2] = bufor_1[0];
        kosstka[4][3] = bufor_1[7];  // zmiana orientacji lewej ścianki względem ścian bocznych
		kosstka[4][5] = bufor_1[1];
		kosstka[4][6] = bufor_1[8];
		kosstka[4][7] = bufor_1[5];
		kosstka[4][8] = bufor_1[2];
		   
	    bufor_2[0] = kosstka[0][0];  // przypisanie buforowi pól jednej z bocznych ścian związanych ze  scianą górną
		bufor_2[1] = kosstka[0][3];
		bufor_2[2] = kosstka[0][6];

		kosstka[0][0] = kosstka[3][8];
		kosstka[0][3] = kosstka[3][5];  
		kosstka[0][6] = kosstka[3][2];

		kosstka[3][2] = kosstka[5][6];
		kosstka[3][5] = kosstka[5][3];  // zmiana pól zgodnie z obrotem
		kosstka[3][8] = kosstka[5][0];

		kosstka[5][0] = kosstka[1][0];
		kosstka[5][3] = kosstka[1][3];
		kosstka[5][6] = kosstka[1][6];

		kosstka[1][0] = bufor_2[0];
		kosstka[1][3] = bufor_2[1];      // przypisanie pól do odpowiedniej ze ścian na podstawie bufora  
		kosstka[1][6] = bufor_2[2];
			
		ruchy.push_back(13);  // zapisanie obroru do tablicy ruchy

	}

	void Lprim(){ //metoda pozwalająca na obrót ściany przedniej (F - front) przeciwnie do ruchu wskazówek zegara

for(int i=0 ; i<9 ; i++){    // przypisanie buforowi pól górnej ściany przy pomocy pętli for
			bufor_1[i] = kosstka[4][i];
		}
		kosstka[4][0] = bufor_1[2];     
		kosstka[4][1] = bufor_1[5];
		kosstka[4][2] = bufor_1[8];
        kosstka[4][3] = bufor_1[1];  // zmiana orientacji górnej ścianki względem ścian bocznych
		kosstka[4][5] = bufor_1[7];
		kosstka[4][6] = bufor_1[0];
		kosstka[4][7] = bufor_1[3];
		kosstka[4][8] = bufor_1[6];
		   
	    bufor_2[0] = kosstka[0][0];  // przypisanie buforowi pól jednej z bocznych ścian związanych ze  scianą górną
		bufor_2[1] = kosstka[0][3];
		bufor_2[2] = kosstka[0][6];

		kosstka[0][0] = kosstka[1][0];	
		kosstka[0][3] = kosstka[1][3];  
		kosstka[0][6] = kosstka[1][6];

		kosstka[1][0] = kosstka[5][0];
		kosstka[1][3] = kosstka[5][3];  // zmiana pól zgodnie z obrotem
		kosstka[1][6] = kosstka[5][6];

		kosstka[5][0] = kosstka[3][8];
		kosstka[5][3] = kosstka[3][5];
		kosstka[5][6] = kosstka[3][2];

		kosstka[3][2] = bufor_2[2];
		kosstka[3][5] = bufor_2[1];      // przypisanie pól do odpowiedniej ze ścian na podstawie bufora  
		kosstka[3][8] = bufor_2[0];
			

		ruchy.push_back(14);  // zapisanie obroru do tablicy ruchy
	}


void L180(){ // metoda powodująca obrót lewej ścianki kostki (U - upper) o 180 stopni
        
			   
		for(int i=0 ; i<9 ; i++){    // przypisanie buforowi pół lewej ściany przy pomocy pętli for
			bufor_1[i] = kosstka[4][i];
		}

		kosstka[4][0] = bufor_1[8];     
		kosstka[4][1] = bufor_1[7];
		kosstka[4][2] = bufor_1[6];
        kosstka[4][3] = bufor_1[5];  // zmiana orientacji lewej ścianki względem ścian bocznych
		kosstka[4][5] = bufor_1[3];
		kosstka[4][6] = bufor_1[2];
		kosstka[4][7] = bufor_1[1];
		kosstka[4][8] = bufor_1[0];
		   
		
	
		bufor_2[0] = kosstka[0][0];  // przypisanie buforowi pól jednej z bocznych ścian związanych ze  scianą górną
		bufor_2[1] = kosstka[0][3];
		bufor_2[2] = kosstka[0][6];
        
		kosstka[0][0] = kosstka[5][0];
		kosstka[0][3] = kosstka[5][3];
		kosstka[0][6] = kosstka[5][6];

		kosstka[5][0] = bufor_2[0];
		kosstka[5][3] = bufor_2[1];      // przypisanie pól do odpowiedniej ze ścian na podstawie bufora  
		kosstka[5][6] = bufor_2[2];

		bufor_2[0] = kosstka[1][0];  // przypisanie buforowi pól jednej z bocznych ścian związanych ze  scianą górną
		bufor_2[1] = kosstka[1][3];
		bufor_2[2] = kosstka[1][6];

		kosstka[1][0] = kosstka[3][8];
		kosstka[1][3] = kosstka[3][5];
		kosstka[1][6] = kosstka[3][2];

		kosstka[3][2] = bufor_2[2];
		kosstka[3][5] = bufor_2[1];      // przypisanie pól do odpowiedniej ze ścian na podstawie bufora  
		kosstka[3][8] = bufor_2[0];

		ruchy.push_back(15);  // zapisanie obroru do tablicy ruchy	
	}



	void R(){ //metoda pozwalająca na obrót ściany prawej (R - right) zgodnie z ruchem wskazówek zegara

for(int i=0 ; i<9 ; i++){    // przypisanie buforowi pól prawej  ściany przy pomocy pętli for
			bufor_1[i] = kosstka[2][i];
		}
		kosstka[2][8] = bufor_1[2];     
		kosstka[2][7] = bufor_1[5];
		kosstka[2][6] = bufor_1[8];
        kosstka[2][5] = bufor_1[1];  // zmiana orientacji górnej ścianki względem ścian bocznych
		kosstka[2][3] = bufor_1[7];
		kosstka[2][2] = bufor_1[0];
		kosstka[2][1] = bufor_1[3];
		kosstka[2][0] = bufor_1[6];
		   
	    bufor_2[0] = kosstka[0][2];  // przypisanie buforowi pól jednej z bocznych ścian związanych ze  scianą górną
		bufor_2[1] = kosstka[0][5];
		bufor_2[2] = kosstka[0][8];

		kosstka[0][2] = kosstka[1][2];
		kosstka[0][5] = kosstka[1][5];  
		kosstka[0][8] = kosstka[1][8];

		kosstka[1][2] = kosstka[5][2];
		kosstka[1][5] = kosstka[5][5];  // zmiana pól zgodnie z obrotem
		kosstka[1][8] = kosstka[5][8];

		kosstka[5][2] = kosstka[3][6];
		kosstka[5][5] = kosstka[3][3];
		kosstka[5][8] = kosstka[3][0];

		kosstka[3][0] = bufor_2[2];
		kosstka[3][3] = bufor_2[1];      // przypisanie pól do odpowiedniej ze ścian na podstawie bufora  
		kosstka[3][6] = bufor_2[0];
			

		ruchy.push_back(7);  // zapisanie obroru do tablicy ruchy
	}


	void Rprim(){ //metoda pozwalająca na obrót ściany prawej (R - right) przeciwnie do ruchu wskazówek zegara

for(int i=0 ; i<9 ; i++){    // przypisanie buforowi pól prawej  ściany przy pomocy pętli for
			bufor_1[i] = kosstka[2][i];
		}
		kosstka[2][8] = bufor_1[6];     
		kosstka[2][7] = bufor_1[3];
		kosstka[2][6] = bufor_1[0];
        kosstka[2][5] = bufor_1[7];  // zmiana orientacji prawej ścianki względem ścian bocznych
		kosstka[2][3] = bufor_1[1];   
		kosstka[2][2] = bufor_1[8];
		kosstka[2][1] = bufor_1[5];
		kosstka[2][0] = bufor_1[2];
		   
	    bufor_2[0] = kosstka[0][2];  // przypisanie buforowi pól jednej z bocznych ścian związanych ze  scianą górną
		bufor_2[1] = kosstka[0][5];   
		bufor_2[2] = kosstka[0][8];

		kosstka[0][2] = kosstka[3][6];
		kosstka[0][5] = kosstka[3][3];  
		kosstka[0][8] = kosstka[3][0];

		kosstka[3][0] = kosstka[5][8]; 
		kosstka[3][3] = kosstka[5][5];
		kosstka[3][6] = kosstka[5][2];

		kosstka[5][2] = kosstka[1][2];
		kosstka[5][5] = kosstka[1][5];
		kosstka[5][8] = kosstka[1][8];

		kosstka[1][2] = bufor_2[0];
		kosstka[1][5] = bufor_2[1];   // przypisanie pól do odpowiedniej ze ścian na podstawie bufora  
		kosstka[1][8] = bufor_2[2];

		ruchy.push_back(8);  // zapisanie obroru do tablicy ruchy
	}

	void R180(){ // metoda powodująca obrót prawej ścianki kostki (U - upper) o 180 stopni
        
			   
		for(int i=0 ; i<9 ; i++){    // przypisanie buforowi pół prawej ściany przy pomocy pętli for
			bufor_1[i] = kosstka[2][i];
		}

		kosstka[2][0] = bufor_1[8];     
		kosstka[2][1] = bufor_1[7];
		kosstka[2][2] = bufor_1[6];
        kosstka[2][3] = bufor_1[5];  // zmiana orientacji prawej ścianki względem ścian bocznych
		kosstka[2][5] = bufor_1[3];
		kosstka[2][6] = bufor_1[2];
		kosstka[2][7] = bufor_1[1];
		kosstka[2][8] = bufor_1[0];
		   
		
	
		bufor_2[0] = kosstka[0][2];  // przypisanie buforowi pól jednej z bocznych ścian związanych ze  scianą górną
		bufor_2[1] = kosstka[0][5];
		bufor_2[2] = kosstka[0][8];
        
		kosstka[0][2] = kosstka[5][2];
		kosstka[0][5] = kosstka[5][5];
		kosstka[0][8] = kosstka[5][8];

		kosstka[5][2] = bufor_2[0];
		kosstka[5][5] = bufor_2[1];      // przypisanie pól do odpowiedniej ze ścian na podstawie bufora  
		kosstka[5][8] = bufor_2[2];

		bufor_2[0] = kosstka[1][2];  // przypisanie buforowi pól jednej z bocznych ścian związanych ze  scianą górną
		bufor_2[1] = kosstka[1][5];
		bufor_2[2] = kosstka[1][8];

		kosstka[1][2] = kosstka[3][6];
		kosstka[1][5] = kosstka[3][3];
		kosstka[1][8] = kosstka[3][0];

		kosstka[3][0] = bufor_2[2];
		kosstka[3][3] = bufor_2[1];      // przypisanie pól do odpowiedniej ze ścian na podstawie bufora  
		kosstka[3][6] = bufor_2[0];

		ruchy.push_back(9);  // zapisanie obroru do tablicy ruchy	
	}





		void B(){ //metoda pozwalająca na obrót ściany tylniej (B - back) zgodnie z ruchem wskazówek zegara

for(int i=0 ; i<9 ; i++){    // przypisanie buforowi pól tylniej  ściany przy pomocy pętli for
			bufor_1[i] = kosstka[3][i];
		}
		kosstka[3][0] = bufor_1[6];     
		kosstka[3][1] = bufor_1[3];
		kosstka[3][2] = bufor_1[0];
        kosstka[3][3] = bufor_1[7];  // zmiana orientacji tylniej ścianki względem ścian bocznych
		kosstka[3][5] = bufor_1[1];
		kosstka[3][6] = bufor_1[8];
		kosstka[3][7] = bufor_1[5];
		kosstka[3][8] = bufor_1[2];
		   
	    bufor_2[0] = kosstka[0][0];  // przypisanie buforowi pól jednej z bocznych ścian związanych ze  scianą górną
		bufor_2[1] = kosstka[0][1];
		bufor_2[2] = kosstka[0][2];

		kosstka[0][2] = kosstka[2][8];
		kosstka[0][1] = kosstka[2][5];  
		kosstka[0][0] = kosstka[2][2];

		kosstka[2][2] = kosstka[5][8];
		kosstka[2][5] = kosstka[5][7];  // zmiana pól zgodnie z obrotem
		kosstka[2][8] = kosstka[5][6];

		kosstka[5][6] = kosstka[4][0];
		kosstka[5][7] = kosstka[4][3];
		kosstka[5][8] = kosstka[4][6];

		kosstka[4][0] = bufor_2[2];
		kosstka[4][3] = bufor_2[1];      // przypisanie pól do odpowiedniej ze ścian na podstawie bufora  
		kosstka[4][6] = bufor_2[0];
			
		ruchy.push_back(10);  // zapisanie obroru do tablicy ruchy

	}


	void Bprim(){ //metoda pozwalająca na obrót ściany tylniej (B - back) przeciwnie do ruchu wskazówek zegara

for(int i=0 ; i<9 ; i++){    // przypisanie buforowi pól tylniej ściany przy pomocy pętli for
			bufor_1[i] = kosstka[3][i];
		}
		kosstka[3][0] = bufor_1[2];     
		kosstka[3][1] = bufor_1[5];
		kosstka[3][2] = bufor_1[8];
        kosstka[3][3] = bufor_1[1];  // zmiana orientacji tylniej ścianki względem ścian bocznych
		kosstka[3][5] = bufor_1[7];
		kosstka[3][6] = bufor_1[0];
		kosstka[3][7] = bufor_1[3];
		kosstka[3][8] = bufor_1[6];
		   
	    bufor_2[0] = kosstka[0][0];  // przypisanie buforowi pól jednej z bocznych ścian związanych ze  scianą górną
		bufor_2[1] = kosstka[0][1];
		bufor_2[2] = kosstka[0][2];

		kosstka[0][0] = kosstka[4][6];	
		kosstka[0][1] = kosstka[4][3];  
		kosstka[0][2] = kosstka[4][0];

		kosstka[4][0] = kosstka[5][6];
		kosstka[4][3] = kosstka[5][7];  // zmiana pól zgodnie z obrotem
		kosstka[4][6] = kosstka[5][8];

		kosstka[5][6] = kosstka[2][8];
		kosstka[5][7] = kosstka[2][5];
		kosstka[5][8] = kosstka[2][2];

		kosstka[2][2] = bufor_2[0];
		kosstka[2][5] = bufor_2[1];      // przypisanie pól do odpowiedniej ze ścian na podstawie bufora  
		kosstka[2][8] = bufor_2[2];
			
		ruchy.push_back(11);  // zapisanie obroru do tablicy ruchy

	}


	void B180(){ // metoda powodująca obrót tylnej ścianki kostki (B- back) o 180 stopni
        
			   
		for(int i=0 ; i<9 ; i++){    // przypisanie buforowi pół tylnej ściany przy pomocy pętli for
			bufor_1[i] = kosstka[3][i];
		}

		kosstka[3][0] = bufor_1[8];     
		kosstka[3][1] = bufor_1[7];
		kosstka[3][2] = bufor_1[6];
        kosstka[3][3] = bufor_1[5];  // zmiana orientacji tylnej ścianki względem ścian bocznych
		kosstka[3][5] = bufor_1[3];
		kosstka[3][6] = bufor_1[2];
		kosstka[3][7] = bufor_1[1];
		kosstka[3][8] = bufor_1[0];
		   
		
	
		bufor_2[0] = kosstka[0][0];  // przypisanie buforowi pól jednej z bocznych ścian związanych ze  scianą górną
		bufor_2[1] = kosstka[0][1];
		bufor_2[2] = kosstka[0][2];
        
		kosstka[0][2] = kosstka[5][6];
		kosstka[0][1] = kosstka[5][7];
		kosstka[0][0] = kosstka[5][8];

		kosstka[5][8] = bufor_2[0];
		kosstka[5][7] = bufor_2[1];      // przypisanie pól do odpowiedniej ze ścian na podstawie bufora  
		kosstka[5][6] = bufor_2[2];

		bufor_2[0] = kosstka[2][2];  // przypisanie buforowi pól jednej z bocznych ścian związanych ze  scianą górną
		bufor_2[1] = kosstka[2][5];
		bufor_2[2] = kosstka[2][8];

		kosstka[2][2] = kosstka[4][6];
		kosstka[2][5] = kosstka[4][3];
		kosstka[2][8] = kosstka[4][0];

		kosstka[4][0] = bufor_2[2];
		kosstka[4][3] = bufor_2[1];      // przypisanie pól do odpowiedniej ze ścian na podstawie bufora  
		kosstka[4][6] = bufor_2[0];

		ruchy.push_back(12);  // zapisanie obroru do tablicy ruchy	
	}



			void D(){ //metoda pozwalająca na obrót ściany dolnej (D - down) zgodnie z ruchem wskazówek zegara

for(int i=0 ; i<9 ; i++){    // przypisanie buforowi pól dolnej  ściany przy pomocy pętli for
			bufor_1[i] = kosstka[5][i];
		}
		kosstka[5][0] = bufor_1[6];     
		kosstka[5][1] = bufor_1[3];
		kosstka[5][2] = bufor_1[0];
        kosstka[5][3] = bufor_1[7];  // zmiana orientacji tylniej ścianki względem ścian bocznych
		kosstka[5][5] = bufor_1[1];
		kosstka[5][6] = bufor_1[8];
		kosstka[5][7] = bufor_1[5];
		kosstka[5][8] = bufor_1[2];
		   
	    bufor_2[0] = kosstka[1][6];  // przypisanie buforowi pól jednej z bocznych ścian związanych ze  scianą górną
		bufor_2[1] = kosstka[1][7];
		bufor_2[2] = kosstka[1][8];

		kosstka[1][6] = kosstka[4][6];
		kosstka[1][7] = kosstka[4][7];  
		kosstka[1][8] = kosstka[4][8];

		kosstka[4][6] = kosstka[3][6];
		kosstka[4][7] = kosstka[3][7];  // zmiana pól zgodnie z obrotem
		kosstka[4][8] = kosstka[3][8];

		kosstka[3][6] = kosstka[2][6];
		kosstka[3][7] = kosstka[2][7];
		kosstka[3][8] = kosstka[2][8];

		kosstka[2][6] = bufor_2[0];
		kosstka[2][7] = bufor_2[1];      // przypisanie pól do odpowiedniej ze ścian na podstawie bufora  
		kosstka[2][8] = bufor_2[2];
			
		ruchy.push_back(16);  // zapisanie obroru do tablicy ruchy

	}


    void Dprim(){ // metoda powodująca obrót dolnej ścianki przeciwnie do ruchu wskazówek zegara

		   
		for(int i=0 ; i<9 ; i++){    // przypisanie buforowi pół dolnej ściany przy pomocy pętli for
			bufor_1[i] = kosstka[5][i];
		}
		kosstka[5][0] = bufor_1[2];     
		kosstka[5][1] = bufor_1[5];
		kosstka[5][2] = bufor_1[8];
        kosstka[5][3] = bufor_1[1];  // zmiana orientacji dolnej ścianki względem ścian bocznych
		kosstka[5][5] = bufor_1[7];
		kosstka[5][6] = bufor_1[0];
		kosstka[5][7] = bufor_1[3];
		kosstka[5][8] = bufor_1[6];



		
		bufor_2[0] = kosstka[1][6];  // przypisanie buforowi pól jednej z bocznych ścian związanych ze  scianą górną
		bufor_2[1] = kosstka[1][7];
		bufor_2[2] = kosstka[1][8];

        kosstka[1][6] = kosstka[2][6];
		kosstka[1][7] = kosstka[2][7];
		kosstka[1][8] = kosstka[2][8];

		kosstka[2][6] = kosstka[3][6];
		kosstka[2][7] = kosstka[3][7];  // przypisanie pól zgodnie z obrotem
		kosstka[2][8] = kosstka[3][8];

		kosstka[3][6] = kosstka[4][6];
		kosstka[3][7] = kosstka[4][7];
		kosstka[3][8] = kosstka[4][8];

		kosstka[4][6] = bufor_2[0];
		kosstka[4][7] = bufor_2[1];   // przypisanie pól do odpowiedniej ze ścian na podstawie bufora  
		kosstka[4][8] = bufor_2[2];

		ruchy.push_back(17);  // zapisanie obroru do tablicy ruchy
	}

void D180(){ // metoda powodująca obrót ściany dolnej kostki (U - upper) o 180 stipni
        
			   
		for(int i=0 ; i<9 ; i++){    // przypisanie buforowi pół górnej ściany przy pomocy pętli for
			bufor_1[i] = kosstka[5][i];
		}

		kosstka[5][0] = bufor_1[8];     
		kosstka[5][1] = bufor_1[7];
		kosstka[5][2] = bufor_1[6];
        kosstka[5][3] = bufor_1[5];  // zmiana orientacji górnej ścianki względem ścian bocznych
		kosstka[5][5] = bufor_1[3];
		kosstka[5][6] = bufor_1[2];
		kosstka[5][7] = bufor_1[1];
		kosstka[5][8] = bufor_1[0];
		   
		
	
		bufor_2[0] = kosstka[1][6];  // przypisanie buforowi pól jednej z bocznych ścian związanych ze  scianą górną
		bufor_2[1] = kosstka[1][7];
		bufor_2[2] = kosstka[1][8];
        
		kosstka[1][6] = kosstka[3][6];
		kosstka[1][7] = kosstka[3][7];
		kosstka[1][8] = kosstka[3][8];

		kosstka[3][6] = bufor_2[0];
		kosstka[3][7] = bufor_2[1];      // przypisanie pól do odpowiedniej ze ścian na podstawie bufora  
		kosstka[3][8] = bufor_2[2];

		bufor_2[0] = kosstka[2][6];  // przypisanie buforowi pól jednej z bocznych ścian związanych ze  scianą górną
		bufor_2[1] = kosstka[2][7];
		bufor_2[2] = kosstka[2][8];

		kosstka[2][6] = kosstka[4][6];
		kosstka[2][7] = kosstka[4][7];
		kosstka[2][8] = kosstka[4][8];

		kosstka[4][6] = bufor_2[0];
		kosstka[4][7] = bufor_2[1];      // przypisanie pól do odpowiedniej ze ścian na podstawie bufora  
		kosstka[4][8] = bufor_2[2];
			
		ruchy.push_back(18);  // zapisanie obroru do tablicy ruchy

	}





};


