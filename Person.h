// Header-Definition File: Person.h
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Person
{
private:
	//Private Data Members
	int age;
	int id;
	string name;


public:
	//Access and Mutate
	int getAge() const;
	int getId() const;
	string getName() const;
	void setId(int idValue);
	void setName(string personName);
	void setAge(int ageValue);

	//Construct
	Person();
	Person(int idValue, string personName, int ageValue);

	//User method
	string toString();
};

//-----------------------------------------------------------------------------------------------
//Implementation Section: Person.cpp
//-----------------------------------------------------------------------------------------------


//Constructors Method
Person::Person(int idValue = 0, string personName = "n.a.", int ageValue = 0)
{
	setId(idValue);
	setName(personName);
	setAge(ageValue);
}

//Accessors
int Person::getId() const
{
	return id;
}

string Person::getName() const
{
	return name;
}

int Person::getAge() const
{
	return age;
}

//Mutators
void Person::setId(int idValue)
{
	id = abs(idValue);
}

void Person::setName(string personName)
{
    name = personName; //TODO - title case the name
}

void Person::setAge(int ageValue)
{
    age = ageValue; //TODO - validate age
}

//toString Method
string Person::toString()
{
	ostringstream sout;
	sout << fixed << setprecision(2) << showpoint;
	sout << "Person [ID: " << id << ", Name: " << name << ", Age: " << age << "]";
	return sout.str();
}


















