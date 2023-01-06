#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inputFile;
	int	   Roll;
	string Name,Front,End;

    // 1. Open file

    ofstream outfile;
    outfile.open("LineUp.txt");
	// Ask user to enter the number of students in the class.
	cout << "\nThis program reports which student would be at the front of\n"
		 << "the line and which one would be at the end of the line.\n\n"
		 << "How many students are in the class? ";
    cin >> Roll;
//	cin.ignore();
	outfile <<cout << "There are " << Roll << "students in the class" << endl;
	
	while (Roll < 1 || Roll > 25)
	{
		cout << "\nError!\nThe number of students in the class must\n"
			 << "be greater than 1 or less than 25.\n\n"
			 << "How many students are in the class? ";
		cin  >> Roll;
	}

	cout << "Enter the first name of a student: ";
	cin  >> Name;
//  cin.ignore();
	
	Front = End = Name;

	for (int Count = 1; Count < Roll; Count++)
	{
		cout << "Enter the first name of the next student: ";
		cin  >> Name;

		if (Name > End)
			End = Name;
		if (Name < Front)
			Front = Name;

	}
 	cout << endl << Front << " is at the front of the line and\n"
		 << End << " is at the end of the line.\n";
 	
	outfile << cout << endl << Front << " is at the front of the line and\n"
		 << End << " is at the end of the line.\n";

	return 0;
}
