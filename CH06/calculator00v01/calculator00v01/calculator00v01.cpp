// Marcin Zajac 20 03 2018
// Stroustrup Rozdzial 06 - version for Chapter 6.7
//
//
// This is example code from Chapter 6.6 "Trying the first version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
// This is example code from Chapter 6.6 "Trying the first version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

#include "../../../std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {
public:
	char kind;        // what kind of token
	double value;     // for numbers: a value 
	Token(char ch)    // make a Token from a char
		:kind(ch), value(0) { }
	Token(char ch, double val)     // make a Token from a char and a double
		:kind(ch), value(val) { }
};


//------------------------------------------------------------------------------

class Token_stream {
public:
	Token_stream();		// Tworzy obiekt typu Token_stream, ktory wczytuje dane ze strumienia cin.
	Token get();		// Daje token (obiekt typu Token)
	void putback(Token t);	// Wklada token z powrotem.
private:
	// szczegoly implementacyjne
	bool full;	// Informuje czy w buforze jest token
	Token buffer;	// Miejsce do przechowywania tokenu zapisanego w strumieniu za pomoca funkcji putback()
};

Token_stream::Token_stream():full(false),buffer(0)	// Bufor jest pusty.
{
}

void Token_stream::putback(Token t)
{
	if (full) error("Wywolanie funkcji putback(), gdy bufor jest pelny.");
	buffer = t;	// Kopiuje t do bufora.
	full = true;	// Bufor jest pelny.
}

Token Token_stream::get()
{
	if (full) {	// Sprawdzenie czy jest gotowy token.
		// Usuniecie tokena z buforu
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;	// Uwaga: >> pomija biale znaki (spacje, nowe wiersze, tabulatory itp.)

	switch (ch)
	{
		case ';':	// drukowanie
		case 'k':	// koniec
		case'(':case')':case'+':case'-':case'*':case'/':case'%':
			return Token(ch);	// Kazdy znak reprezentuje sam siebie
		case'.':
		case'0':case'1':case'2':case'3':case'4':
		case'5':case'6':case'7':case'8':case'9':
			{	cin.putback(ch);	// Wstawia cyfre z powrotem do strumienia wejsciowego
				double val;
				cin >> val;	// Wczytuje liczbe zmiennoprzecinkowa.
				return Token('8',val);	// '8' reprezentuje "liczbe"
			}
	default:
		error("Nieprawidlowy token.");
	}
}

Token_stream ts;	// Udostepnia funkcje get() i putback().

//------------------------------------------------------------------------------

double expression();  // read and evaluate a Expression

					  //------------------------------------------------------------------------------

double term();        // read and evaluate a Term

					  //------------------------------------------------------------------------------

double primary()     // read and evaluate a Primary
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':    // handle '(' expression ')'
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case '8':            // we use '8' to represent a number
		return t.value;  // return the number's value
	default:
		error("primary expected");
	}
}
//------------------------------------------------------------------------------

int main()
try {
	double val = 0;
	while (cin)
	{
		Token t = ts.get();

		if (t.kind == 'k') break;	// 'k' = koniec
		if (t.kind == ';')	// ';' = drukuj teraz
			cout << "=" << val << '\n';
		else
			ts.putback(t);
		val = expression();
	}
	keep_window_open("~0");
}
catch (exception& e) {
	cerr << e.what() << endl;
	keep_window_open("~1");
	return 1;
}
catch (...) {
	cerr << "exception \n";
	keep_window_open("~2");
	return 2;
}

//------------------------------------------------------------------------------

double expression()
{
	double left = term();      // read and evaluate a Term
	Token t = ts.get();	// Pobiera nastepny token ze strumienia tokenow.
	while (true) {
		switch (t.kind) {
		case '+':
			left += term();    // evaluate Term and add
			t = ts.get();
			break;
		case '-':
			left -= term();    // evaluate Term and subtract
			t =ts.get();
			break;
		default:
			ts.putback(t);	// Wstawia token t z powrotem do strumienia tokenow.
			return left;       // finally: no more + or -: return the answer
		}
	}
}

//------------------------------------------------------------------------------

double term()
{
	double left = primary();
	Token t = ts.get();	// Pobiera nastepny token ze strumienia tokenow.

	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);	// Wstawia token t z powrotem do strumienia tokenow.
			return left;
		}
	}
}

//------------------------------------------------------------------------------
