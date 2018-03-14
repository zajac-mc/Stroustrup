// Marcin Zajac 12 03 2018
// Stroustrup Rozdzial 05 H12

/*
Program 'Byki i Krowy'
*/

#include"../../../std_lib_facilities.h"

const int rozmiar_wektora = 4;
const char znak_konca = '|';

/*Funkcja tworzy wektor 0 1 2 3*/
vector<int> inicjalizuj_wektor() {
	vector<int> v;
	for (int i = 0; i < rozmiar_wektora; ++i) {
		v.push_back(i);
	}
	return v;
}


/*Funkcja tworzy wektor x x x x*/
vector<int> inicjalizuj_wektor_x(int x) {
	if (x < 0 || x >9) error("Niepoprawna parametr fukcji(0-9)", x);
	vector<int> v;
	for (int i = 0; i < rozmiar_wektora; ++i) {
		v.push_back(x);
	}
	return v;
}


vector<int> get_vector_from_player() {
	vector<int> v;
	cout << "Podaj wektor " << rozmiar_wektora << " cyfr(0-9), aby zakonczyc wprowadzanie wpisz dowolny znak niebedacy cyfra:\n";
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

/*Funkcja testowa pokazujaca zawartosc wektorow*/
void show_vector(vector<int> v) {
	cout << endl;
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
}

int ile_bykow(vector<int> v_to_guess, vector<int> v_players) {
	if (v_to_guess.size() != rozmiar_wektora) error("Nieprawidlowy rozmiar wektora do odgadniecia!", v_to_guess.size());
	if (v_players.size() != rozmiar_wektora) error("Rozmiar wektora gracza jest nieprawidlowy!", v_players.size());
	int byki = 0;
	for (int i = 0; i < v_to_guess.size(); ++i)
		if (v_to_guess[i] == v_players[i]) ++byki;
	return byki;
}

int ile_krow(vector<int> v_to_guess, vector<int> v_players) {
	if (v_to_guess.size() != rozmiar_wektora) error("Nieprawidlowy rozmiar wektora do odgadniecia!", v_to_guess.size());
	if (v_players.size() != rozmiar_wektora) error("Rozmiar wektora gracza jest nieprawidlowy!", v_players.size());
	bool krowa = false;
	vector<int> already_checked(rozmiar_wektora, 0);
	int krowy = 0;
	
	/*for (int i = 0; i < v_to_guess.size(); ++i) {	//	Sprawdza/porownuje kazdy element wektora do odgadniecia
		if (v_to_guess[i] != v_players[i])		//	Warunek "jesli nie byk"
			for (int j = 0; j < v_players.size(); ++j)	// Z kazdym elementem wektora podanego przez gracza
				if (!already_checked[j] && v_players[j] == v_to_guess[i]) {// Jesli dany element podany przez gracza nie byl jeszcze wykorzystany do wyznaczenia "krowy" i jesli jest "krowa"
					krowa = true;	// oznaczam, ze jest krowa
					already_checked[j] = 1;	// oznaczam, ze zostal juz wykorzystany, aby nie porownywac z tym elementem ponownie
				}
		if (krowa) {
			++krowy;
			krowa = false;
		}
	}*/
	/*for (int i = 0; i < v_to_guess.size(); ++i)
		if (v_to_guess[i] != v_players[i]) {		// Warunek "jesli nie byk"
			for (int j = 0; j < v_players.size(); ++j)
					if (v_to_guess[i] == v_players[j] && !already_checked[j]) {
						krowa = true;
						already_checked[j] = true;
					}
						if (krowa) ++krowy;
				}
			krowa = false;
		}
	*/
	/*for (int i = 0; i < v_to_guess.size(); ++i) {
		if (v_to_guess[i] != v_players[i])
			for (int j = 0; j < v_players.size();++j)
				if(v_to_guess[i]==v_players[j])
					krowa = true;
		if (krowa)++krowy;
		krowa = false;
	}*/


	// A moze by tak zaczac od j=i -- tak tez nie:(
	/*for (int i = 0; i < v_to_guess[i]; ++i) {
		if(v_to_guess[i]!=v_players[i])
			for (int j = i; j < v_players.size();++j) // <_______________________
	}*/
	return krowy;
}

vector<int> get_score(vector<int> v_to_guess, vector<int> v_players) {
	if (v_to_guess.size() != rozmiar_wektora) error("Nieprawidlowy rozmiar wektora do odgadniecia!", v_to_guess.size());
	if (v_players.size() != rozmiar_wektora) error("Rozmiar wektora gracza jest nieprawidlowy!", v_players.size());
	int byki = 0;
	int krowy = 0;

	for (int i = 0; i < v_to_guess.size(); ++i) {
		;
	}

	vector<int> wynik(2);
	wynik[0] = byki;
	wynik[1] = krowy;
	return wynik;
}


// funkcja zliczajaca
// liczbe bykow: liczba wystapien tej samej cyfry w dwoch wektorach na tej samej pozycji
// oraz liczbe krow: liczba wystapien tej samej cyfry na roznych pozycjach
// funkcja zwraca dwuelementowy wektor, gdzie [0] informuje o liczbie bykow,
// a [1] o liczbie krow
// v_c = [2 2 2 2]; v_p = [2 2 1 2] <---- !!!blad
vector<int> licz_zwierzeta(vector<int> v_c, vector<int> v_p)	// v_c - wektor komputera; v_p - wektor gracza
{
	vector<int> zwierzeta(2);
	zwierzeta[0] = 0;       // liczba bykow
	zwierzeta[1] = 0;       // liczba krow

	for (int i = 0; i<v_c.size(); ++i) {
		if (v_c[i] == v_p[i]) {
			++zwierzeta[0];
			v_c[i] = -1;
			v_p[i] = -2;
		}
		else {
			for (int j = 0; j<i; ++j)
				if (v_c[i] == v_p[j]) {
					++zwierzeta[1];
					v_c[i] = -1;
					v_p[j] = -2;
				}
			for (int j = i + 1; j<v_p.size(); ++j)
				if (v_c[i] == v_p[j]) {
					++zwierzeta[1];
					v_c[i] = -1;
					v_p[j] = -2;
				}
		}
	}

	return zwierzeta;
}

vector<int> licz_zwierzeta_2(vector<int> v_c, vector<int> v_p)	// v_c - wektor komputera; v_p - wektor gracza
{
	vector<int> zwierzeta(2);
	zwierzeta[0] = 0;       // liczba bykow
	zwierzeta[1] = 0;       // liczba krow

	for (int i = 0; i < v_c.size(); ++i) {
		if (v_c[i] == v_p[i]) {
			++zwierzeta[0];
			v_c[i] = -1;
			v_p[i] = -2;
		}
	}

	for (int i = 0; i < v_c.size(); ++i) {
		for (int j = 0; j < v_c.size(); ++j) {
			if (v_c[i] == v_p[j]) {
				++zwierzeta[1];
				v_c[i] = -1;
				v_p[j] = -2;
			}
		}
	}
/*
	for (int i = 0; i<v_c.size(); ++i) {
		if (v_c[i] == v_p[i]) {
			++zwierzeta[0];
			v_c[i] = -1;
			v_p[i] = -2;
		}
		else {
			for (int j = 0; j<i; ++j)
				if (v_c[i] == v_p[j]) {
					++zwierzeta[1];
					v_c[i] = -1;
					v_p[j] = -2;
				}
			for (int j = i + 1; j<v_p.size(); ++j)
				if (v_c[i] == v_p[j]) {
					++zwierzeta[1];
					v_c[i] = -1;
					v_p[j] = -2;
				}
		}
	}
	*/
	return zwierzeta;
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
		show_vector(v_comp);
		cout << endl;
	}

//	vector<int> v_player = get_vector_from_player();
	vector<int> v_player;
	/*Testowe wyswietlenie wektora wprowadzonego przez gracza*/
	if (true) {
		show_vector(v_player);
		cout << endl;
	}

//	cout << "Zdobywasz " << ile_bykow(v_comp, v_player) << " bykow" << endl;
//	cout << "oraz " << ile_krow(v_comp, v_player) << " krow" << endl;
	
	char ch = ' ';
	bool victory = false;
	vector<int> wyniki;
	while (ch != znak_konca) {
		v_player = get_vector_from_player();

		cout << "Zdobywasz " << ile_bykow(v_comp, v_player) << " bykow" << endl;
		cout << "oraz " << ile_krow(v_comp, v_player) << " krow" << endl;

		wyniki = licz_zwierzeta(v_comp,v_player);
		cout << "Licz zwierzeta- byki: " << wyniki[0] << ", krowy: " << wyniki[1] << endl;

		wyniki = licz_zwierzeta_2(v_comp, v_player);
		cout << "---> Licz zwierzeta_2- byki: " << wyniki[0] << ", krowy: " << wyniki[1] << endl;

		if (ile_bykow(v_comp, v_player) == rozmiar_wektora) {
			ch = znak_konca;
			cout << "Gratulacje! Udalo sie Tobie odgadnac prawidlowo caly wektor!\n";
		}
		else {
			cout << "Jesli chesz grac dalej wprowadz dowolny znak, aby zakonczyc wprowadz '|': ";
			cin >> ch;
		}
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