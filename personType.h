#pragma once
#include <iostream>
#include <string>

using namespace std;

class personType {
public:
	personType() {										//contructor
		firstName = "";									//sets firstName to default ""
		lastName = "";									//sets lastName to default ""
	}
	personType(string F, string L) {			//takes 2 strings as formal parameters
		setFirstName(F);								//calls member function setFirstName with parameter F
		setLastName(L);									//calls member function setLastName with parameter L
	}
	void setFirstName(string F) {					//takes 1 string as formal parameters
		firstName = F;									//sets firstName equal to parameter F
	}
	string getFirstName() {						//has no formal parameters
		return firstName;								//returns firstName
	}
	void setLastName(string L) {					//takes 1 string as formal parameter
		lastName = L;									//sets lastName eqaul to parameter L
	}
	string getLastName() {							//has no formal parameters
		return lastName;								//returns lastName
	}
	string firstName;
	string lastName;
};
