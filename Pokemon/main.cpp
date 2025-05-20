#include <iostream> 
#include <limits>
#include <string>

#include "PokemonType.hpp"
#include "PokemonChoice.hpp"
#include "Utility.hpp"

using namespace std;






class Pokemon
{
public:
	string name;
	PokemonType type;
	int health;

	//Default Constructor
	Pokemon()
	{
		name = "Pikachu";
		type = PokemonType::Electric;
		health = 10;
	}


	//Parameterized Constructor
	Pokemon(string pName, PokemonType pType, int pHealth) 
	{
		name = pName;
		type = pType;
		health = pHealth;
	}

	// Copy constructor 
	Pokemon(const Pokemon& other)
	{
		name = other.name;
		type = other.type;
		health = other.health;
	}

	~Pokemon()
	{
	
	}

	void attack()
	{
		cout << name << "Used Confused Ray, It was Super Effective!\n";
		Utility::waitForResponse();

	}

};

class Player
{
public:
	//public variables
	string name;
	Pokemon chosenPokemon;

	//Constructor & Deconstructor
	//Default
	Player()
	{
		name = "Trainer";
		chosenPokemon = Pokemon();
	}
	//Parameterized constructor
	Player(string tName,Pokemon selectedPokemon)
	{
		name = tName;
		chosenPokemon = selectedPokemon;
	}
	// Copy constructor 
	Player(const Player& pCopy)
	{
		name = pCopy.name;
		chosenPokemon = pCopy.chosenPokemon;
	}
	

	void choosePokemon(int Chosen)
	{
		//Store Starter based on Trainer input
		switch ((ChosenPokemon)Chosen)
		{
		case ChosenPokemon::Oddish:
			chosenPokemon = Pokemon("Oddish", PokemonType::Grass, 100);
			break;

		case ChosenPokemon::Ghastly:
			chosenPokemon = Pokemon("Ghastly", PokemonType::Ghost, 100);
			break;

		case ChosenPokemon::Spheal:
			chosenPokemon = Pokemon("Spheal", PokemonType::Ice, 100);
			break;

		default:
			chosenPokemon = Pokemon("Pikachu", PokemonType::Electric, 100);
			break;
		}

		cout << "Trainer " << name << " chose " << chosenPokemon.name << "!\n";
		Utility::waitForResponse();
	}
};

class ProfessorOak
{
public:
	string name;

	//Parameterized cosntructor.
	ProfessorOak(string oName)
	{
		name = oName;
	}


	void WelcomePlayer(Player& trainer)
	{
		Utility::clearConsole();

		// Introduction by the Professor
		cout << name << ": Hello! I didn't see you there, you must be the new Trainer in town that just came of age.\n";
		cout << name << ": My name is Oak. I'm a Pokemon Professor who is a Pokemon Fanatic!\n";
		Utility::waitForResponse();

		cout << name << ": I mean who could say no to being able to examine a Garyados teeth up close?!\n";
		Utility::waitForResponse();

		cout << name << ": ...\n";
		Utility::waitForResponse();

		cout << name << ": Ah hmm...(got a little carried away)... Anyway this isn't about me, this is about you, Trainer!\n";
		Utility::waitForResponse();

		cout << name << ": Before you embark on your journey,the Pokemon world needs to know who you are.\n";
		Utility::waitForResponse();

		cout << name << ": Time to step up and tell us your name and remember, a great name is the start of every great adventure!\n\n";
		Utility::waitForResponse();
	}

	void OfferPokemonChoices(Player& trainer)
	{
		Utility::clearConsole();
		// Get Trainer's Name
		cout << name << ": What is your name?\n";	//Enter Trainer Name Message
		getline(cin, trainer.name);	//Trainer Input Name
		cout << name << ": Oh your name is " << trainer.name << ", that's a magnificent name!\n";
		Utility::waitForResponse();

		// Presenting Starter Choices
		cout << name << ": Now " << trainer.name << ", it's time for you to take your first steps to becoming a Pokemon Trainer.\n"; //Beginning of Choice Starter Text
		Utility::waitForResponse();
		cout << name << ": It's time for you to choose your Starter Pokemon.\n";
		Utility::waitForResponse();
		cout << name << ": You can choose one of the following Pokemon:\n";
		cout << "\n1. Oddish - The Weed Pokemon. A Sweet Heart!\n";
		cout << "\n2. Ghastly - The Gas Pokemon. A Prankster!\n";
		cout << "\n3. Spheal - The Clap Pokemon. A Playful Spirit!\n\n";
		cout << name << ": Which Pokemon would you like to choose?\nEnter the number: ";
		int Pkmn; //Pokémon Switch Index (The Expression)
		cin >> Pkmn;
		trainer.choosePokemon(Pkmn);
		Utility::waitForResponse();

		
	}

