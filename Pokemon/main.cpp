#include<iostream>

using namespace std;

enum StarterPokemon 
{
	Oddish,
	Ghastly,
	Spheal,
	InvalidChoice
};

int main()
{
	//Store Variables Trainer Name and Starter Pokemon
	string TrainerName;
	StarterPokemon StarterPkmn;

	// Introduction by the Professor
	cout << "Professor Oak: Hello! I didn't see you there, you must be the new Trainer in town that just came of age.\n";	
	cout << "Professor Oak: My name is Professor Oak. I'm a Pokemon Professor who is a Pokemon Fanatic!\n";
	cout << "Professor Oak: I mean who could say no to being able to examine a Garyados teeth up close?!\n";
	cout << "Professor Oak: ...\n";
	cout << "Professor Oak: Ah hmm...(got a little carried away) Anyway this isn't about me this about you, Trainer!\n";
	cout << "Professor Oak: Before you embark on your journey,the Pokemon world needs to know who you are\n";
	cout << "Professor Oak: Time to step up and tell us your name and remember, a great name is the start of every great adventure!\n\n";

	// Get Trainer's Name
	cout << "Professor Oak: What is your name?\n";	//Enter Trainer Name Message
	cin >> TrainerName;	//Trainer Input Name
	cout << "\nProfessor Oak: Oh your name is " << TrainerName << ", that's a magnificent name!\n";

	// Presenting Starter Choices
	cout << "Professor Oak: Now " << TrainerName << ", it's time for you to take your first steps to becoming a Pokemon Trainer.\n"; //Beginning of Choice Starter Text
	cout << "Professor Oak: It's time for you to choose your Starter Pokemon.\n";
	cout << "Professor Oak: You can choose one of the following Pokemon:\n";
	cout << "\n1. Oddish - The Weed Pokemon. A Sweet Heart!\n";
	cout << "\n2. Ghastly - The Gas Pokemon. A Prankster!\n";
	cout << "\n3. Spheal - The Clap Pokemon. A Playful Spirit!\n";

	cout << "\nProfessor Oak: Which Pokemon would you like to choose?\nEnter the number: ";
	int Pkmn; //Pokémon Switch Index (The Expression)
	cin >> Pkmn;
	
	//Store Starter based on Trainer input
	switch (Pkmn)
	{
		case 1:
		StarterPkmn = Oddish;
		break;
		
		case 2:
		StarterPkmn = Ghastly;
		break;
		
		case 3:
		StarterPkmn = Spheal;
		break;
		
		default:
		StarterPkmn = InvalidChoice;
		break;
	}
	//Response based on Starter Pokemon
	switch(StarterPkmn) //Pokémon struct
	{
		case Oddish:	//Cases equate to choices
		cout << "\nProfessor Oak: You chose a verdant pal!\n";
		break;	//Code will continue to execute until break for Switch Conditions

		case Ghastly:
		cout << "\nProfessor Oak: You chose a spooky partner!\n";
		break;
	
		case Spheal:
		cout << "\nProfessor Oak: You chose a chilly friend!\n";
		break;
		
		default: //if expression != case
		StarterPkmn = Oddish;
		cout << "\nProfessor Oak: Hmm... unfortunately I currently don't have that option, but I do have an Oddish! A budding choice!\n";
		break;
	}

	//Conclusion
	cout << "Professor Oak: " << TrainerName << " I have the feeling you and that " <<(StarterPkmn == Oddish ? "Oddish": StarterPkmn == Ghastly? "Ghastly": "Spheal") << " are going to get along well!\n";
	cout << "Professor Oak: This is the beginning of your journey get ready to embark on an adventure that will give you thrilling\n""moments, I can't wait to see how your story unfolds!\n";

	return 0;
	
	
};
