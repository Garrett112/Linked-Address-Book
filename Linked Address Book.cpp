#include <iostream>
#include <string>
#include <cassert>
#include <fstream>

using namespace std;

template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type>* link;
};
template <class Type>
class linkedListIterator
{
public:
	linkedListIterator();
	//Default constructor
	//Postcondition: current = nullptr;
	linkedListIterator(nodeType<Type>* ptr);
	//Constructor with a parameter.
	//Postcondition: current = ptr;
	Type operator*();
	//Function to overload the dereferencing operator *.
	//Postcondition: Returns the info contained in the node.
	linkedListIterator<Type> operator++();
	//Overload the pre-increment operator.
	//Postcondition: The iterator is advanced to the next
	// node.
	bool operator==(const linkedListIterator<Type>& right) const;
	//Overload the equality operator.
	//Postcondition: Returns true if this iterator is equal to
	// the iterator specified by right,
	// otherwise it returns the value false.
	bool operator!=(const linkedListIterator<Type>& right) const;
	//Overload the not equal to operator.
	//Postcondition: Returns true if this iterator is not
	// equal to the iterator specified by
	// right; otherwise it returns the value
	// false.
private:
	nodeType<Type>* current; //pointer to point to the current
	//node in the linked list
};
template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
	current = nullptr;
}
template <class Type>
linkedListIterator<Type>::
linkedListIterator(nodeType<Type>* ptr)
{
	current = ptr;
}
template <class Type>
Type linkedListIterator<Type>::operator*()
{
	return current->info;
}
template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::
operator++()
{
	current = current->link;
	return *this;
}
template <class Type>
bool linkedListIterator<Type>::operator==
(const linkedListIterator<Type>& right) const
{
	return (current == right.current);
}
template <class Type>
bool linkedListIterator<Type>::operator!=
(const linkedListIterator<Type>& right) const
{
	return (current != right.current);
}
//***************** class linkedListType ****************
template <class Type>
class linkedListType
{
public:
	const linkedListType<Type>& operator=
		(const linkedListType<Type>&);
	//Overload the assignment operator.
	void initializeList();
	//Initialize the list to an empty state.
	//Postcondition: first = nullptr, last = nullptr,
	// count = 0;
	bool isEmptyList() const;
	//Function to determine whether the list is empty.
	//Postcondition: Returns true if the list is empty,
	// otherwise it returns false.
	void print() const;
	//Function to output the data contained in each node.
	//Postcondition: none
	void reversePrint() const;
	//Function to output the data in reverse (starting from the first)
	void reversePrint(nodeType<Type>* current) const;
	//Function to output the data in reverse starting from current)
	int length() const;
	//Function to return the number of nodes in the list.
	//Postcondition: The value of count is returned.
	void destroyList();
	//Function to delete all the nodes from the list.
	//Postcondition: first = nullptr, last = nullptr,
	// count = 0;
	Type front() const;
	//Function to return the first element of the list.
	//Precondition: The list must exist and must not be
	// empty.
	//Postcondition: If the list is empty, the program
	// terminates; otherwise, the first
	// element of the list is returned.
	Type back() const;
	//Function to return the last element of the list.
	//Precondition: The list must exist and must not be
	// empty.
	//Postcondition: If the list is empty, the program
	// terminates; otherwise, the last
	// element of the list is returned.
	virtual bool search(const Type& searchItem) const = 0;
	//Function to determine whether searchItem is in the list.
	//Postcondition: Returns true if searchItem is in the
	// list, otherwise the value false is
	// returned.
	virtual void insertFirst(const Type& newItem) = 0;
	//Function to insert newItem at the beginning of the list.
	//Postcondition: first points to the new list, newItem is
	// inserted at the beginning of the list,
	// last points to the last node in the list,
	// and count is incremented by 1.
	virtual void insertLast(const Type& newItem) = 0;
	//Function to insert newItem at the end of the list.
	//Postcondition: first points to the new list, newItem
	// is inserted at the end of the list,
	// last points to the last node in the
	// list, and count is incremented by 1.
	virtual void deleteNode(const Type& deleteItem) = 0;
	//Function to delete deleteItem from the list.
	//Postcondition: If found, the node containing
	// deleteItem is deleted from the list.
	// first points to the first node, last
	// points to the last node of the updated
	// list, and count is decremented by 1.
	linkedListIterator<Type> begin();
	//Function to return an iterator at the begining of
	//the linked list.
	//Postcondition: Returns an iterator such that current
	// is set to first.
	linkedListIterator<Type> end();
	//Function to return an iterator one element past the
	//last element of the linked list.
	//Postcondition: Returns an iterator such that current
	// is set to nullptr.
	linkedListType();
	//Default constructor
	//Initializes the list to an empty state.
	//Postcondition: first = nullptr, last = nullptr,
	// count = 0;
	linkedListType(const linkedListType<Type>& otherList);
	//copy constructor
	~linkedListType();
	//Destructor
	//Deletes all the nodes from the list.
	//Postcondition: The list object is destroyed.
protected:
	int count; //variable to store the number of
	//elements in the list
	nodeType<Type>* first; //pointer to the first node of the list
	nodeType<Type>* last; //pointer to the last node of the list
private:
	void copyList(const linkedListType<Type>& otherList);
	//Function to make a copy of otherList.
	//Postcondition: A copy of otherList is created and
	// assigned to this list.
};
template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
	return (first == nullptr);
}
template <class Type>
linkedListType<Type>::linkedListType() //default constructor
{
	first = nullptr;
	last = nullptr;
	count = 0;
}
template <class Type>
void linkedListType<Type>::destroyList()
{
	nodeType<Type>* temp; //pointer to deallocate the memory
	//occupied by the node
	while (first != nullptr) //while there are nodes in
	{ //the list
		temp = first; //set temp to the current node
		first = first->link; //advance first to the next node
		delete temp; //deallocate the memory occupied by temp
	}
	last = nullptr; //initialize last to nullptr; first has
	//already been set to nullptr by the while loop
	count = 0;
}
template <class Type>
void linkedListType<Type>::initializeList()
{
	destroyList(); //if the list has any nodes, delete them
}
template <class Type>
void linkedListType<Type>::print() const
{
	nodeType<Type>* current; //pointer to traverse the list
	current = first; //set current so that it points to
	//the first node
	while (current != nullptr) //while more data to print
	{
		cout << current->info << " ";
		current = current->link;
	}
}//end print
template <class Type>
void linkedListType<Type>::reversePrint() const
{
	reversePrint(first);
}
template <class Type>
void linkedListType<Type>::reversePrint(nodeType<Type>* current) const
{
	if (current != nullptr)
	{
		reversePrint(current->link); //print the tail
		cout << current->info << " "; //print the node
	}
}
template <class Type>
int linkedListType<Type>::length() const
{
	return count;
} //end length
template <class Type>
Type linkedListType<Type>::front() const
{
	assert(first != nullptr);
	return first->info; //return the info of the first node
}//end front
template <class Type>
Type linkedListType<Type>::back() const
{
	assert(last != nullptr);
	return last->info; //return the info of the last node
}//end back
template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
	linkedListIterator<Type> temp(first);
	return temp;
}
template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
	linkedListIterator<Type> temp(nullptr);
	return temp;
}
template <class Type>
void linkedListType<Type>::copyList
(const linkedListType<Type>& otherList)
{
	nodeType<Type>* newNode; //pointer to create a node
	nodeType<Type>* current; //pointer to traverse the list
	if (first != nullptr) //if the list is nonempty, make it empty
		destroyList();
	if (otherList.first == nullptr) //otherList is empty
	{
		first = nullptr;
		last = nullptr;
		count = 0;
	}
	else
	{
		current = otherList.first; //current points to the list to be copied
		count = otherList.count;
		//copy the first node
		first = new nodeType<Type>; //create the node
		first->info = current->info; //copy the info
		first->link = nullptr; //set the link field of the node to nullptr
		last = first; //make last point to the first node
		current = current->link; //make current point to the next node
		//copy the remaining list
		while (current != nullptr)
		{
			newNode = new nodeType<Type>; //create a node
			newNode->info = current->info; //copy the info
			newNode->link = nullptr; //set the link of newNode to nullptr
			last->link = newNode; //attach newNode after last
			last = newNode; //make last point to the actual last node
			current = current->link; //make current point to the next node
		}//end while
	}//end else
}//end copyList
template <class Type>
linkedListType<Type>::~linkedListType() //destructor
{
	destroyList();
}//end destructor
template <class Type>
linkedListType<Type>::linkedListType
(const linkedListType<Type>& otherList)
{
	first = nullptr;
	copyList(otherList);
}//end copy constructor
//overload the assignment operator
template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=
(const linkedListType<Type>& otherList)
{
	if (this != &otherList) //avoid self-copy
	{
		copyList(otherList);
	}//end else
	return *this;
}

