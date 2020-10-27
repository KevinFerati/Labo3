/*
  ---------------------------------------------------------------------------
  Fichier     : labo3-feratiHebert.cpp
  Nom du labo : 02_taxi
  Auteur(s)   : Kevin Ferati, Elliott Hébert
  Date        : 26.10.2020
  But         : Ce programme demande à l'utilisateur une année,
  				    en vérifie l'intégrité, puis affiche tous les mois de cette année

  Remarque(s) : Lancer l'exe si possible depuis le terminal windows
  					 afin de profiter au maximum des fonctions de nettoyage d'écran

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
	 const char CHAR_TO_REPEAT = 'O'; // Char that has to be input by the user to repeat the operation

	 do {
		  system("cls"); // clear the screen
		  int userYear;
		  bool isIncorrect;

		  do {
				cout << "entrer une valeur [" << MIN_YEAR << "-" << MAX_YEAR << "] : ";
				cin >> userYear;

				cin.clear();
				CLEAR_BUFFER;

				isIncorrect = cin.fail() || userYear < MIN_YEAR || userYear > MAX_YEAR;

				if (isIncorrect) {
					 cout << endl << "/!\\ recommencer" << endl;
				}
		  } while (isIncorrect);

		  // Display calendar
		  bool isUserYearLeap = userYear % 400 == 0 || (userYear % 4 == 0 && userYear % 100 != 0);
		  int feblastDay = isUserYearLeap ? 29 : 28;
		  int offset = 0;

		  for (int month = (int) Months::JAN; month <= (int) Months::DEC; ++month) {
				int lastDay;
				switch (Months(month)) {

					 case Months::JAN : {
						  lastDay = 31;
						  cout << "JANVIER";
						  break;
					 }
					 case Months::FEB : {
						  lastDay = feblastDay;
						  cout << "FEVRIER";
						  break;
					 }
					 case Months::MAR : {
						  lastDay = 31;
						  cout << "MARS";
						  break;
					 }
					 case Months::APR : {
						  lastDay = 30;
						  cout << "AVRIL";
						  break;
					 }
					 case Months::MAY : {
						  lastDay = 31;
						  cout << "MAI";
						  break;
					 }
					 case Months::JUN : {
						  lastDay = 30;
						  cout << "JUIN";
						  break;
					 }
					 case Months::JUL : {
						  lastDay = 31;
						  cout << "JUILLET";
						  break;
					 }
					 case Months::AUG : {
						  lastDay = 31;
						  cout << "AOUT";
						  break;
					 }
					 case Months::SEP : {
						  lastDay = 30;
						  cout << "SEPTEMBRE";
						  break;
					 }
					 case Months::OCT : {
						  lastDay = 31;
						  cout << "OCTOBRE";
						  break;
					 }
					 case Months::NOV : {
						  lastDay = 30;
						  cout << "NOVEMBRE";
						  break;
					 }
					 case Months::DEC : {
						  lastDay = 31;
						  cout << "DECEMBRE";
						  break;
					 }
				}

				cout << " " << userYear << endl;

				const int CELL_WIDTH = 3,
						  DAYS_IN_WEEK = 7;

				cout << right << setw(CELL_WIDTH) << (char) Days::MONDAY
					  << right << setw(CELL_WIDTH) << (char) Days::TUESDAY
					  << right << setw(CELL_WIDTH) << (char) Days::WEDNESDAY
					  << right << setw(CELL_WIDTH) << (char) Days::THURSDAY
					  << right << setw(CELL_WIDTH) << (char) Days::FRIDAY
					  << right << setw(CELL_WIDTH) << (char) Days::SATURDAY
					  << right << setw(CELL_WIDTH) << (char) Days::SUNDAY
					  << endl;

				int numberOfCells = lastDay + offset;
				int numberOfWeeks = ceil(numberOfCells / (double) DAYS_IN_WEEK);
				int day = 1;

				for (int week = 1; week <= numberOfWeeks; ++week) {
					 for (int dayInWeek = 1; dayInWeek <= DAYS_IN_WEEK; ++dayInWeek) {
						  cout << right << setw(CELL_WIDTH);
						  if (dayInWeek <= offset && week == 1) {
								cout << "";
						  } else {
								cout << day;

								if (day == lastDay) {
									 break;
								} else {
									 ++day;
								}
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
