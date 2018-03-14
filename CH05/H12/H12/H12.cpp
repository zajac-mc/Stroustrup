// Marcin Zajac 14 03 2018
// Stroustrup Rozdzial 05 H13

/*
Program 'Byki i Krowy'
*/

#include"../../../std_lib_facilities.h"

const int rozmiar_wektora = 4;
const char znak_konca_rundy = '|';
const char znak_konca_gry = '!';
bool test_mode = false;

void show_info() {
	cout << "BYKI I KROWY\n\n"
		<< "Program w pamieci ma wektor czterech cyfr z zakresu od 0 do 9.\n"
		<< "Zadaniem gracza jest odgadnac te cyfry w kilku probach.\n"
		<< "Jesli do odgadniecia jest liczba 1234, a gracz wpisze 1359,\n"
		<< "program wydrukuje: \"1 byk i 1 krowa\", poniewaz gracz odgadl jedna cyfre\n"
		<< "i podal ja na wlasciwej pozycji (byk) oraz odgadl druga,\n"
		<< "ale podal ja na zlej pozycji (krowa). Gra toczy sie, az uzytkownik zdobedzie\n"
		<< "cztery byki, tzn. odgadnie wszystkie cztery liczby\n"
		<< "i ustawi je na wlasciwych pozycjach.\n\n";
}

void zdobadz_ziarno() {
	cout << "W celu otrzymania losowych wartosci wektora, ktory bedziesz zgadywac, podaj liczbe" << endl
		<< "(dana liczba genereuje zawsze takie same wartosci): ";
	int n;
	cin >> n;
	srand(n);
}

vector<int> tworz_losowy_wektor() {
	vector<int> v;
	for (int i = 0; i < rozmiar_wektora; ++i)
		v.push_back(randint(9));
	return v;
}

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

/*Funkcja testowa pokazujaca zawartosc wektora oraz jego nazwe*/
void show_vector(vector<int> v, string v_name) {
	cout << endl<< v_name << ": ";
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
	cout << endl;
}


// funkcja zliczajaca
// liczbe bykow: liczba wystapien tej samej cyfry w dwoch wektorach na tej samej pozycji
// oraz liczbe krow: liczba wystapien tej samej cyfry na roznych pozycjach
// funkcja zwraca dwuelementowy wektor, gdzie [0] informuje o liczbie bykow,
// a [1] o liczbie krow
vector<int> licz_zwierzeta_2018(vector<int> v_c, vector<int> v_p)	// v_c - wektor komputera; v_p - wektor gracza
{
	if (v_c.size() != rozmiar_wektora) error("Nieprawidlowy rozmiar wektora do odgadniecia!", v_c.size());
	if (v_p.size() != rozmiar_wektora) error("Rozmiar wektora gracza jest nieprawidlowy!", v_p.size());
	vector<int> zwierzeta(2);
	zwierzeta[0] = 0;       // liczba bykow
	zwierzeta[1] = 0;       // liczba krow

	for (int i = 0; i < v_c.size(); ++i) {
		if (v_c[i] == v_p[i]) {
			++zwierzeta[0];
			v_c[i] = -1;		// Wykorzystuje wartosc -1 do oznaczenia, ze element v_c[i] zostal juz wykorzystany do obliczenia bykow,
			v_p[i] = -2;		// aby nie brac go pod uwage w dalszych obliczeniach. Analogicznie v_p[i] = -2.
		}						// Korzystam z wartosci spoza zakresu dostepnego dla gracza, roznych w kazdym wektorze,
	}							// aby przy dalszym obliczaniu krow nie powodowac bledow

	for (int i = 0; i < v_c.size(); ++i) {
		for (int j = 0; j < v_c.size(); ++j) {
			if (v_c[i] == v_p[j]) {
				++zwierzeta[1];
				v_c[i] = -1;
				v_p[j] = -2;
			}
		}
	}
	return zwierzeta;
}

void jedna_runda(vector<int> v_c) {	// v_c - wektor do odgadniecia
	vector<int> v_player;
	if (test_mode) {
		show_vector(v_player, "v_player");
		cout << endl;
	}

	char ch_r = ' ';
	vector<int> wyniki;
	while (ch_r != znak_konca_rundy) {
		v_player = get_vector_from_player();

		wyniki = licz_zwierzeta_2018(v_c, v_player);
		cout << "Byki: " << wyniki[0] << ", krowy: " << wyniki[1] << endl;

		if (wyniki[0] == rozmiar_wektora) {
			ch_r = znak_konca_rundy;
			cout << "Gratulacje! Udalo sie Tobie odgadnac prawidlowo caly wektor!\n";
		}
		else {
			cout << "Jesli chesz grac dalej wprowadz dowolny znak, aby zakonczyc runde wprowadz '|': ";
			cin >> ch_r;
		}
	}

}



int main()
try {
	show_info();

	zdobadz_ziarno();

	vector<int> v_comp;	// wektor liczb komputera

	char ch = ' ';
	while (ch!= znak_konca_gry) {
		v_comp = tworz_losowy_wektor();
		if (v_comp.size() != rozmiar_wektora) error("Nieprawidlowy rozmiar wektora!\n");
		if (test_mode) {
			show_vector(v_comp, "v_comp");
			cout << endl;
		}

		jedna_runda(v_comp);
		cout << "Aby zakonczyc gre wprowadz: '" << znak_konca_gry <<"', wprowadzenie innego znaku rozpocznie kolejna runde:)\n";
		cin >> ch;
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
