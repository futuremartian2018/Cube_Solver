
#include "pch.h"
#include <iostream>
#include <stdio.h>
//#include "convert.h"
#include "colors2numbers.h"
//#include "kostka.h"
#include "algorytm.h"
#include<fstream>
#include <string>

int Algorytm::tablica_k1[2] = { 0 };
int Algorytm::tablica_k2[4] = { 0 };
int Algorytm::suma = 0;
int Algorytm::paramter = 0;
int Algorytm::par2 = 0;
vector<int> Kostka::ruchy = { 0 };
int Colors2Numbers::numbers[6][9] = { 0 };
bool state = true;
int main()
{


	char c[6][9] = {
					   {'y', 'w', 'g', 'b', 'w', 'b', 'b','o', 'w'},
					   {'o','y','r', 'w', 'r', 'r', 'b', 'g', 'b'},
					   {'b', 'y', 'w','b', 'b', 'b', 'y', 'g', 'g'},
					   {'o', 'g','r', 'o', 'o', 'g', 'y', 'r', 'w'},
					   {'g', 'w','y', 'r', 'g', 'r', 'r', 'o', 'o'},
					   {'w', 'o', 'r', 'w', 'y', 'y', 'g', 'y', 'o'}
	};

	/*fstream plik("C:/Users/futur/Desktop/cube.txt", ios::in);


	int lim = 54;
	string line;
	/*for (int i = 0; i < lim; i++) {
	}*/
	/*if (plik.good() == true)
	{
		while (!plik.eof())
		{
			getline(plik, line);
		}
		plik.close();
	}

	char c[6][9];
	int k = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 9; j++) {
			c[i][j] = (char)line[k];
			
			k++;
		}

	}*/



	/* char c[6][9] = {
					   {'w', 'o', 'y', 'b', 'w', 'g', 'r','r', 'o'},
					   {'w','w','b', 'w', 'r', 'b', 'y', 'y', 'g'},
					   {'y', 'y', 'r','r', 'b', 'b', 'w', 'r', 'w'},
					   {'g', 'g','b', 'y', 'o', 'g', 'g', 'w', 'b'},
					   {'o', 'o','b', 'r', 'g', 'b', 'y', 'w', 'g'},
					   {'o', 'o', 'r', 'g', 'y', 'y', 'r', 'o', 'o'}
	};*/

	Colors2Numbers *cube;
	Kostka *kosc;
	Algorytm *algo = new Algorytm();
	if (state) {

		cube = new Colors2Numbers(c);
		cube->convertColorsToNumbers();
		kosc = new Kostka(Colors2Numbers::numbers);

		std::cout << endl;
		std::cout << "Kostka przed ulozeniem: ";
		std::cout << endl;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 9; j++) {
				std::cout << kosc->getKostka(i, j);
				std::cout << ' ';
			}
			std::cout << endl;
		}
		std::cout << endl;

		kosc->clearRuchy();

		cube->showColors();

		cube->showNumbers();

		algo->solve(kosc);
		std::cout << endl;
		std::cout << "Ulozona kostka: ";
		std::cout << endl;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 9; j++) {
				std::cout << kosc->getKostka(i, j);
				std::cout << ' ';
			}
			std::cout << endl;
		}
		std::cout << endl;
		std::cout << "Konieczna liczba ruchow: ";
		std::cout << kosc->getRozmiar();
		std::cout << endl;

		ofstream zapis("C:/Users/futur/Desktop/test.txt", ios_base::app);

		int lim = kosc->getRozmiar();

		for (int i = 0; i < lim; i++) {

			zapis << kosc->getRuchy(i);
			zapis << ',';
		}
		
		zapis.close();

	}

}