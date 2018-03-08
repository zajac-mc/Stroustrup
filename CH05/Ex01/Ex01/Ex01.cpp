// Marcin Zajac 08 03 2018
// Stroustrup Rozdzial 05 Ex01

#include "../../../std_lib_facilities.h"
int main()
try {
	int x = 20;
	char c = x;
	if (c == 20) cout << "Brawo!\n";
	cout << c;
	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << "Blad: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Nieznany rodzaj wyjatku!\n";
	return 2;
}