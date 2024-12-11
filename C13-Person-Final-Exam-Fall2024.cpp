// C13-Person-Final-Exam-Fall2024.cpp 

#include "Person.h"
using namespace std;

//Protoypes
void showDatabase(vector<Person> db);
void printYoungPeople(vector<Person>& db);


int main()
{
    //Vector db represents the database
	vector<Person> db;

    //Variables
	string line, idLine, name, ageLine, ex;
	int    id, age;

	//Open file
	ifstream inFile("c:/temp/Simpsons/springfieldPeople.txt");
	if (!inFile)
	{
		cout << "Error: No file found!" << endl;
		exit(1);
	}

	
    //Read each part of a record
    while (getline(inFile, idLine, ',') &&
           getline(inFile, name, ',') &&
           getline(inFile, ageLine) )
    {
        id  = stoi(idLine);
        age = stoi(ageLine);
        db.push_back(Person(id, name, age));
    }

    inFile.close();

    //Output
    showDatabase(db);
    printYoungPeople(db);
    return 0;
}

//Functions
void printYoungPeople(vector<Person>& db)
{
    //Check - Empty database?
	if (db.empty())
	{
		cout << "No data - Springfield is on Vacation!";
		exit(1);
	}

	//Calculate Average Age
	double totalAge = 0;
	double averageAge = 0;

	for (int i = 0; i < db.size(); i++)
	{
		totalAge += db[i].getAge();
	}
	averageAge = totalAge / db.size();

	//Report average age
	cout << "\nPersons younger than the average age (" << averageAge << "):" << endl;
	
	//Young people printout
	for (Person p : db)
	{
		if (p.getAge() < averageAge)
		{
			cout << p.toString() << endl;
		}
	}
}

void showDatabase(vector<Person> db)
{
	//Check if database is empty
	if (db.empty())
	{
		cout << "No data - Springfield is on Vacation!";
		exit(1);
	}

    //Show each object in the database
	cout << "\nDatabase db - All Persons:" << endl;
	for (Person p : db)
	{
		cout << p.toString() << endl;
	}
	cout << endl;
}
