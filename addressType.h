#include <iostream>
#include <string>

using namespace std;

class addressType {
public:
	addressType() {								//constructor
		address = "";							//sets address
		city = "";								//sets city
		state = "XX";							//sets state as XX
		zipcode = "10000";						//sets zipcode as 10000
	}
	addressType(string addressName, string cityName, string stateAbbv, string zipC) {
		setAddress(addressName);				//puts input address into setAddress 
		setCity(cityName);						//puts input city into setCity
		setState(stateAbbv);					//puts input state into setState
		setZipcode(zipC);						//puts input zipcode into setZipcode
	}
	void setAddress(string addressName) {
		address = addressName;					//sets address as the input
	}
	void setCity(string cityName) {
		city = cityName;						//sets city as the input
	}
	void setState(string stateAbbv) {
		if (stateAbbv.length() == 2) {			//checks if the state is 2 characters
			state = stateAbbv;					//sets state as the input if it is 2 characters
		}
		else {									//gives error message if state is not 2 characters 
			cout << "Invalid state, please enter as a two letter abbreviation." << endl;
			state = "XX";						//sets the state as the default XX
		}
	}
	void setZipcode(string zipC) {
		zipcode = zipC;						//sets zipcode as the input
	}
	string getAddress() {
		return address;								//outputs current address
	}
	string getCity() {
		return city;									//outputs current address
	}
	string getState() {
		return state;									//outputs current state
	}
	string getZip() {
		return zipcode;								//outputs current zipcode
	}
	void print() {						//prints address, city, state, and zipcode
		cout << address << endl << city << " " << state << ", " << zipcode << endl;
	}
private:
	string address;
	string city;
	string state;
	string zipcode;
};
