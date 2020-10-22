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
#include <iomanip>

using namespace std;

#define CLEAR_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

int main() {
	 const int MIN_YEAR = 1900,
				MAX_YEAR = 2100;

	 enum class Months { JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

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

		  // cout << "Votre numéro est : " << userYear << endl;

		  // Display calendar
		  bool isUserYearLeap = (userYear % 4 == 0 or userYear % 400 == 0) and userYear % 100 != 0;
		  short feblastDay = isUserYearLeap ? 29 : 28 ;
		  short lastDay, firstDayOfMonth = 1;

        for (int month = 1; month <= 12 ; ++month) {
           switch (month) {
             case 1:  {
                lastDay = 31;
                cout << "JANVIER";
                break;
             }
             case 2:  {
                lastDay = feblastDay;
                cout << "FEVRIER";
                break;
             }
             case 3: {
                lastDay = 31;
                cout << "MARS";
                break;
             }
             case 4: {
                lastDay = 30;
                cout << "AVRIL";
                break;
             }
             case 5: {
                lastDay = 31;
                cout << "MAI";
                break;
             }
             case 6: {
                lastDay = 30;
                cout << "JUIN"
                ; break;
             }
             case 7: {
                lastDay = 31;
                cout << "JUILLET";
                break;
             }
             case 8: {
                lastDay = 31;
                cout << "AOUT";
                break;
             }
             case 9: {
                lastDay = 30;
                cout << "SEPTEMBRE";
                break;
             }
             case 10: {
                lastDay = 31;
                cout << "OCTOBRE";
                break;
             }
             case 11: {
                lastDay = 30;
                cout << "NOVEMBRE";
                break;
             }
             case 12:{
                lastDay = 31;
                cout << "DECEMBRE";
                break;
             }
          }

           cout << " " << userYear << endl;

           short day = 1;

           cout << left << setw(3) << "L"
                << left << setw(3) << "M"
                << left << setw(3) << "M"
                << left << setw(3) << "J"
                << left << setw(3) << "V"
                << left << setw(3) << "S"
                << left << setw(3) << "D"
                << endl;
           for (int week = 1; week <= 5; ++week) {

              for (int dayOfWeek = 1; dayOfWeek <= 7; ++dayOfWeek) {
                 if (day * week < firstDayOfMonth) {
                    cout << left << setw(3) << "";
                 } else {
                    cout << left << setw(3) << day;
                 }

                  if (day == lastDay){
                     firstDayOfMonth = dayOfWeek + 1;
                     break;
                  } else {
                     ++day;
                  }

              }

              cout << endl;

           }
           cout << endl;
        }

		  cout << "Voulez-vous recommencer ? [O/N]";
		  cin >> quit;
		  cin.clear();
		  CLEAR_BUFFER;
	 } while (!cin.fail() && quit == 'O');

}
