// Marcin Zajac 10 04 2018
// Stroustrup Rozdzial 06 H07

/*
Napisz gramatyke dla wyrazen logicznych
!x;		~x;		x|y^z = x|(y^z);	x^y&z = x^(y&z)

F1:
	F2
	F1 "|" F2
F2:
	F3
	F2 "^" F3
F3:
	F4
	F3 "&" F4
F4:
	x
	"!"x
	"~"x
*/