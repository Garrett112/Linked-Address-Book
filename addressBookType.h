#include <iostream>
#include <istream>
#include <string>
#include <fstream>
#include "addressType.h"
#include "dateType.h"
#include "personType.h"
#include "extPersonType.h"
#include "orderedLinkedList.h"

using namespace std;

class addressBookType : public orderedLinkedList<extPersonType> {
public:
	addressBookType() {}

	void initEntry() {
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
		nodeType<extPersonType>* current;
		nodeType<extPersonType>* end = this->first;
		while (end != nullptr) {
			end = end->link;
		}
		int i = 0;
		if (file.eof()) {
			i = 1;
		}
		while (i == 0) {
			file >> tempFname >> tempLname;
			current->info.setFirstName(tempFname);
			current->info.setLastName(tempLname);
			file >> tempDay >> tempMonth >> tempYear;
			current->info.birthday.setDate(tempMonth, tempDay, tempYear);
			getline(file, tempAddress);
			getline(file, tempAddress);
			current->info.address.setAddress(tempAddress);
			getline(file, tempCity);
			file >> tempState >> tempZip;
			current->info.address.setCity(tempCity);
			current->info.address.setState(tempState);
			current->info.address.setZipcode(tempZip);
			file >> tempPhone >> tempRelation;
			current->info.setPhoneNumber(tempPhone);
			current->info.setRelationship(tempRelation);
			end->link = current;
			end = end->link;
			if (file.eof()) {
				i = 1;
			}
		}
	}

	void addEntry(extPersonType E) {
		insert(E);
	}
	void findPerson(string lName) {
		nodeType<extPersonType>* searcher = this->first;
		while (searcher != nullptr) {
			if (searcher->info.getLastName() == lName) {
				searcher->info.print();
			}
		searcher = searcher->link;
		}
	}
	void findBirthdays(int bDayMonth) {
		nodeType<extPersonType>* searcher = this->first;
		while (searcher != nullptr) {
			if (searcher->info.getBirthMonth() == bDayMonth) {
				searcher->info.print();
			}
			searcher = searcher->link;
		}
	}
	void findRelationship(string rShip) {
		nodeType<extPersonType>* searcher = this->first;
		while (searcher != nullptr) {
			if (searcher->info.getRelationship() == rShip) {
				searcher->info.print();
			}
			searcher = searcher->link;
		}
	}
	void print() {
		nodeType<extPersonType>* searcher = this->first;
		while (searcher != nullptr) {
			searcher->info.print();
			searcher = searcher->link;
		}
	}
	void manualEntry() {
		extPersonType newNode;
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
		cout << "Enter First Name: ";
		cin >> tempFname;
		newNode.setFirstName(tempFname);
		cout << endl << "Enter Last Name: ";
		cin >> tempLname;
		newNode.setLastName(tempLname);
		cout << endl << "Enter Birthday (M D Y): ";
		cin >> tempMonth >> tempDay >> tempYear;
		newNode.birthday.setDate(tempMonth, tempDay, tempYear);
		cout << endl << "Enter Street Address: ";
		cin >> tempAddress;
		newNode.address.setAddress(tempAddress);
		cout << endl << "Enter City: ";
		cin >> tempCity;
		newNode.address.setCity(tempCity);
		cout << endl << "Enter State: ";
		cin >> tempState;
		newNode.address.setState(tempState);
		cout << endl << "Enter Zip Code: ";
		cin >> tempZip;
		newNode.address.setZipcode(tempZip);
		cout << endl << "Enter Phone Number: ";
		cin >> tempPhone;
		newNode.setPhoneNumber(tempPhone);
		cout << endl << "Enter Relationship: ";
		cin >> tempRelation;
		addEntry(newNode);
	}
	void manualRemoveEntry() {
		string lName;
		string fName;
		cout << "Enter Last Name: ";
		cin >> lName;
		cout << endl << "Enter First Name: ";
		cin >> fName;
		nodeType<extPersonType>* searcher = this->first;
		nodeType<extPersonType>* searcher2;
		while (searcher != nullptr) {
			if (searcher->info.getLastName() == lName && searcher->info.getFirstName() == fName) {
				cout << "Should the Following Entry be Deleted (Y/N)?: " << endl;
				searcher->info.print();
				string choice;
				cin >> choice;
				if (choice == "Y") {
					searcher = searcher->link;
					searcher2->link = searcher;
					cout << endl << "Entry has been Deleted.";
				}
				else {
					cout << endl << "Entry has not been Deleted. ";
				}
			}
			searcher2 = searcher;
			searcher = searcher->link;
		}

	}
	void saveData() {
		ofstream file("addressBookBackup.txt");
		nodeType<extPersonType>* pointer = this->first;
		while (pointer != nullptr) {
			file << pointer->info.getFirstName() << " " << pointer->info.getLastName() << endl;
			file << pointer->info.birthday.getMonth() << " " << pointer->info.birthday.getDay() << " " << pointer->info.birthday.getYear() << endl;
			file << pointer->info.address.getAddress() << endl;
			file << pointer->info.address.getCity() << endl;
			file << pointer->info.address.getState() << endl;
			file << pointer->info.address.getZip() << endl;
			file << pointer->info.getPhoneNumber() << endl;
			file << pointer->info.getRelationship() << endl;
			pointer = pointer->link;
		}
		file.close();

	}
	void showMenu() {
		addressBookType addressBook;
		addressBook.initEntry();
		int w = 1;
		while (w == 1) {
			cout << "Please Select an Option:" << endl;
			cout << "Enter 1 to Search by Last Name" << endl;
			cout << "Enter 2 to Search by Birth Month" << endl;
			cout << "Enter 3 to Search by Relationship" << endl;
			cout << "Enter 4 to Show all Entries" << endl;
			cout << "Enter 5 to Quit" << endl;
			int choice;
			cin >> choice;
			if (choice == 1) {
				cout << "Enter Last Name: ";
				string InputL;
				cin >> InputL;
				cout << endl;
				addressBook.findPerson(InputL);
			}
			if (choice == 2) {
				cout << "Enter Birth Month (Number 1-12): ";
				int InputM;
				cin >> InputM;
				cout << endl;
				addressBook.findBirthdays(InputM);
			}
			if (choice == 3) {
				cout << "Enter Relationship (Family, Friend, or Business): ";
				string InputR;
				cin >> InputR;
				cout << endl;
				addressBook.findRelationship(InputR);
			}
			if (choice == 4) {
				addressBook.print();
			}
			if (choice == 5) {
				w = 0;
			}
		}
	}
};