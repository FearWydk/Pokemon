#include <iostream> 
#include <limits.h>
#include <string>

using namespace std;


void clearConsole()
{
	#ifdef _WIN32
		system("cls");
	#else
		(void)system("clear");
	#endif
};
//function for Player response
void waitForResponse()
{
	cin.get(); // Wait for Player Input
};

enum class ChosenPokemon
{
	InvalidChoice,
	Oddish,
	Ghastly,
	Spheal,
	Pikachu
	
};

enum class PokemonType
{
	InvalidChoice,
	Electric,
	Fire,
	Ghost,
	Grass,
	Ground,
	Ice,
	Steel,
	Water
	
};

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
		waitForResponse();
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
		waitForResponse();
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
		clearConsole();

		// Introduction by the Professor
		cout << name << ": Hello! I didn't see you there, you must be the new Trainer in town that just came of age.\n";
		cout << name << ": My name is Oak. I'm a Pokemon Professor who is a Pokemon Fanatic!\n";
		waitForResponse();

		cout << name << ": I mean who could say no to being able to examine a Garyados teeth up close?!\n";
		waitForResponse();

		cout << name << ": ...\n";
		waitForResponse();

		cout << name << ": Ah hmm...(got a little carried away)... Anyway this isn't about me, this is about you, Trainer!\n";
		waitForResponse();

		cout << name << ": Before you embark on your journey,the Pokemon world needs to know who you are.\n";
		waitForResponse();

		cout << name << ": Time to step up and tell us your name and remember, a great name is the start of every great adventure!\n\n";
		waitForResponse();
	}

	void OfferPokemonChoices(Player& trainer)
	{
		clearConsole();
		// Get Trainer's Name
		cout << name << ": What is your name?\n";	//Enter Trainer Name Message
		getline(cin, trainer.name);	//Trainer Input Name
		cout << name << ": Oh your name is " << trainer.name << ", that's a magnificent name!\n";
		waitForResponse();

		// Presenting Starter Choices
		cout << name << ": Now " << trainer.name << ", it's time for you to take your first steps to becoming a Pokemon Trainer.\n"; //Beginning of Choice Starter Text
		waitForResponse();
		cout << name << ": It's time for you to choose your Starter Pokemon.\n";
		waitForResponse();
		cout << name << ": You can choose one of the following Pokemon:\n";
		cout << "\n1. Oddish - The Weed Pokemon. A Sweet Heart!\n";
		cout << "\n2. Ghastly - The Gas Pokemon. A Prankster!\n";
		cout << "\n3. Spheal - The Clap Pokemon. A Playful Spirit!\n\n";
		cout << name << ": Which Pokemon would you like to choose?\nEnter the number: ";
		int Pkmn; //Pokémon Switch Index (The Expression)
		cin >> Pkmn;
		trainer.choosePokemon(Pkmn);
		waitForResponse();

		
	}

	void explainMainQuest(Player& trainer)
	{
		clearConsole();

		cout << name << ": Alright " << trainer.name << ", I am about to explain to you about your upcoming grand adventure.\n";
		waitForResponse();

		cout << name << ": You see, becoming a Pokemon Master is no easy feat. It takes courage, wisdom, and a bit of luck.\n";
		waitForResponse();

		cout << name << ": Your mission, should you choose to accept it (and trust me, you really don't have a choice)\n"
			 << "is to collect all the Pokemon Badges and conquer the Pokemon League.\n";
		waitForResponse();

		cout << trainer.name << ":  Wait... that sounds a lot like every other Pokemon game out there.\n";
		waitForResponse();

		cout << name << ": Shhh! Don't break the fourth wall" << trainer.name << "!This is serious business.\n";
		waitForResponse();

		cout << name << ": To achieve this, you'll need to battle wild Pokemon, challenge gym leaders, and of course, keep your Pokemon healthy at the PokeCenter.\n";
		waitForResponse();

		cout << name << ": Along the way, you'll capture new Pokemon to strengthen your team. Just remember—there's a limit to how many Pokemon you can carry, so choose wisely!.\n";
		waitForResponse();

		cout << trainer.name << ": Sounds like a walk in the park... right?\n";
		waitForResponse();

		cout << name << ": Hah! That’s what they all say! But beware, young Trainer, the path to victory is fraught with challenges.\n"
			 << "And if you lose a battle... well, let’s just say you'll be starting from square one.\n";
		waitForResponse();

		cout << name << ": So, what do you say? Are you ready to become the next Pokemon Champion?\n";
		waitForResponse();

		cout << trainer.name << ": Ready as I'll ever be, Professor!\n";
		waitForResponse();

		cout << name << ": That's the spirit! Now, your journey begins.\n";
		waitForResponse();

		cout << name << ": But first... let's just pretend I didn't forget to set up the actual game loop... Ahem, onwards!\n";
		waitForResponse();

	}

	void conclusionMessage(Player& trainer)
	{
		clearConsole();
		//Conclusion
		cout << name << ": " << trainer.name << " I have the feeling you and that " << trainer.chosenPokemon.name << " are going to get along well!\n";
		waitForResponse();
		cout << name << ": This is the beginning of your journey get ready to embark on an adventure that will give you thrilling\n""moments, I can't wait to see how your story unfolds!\n";
		waitForResponse();
	}
};




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

	//Game Loop Placeholder
	cout << "\n[Placeholder for the Game Loop]\n";
	
	
	
		return 0;
};
