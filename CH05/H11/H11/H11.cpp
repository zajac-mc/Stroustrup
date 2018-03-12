// Marcin Zajac 12 03 2018
// Stroustrup Rozdzial 05 H11

#include "../../../std_lib_facilities.h"

void fibo(int n) {
	if (n < 2) error("Podano nieprawidlowa liczbe elementow ciagu: ", n);
	int x1 = 1;
	int x2 = 1;
	cout << "Ciag Fibonacciego:\n";
	cout << x1 << ", " << x2;
	int temp = -1;
	for (int i = 2; i < n; ++i) {
		temp = x1;
		x1 += x2;
		x2 = temp;
		if (x1 < x2) error("Przekroczono zakres int; ilosc elementow: ", i);
		cout << ", " <<  x1;
	}
	cout << endl;
}

int main()
try
{
	cout << "Podaj liczbe elementow ciagu Fibonnaciego, ktore chcialbys otrzymac: ";
	int ile = -1;
	cin >> ile;
	fibo(ile);
	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << "Blad: " << e.what() << endl;
	keep_window_open();
	return 1;
}
catch (...)
{
	cerr << "Nieznany typ bledu!/n";
	return 2;
}