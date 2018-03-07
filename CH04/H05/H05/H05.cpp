// Marcin Zajac 07 03 2018
// Stroustrup Rozdzial 04 H05

#include "../../../std_lib_facilities.h"

int main() {
	char znak_konca = '|';
	char ch = ' ';
	double val1 = 0;
	double val2 = 0;
	char symbol_dzialania = ' ';
	while (ch != znak_konca)
	{
		cout << "Podaj dwie liczby oraz symbol dzialania(+, -, *, / ) jakie chcesz na nich wykonac : ";
		cin >> val1 >> val2 >> symbol_dzialania;
		switch (symbol_dzialania)
		{
		case '+':
			cout << "Wynikiem dzialania: " << val1 << " " << symbol_dzialania << " " << val2 << " = " << val1 + val2 << endl;
			break;
		case '-':
			cout << "Wynikiem dzialania: " << val1 << " " << symbol_dzialania << " " << val2 << " = " << val1 - val2 << endl;
			break;
		case '*':
			cout << "Wynikiem dzialania: " << val1 << " " << symbol_dzialania << " " << val2 << " = " << val1 * val2 << endl;
			break;
		case '/':
			if (val2 == 0)
				cout << "Nie dzielimy przez 0!!!";
			else
				cout << "Wynikiem dzialania: " << val1 << " " << symbol_dzialania << " " << val2 << " = " << val1 / val2 << endl;
			break;
		default:
			cout << "Podales niepoprawny symbol dzialania: " << symbol_dzialania << endl;
			break;
		}

		cout << "\nJesli chcesz zakonczyc dzialanie programu wpisz znak '|'," << endl
			<< "Jesli chcesz kontynuowac wprowadz dowolny inny znak: ";
		cin >> ch;

	}
}
