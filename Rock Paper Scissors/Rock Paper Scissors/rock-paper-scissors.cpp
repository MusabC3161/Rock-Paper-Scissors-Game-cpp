#include <iostream>
#include <cstdlib>
#include<windows.h>

using namespace std;

//Variables
int userScore = 0;
int computerScore = 0;

char user, computer;
int randNum;
int randomizer;
char restart = 'y';

// Update the Score
void board() {
	cout << "The Rock Paper Scissors Game\n\n" << endl;

	cout << "Player Score: " << userScore << endl;
	cout << "Computer Score: " << computerScore << endl;
}

//Select a random number for Computer and take input from user
void engine() {
	srand(randomizer);
	randomizer += rand();
	randNum = rand() % 3;

	if (randNum == 0) {
		computer = 'R';
	}
	else if (randNum == 1) {
		computer = 'P';
	}
	else {
		computer = 'S';
	}

	cout << "Select Rock, Paper or Scissors(R/P/S): ";
	cin >> user;
}

// Determine who had won the round. Add the score
int main() {
	do {
		system("cls");
		board();
		engine();
		if (user == 'R' && computer == 'S') {
			userScore++;
			cout << "Computer Selected " << computer << "." << endl;
			cout << "Player Wins!" << endl;
			Sleep(1500);
		}
		else if (user == 'P' && computer == 'R') {
			userScore++;
			cout << "Computer Selected " << computer << "." << endl;
			cout << "Player Wins!" << endl;
			Sleep(1500);
		}
		else if (user == 'S' && computer == 'P') {
			userScore++;
			cout << "Computer Selected " << computer << "." << endl;
			cout << "Player Wins!" << endl;
			Sleep(1500);
		}
		else if (user == computer) {
			cout << "Computer Selected " << computer << "." << endl;
			cout << "Draw!" << endl;
			Sleep(1500);
		}
		else {
			computerScore++;
			cout << "Computer Selected " << computer << "." << endl;
			cout << "Computer Wins!" << endl;
			Sleep(1500);
		}
		//if one of the players have reached to 5 points, game ends. And asks if you want to play the game again.
		if (userScore == 5 || computerScore == 5) {
			system("cls");
			board();
			cout << "Game Over!" << endl;
			cout << "Do you want to restart the game?(y/n): ";
			cin >> restart;
			if (restart == 'y') {
				userScore = 0;
				computerScore = 0;
			}
		}

		if (restart == 'n') {
			return 0;
		}

	} while (restart == 'y');

	return 0;
}