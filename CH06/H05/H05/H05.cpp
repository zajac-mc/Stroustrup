// Marcin Zajac 10 04 2018
// Stroustrup Rozdzial 06 H06


/*
Sentence:
	Noun Verb
	Sentence Conjunction Sentence
Conjunction:
	"and"
	"or"
	"but"
Noun:
	"birds"
	"fish"
	"C++"
	Article Noun
Verb:
	"rules"
	"fly"
	"swim"
Article:
	"the"
*/

#include "../../../std_lib_facilities.h"


const char end_of_sentence = '.';	// Zgodnie z zalozeniami, kazde zdanie
									// konczy sie kropka otoczona bialymi znakami

vector<string> conjunctions;
vector<string> nouns;
vector<string> verbs;
vector<string> articles;

void init_dictionary() {
	conjunctions.push_back("and");
	conjunctions.push_back("or");
	conjunctions.push_back("but");

	nouns.push_back("birds");
	nouns.push_back("fish");
	nouns.push_back("C++");

	verbs.push_back("rules");
	verbs.push_back("fly");
	verbs.push_back("swim");

	articles.push_back("the");
}

bool sentence();
bool noun();
bool verb();
bool my_conjunction();			// conjunction jest juz uzywane przez jezyk
bool article(string word_art);

bool sentence() {
	bool is_sentence = noun() && verb();		// Zdanie to polaczenie rzeczownika i czasownika
	char ch = ' ';
	cin >> ch;
	if (ch != end_of_sentence) {				// Sprawdza czy zdanie zostalo zakonczone kropka
		cin.putback(ch);							// Jesli nie ma kropki, a istnieje spojnik
		if (my_conjunction()) is_sentence = is_sentence && sentence();	// sprawdza czy kolejna czesc jest zdaniem
		else is_sentence = false;			// Jesli nie bylo kropki oraz prawidlowego spojnika nie jest to zdanie
	}
	else
		cin.putback(ch);
	return is_sentence;
};

bool noun() {
	string word = " ";
	bool is_noun = false;
	cin >> word;
	bool is_article = article(word);	// Sprawdza czy slowo jest przedimkiem
	if (is_article) cin >> word;		// jesli jest, pobiera kolejne slowo
	for (unsigned int i = 0; i < nouns.size(); i++)
		if (word == nouns[i]) is_noun = true;
	return is_noun;
};
bool verb() {
	bool is_verb = false;
	string word = " ";
	cin >> word;
	for (unsigned int i = 0; i < verbs.size(); i++)
		if (word == verbs[i]) is_verb = true;
	return is_verb;
};
bool my_conjunction() {
	bool is_conjunction = false;
	string word = " ";
	cin >> word;
	for (unsigned int i = 0; i < conjunctions.size(); i++)
		if (word == conjunctions[i]) is_conjunction = true;
	return is_conjunction;
};
bool article(string word_art) {
	bool is_article = false;
	for (unsigned int i = 0; i < articles.size(); i++)
		if (word_art == articles[i]) is_article = true;
	return is_article;
};

int main()
try {
	init_dictionary();
	string word = " ";
	char ch = ' ';
	bool is_sentence = false;
	while (true) {
		cin >> ch;
		if (ch == end_of_sentence) {
			cout << endl << "Koniec pobierania danych." << endl;
			if (is_sentence)
				cout << endl << "Zgodnie z przyjeta gramatyka to bylo zdanie." << endl;
			else
				cout << "Zgodnie z przyjeta gramatyka to nie bylo zdanie." << endl;
			break;
		}
		else cin.putback(ch);
		is_sentence = sentence();
	}
	keep_window_open();
	return 0;
}
catch (exception& e)
{
	cerr << "error: " << e.what() << endl;
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Nieznany blad!" << endl;
	keep_window_open();
	return 2;
}
