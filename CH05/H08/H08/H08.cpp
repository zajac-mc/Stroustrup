// Marcin Zajac 12 03 2018
// Stroustrup Rozdzial 05 H08

/*
Autor polecenia w podanym przez siebie rozwiazaniu najpierw pobiera ilosc elementow do zsumowania, a dopiero potem prosi o wprowadzenie serii.
Choc nie jest to do konca zgodne z poleceniem, znaczaco ulatwia to wykonanie cwiczenia
*/

#include "../../../std_lib_facilities.h"

int main()
try
{
	cout << "Ile liczb z serii zsumowac:  ";
	int ile_dodac = -1;
	cin >> ile_dodac;
	if (ile_dodac < 1) error("Liczba elementow do zsumowania musi byc liczba dodatnia!\n");

	cout << "Podaj elementy serii, aby zakonczyc wpisz'|':\n";
	vector<int> liczby;
	int liczba;
	while (cin >> liczba)
		liczby.push_back(liczba);

	if (ile_dodac > liczby.size()) error("Chcesz zsumowac wiecej liczb niz zawiera seria: ", ile_dodac);

	double suma = 0;
	for (int i = 0; i < ile_dodac; ++i)
		suma += liczby[i];
	cout << "Suma pierwszych " << ile_dodac << " liczb wynosi: " << suma << endl;
	keep_window_open();
	keep_window_open();
}
catch (exception& e)
{
	cerr << "Blad: " << e.what() << endl;
	keep_window_open();
	keep_window_open();
	return 1;
}
catch (...)
{
	cerr << "Nieznany typ bledu!\n";
		keep_window_open();
		return 2;
}