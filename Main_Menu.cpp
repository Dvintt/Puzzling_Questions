//DAVID ALDAY
#include "Menu.h"
#include "Puzzling_Questions_Headers.h"

using namespace std;

//varibles
char choice;
char choice_Help;
bool game_Is_On = true;
bool help_Menu = false;



void Show_hFile(ifstream & file, string section)
{
	//Opens the file for use
	file.open("Help.txt");

	string line;
	if (file.is_open())
	{
		//Loops until it finds the line that equals the question
		while (getline(file, line))
		{

			//Prints the question
			if (line.substr(0, 4) == section)
			{
				getline(file, line, '*');

				cout << line << '\n';
			}
		}

		//Close file for more memory
		file.close();

	}

	//Error check
	else
	{
		cout << "File not found" << endl;
	}



}


//Displays the options for the player
void Show_Menu()
{
	ifstream fHelp;
	Show_hFile(fHelp, "SC1");
	//Uses the printQuestion function from game.cpp to print the title.
	cin >> choice;

}


//Displays the answers to the questions
void Show_Help()
{
	string line;
	ifstream fHelp;

	Show_hFile(fHelp, "SC2");
	
}

//Displays the Answers to the question
void Help()
{
	//Will show the answers and will keep running until user enters 'a'
	while (help_Menu != false)
	{
		Show_Help();
		cout << "Type 'a' to go back to the menu " << endl;

		cin >> choice_Help;

		if (choice_Help = 'a')
		{
			clearScreen();
			help_Menu = false;	
			break;
		}
		else
		{
			cout << "Invalid Input, type 'a' to go back to the main menu" << endl;

		}
	
	}
	
}

//Displays Main menu for the game.
void Menu()
{
	while (game_Is_On != false)
	{
		Show_Menu();

		switch (choice)
		{
	    
	    // Starts game
		case 'a':
			clearScreen();
			playGame();			
			break;
		
		// Displays Help
		case 'b':
			clearScreen();
			help_Menu = true;
			Help();

			break;
        
	    //Exits the game
		case 'c':
			clearScreen();
			game_Is_On = false;
			break;

		default:
			cout << "Invalid Input, Please enter a,b,or c" << endl;



		}


	}

}

