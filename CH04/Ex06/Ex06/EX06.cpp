// Marcin Zajac 06 03 2018
// Stroustrup Rozdzial 04 Ex 07-11

#include "../../../std_lib_facilities.h"

int main()
{
	const double cm_per_m = 100;
	const double cm_per_cal = 2.54;
	const double cal_per_st = 12;

	char znak_konca = '|';
	char ch = ' ';
	string unit = " ";
	bool first_run = true;
	bool unit_checker = true;
	int val_counter = 0;
	double suma = 0;

	double val = 0;
	double min = val;
	double max = val;
	vector<double> values;

	while (ch != znak_konca)
	{
		cout << "Podaj liczbe wraz z jednostka [cm, m, cal, st]: ";
		cin >> val >> unit;
		if (unit == "m") {
			unit_checker = true;
		}
		else if (unit == "cm") {
			val /= cm_per_m;
			unit_checker = true;
		}
		else if (unit == "cal") {
			val = val * cm_per_cal / cm_per_m;
			unit_checker = true;
		}
		else if (unit == "st") {
			val = val * cal_per_st * cm_per_cal / cm_per_m;
			unit_checker = true;
		}
		else {
			cout << "Bledna jednostka!\n";
			unit_checker = false;
		}

		if (first_run)
			if (unit_checker) {
				min = val;
				max = val;
				first_run = false;
			}

		if (unit_checker) {
			cout << "Podales liczbe: " << val << " m" << endl;
			if (val < min) {
				cout << "Ta byla jak do tej pory najmniejsza." << endl;
				min = val;
			}
			else if (val > max) {
				cout << "Ta byla jak do tej pory najwieksza" << endl;
				max = val;
			}
			val_counter++;
			suma += val;
			values.push_back(val);
		}
		cout << "\nJesli chcesz zakonczyc dzialanie programu wpisz znak '|'," << endl
			<< "Jesli chcesz kontynuowac wprowadz dowolny inny znak: ";
		cin >> ch;
	}

	cout << "Podales lacznie " << val_counter << " prawidlowych wartosci, ktorych suma wynosi: " << suma << "m." << endl
		<< "Najmniejsza podana wartosc to: " << min << "m, a najwieksza: " << max << "m." << endl;

	sort(values.begin(), values.end());
	cout << "Oto wszystkie prawidlowo wprowadzone wartosci (posortowane):\n";
	for (int i = 0; i < values.size(); ++i)
		cout << i+1 << ": " << values[i] << " m; \t";
	cout << endl;

	keep_window_open();
	return 0;
}
