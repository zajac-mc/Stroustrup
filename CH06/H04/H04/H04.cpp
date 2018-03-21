// Marcin Zajac 21 03 2018
// Stroustrup Rozdzial 06 H04

// Bjarne Stroustrup 7/25/2009
// Chapter 4 Exercise 19

#include "../../../std_lib_facilities.h"	
// note that different compilers/SDEs keep header files in different places
// so that you may have to use "../std_lib_facilities.h" or "../../std_lib_facilities.h"
// the ../ notation means "look one directly/folder up from the current directory/folder"

/*
enter name-and-value pairs into a pair of vectors
check that each name is unique
exit when we see the input "NoName 0"
output the pairs
*/


class Name_value
{
public:
	Name_value(string s,double v);

//private:

	string name;
	double value;
};


Name_value::Name_value(string s, double v):name(s),value(v)
{
}


int main()	
try
{
	vector<string> names;
	vector<int> scores;

	vector<Name_value> lista;

	string n;
	int v;

	while (cin >> n >> v && n != "NoName") {
		for (int i = 0; i < lista.size(); ++i)
			if (n == lista[i].name) error("duplicate: ", n);
		Name_value nv(n, v);
		lista.push_back(nv);
	}

	for (int i = 0; i < lista.size(); ++i)
		cout << '(' << lista[i].name << ',' << lista[i].value << ')' << endl;

	keep_window_open("~");	// For some Windows(tm) setups
}
catch (runtime_error e) {	// this code is to produce error messages; it will be described in Chapter 5
	cout << e.what() << '\n';
	keep_window_open("~");	// For some Windows(tm) setups
}
catch (...) {	// this code is to produce error messages; it will be described in Chapter 5
	cout << "exiting\n";
	keep_window_open("~");	// For some Windows(tm) setups
}

/*
(name,value) pairs are useful in many contexts. This is just the first and simplest variant.
Exercise 6.4 is another variant.

Note how we could read a (name,value) pair and used a specific name to indicated the end of input.
There is a second (undocumented) way of terminating the input. Try leaving out an integer; for example,
frank 3 joe bill 7
You may consider that a bug or a feature. If you consider it a bug, you'll find it a bit hard to detect
it reliably.

Checking for duplicates is another common activity, and easy.
*/