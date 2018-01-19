//DAVID ALDAY
//Header file for Game 
#ifndef PUZZLING_QUESTIONS_HEADERS_H
#define PUZZLING_QUESTIONS_HEADERS_H

//Libraries called
#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <cstdlib>
#include "PlayerHeader.h"

//Prototype Functions
using namespace std;
bool Correct(string uInput, string Answer);
void Correct();
bool gameIsOver(Player User);
void printQuestion(ifstream & file, string question);
void gameWin();
void gameLose();
void clearScreen();
void playGame();
void tprintQuestion(ifstream & file, string question);
void Test();



#endif