template <class Type>
class orderedLinkedList : public linkedListType<class Type>
{
public:
	bool search(const Type& searchItem) const;
	//Function to determine whether searchItem is in the list.
	//Postcondition: Returns true if searchItem is in the
	// list, otherwise it returns false.
	void insert(const Type& newItem);
	//Function to insert newItem in the list.
	//Postcondition: first points to the new list, newItem
	// is inserted at the proper place in the
	// list, and count is incremented by 1.
	void insertFirst(const Type& newItem);
	//Function to insert newItem in the list.
	//Because the resulting list must be sorted, newItem is
	//inserted at the proper in the list.
	//This function uses the function insert to insert newItem.
	//Postcondition: first points to the new list, newItem is
	// inserted at the proper in the list,
	// and count is incremented by 1.
	void insertLast(const Type& newItem);
	//Function to insert newItem in the list.
	//Because the resulting list must be sorted, newItem is
	//inserted at the proper in the list.
	//This function uses the function insert to insert newItem.
	//Postcondition: first points to the new list, newItem is
	// inserted at the proper in the list,
	// and count is incremented by 1.
	void deleteNode(const Type& deleteItem);
	//Function to delete deleteItem from the list.
	//Postcondition: If found, the node containing
	// deleteItem is deleted from the list;
	// first points to the first node of the
	// new list, and count is decremented by 1.
	// If deleteItem is not in the list, an
	// appropriate message is printed.
};
template <class Type>
bool orderedLinkedList<Type>::
search(const Type& searchItem) const
{
	bool found = false;
	nodeType<Type>* current; //pointer to traverse the list
	current = this->first; //start the search at the first node
	while (current != nullptr && !found)
		if (current->info >= searchItem)
			found = true;
		else
			current = current->link;
	if (found)
		found = (current->info == searchItem); //test for equality
	return found;
}//end search
template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
	nodeType<Type>* current; //pointer to traverse the list
	nodeType<Type>* trailCurrent = nullptr; //pointer just before current
	nodeType<Type>* newNode; //pointer to create a node
	bool found;
	newNode = new nodeType<Type>; //create the node
	newNode->info = newItem; //store newItem in the node
	newNode->link = nullptr; //set the link field of the node to nullptr
	if (this->first == nullptr) //Case 1
	{
		this->first = newNode;
		this->last = newNode;
		this->count++;
	}
	else
	{
		current = this->first;
		found = false;
		while (current != nullptr && !found) //search the list
			if (current->info >= newItem)
				found = true;
			else
			{
				trailCurrent = current;
				current = current->link;
			}
		if (current == this->first) //Case 2
		{
			newNode->link = this->first;
			this->first = newNode;
			this->count++;
		}
		else //Case 3
		{
			trailCurrent->link = newNode;
			newNode->link = current;
			if (current == nullptr)
				this->last = newNode;
			this->count++;
		}
	}//end else
}//end insert
template<class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
	insert(newItem);
}//end insertFirst
template<class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
	insert(newItem);
}//end insertLast
template<class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type>* current; //pointer to traverse the list
	nodeType<Type>* trailCurrent = nullptr; //pointer just
	//before current
	bool found;
	if (this->first == nullptr) //Case 1
		cout << "Cannot delete from an empty list." << endl;
	else
	{
		current = this->first;
		found = false;
		while (current != nullptr && !found) //search the list
			if (current->info >= deleteItem)
				found = true;
			else
			{
				trailCurrent = current;
				current = current->link;
			}
		if (current == nullptr) //Case 4
			cout << "The item to be deleted is not in the "
			<< "list." << endl;
		else
			if (current->info == deleteItem) //the item to be
				//deleted is in the list
			{
				if (this->first == current) //Case 2
				{
					this->first = this->first->link;
					if (this->first == nullptr)
						this->last = nullptr;
					delete current;
				}
				else //Case 3
				{
					trailCurrent->link = current->link;
					if (current == this->last)
						this->last = trailCurrent;
					delete current;
				}
				this->count--;
			}
			else //Case 4
				cout << "The item to be deleted is not in the "
				<< "list." << endl;
	}
}

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

