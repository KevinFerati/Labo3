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
#include <cmath>

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
		  int feblastDay = isUserYearLeap ? 29 : 28 ;
		  int lastDay, numberOfCells, numberOfWeeks, day, offSet = 0;

        for (int month = 1; month <= 12 ; ++month) {
           switch (Months(month)) {
             case Months::JAN:  {
                lastDay = 31;
                cout << "JANVIER";
                break;
             }
             case Months::FEB:  {
                lastDay = feblastDay;
                cout << "FEVRIER";
                break;
             }
             case Months::MAR: {
                lastDay = 31;
                cout << "MARS";
                break;
             }
             case Months::APR: {
                lastDay = 30;
                cout << "AVRIL";
                break;
             }
             case Months::MAY: {
                lastDay = 31;
                cout << "MAI";
                break;
             }
             case Months::JUN: {
                lastDay = 30;
                cout << "JUIN"
                ; break;
             }
             case Months::JUL: {
                lastDay = 31;
                cout << "JUILLET";
                break;
             }
             case Months::AUG: {
                lastDay = 31;
                cout << "AOUT";
                break;
             }
             case Months::SEP: {
                lastDay = 30;
                cout << "SEPTEMBRE";
                break;
             }
             case Months::OCT: {
                lastDay = 31;
                cout << "OCTOBRE";
                break;
             }
             case Months::NOV: {
                lastDay = 30;
                cout << "NOVEMBRE";
                break;
             }
             case Months::DEC:{
                lastDay = 31;
                cout << "DECEMBRE";
                break;
             }
          }

           cout << " " << userYear << endl;

           cout << left << setw(3) << "L"
                << left << setw(3) << "M"
                << left << setw(3) << "M"
                << left << setw(3) << "J"
                << left << setw(3) << "V"
                << left << setw(3) << "S"
                << left << setw(3) << "D"
                << endl;

            numberOfCells = lastDay + offSet;
            numberOfWeeks = ceil(numberOfCells / 7.);
            day = 1;

           for (int week = 1; week <= numberOfWeeks; ++week) {
              for (int col = 1; col <= 7; ++col) {
                 if (col <= offSet and week == 1) {
                    cout << left << setw(3) << "";
                 } else {
                    cout << left << setw(3) << day;

                    if (day == lastDay) {
                       break;
                    } else {
                       ++day;
                    }
                 }
              }
              cout << endl;
           }

           offSet = numberOfCells % 7;

           cout << endl;
        }

		  cout << "Voulez-vous recommencer ? [O/N]";
		  cin >> quit;
		  cin.clear();
		  CLEAR_BUFFER;
	 } while (!cin.fail() && quit == 'O');

}
