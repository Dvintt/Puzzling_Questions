//DAVID ALDAY
#include "Puzzling_Questions_Headers.h"


using namespace std;

//Question and answers
string Questions[15] = { "Q01", "Q02", "Q03", "Q04", "Q05", "Q06", "Q07", "Q08", "Q09", "Q10", "Q11", "Q12", "Q13", "Q14", "Q15" };
string Answers[15] = {"c", "d", "c", "b", "r", "a", "d", "a", "c" , "infront of you", "b" , "a" , "d" , "14" , "to create is to inspire"};



//Returns a true if user input matches the answer or false if it does not.
bool Correct(string uInput, string Answer)
{
	//varible
	bool verdict;

	//Returns true if user input matches the answer and returns false if it does not.
	if (uInput == Answer)
	{
		verdict = true;
	}
	else
	{
		verdict = false;
	}

	return verdict;
   

}

//Checks to see if player runs out of lives and returns true if lives =0.
bool gameIsOver(Player User)
{
	bool verdict;
	if (User.get_Lives() == 0)
	{
		verdict = true;
	}
	else
	{
		verdict = false;
	}

	return verdict;

}


//Prints the question from the txt document
void printQuestion(ifstream & file,string question)
{
	//Opens the file for use
	file.open("Questions.txt");

	string line;
	if (file.is_open())
	{
		//Loops until it finds the line that equals the question
		while (getline(file, line))
		{

			//Prints the question
			 if (line.substr(0, 3) == question)
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

//Will print Win if player wins the game
void gameWin()
{
	ifstream qFile;
	printQuestion(qFile, "WIN");
}

//Will print Lose if player loses the game
void gameLose()
{
	ifstream qFile;
	printQuestion(qFile, "LOS");

}

void clearScreen()
{
	cout << string(100, '\n');

}

//Runs the game
void playGame()
{
	//Varibles
	Player User;
	string uInput;
	bool next;
	bool gameOn = true;
	bool lose = false;
	bool verdict = false;
	ifstream qFile;

	//Loops through all the questions
	for (int i = 0; i < 15; i++)
	{
		next = false;
		clearScreen();

		//Question will keep repeating until user gets it right or runs out of lives
		while (next != true)
		{
			cout << "Lives: " << User.get_Lives() << endl;

			printQuestion(qFile, Questions[i]);
			
			
      		getline(cin,uInput);
			
			//Checks to see if user input is correct, if not player loses a life
			if (Correct(uInput, Answers[i]))
			{

				if (i == 14)
				{
					verdict = true;
				}

				next = true;
			}
			else
			{
				cout << "WRONG" << endl;
				User.lose_Life();
				clearScreen();
			}
				
			//Checks to see if player has 0 lives.
			if (gameIsOver(User))
			{
				break;
			}

		}

		//Checks to see if player has 0 lives.
		if (gameIsOver(User))
		{
			break;
		}
	}

	//Checks to see if player Won or lost the game
	if (verdict == true)
	{
		gameWin();
		cin.get();	
	}

	else
	{
		gameLose();
		cin.get();		
	}

}



void tprintQuestion(ifstream & file, string question)
{
	//Opens the file for use
	file.open("Questions.txt");

	string line;
	if (file.is_open())
	{
		//Loops until it finds the line that equals the question
		while (getline(file, line))
		{

			//Prints the question
			if (line.substr(0, 4) == question)
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





void Test()
{
	
	Player User;
	
	ifstream qFile("Questions.txt");

	for (int i = 0; i < 15; i++)
	{

		cout << "Lives: " << User.get_Lives() << endl;
			
			tprintQuestion(qFile, Questions[i]);
			cout << endl;

		
	}
	

}

