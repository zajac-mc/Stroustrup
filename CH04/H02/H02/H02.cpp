// Marcin Zajac 06 03 2018
// Stroustrup Rozdzial 04 H02

#include "../../../std_lib_facilities.h"

//Wczytuje wartosci temperatur do wektora.
//Oblicza srednia i mediane temperatur.
int main()
{
	vector<double> temps;       //temperatury
	double temp;                //pojedynczy odczyt
	cout << "Podaj odczyt temperatury: ";
	while (cin >> temp)           //wczytywanie
	{
		cout << "Podaj odczyt temperatury: ";
		temps.push_back(temp);  //wstawianie do wektora
	}

	//Obliczanie sredniej temperatury:
	double suma = 0;
	for (unsigned int i = 0; i<temps.size(); i++)
		suma += temps[i];
	cout << "Srednia temperatura wynosi: " << suma / (double)temps.size() << endl;

	//Obliczanie mediany temperatury:
	sort(temps.begin(), temps.end());
	if (temps.size() % 2)
		cout << "Mediana temperatur: " << temps[temps.size() / 2] << endl;
	else
		cout << "Mediana temperatur: " << (temps[temps.size() / 2 - 1] + temps[temps.size() / 2]) / 2 << endl;
	cout << "Temps.size = " << temps.size() << endl;

	keep_window_open();
	keep_window_open();
	return 0;
}
