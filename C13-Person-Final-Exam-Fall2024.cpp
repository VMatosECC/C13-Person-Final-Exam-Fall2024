// C13-Person-Final-Exam-Fall2024.cpp 

#include "Person.h"
using namespace std;

//Protoypes ------------------------------------------------------------------------------
void showDatabase(vector<Person> db);
void printYoungPeople(vector<Person>& db);
void findOldest(vector<Person>& db, int& oldestId, int& idLowerBound, int& idUpperBound);
void findElderly(vector<Person>& db, int& oldestAge, int& oldestCount);


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

    //Query 1 - Young people (age below average)
    showDatabase(db);
    printYoungPeople(db);

    //Query 2 - Oldest among a range of ids
    int oldestId = 0, idLowerBound=100, idUpperBound=175;
    findOldest(db, oldestId, idLowerBound, idUpperBound);
    cout << "\nQuery 2 \n";
	if (oldestId == -1)
	{
        cout << "No person found in the range [" << idLowerBound << ", " << idUpperBound << "]" << endl;
	}
    else {

        cout << "Oldest person in the range [" << idLowerBound << ", "
            << idUpperBound
            << "] has id: " << oldestId
            << endl;
        //Display Oldest Person Object
        for (Person p : db)
        {
            if (p.getId() == oldestId)
            {
                cout << p.toString() << endl;
                break;
            }
        }
    }
    

    //Query 3 - Count of oldest people
    int oldestAge = 0, oldestCount = 0;
    findElderly(db, oldestAge, oldestCount);
    cout << "\nQuery 3\nOldest age is: " << oldestAge << " years" << endl;
    cout << "Number of oldest person(s): " << oldestCount << endl;
    
}

//User-defined Functions -------------------------------------------------------------------
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
	cout << "\nQuery 1\nPersons younger than the average age (" << averageAge << "):" << endl;
	
	//Young people printout
	for (Person p : db)
	{
		if (p.getAge() < averageAge)
		{
			cout << p.toString() << endl;
		}
	}
}
//--------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------
void findOldest(vector<Person>& db, int& oldestId, int& idLowerBound, int& idUpperBound)
{

    //Find the oldest person in the range [idLowerBound, idUpperBound]
    int oldestAge = -1;
    int countOlder = 0;

    for (Person p : db)
    {
        if (p.getId() >= idLowerBound && p.getId() <= idUpperBound)
        {
            if (p.getAge() > oldestAge)
            {
                oldestAge = p.getAge();
                oldestId  = p.getId();
            }
        }
    }

}

//--------------------------------------------------------------------------------------------
void findElderly(vector<Person>& db, int& oldestAge, int& oldestCount)
{

    //Find the count of oldest person(s)
    oldestAge  = db[0].getAge();
    int countOlder = 1;

    for (Person p : db)
    {

            if (p.getAge() > oldestAge)
            {
                oldestAge = p.getAge();
                oldestCount = 1;
            }
            else if (p.getAge() == oldestAge)
            {
                oldestCount++;
            }
      
    }

}