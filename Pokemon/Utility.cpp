#include "Utility.hpp"
#include <iostream> 
#include <limits>
using namespace std;

void Utility::clearConsole()
{

#ifdef _WIN32
	system("cls");
#else
	(void)system("clear");
#endif

}
void Utility::waitForResponse()
{
	cin.get();  // Wait for Player Input
}

void Utility::clearInputBuffer() //InputBuffer Temp holds uuser input prior to processing by program
{
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