class addressType {
public:
	addressType() {								//constructor
		address = "";							//sets address
		city = "";								//sets city
		state = "XX";							//sets state as XX
		zipcode = "10000";						//sets zipcode as 10000
	}
	//addressType(string addressName, string cityName, string stateAbbv, string zipC) {
	//	setAddress(addressName);				//puts input address into setAddress 
	//	setCity(cityName);						//puts input city into setCity
	//	setState(stateAbbv);					//puts input state into setState
	//	setZipcode(zipC);						//puts input zipcode into setZipcode
	//}
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

class extPersonType : public personType {
public:
	extPersonType() {														//constructor
		phoneNumber = "";													//sets default phoneNumber as  ""
		relationship = "";													//sets default relationship as ""
	}

	//bool operator==(const extPersonType& other) const {
	//	return (lastName + " " + firstName) == (other.lastName + " " + other.firstName);
	//}

	//bool operator!=(const extPersonType& other) const {
	//	return !(*this == other);
	//}

	//bool operator>=(const extPersonType& other) const {
	//	return (lastName + " " + firstName) >= (other.lastName + " " + other.firstName);
	//}

	extPersonType(string F, string L, int M, int D, int Y, string A, string C, string S, string Z, string P, string R) {
		setFirstName(F);													//calls member function setFirstName
		setLastName(L);														//calls member function setLastName
		address.setAddress(A);												//calls the addressType member function setAddress
		address.setCity(C);													//calls the addressType member function setCity
		address.setState(S);												//calls the addressType member function setState
		address.setZipcode(Z);												//calls the addressType member function setZipcode
		birthday.setDate(M, D, Y);											//calls the dateType member function setDate
		setPhoneNumber(P);													//calls the member function setPhoneNumber
		setRelationship(R);													//calls the member function setRelationship
	}
	void setPhoneNumber(std::string N) {									//uses one string as a formal parameter
		phoneNumber = N;													//sets phoneNumber as the parameter N
	}
	std::string getPhoneNumber() {											//has no formal parameters
		return phoneNumber;													//returns the current value for phoneNumber
	}
	void setRelationship(std::string R) {									//uses one string as a formal parameter
		if (R == "Family" || R == "Friend" || R == "Business") {			//checks if R is "Family" "Friend" or "Business"
			relationship = R;												//sets relationship as parameter R if true
		}
		else {																//gives error message and sets relationship to default if false
			std::cerr << "Invalid relationship, please enter Family, Friend, or Business." << std::endl;
			relationship = "";
		}
	}
	std::string getRelationship() {											//has no formal parameters
		return relationship;												//returns current value of relationship
	}
	int getBirthMonth() {													//has no formal parameters
		return birthday.getMonth();											//returns the value of the dateType member function getMonth
	}
	void print() {															//has no formal parameters
		std::cerr << getFirstName() << " " << getLastName() << std::endl;	//prints firstName, lastName, endl
		birthday.print();													//calls the dateType member function print
		address.print();													//calls the addressType member function print
		std::cerr << phoneNumber << std::endl << relationship << std::endl;	//prints phoneNumber, endl, relationship, endl

	}
	addressType address;
	dateType birthday;
private:
	string phoneNumber;
	string relationship;
};

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
			cout << "Enter 5 to Add an Entry" << endl;
			cout << "Enter 6 to Remove an Entry" << endl;
			cout << "Enter 7 to Save and Quit" << endl;
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
				manualEntry();
			}
			if (choice == 6) {
				manualRemoveEntry();
			}
			if (choice == 7) {

			}
		}
	}
};

int main() {
	addressBookType AddressBook;
	return 0;
}