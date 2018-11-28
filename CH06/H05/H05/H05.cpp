// Marcin Zajac 28 03 2018
// Stroustrup Rozdzial 06 H06

// test - reminder
// test - reminder 2


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

const char end_of_sentence = '.';

bool article(string s) {
	if (s == "the") return true;
	else false;
}

bool noun(string s) {
	if (s == "birds" || s == "fish" || s == "C++") return true;
	//else if 
	else return false;
}

bool verb(string s) {
	if (s == "rules" || s == "fly" || s == "swim") return true;
	else return false;
}

bool conjunction(string s) {
	if (s == "and" || s == "or" || s == "but")
		return true;
	else return false;
}

bool is_sentence(string s) {

}

int main()
try
{

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