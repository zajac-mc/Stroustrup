// Marcin Zajac 12 03 2018
// Stroustrup Rozdzial 05 H12

/*
Program 'Byki i Krowy'
*/

#include"../../../std_lib_facilities.h"

const int rozmiar_wektora = 4;

vector<int> inicjalizuj_wektor() {
	vector<int> v;
	for (int i = 0; i < rozmiar_wektora; ++i) {
		v.push_back(i);
	}
	return v;
}

vector<int> get_vector_from_player() {
	vector<int> v;
	cout << "Podaj wektor " << rozmiar_wektora << " cyfr(0-9), aby zakonczyc wpisz'|':\n";
	int temp = -1;
	while (cin >> temp)
	{
		if (temp < 0 || temp >9) error("Niepoprawna wartosc(0-9)", temp);
		v.push_back(temp);
	}
	cin.clear();
	cin.ignore(10000, '\n');
	/*
	The cin.clear() clears the error flag on cin (so that future I/O operations will work correctly),
	and then cin.ignore(10000, '\n') skips to the next newline 
	(to ignore anything else on the same line as the non-number
	so that it does not cause another parse failure).
	It will only skip up to 10000 characters, so the code is assuming the user will not put in a very long, invalid line.

	https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input
	*/

	if (v.size() != rozmiar_wektora) error("Wprowadziles niepoprawana liczbe cyfr", v.size());
	return v;
}

void show_vector(vector<int> v) {
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
}

int main()
try {
	cout << "BYKI I KROWY\n\n"
		<< "Program w pamieci ma wektor czterech cyfr z zakresu od 0 do 9.\n"
		<< "Zadaniem gracza jest odgadnac te cyfry w kilku probach.\n"
		<< "Jesli do odgadniecia jest liczba 1234, a gracz wpisze 1359,\n"
		<< "program wydrukuje: \"1 byk i 1 krowa\", poniewaz gracz odgadl jedna cyfre\n"
		<< "i podal ja na wlasciwej pozycji (byk) oraz odgadl druga,\n"
		<< "ale podal ja na zlej pozycji (krowa). Gra toczy sie, az uzytkownik zdobedzie\n"
		<< "cztery byki, tzn. odgadnie wszystkie cztery liczby\n"
		<< "i ustawi je na wlasciwych pozycjach.\n\n";

	vector<int> v_comp;	// wektor liczb komputera
	v_comp = inicjalizuj_wektor();
	if (v_comp.size() != rozmiar_wektora) error("Nieprawidlowy rozmiar wektora!\n");
	/*Testowe wyswietlenie wektora przechowywanego przez komputer*/
	if (true) {
		/*
		for (int i = 0; i < v_comp.size(); ++i)
			cout << v_comp[i] << ' ';
			*/
		show_vector(v_comp);
		cout << endl;
	}

	vector<int> v_player = get_vector_from_player();
	/*Testowe wyswietlenie wektora wprowadzonego przez gracza*/
	if (true) {
		show_vector(v_player);
		cout << endl;
	}



		
	keep_window_open();
	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << "Blad: " << e.what() << endl;
	keep_window_open();
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Nieznany typ bledu!\n";
	keep_window_open();
	keep_window_open();
	return 2;
}