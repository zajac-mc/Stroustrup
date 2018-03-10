// Marcin Zajac 10 03 2018
// Stroustrup Rozdzial 05 H07

#include "../../../std_lib_facilities.h"

// Funkcja rozwiazujaca rownanie kwadratowe
vector<double> licz_x(double a, double b, double c)
{
	vector<double> result;
	double delta = b * b - 4 * a*c;
	if (delta<0)
		throw runtime_error("Z takimi parametrami nie istnieje rozwiazanie w zbiorze liczb rzeczywistych!");
	else if (a == 0) {
		if (b == 0) {
			if (c == 0) throw runtime_error("Dowolny x jest rozwiazaniem takiego rownania!");
			else throw runtime_error("Rownanie takie nie ma rozwiazan!");
		}
		else result.push_back(-c / b);
	}
	else {
		if (delta == 0)
			result.push_back(-b / (2 * a));
		else {
			result.push_back((-b - sqrt(delta)) / (2 * a));
			result.push_back((-b + sqrt(delta)) / (2 * a));
		}
	}

	for (int i = 0; i<result.size(); ++i)
		if ((a*result[i] * result[i] + b * result[i] + c) != 0)
			cerr << "\n0 = " << (a*result[i] * result[i] + b * result[i] + c);
	//throw runtime_error ("Cos poszlo zle");
	return result;
}

int main()
try
{
	cout << "Program rozwiazuje rowania kwadratowe postaci:\n"
		<< "a*x^2 + b*x + c = 0\n";
	char znak_konca = ' ';
	while (znak_konca != '|') {

		cout << "Podaj wspolczynnik a: ";
		double val_a;
		cin >> val_a;

		cout << "Podaj wspolczynnik b: ";
		double val_b;
		cin >> val_b;

		cout << "Podaj wspolczynnik c: ";
		double val_c;
		cin >> val_c;

		vector<double> rozwiazania = licz_x(val_a, val_b, val_c);

		if (rozwiazania.size() == 1)
			cout << "\nRozwiazaniem takiego rownania jest: " << rozwiazania[0];
		else cout << "\nRozwiazaniem takiego rownania jest:\n"
			<< "x1 = " << rozwiazania[0] << '\n'
			<< "x2 = " << rozwiazania[1] << '\n';



		cout << "\nAby kontynuowac nacisnij dowolny klawisz,\n"
			<< "w celu zakonczenia wprowadz znak '|': ";
		cin >> znak_konca;
	}

	keep_window_open();
	return 0;
}
catch (runtime_error& e) {
	cerr << "Blad:\n" << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Nieznany typ wyjatku!\n";
	keep_window_open();
	return 2;
}
