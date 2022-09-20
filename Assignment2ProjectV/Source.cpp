/*
4 versions of code
only pre-release should be commented/uncommented
IDE identifies if it is in debug mode

debug pre-release
debug pre-release commented out
release pre-release
release release

*/



#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

//Declare the STUDENT_DATA struct
struct STUDENT_DATA
{
	string firstName;
	string lastName;
	
	//
	//#ifdef _DEBUG
		//string email;
	//#endif
	//code for ifdefine based on version
	//string email

};

int main()
{
	//counter variables
	int i;
	
	//ifdef under this line
	int arrSize = 2;

	string fromFile;
	
	//ifdef under this line
	string pieceArray[2];

	STUDENT_DATA student;
	//create vector
	vector <STUDENT_DATA> myStudents;
	vector <string> commaSep;

	fstream studFile;
	studFile.open("StudentData.txt");

	while (!studFile.eof())
	{
		getline(studFile, fromFile);

		stringstream pieces(fromFile);

		//ifdef for this loop
		for (i = 0; i < arrSize; i++)
		{
			string substr;
			getline(pieces, substr, ',');
			pieceArray[i] = substr;
		}

		//ifdef here
		student.lastName = pieceArray[0];

		student.firstName = pieceArray[1];

		//Expression for when emails are here
	

		myStudents.push_back(student);
	}


	//future output statement

	/*
	for (i = 0; i < myStudents.size(); i++)
	{
		cout << myStudents[i].firstName  << " " << myStudents[i].lastName << endl;
	}
	*/

	/*
	TODO Here, psuedocode

	while !=eof
	{
	getline
	manipulate line based on where commas are
	STUDENT_DATA.firstName = blah
	STUDENT_DATA.lastName = blah
	ifdefine based on version
	STUDENT_DATA.studEmail = blah

	myStudents.pushback(STUDENT_DATA)
	}

	Output statements based on version
	use myStudents.size or .length for forloop

	*/

	return 1;
}