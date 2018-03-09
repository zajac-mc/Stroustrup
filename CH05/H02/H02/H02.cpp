// Marcin Zajac 09 03 2018
// Stroustrup Rozdzial 05 H05

#include "../../../std_lib_facilities.h"

const double c_min = -273.15;
const double roznica_KC = 273.15;
const double k_min = 0;

double ctok(double c) // Konwertuje stopnie w skali Celcjusza na skale Kelwina
{
	if (c < c_min) error("Podano temperature ponizej zera absolutnego(C)", c);
	double k = c + roznica_KC;
	return k;
}

double ktoc(double k)   //Konwertuje z K na C
{
	if (k<k_min) error("Podales temperature ponizej zera absolutnego(K)", k);
	return k - roznica_KC;
}

int main()
try
{
	double c = 0; // Zmienna do odbierania danych wejsciowych
	cout << "Podaj temperature w C, ktora chcesz przekonwertowac na K: ";
	cin >> c;	// Pobiernanie temperatury do zmiennej wejsciowej
	cout << ctok(c) << endl;	// konwersja i drukowanie temperatury

	cout << "Podaj temperature w K, ktora chesz przekonwertowac na C: ";
	double k = 0;
	cin >> k;
	cout << ktoc(k) << endl;
	keep_window_open();
}
catch (exception& e) {
	cerr << "Blad: " << e.what() << endl;
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Nieznany typ wyjatku!\n";
	keep_window_open();
	return 2;
}
