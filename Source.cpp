#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool lookupEmployee(int idNumber);

int main()
{
	int idNumber;
	cout << "Please enter the ID Number that you want to find: ";
	cin >> idNumber;
	if (lookupEmployee(idNumber) == false)
	{
		cout << "Employee can not be found!";
	}
	return 0;
}

bool lookupEmployee(int idNumber)
{
	ifstream inputStream;
	inputStream.open("employees.txt");
	int count = 0;
	while (!inputStream.eof())
	{
		int ID_File;
		string firstName, lastName;
		inputStream >> ID_File >> firstName >> lastName;
		if (ID_File == idNumber)
		{
			cout << "The name with your ID entered " << idNumber << " is: " << firstName << " " << lastName;
			return true;
		}
	}
	inputStream.close();
	return false;
}