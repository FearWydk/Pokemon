#include <iostream>
#include <string>

using namespace std;

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
		cout << "A new pokemon has arrived from the default constructor!\n";
	}


	//Parameterized Constructor
	Pokemon(string pName, PokemonType pType, int pHealth) 
	{
		name = pName;
		type = pType;
		health = pHealth;
		cout << "A new pokemon named " << name << " has appeared!\n";
	}

	// Copy constructor 
	Pokemon(const Pokemon& other)
	{
		name = other.name;
		type = other.type;
		health = other.health;
		cout << "A new Pokemon has been duplicated from " << other.name << "!\n";
	}

	~Pokemon()
	{
		cout << name << " has been released.\n";
	}

	void attack()
	{
		cout << name << "Used Confused Ray, It was Super Effective!\n";
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
		cout << "A new trainer named " << name << " has arrived!\n";
	}
	//Parameterized constructor
	Player(string tName,Pokemon selectedPokemon)
	{
		name = tName;
		chosenPokemon = selectedPokemon;
		cout << "Trainer" << name << " has arrived!\n";
	}
	// Copy constructor 
	Player(const Player& pCopy)
	{
		name = pCopy.name;
		chosenPokemon = pCopy.chosenPokemon;

		cout << "A new Trainer has been duplicated from " << pCopy.name << "!\n";
	}
	~Player()
	{

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
		// Introduction by the Professor
		cout << name << ": Hello! I didn't see you there, you must be the new Trainer in town that just came of age.\n";
		cout << name << ": My name is Oak. I'm a Pokemon Professor who is a Pokemon Fanatic!\n";
		cout << name << ": I mean who could say no to being able to examine a Garyados teeth up close?!\n";
		cout << name << ": ...\n";
		cout << name << ": Ah hmm...(got a little carried away) Anyway this isn't about me this about you, Trainer!\n";
		cout << name << ": Before you embark on your journey,the Pokemon world needs to know who you are\n";
		cout << name << ": Time to step up and tell us your name and remember, a great name is the start of every great adventure!\n\n";	
	}

	void OfferPokemonChoices(Player& trainer)
	{
		// Get Trainer's Name
		cout << name << ": What is your name?\n";	//Enter Trainer Name Message
		getline(cin, trainer.name);	//Trainer Input Name
		cout << name << ": Oh your name is " << trainer.name << ", that's a magnificent name!\n";

		// Presenting Starter Choices
		cout << name << ": Now " << trainer.name << ", it's time for you to take your first steps to becoming a Pokemon Trainer.\n"; //Beginning of Choice Starter Text
		cout << name << ": It's time for you to choose your Starter Pokemon.\n";
		cout << name << ": You can choose one of the following Pokemon:\n";
		cout << "\n1. Oddish - The Weed Pokemon. A Sweet Heart!\n";
		cout << "\n2. Ghastly - The Gas Pokemon. A Prankster!\n";
		cout << "\n3. Spheal - The Clap Pokemon. A Playful Spirit!\n\n";

		cout << name << ": Which Pokemon would you like to choose?\nEnter the number: ";
		int Pkmn; //Pokémon Switch Index (The Expression)
		cin >> Pkmn;
		trainer.choosePokemon(Pkmn);

		
	}
};




int main()
{
	//Test Default and Parameterized Constructor
	Pokemon defaultPokemon;
	Pokemon charmander("Charmander", PokemonType::Fire, 100);
	cout << "Pokemon Details:\n";
	cout << "Name: " << defaultPokemon.name << "\nType: " << (int)defaultPokemon.type << "\nHealth: " << defaultPokemon.health << "\n";
	cout << "Name: " << charmander.name << "\nType: " << (int)charmander.type << "\nHealth: " << charmander.health << "\n";

	// Test Copy Constructor
	Pokemon bulbasaur("Bulbasaur", PokemonType::Grass, 100);
	Pokemon bulbasaurC = bulbasaur;
	cout << "Original Pokemon Health: " << bulbasaur.health << "\n";
	cout << "Copied Pokemon Health: " << bulbasaurC.health << "\n";

	// Modify Copy Health
	bulbasaurC.health = 80;
	cout << "After Modification:\n";
	cout << "Original Pokemon Health: " << bulbasaur.health << "\n";
	cout << "Copied Pokemon Health: " << bulbasaurC.health << "\n";

	// Test Destructor
	{ Pokemon garatina("Garatina", PokemonType::Ghost, 120); }


	
	
	//assign Player name
	Player trainer ("Josh", charmander);

	//assign Professor Oaks name
	ProfessorOak professor ("Professor Oak");

	professor.WelcomePlayer(trainer);
	professor.OfferPokemonChoices(trainer);

	

	
	//Conclusion
	cout << professor.name << ": " << trainer.name << " I have the feeling you and that " << trainer.chosenPokemon.name << " are going to get along well!\n";
	cout << "Professor Oak: This is the beginning of your journey get ready to embark on an adventure that will give you thrilling\n""moments, I can't wait to see how your story unfolds!\n";
	
		return 0;
};
