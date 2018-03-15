// Marcin Zajac 15 03 2018
// Stroustrup Rozdzial 05 H14

#include"../../../std_lib_facilities.h"

vector<int> pn;
vector<int> wt;
vector<int> sr;
vector<int> czw;
vector<int> pt;
vector<int> sb;
vector<int> nd;

char znak_konca = '|';

void czytaj_pary() {
	cout << "Podaj pare \"dzien_tygodnia liczba\": ";
	string dzien;
	int liczba;
	cin >> dzien >> liczba;
	if (!cin) error("Pojawil sie blad wczytujac: "+dzien,liczba);
	if (dzien == "Poniedzialek" || dzien == "poniedzialek" || dzien == "pn" || dzien == "Pn")
		pn.push_back(liczba);
	else if (dzien == "Wtorek" || dzien == "wtorek" || dzien == "Wt" || dzien == "wt")
		wt.push_back(liczba);
	else if (dzien == "Sroda" || dzien == "sroda" || dzien == "Sr" || dzien == "sr")
		sr.push_back(liczba);
	else if (dzien == "Czwartek" || dzien == "czwartek" || dzien == "Czw" || dzien == "czw")
		czw.push_back(liczba);
	else if (dzien == "Piatek" || dzien == "piatek" || dzien == "Pt" || dzien == "pt")
		pt.push_back(liczba);
	else if (dzien == "Sobota" || dzien == "sobota" || dzien == "Sb" || dzien == "sb")
		sb.push_back(liczba);
	else if (dzien == "Niedziela" || dzien == "niedziela" || dzien == "Nd" || dzien == "nd")
		nd.push_back(liczba);
	else error("Nieznana nazwa dnia: ",dzien);
}

void drukuj_wartosci_dnia(vector<int> v) {
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
}

int licz_sume_dnia(vector<int> v) {
	int suma = 0;
	for (int i = 0; i < v.size(); ++i) {
		suma += v[i];
	}
	return suma;
}

void podsumowanie_tygodnia() {
	cout << "Poniedzialek: ";
	drukuj_wartosci_dnia(pn);
	cout << ". Suma = " << licz_sume_dnia(pn) << endl;

	cout << "Wtorek: ";
	drukuj_wartosci_dnia(wt);
	cout << ". Suma = " << licz_sume_dnia(wt) << endl;

	cout << "Sroda: ";
	drukuj_wartosci_dnia(sr);
	cout << ". Suma = " << licz_sume_dnia(sr) << endl;

	cout << "Czwartek: ";
	drukuj_wartosci_dnia(czw);
	cout << ". Suma = " << licz_sume_dnia(czw) << endl;

	cout << "Piatek: ";
	drukuj_wartosci_dnia(pt);
	cout << ". Suma = " << licz_sume_dnia(pt) << endl;

	cout << "Sobota: ";
	drukuj_wartosci_dnia(sb);
	cout << ". Suma = " << licz_sume_dnia(sb) << endl;

	cout << "Niedziela: ";
	drukuj_wartosci_dnia(nd);
	cout << ". Suma = " << licz_sume_dnia(nd) << endl;
}

int main()
try {
	char ch = ' ';
	while (ch!=znak_konca)
	{
		czytaj_pary();
		cout << "Aby zakonczyc wprowadz '" << znak_konca << "', cokolwiek innego oznacza kontynuacje: ";
		cin >> ch;
	}
	podsumowanie_tygodnia();
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
	cerr << "\nNieznany typ bledu!\n";
	keep_window_open();
	keep_window_open();
	return 2;
}