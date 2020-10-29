/*
  ---------------------------------------------------------------------------
  Fichier     : labo3-feratiHebert.cpp
  Nom du labo : 02_taxi
  Auteurs     : Kevin Ferati, Elliott Hébert
  Date        : 26.10.2020
  But         : Ce programme demande à l'utilisateur une année,
  				    en vérifie l'intégrité, puis affiche tous les mois de cette année

  Remarques   : Lancer l'exe si possible depuis le terminal windows
  					 afin de profiter au maximum des fonctions de nettoyage d'écran.
  					 Les entrées utilisateurs sont vérifiées.
  					 Pour simplifier, les premiers janviers sont des lundis.

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

	 const char CHAR_TO_REPEAT = 'O'; // Char that has to be input by the user to repeat the operation

	 const int CELL_WIDTH = 3,
				DAYS_IN_WEEK = 7;

	 enum class Months {
		  JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
	 };

	 enum class Days {
		  MONDAY    = 'L',
		  TUESDAY   = 'M',
		  WEDNESDAY = 'M',
		  THURSDAY  = 'J',
		  FRIDAY    = 'V',
		  SATURDAY  = 'S',
		  SUNDAY    = 'D'
	 };

	 cout << "Bonjour" << endl
			<< "Ce programme vous demande une annee et vous affiche les calendriers de cette annee" << endl;

	 char quit;
	 do {
		  system("cls"); // clear the screen

		  int chosenYear;
		  bool isIncorrect;
		  do {
				cout << "entrer une valeur [" << MIN_YEAR << "-" << MAX_YEAR << "] : ";
				cin >> chosenYear;

				cin.clear();
				CLEAR_BUFFER;

				isIncorrect = cin.fail() || chosenYear < MIN_YEAR || chosenYear > MAX_YEAR;

				if (isIncorrect) {
					 cout << endl << "/!\\ recommencer" << endl;
				}
		  } while (isIncorrect);

		  bool isChosenYearLeap = chosenYear % 400 == 0 || (chosenYear % 4 == 0 && chosenYear % 100 != 0);
		  int daysInFebruary = isChosenYearLeap ? 29 : 28;
		  int offset = 0;

		  for (int month = (int) Months::JAN; month <= (int) Months::DEC; ++month) {

				int numberOfDaysInMonth;

				switch (Months(month)) {

					 case Months::JAN : {
						  numberOfDaysInMonth = 31;
						  cout << "JANVIER";
						  break;
					 }

					 case Months::FEB : {
						  numberOfDaysInMonth = daysInFebruary;
						  cout << "FEVRIER";
						  break;
					 }

					 case Months::MAR : {
						  numberOfDaysInMonth = 31;
						  cout << "MARS";
						  break;
					 }

					 case Months::APR : {
						  numberOfDaysInMonth = 30;
						  cout << "AVRIL";
						  break;
					 }

					 case Months::MAY : {
						  numberOfDaysInMonth = 31;
						  cout << "MAI";
						  break;
					 }

					 case Months::JUN : {
						  numberOfDaysInMonth = 30;
						  cout << "JUIN";
						  break;
					 }

					 case Months::JUL : {
						  numberOfDaysInMonth = 31;
						  cout << "JUILLET";
						  break;
					 }

					 case Months::AUG : {
						  numberOfDaysInMonth = 31;
						  cout << "AOUT";
						  break;
					 }

					 case Months::SEP : {
						  numberOfDaysInMonth = 30;
						  cout << "SEPTEMBRE";
						  break;
					 }

					 case Months::OCT : {
						  numberOfDaysInMonth = 31;
						  cout << "OCTOBRE";
						  break;
					 }

					 case Months::NOV : {
						  numberOfDaysInMonth = 30;
						  cout << "NOVEMBRE";
						  break;
					 }

					 case Months::DEC : {
						  numberOfDaysInMonth = 31;
						  cout << "DECEMBRE";
						  break;
					 }
				}

				cout << " " << chosenYear << endl;

				cout << right << setw(CELL_WIDTH) << (char) Days::MONDAY
					  << right << setw(CELL_WIDTH) << (char) Days::TUESDAY
					  << right << setw(CELL_WIDTH) << (char) Days::WEDNESDAY
					  << right << setw(CELL_WIDTH) << (char) Days::THURSDAY
					  << right << setw(CELL_WIDTH) << (char) Days::FRIDAY
					  << right << setw(CELL_WIDTH) << (char) Days::SATURDAY
					  << right << setw(CELL_WIDTH) << (char) Days::SUNDAY
					  << endl;

				int numberOfCells = numberOfDaysInMonth + offset;
				int numberOfWeeks = (int)ceil(numberOfCells / (double) DAYS_IN_WEEK);
				int day = 1;

				for (int week = 1; week <= numberOfWeeks; ++week) {
					 for (int dayInWeek = 1; dayInWeek <= DAYS_IN_WEEK; ++dayInWeek) {
						  cout << right << setw(CELL_WIDTH);

						  if (dayInWeek <= offset && week == 1) {
								cout << "";
						  } else {
								cout << day;
								if (day == numberOfDaysInMonth) {
									 break;
								}
								++day;
						  }
					 }
					 cout << endl;
				}

				offset = numberOfCells % DAYS_IN_WEEK;
				cout << endl;
		  }

		  cout << "Voulez-vous recommencer ? [" << CHAR_TO_REPEAT << "/N]";
		  cin >> quit;
		  cin.clear();
		  CLEAR_BUFFER;
	 } while (!cin.fail() && quit == CHAR_TO_REPEAT);

	 return EXIT_SUCCESS;
}
