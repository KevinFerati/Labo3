/*
  ---------------------------------------------------------------------------
  Fichier     : labo3-feratiHebert.cpp
  Nom du labo : 02_taxi
  Auteur(s)   : Kevin Ferati, Elliott Hébert
  Date        : 26.10.2020
  But         : Ce programme demande à l'utilisateur une année,
  				    en vérifie l'intégrité, puis affiche tous les mois de cette année

  Remarque(s) :

  Compilateur : MinGW-W64
  ---------------------------------------------------------------------------
*/
#include <iostream>
#include <climits>

using namespace std;

#define CLEAR_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

int main() {
	 const int MIN_YEAR = 1900,
				MAX_YEAR = 2100;

	 cout << "Bonjour" << endl
			<< "Ce programme vous demande une annee et vous affiche les calendriers de cette annee" << endl;
	 char quit;

	 do {

		  int userYear;
		  bool isIncorrect;
		  do {
				cout << "entrer une valeur : [" << MIN_YEAR << "-" << MAX_YEAR << "]";
				cin >> userYear;
				cin.clear();

				CLEAR_BUFFER;
				isIncorrect = cin.fail() || userYear < MIN_YEAR || userYear > MAX_YEAR;

				if (isIncorrect) {
					 cout << endl << "/!\\ recommencer" << endl;
				}
		  } while (isIncorrect);

		  cout << "Votre numéro est : " << userYear << endl;

		  cout << "Voulez-vous recommencer ? [O/N]";
		  cin >> quit;
		  cin.clear();
		  CLEAR_BUFFER;
	 } while (!cin.fail() && quit == 'O');

}
