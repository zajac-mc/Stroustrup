// Marcin Zajac 03 04 2019
// Stroustrup Rozdzial 04 H11

#include "../../../std_lib_facilities.h"

int upper_limit = 0;
int upper_limit_warning = 10000;
vector<int> primes;
void primes_init() { primes.push_back(2); }
bool is_prime(int x);
void search_for_primes();

bool is_prime(int x) {
	for (int i = 0; i < primes.size(); i++) {
		if (!(x%primes[i])) return false;	// jesli reszta z dzielenia jest rowna 0, liczba nie jest pierwsza
	}
	return true;
}

void search_for_primes() {
	for (int i = 3; i <= upper_limit; i++)
		if (is_prime(i)) primes.push_back(i);
}



int main() {
	cout << "Program wyszukuje i wyswietla liczby pierwsze mniejsze lub rowne od podanej liczby." << endl
		<< "Dla jakiej liczby chcesz zaczac poszukiwania: ";
	cin >> upper_limit;
	if (upper_limit < 0) cout << "Podales liczbe ujemna(lub przekraczajaca zakres)!" << endl 
		<< "Obliczenia nie beda przeprowadzone w sposob prawidlowy" << endl;
	if (upper_limit > upper_limit_warning) cout << "Obliczenia moga zajac sporo czasu!" << endl;
	primes_init();
	search_for_primes();

	for (unsigned int i = 0; i < primes.size(); i++) {
		cout << i + 1 << ": " << primes[i] << endl;
	}
	cout << endl;
	keep_window_open();
	return 0;
}