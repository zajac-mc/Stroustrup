// Marcin Zajac 02 03 2018
// Stroustrup Rozdzial 04 Ex 01-05

#include "../../../std_lib_facilities.h"

int main()
{
	double a = 0;
	double b = 0;
	char znak_konca = '|';
	char ch = ' ';
	while (ch != znak_konca)
	{
		cout << "Podaj dwie liczby: ";
		cin >> a >> b;
		cout << "Podales " << a << " i " << b << endl;
		if (a < b) {
			cout << "Mniejsza z liczb to: " << a << endl;
			if (b - a < 1.0 / 100)
				cout << "Liczby sa prawie rowne\n";
		}
		else if (b < a) {
			cout << "Mniejsza z liczb to: " << b << endl;
			if (a - b < 1.0 / 100)
				cout << "Liczby sa prawie rowne.\n";
		}
		else if (a == b)
			cout << "Liczby sa rowne\n";
		else
			cout << "Cos poszlo nie tak:(";
		cout << "Jesli chcesz zakonczyc dzialanie programu wpisz znak '|'," << endl
			<< "Jesli chcesz kontynuowac wprowadz dowolny inny znak: ";
		cin >> ch;
	}

	keep_window_open();
	return 0;
}