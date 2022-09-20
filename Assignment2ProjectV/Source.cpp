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


//define PRE_RELEASE. If not in pre-release version, this can be commented out. 
//#define PRE_RELEASE

//Declare the STUDENT_DATA struct
struct STUDENT_DATA
{
	string firstName;
	string lastName;
	
	//If in pre-release version, this struct has an email string
	#ifdef PRE_RELEASE
		string email;
	#endif
	

};

int main()
{

	//statement for which version this code is running in
	#ifdef PRE_RELEASE
		cout << "This code is running in pre-release" << endl;
	#else
		cout << "This code is running in regular release version" << endl;
	#endif

	//counter variables
	int i;
	int  arrSize;

	//arraysize depends on what version the code is in

	#ifdef PRE_RELEASE
		 arrSize = 3;
	#else
		 arrSize = 2;
	#endif
		string fromFile;
	
	//size of the piece array depends on version
	//version with email has 3 pieces, version without has 2

	#ifdef PRE_RELEASE
		string pieceArray[3];
	#else
		string pieceArray[2];
	#endif

	//create instance of student
	
	STUDENT_DATA student;

	//create vector

	vector <STUDENT_DATA> myStudents;
	fstream studFile;

	//choose which file to read from
	#ifdef PRE_RELEASE
		studFile.open("StudentData_Emails.txt");
	#else
		studFile.open("StudentData.txt");
	#endif

	//read from file

	while (!studFile.eof())
	{
		getline(studFile, fromFile);

		//allows for manipulation of string to separate based on the commas
		stringstream pieces(fromFile);

		//separate substring based on commas
		for (i = 0; i < arrSize; i++)
		{
			string substring;
			getline(pieces, substring, ',');
			pieceArray[i] = substring;
		}

		//put student info into struct
		student.lastName = pieceArray[0];

		student.firstName = pieceArray[1];

		//in pre-release, add email to struct
		#ifdef PRE_RELEASE
			student.email = pieceArray[2];
		#endif

		//push student info into array
		myStudents.push_back(student);
	}


	#ifdef _DEBUG
		#ifdef PRE_RELEASE
			for (i = 0; i < myStudents.size(); i++)
			{
				cout << myStudents[i].firstName << " " << myStudents[i].lastName << " " << myStudents[i].email << endl;
			}
		#else
			for (i = 0; i < myStudents.size(); i++)
			{
				cout << myStudents[i].firstName  << " " << myStudents[i].lastName << endl;
			}
		#endif
	#endif

	return 1;
}