#include "game_of_life.h"
#include <ctime>
using namespace std;

int gen_rnd(int min, int max) {
	return rand() % (max - min + 1) + min;
}

bool game_of_life::slucajna_vrijednost() {
	
	if (gen_rnd(1, 10) == 1) {
		return true;
	}
	else
		return false;
}

int game_of_life::celija_zauzeta(int redak, int stupac) {
	int susjedi = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i == 0 && j == 0)
				continue;
			int a = redak + j;
			int b = stupac + i;
			if (a >= 0 and a < REDAKA and b >=0 and b < STUPACA)
				if (_generacija[a][b] == 1)
				{
					susjedi++;
				}
		}
	}
	return susjedi;
}

game_of_life::game_of_life() {
	srand(time(nullptr));
	for (int i = 0; i < REDAKA; i++) {
	 	for (int j = 0; j < STUPACA; j++) {
			_generacija[i][j] = slucajna_vrijednost();
		}
	}
}

void game_of_life::sljedeca_generacija() {

	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			int susjedi = celija_zauzeta(i,j);
			
			if (_generacija[i][j])
			{
				if (susjedi < 2 or susjedi > 3)
					_sljedeca_generacija[i][j] = false;
				else
					_sljedeca_generacija[i][j] = true;
			}
			else if (!_generacija[i][j])
			{
				if (susjedi == 3)
					_sljedeca_generacija[i][j] = true;
				else
					_sljedeca_generacija[i][j] = false;
			};
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
	
}

void game_of_life::iscrtaj() {

	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			if (_generacija[i][j]) {
				cout << '*';
			}
			else
			cout << '-';
		}
		cout << endl;
	}
}

