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
	Electric,
	Fire,
	Ghost,
	Grass,
	Ground,
	Ice,
	Steel,
	Water,
	InvalidChoice
};

class Pokemon
{
public:
	string name;
	PokemonType type;
	int health;

	//Created 2 constructors
	Pokemon()
	{
	}



	Pokemon(string pName, PokemonType pType, int pHealth) 
	{
		name = pName;
		type = pType;
		health = pHealth;
	}

	void attack()
	{
		cout << name << "Used Confused Ray, It was Super Effective!\n";
	}

};

class Player
{
public:
	string name;
	Pokemon chosenPokemon;

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
	Player trainer;
	ProfessorOak professor;
	Pokemon placeholderPokemon;

	//assign placeholder Pokemon values
	placeholderPokemon.name = "Bulbasaur";
	placeholderPokemon.type = PokemonType::Grass;
	placeholderPokemon.health = 40;

	//assign Player name
	trainer.name = "Trainer";

	//assign Professor Oaks name
	professor.name = "Professor Oak";

	professor.WelcomePlayer(trainer);
	professor.OfferPokemonChoices(trainer);
	
	//Conclusion
	cout << professor.name << ": " << trainer.name << " I have the feeling you and that " << trainer.chosenPokemon.name << " are going to get along well!\n";
	cout << "Professor Oak: This is the beginning of your journey get ready to embark on an adventure that will give you thrilling\n""moments, I can't wait to see how your story unfolds!\n";
	
		return 0;
};