	void explainMainQuest(Player& trainer)
	{
		Utility::clearConsole();

		cout << name << ": Alright " << trainer.name << ", I am about to explain to you about your upcoming grand adventure.\n";
		Utility::waitForResponse();

		cout << name << ": You see, becoming a Pokemon Master is no easy feat. It takes courage, wisdom, and a bit of luck.\n";
		Utility::waitForResponse();

		cout << name << ": Your mission, should you choose to accept it (and trust me, you really don't have a choice)\n"
			 << "is to collect all the Pokemon Badges and conquer the Pokemon League.\n";
		Utility::waitForResponse();

		cout << trainer.name << ":  Wait... that sounds a lot like every other Pokemon game out there.\n";
		Utility::waitForResponse();

		cout << name << ": Shhh! Don't break the fourth wall" << trainer.name << "!This is serious business.\n";
		Utility::waitForResponse();

		cout << name << ": To achieve this, you'll need to battle wild Pokemon, challenge gym leaders, and of course, keep your Pokemon healthy at the PokeCenter.\n";
		Utility::waitForResponse();

		cout << name << ": Along the way, you'll capture new Pokemon to strengthen your team. Just remember—there's a limit to how many Pokemon you can carry, so choose wisely!.\n";
		Utility::waitForResponse();

		cout << trainer.name << ": Sounds like a walk in the park... right?\n";
		Utility::waitForResponse();

		cout << name << ": Hah! That’s what they all say! But beware, young Trainer, the path to victory is fraught with challenges.\n"
			 << "And if you lose a battle... well, let’s just say you'll be starting from square one.\n";
		Utility::waitForResponse();

		cout << name << ": So, what do you say? Are you ready to become the next Pokemon Champion?\n";
		Utility::waitForResponse();

		cout << trainer.name << ": Ready as I'll ever be, Professor!\n";
		Utility::waitForResponse();

		cout << name << ": That's the spirit! Now, your journey begins.\n";
		Utility::waitForResponse();

		cout << name << ": But first... let's just pretend I didn't forget to set up the actual game loop... Ahem, onwards!\n";
		Utility::waitForResponse();

	}

	void conclusionMessage(Player& trainer)
	{
		Utility::clearConsole();
		//Conclusion
		cout << name << ": " << trainer.name << " I have the feeling you and that " << trainer.chosenPokemon.name << " are going to get along well!\n";
		Utility::waitForResponse();
		cout << name << ": This is the beginning of your journey get ready to embark on an adventure that will give you thrilling\n""moments, I can't wait to see how your story unfolds!\n";
		Utility::waitForResponse();
	}
};


void gameLoop(Player& trainer)
{
	int pChoice;
	bool gameRunning = true;
	while (gameRunning)
	{
		Utility::clearConsole();

		cout << "What would you like to do next" << trainer.name << " ?\n";
		cout << "1. Walk through the tall grass.\n";
		cout << "2. Visit the PokeCenter.\n";
		cout << "3. Challenge a Gym Leader.\n";
		cout << "4. Visit the PokeMart.\n";
		cout << "5. Quit.\n";
		cin >> pChoice;
		
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (pChoice)
		{
		case 1:
			cout << "You look around... but all the wild Pokemon are on vacation. Maybe try again later?\n";;
			break;
		case 2:
			cout << "You head to the PokeCenter, but Nurse Joy is out on a coffee break." 
				 << "Guess your Pokemon will have to tough it out for now!\n";
			break;
		case 3:
			cout << "You march up to the Gym, but it's closed for renovations. Seems like even Gym Leaders need a break!\\n";
			break;
		case 4:
			cout << "You push open the PokeMart doors… only to find the clerk snoozing atop the counter!\n"
				<< "\"Zzz… Welcome to PokeMart… zzz…\"\n"
				<< "Guess you'll have to shop while he's catching Z's!\n";
			break;
		case 5:
			cout << "You decide to quit, but Professor Oak's voice echoes: 'There's no quitting in Pokemon training!'\\n";
			cout << "Are you sure you want to quit? (y/n): ";
			char quitChoice;
			cin >> quitChoice;
			if (quitChoice == 'y' || quitChoice == 'Y') 
			{
				gameRunning = false;
			};
			break;
		default:
			cout << "That's not a valid choice. Try again!\n";
			break;
		}
		Utility::waitForResponse();
	}
	
	cout << "Until next time" << trainer.name << "your Pokemon journey awaits for your return.\n";
}

int main()
{
	//Initialize Player & Pokemon objects for the game
	Pokemon charmander("Charmander", PokemonType::Fire, 100);

	//Continue to initializing Player characters
	Player trainer ("Brock", charmander);
	ProfessorOak professor ("Professor Oak");

	//Greet player and offer Pokemon Choices[sets player name and starter pokemon]
	professor.WelcomePlayer(trainer);
	professor.OfferPokemonChoices(trainer);

	// Main Quest Explaination
	professor.explainMainQuest(trainer);

	//Game Loop
	gameLoop(trainer);

	
	
		return 0;
		
		};
