#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <fstream>
#include "addressType.h"
#include "dateType.h"
#include "personType.h"
#include "extPersonType.h"

using namespace std;

class addressBookType {
public:
	addressBookType() {
		length = 0;
		maxLength = 200;
	}
	void initEntry() {
		int i = 0;
		string tempFname;
		string tempLname;
		int tempDay;
		int tempMonth;
		int tempYear;
		string tempAddress;
		string tempCity;
		string tempState;
		string tempZip;
		string tempPhone;
		string tempRelation;
		string line;
		ifstream file("AddressBookData.txt");
		while (i < 6) {
			cout << i << endl;
			file >> tempFname >> tempLname;
			addressList[i].setFirstName(tempFname);
			addressList[i].setLastName(tempLname);
			file >> tempDay >> tempMonth >> tempYear;
			addressList[i].birthday.setDate(tempMonth, tempDay, tempYear);
			getline(file, tempAddress);
			getline(file, tempAddress);
			addressList[i].address.setAddress(tempAddress);
			getline(file, tempCity);
			file >> tempState >> tempZip;
			addressList[i].address.setCity(tempCity);
			addressList[i].address.setState(tempState);
			addressList[i].address.setZipcode(tempZip);
			file >> tempPhone >> tempRelation;
			addressList[i].setPhoneNumber(tempPhone);
			addressList[i].setRelationship(tempRelation);
			++length;
			addressList[i].print();
			++i;
		}
		sortEntries();
	}

	void addEntry(extPersonType E) {
		if (length < maxLength) {
			length++;
			addressList[length] = E;
		}
		else {
			cout << "Array has reached it's maximum capacity." << endl;
		}
	}
	void findPerson(string lName) {
		for (int i = 0; i <= length; ++i) {
			if (addressList[i].getLastName() == lName) {
				addressList[i].print();
			}
		}
	}
	void findBirthdays(int bDayMonth) {
		for (int i = 0; i <= length; ++i) {
			if (addressList[i].getBirthMonth() == bDayMonth) {
				addressList[i].print();
			}
			else {}
		}
	}
	void findRelationship(string rShip) {
		for (int i = 0; i <= length; ++i) {
			if (addressList[i].getRelationship() == rShip) {
				addressList[i].print();
			}
			else {}
		}
	}
	void print() {
		for (int i = 0; i < length; ++i) {
			addressList[i].print();
		}
	}
	void sortEntries() {
		for (int c = 1; c < length; c++) {
			int i = c;
			bool placeFound = false;
			while (i > 0 && !placeFound) {
				if (addressList[i].getLastName() < addressList[i - 1].getLastName()) {
					string temp = addressList[i].getLastName();
					addressList[i].setLastName(addressList[i - 1].getLastName());
					addressList[i - 1].setLastName(temp);
					i--;
				}
				else {
					placeFound = true;
				}
			}
		}
	}
private:
	extPersonType addressList[15];
	int length;
	int maxLength;
};
