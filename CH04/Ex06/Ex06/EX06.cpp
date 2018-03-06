// Marcin Zajac 05 03 2018
// Stroustrup Rozdzial 04 Ex 06

#include "../../../std_lib_facilities.h"

int main()
{
	char znak_konca = '|';
	char ch = ' ';

	cout << "Podaj pierwsza liczbe: ";
	double val;
	cin >> val;
	double min = val;
	double max = val;
	while (ch != znak_konca)
	{
		cout << "Podaj kolejna liczbe: ";
		cin >> val;
		cout << "Podales liczbe: " << val << endl;
		if (val < min) {
			cout << "Ta byla jak do tej pory najmniejsza." << endl;
			min = val;
		}
		else if (val > max) {
			cout << "Ta byla jak do tej pory najwieksza" <<  endl;
			max = val;
		}
		cout << "Jesli chcesz zakonczyc dzialanie programu wpisz znak '|'," << endl
			<< "Jesli chcesz kontynuowac wprowadz dowolny inny znak: ";
		cin >> ch;
	}

	keep_window_open();
	return 0;
}
