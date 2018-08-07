#include <iostream>
#include <locale>
#include <string>
#include <cstdlib>
using namespace std;

int loc2()
{
	locale langLocale("");
	cout.imbue(langLocale);

	bool isGerman;
	if (langLocale.name() == "de_DE"||
		langLocale.name() == "de"||
		langLocale.name() == "german"){
		isGerman = true;
	}
	else {
		isGerman = false;
	}

	if (isGerman) {
		cout << "Sprachumgebung fuer Eingaben: ";
	}
	else{
		cout << "Locale for input: ";
	}

	string s;
	cin >> s;
	if (!cin) {
		if (isGerman) {
			cerr << "FEHLER begin Einlesen der Sprachumgebug" << endl;
		}
		else {
			cerr << "ERROR while reading the locale " << endl;
		}
		return EXIT_FAILURE;
	}
	locale cinLocale(s.c_str());
	cin.imbue(cinLocale);
	double value;
	while (cin >> value) {
		cout << value << endl;
	}
}


int loc1()
{
	cin.imbue(locale::classic());
	cout.imbue(locale("de_DE"));
	double value;
	while (cin>>value){
		cout << value << endl;
	}
	return 0;
}



