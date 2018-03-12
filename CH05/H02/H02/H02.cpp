// Marcin Zajac 12 03 2018
// Stroustrup Rozdzial 05 H09

#include "../../../std_lib_facilities.h"

bool zadanie_9 = true;	// przelacznik dla zadania 9, aby po jego wylaczeniu program dzialal normalnie
const double c_min = -273.15;
const double roznica_KC = 273.15;
const double k_min = 0;
const double f_min = 9.0 / 5.0 *c_min + 32;

double ctok(double c) // Konwertuje stopnie w skali Celcjusza na skale Kelwina
{
	if (c < c_min) error("Podano temperature ponizej zera absolutnego(C)", c);
	double k = c + roznica_KC;
	return k;
}

double ktoc(double k)   //Konwertuje z K na C
{
	if (k < k_min) error("Podales temperature ponizej zera absolutnego(K)", k);
	return k - roznica_KC;
}

double ctof(double c)   // Z C na F
{
	if (c < c_min) error("Ponizej zera absolutnego!");
	if (zadanie_9) {
		int x_9 = narrow_cast<int>(9.0 / 5.0*c + 32);
	}
	return 9.0 / 5.0*c + 32;
}

double ftoc(double f)	// Z F na C
{
	if (f < f_min) error("Podano temperature ponizej zera absolutnego(F)", f);
	if (zadanie_9) {
		int x_9 = narrow_cast<int>((f - 32) * 5.0 / 9.0);
	}
	return (f - 32) * 5.0 / 9.0;
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

	cout << "A teraz temparatura dla C na F: ";
	double cf = 0;
	cin >> cf;
	cout << ctof(cf) << endl;

	cout << "f_min = " << f_min << endl; // Ciekawostka(?)
	cout << "Kolej na F na C:";
	double fc = 0;
	cin >> fc;
	cout << ftoc(fc) << endl;

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
