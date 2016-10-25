//Classroom Management Program
//Data stored as: FirstName LastName Hometown Homestate Rank PrimaryMajor HoursTaken NumOfMajors GPA
//Lab Task: complete the source code, look for the word TODO and the comment to see what code you need to insert

#include<iostream>
#include<string>
#include<fstream>

const int MAX_STUDENTS = 25;

struct Student
{
	std::string firstName;
	std::string lastName;
	std::string hometown;
	std::string homestate;
	std::string rank;
	std::string primaryMajor;
	int hoursTaken;
	char numMajors;
	float gpa;
};

Student studentData[MAX_STUDENTS];

//Function menuFunction: lists a menu and allows the user to make a selection
//Input: none
//Outputs: error message if input is not valid
//Returns: menu selection as an integer
int menuFunction();

void listData(Student[], int);

//Function printArray: prints the studentData array
//Input: studentData array of type Student, MAX_STUDENTS of type int
//Outputs: data stored in studentData array
//Returns: none
void printArray(Student[], int);

int main()
{
	std::ifstream inputHandler;			//Input file handler
	std::string fileName;				//Store filename from user
	int loopCounter = 0;				//Keep track of which line the error is in
	Student aStudent;					//Variable aStudent of type Student
	int userSelection;					//Stores the selection made by the user

										//Ask the user to enter the filename
	std::cout << "Please enter the student record file name: ";
	std::cin >> fileName;

	//Open the file after converting filename to a c_str
	inputHandler.open(fileName.c_str());

	//If inputHandler is invalid terminate the program
	if (!inputHandler)
	{
		return -1;
	}

	//If inputHandler is valid begin reading data
	else
	{
		inputHandler >> aStudent.firstName >> aStudent.lastName >> aStudent.hometown >> aStudent.homestate >> aStudent.rank >> aStudent.primaryMajor >> aStudent.hoursTaken >> aStudent.numMajors >> aStudent.gpa;

		std::cout << "Filling data array." << std::endl;

		//Loop through remainder of the file
		while (inputHandler)
		{
			if (loopCounter < MAX_STUDENTS)
			{
				studentData[loopCounter] = aStudent;
			}

			//Read the next line of data
			inputHandler >> aStudent.firstName >> aStudent.lastName >> aStudent.hometown >> aStudent.homestate >> aStudent.rank >> aStudent.primaryMajor >> aStudent.hoursTaken >> aStudent.numMajors >> aStudent.gpa;

			//Increment the loop counter
			loopCounter = loopCounter + 1;
		}

		std::cout << "Data array filled." << std::endl;
		inputHandler.close();

		//Calls menuFunction and takes the return and stores it in userSelection
		userSelection = menuFunction();

		//Based on the value of userSelection either prints, lists of quits program
		if (userSelection == 1)
		{
			printArray(studentData, MAX_STUDENTS);
			return 0;
		}
		else if (userSelection == 2)
		{
			listData(studentData, MAX_STUDENTS);
			return 0;
		}
		else
		{
			return 0;
		}
	}
}

//Function: menuFunction
//Input: none
//Outputs: error message if user selection is invalid
//Returns: menu selected as integer
int menuFunction()
{
	int menuSelection;
	std::cout << "Press 1 and then enter to print the data in the array." << std::endl;
	std::cout << "Press 2 and then enter to list student data based on your specification." << std::endl;
	std::cout << "Press 3 to quit." << std::endl;
	std::cin >> menuSelection;
	while (menuSelection < 1 || menuSelection > 3)
	{
		std::cout << "ERROR ACCEPTING INPUT." << std::endl;
		std::cout << "Press 1 and then enter to print the data in the array." << std::endl;
		std::cout << "Press 2 and then enter to list student data based on your specification." << std::endl;
		std::cout << "Press 3 to quit." << std::endl;
		std::cin >> menuSelection;
	}
	return menuSelection;
}

void listData(Student studentData[], int MAX_STUDENTS)
{
	int choice;
	std::string majorIndex;
	std::string stateIndex;
	std::cout << "Would you like to 1) view students of a specific major, or 2) view students from a specific state?: ";
	std::cin >> choice;
	while (choice != 1 && choice != 2)
	{
		if (choice != 1 && choice != 2)
		{
			std::cout << "I'm sorry, but that was not one of the available choices." << std::endl;
			std::cout << "Would you like to 1) view students of a specific major, or 2) view students from a specific state?: ";
			std::cin >> choice;
		}
	}
	switch (choice)
	{
	case 1:
		std::cout << "What major would you like to see?: ";
		std::cin >> majorIndex;
		std::cout << "Students studying " << majorIndex << ":" << std::endl;
		for (int i = 0; i < MAX_STUDENTS; i++)
		{
			if (studentData[i].primaryMajor == majorIndex)
			{
				std::cout << studentData[i].firstName << " ";
				std::cout << studentData[i].lastName << " ";
				std::cout << studentData[i].hometown << " ";
				std::cout << studentData[i].homestate << " ";
				std::cout << studentData[i].rank << " ";
				std::cout << studentData[i].primaryMajor << " ";
				std::cout << studentData[i].hoursTaken << " ";
				std::cout << studentData[i].numMajors << " ";
				std::cout << studentData[i].gpa << std::endl;
			}
		}
	case 2:
		std::cout << "What State would you like to see?: ";
		std::cin >> stateIndex;
		std::cout << "Students from " << majorIndex << ":" << std::endl;
		for (int i = 0; i < MAX_STUDENTS; i++)
		{
			if (studentData[i].homestate == stateIndex)
			{
				std::cout << studentData[i].firstName << " ";
				std::cout << studentData[i].lastName << " ";
				std::cout << studentData[i].hometown << " ";
				std::cout << studentData[i].homestate << " ";
				std::cout << studentData[i].rank << " ";
				std::cout << studentData[i].primaryMajor << " ";
				std::cout << studentData[i].hoursTaken << " ";
				std::cout << studentData[i].numMajors << " ";
				std::cout << studentData[i].gpa << std::endl;
			}
		}
	}
}

//Function: printArray
//Input: studentData and MAX_STUDENTS
//Outputs: data stored in studentData
//Returns: none
void printArray(Student studentData[], int MAX_STUDENTS)
{
	system("clear");
	int idx = 0;
	std::cout << "Data in array contains" << std::endl;
	std::cout << "Index FirstName LastName Hometown Homestate Rank PrimaryMajor HoursTaken NumMajors GPA" << std::endl;
	for (idx = 0; idx < MAX_STUDENTS; idx++)
	{
		std::cout << idx + 1 << ": ";
		std::cout << studentData[idx].firstName << " ";
		std::cout << studentData[idx].lastName << " ";
		std::cout << studentData[idx].hometown << " ";
		std::cout << studentData[idx].homestate << " ";
		std::cout << studentData[idx].rank << " ";
		std::cout << studentData[idx].primaryMajor << " ";
		std::cout << studentData[idx].hoursTaken << " ";
		std::cout << studentData[idx].numMajors << " ";
		std::cout << studentData[idx].gpa << std::endl;
	}
}
