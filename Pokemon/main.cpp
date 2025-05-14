#include<iostream>
using namespace std;

int main()
{

	string PlayerName;

	cout << "Trainer!Before you embark on your journey,the Pok�mon world needs to know who you are" << endl;	//1st message from Professor Oak
	cout <<"Time to step up and tell us your name and remember, a great name is the start of every great adventure!" << endl <<endl;	//2nd message from Professor Oak

	cout << "Enter your name" << endl;	//Enter Player Name Message

	cin >> PlayerName;	//Player Input Name

	cout << endl << "Oh your name is " << PlayerName << ", Welcome to the world of Pokemon!" << endl;	//Finished statment

	cout << endl << "Now " << PlayerName << ", it's time for you to take your first steps to becoming a Pok�mon Trainer." << endl;
	cout << "It's time for you to choose your Starter Pok�mon." << endl;
	cout << "You can choose one of the following Pok�mon:" << endl;
	cout << "1.Oddish\n2. Ghastly\n3. Spheal\n" << endl;
	cout << "Which Pok�mon would you like to choose? Enter the number: ";

	int Starter; //Starter Pokemon Choice 
	cin >> Starter;
	

	if (Starter == 1)
	{
		cout << "You chose Oddish! A verdant pal.\n";
	}
	else if(Starter == 2)
	{
		cout << "You chose Ghastly! A spooky partner.\n";
	}
	else if(Starter == 3)
	{
		cout << "You chose Spheal! A chilly friend!\n";
	}
	else
	{
		cout << "Not a Valid Starter! Game will now close.\n";

		return 0;
	}
};
