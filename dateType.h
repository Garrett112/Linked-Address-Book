#include <iostream>

using namespace std;

class dateType {
public:
	dateType() {										//constructor
		month = 1;										//sets default month to 1
		day = 1;										//sets default day to 1
		year = 1900;									//sets default year to 1900
	}
	dateType(int D, int M, int Y) {
		setDate(D, M, Y);								//plugs input date into setDate
	}
	void setDate(int M, int D, int Y) {

		if (M >= 1 && M <= 12) {						//checks if input month falls between 1 and 12
			month = M;									//sets month as input value
		}
		else {											//outputs error message and resets month value
			std::cerr << "Invalid Month, please enter a value between 1 and 12" << std::endl;
			month = 1;
		}
		if (M == 4 || M == 6 || M == 11) {				//checks if input month is 4, 6, or 11
			if (D >= 1 && D <= 30) {					//checks if input day falls between 1 and 30
				day = D;								//sets day as input value
			}
			else {										//outputs error message and resets day value
				cout << "Invalid Day, the selected month has 30 days" << endl;
				day = 1;
			}
		}
		else {
			if (M == 2) {								//checks if input month is 2
				if (isLeapYear(Y) == true) {			//checks if leap year is true
					if (D >= 1 && D <= 29) {			//checks if input day falls between 1 and 29
						day = D;						//sets day as input value
					}
					else {								//outputs error message and resets day value
						cout << "Invalid Day, the selected month has 29 days" << endl;
						day = 1;
					}
				}
				else {
					if (D >= 0 && D <= 28) {			//checks if input day falls between 1 and 28
						day = D;						//sets day as input value
					}
					else {								//outputs error message and resets day value
						cout << "Invalid Day, the selected month has 28 days" << endl;
						day = 1;
					}
				}
			}
			else {
				if (D >= 1 && D <= 31) {				//checks if input day falls between 1 and 31
					day = D;							//sets day as input value
				}
				else {									//outputs error message and resets day value
					cout << "Invalid Day, the selected month has 31 days" << endl;
					day = 1;
				}
			}
		}
		if (Y >= 1900) {								//checks if input year is after 1899
			year = Y;									//sets year as input value
		}
		else {											//outputs error message and resets year value
			cout << "Invalid Year, please enter a value of 1900 or above" << endl;
			year = 1900;
		}

	}
	int getDay() {
		return day;										//returns current day
	}
	int getMonth() {
		return month;									//returns current month
	}
	int getYear() {
		return year;									//returns current year
	}
	void print() {										//prints date in correct format
		cout << day << "-" << month << "-" << year << endl;
	}
	bool isLeapYear(int Y) {
		if (Y % 4 == 0) {								//checks if the year is evenly divisible by 4
			if (Y % 100 == 0) {							//checks if the year is evenly divisible by 100
				if (Y % 400 == 0) {						//checks if the year is evenly divisible by 400
					return true;						//returns true
				}
				else {
					return false;						//returns false
				}
			}
			else {
				return true;							//returns true
			}
		}
		else {
			return false;								//returns false
		}
	}
	int month;
	int day;
	int year;
};
