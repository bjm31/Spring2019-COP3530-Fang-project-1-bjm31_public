#include <iostream>
#include <string>
#include <fstream>

#include "question.h"
#include "question_bank.h"
#include "game.h"

using namespace std;

int main() {

	string fileName;
	int choice = 0;
	int menuChoice = 0;
	cout << "Welcome to Numberical Wagers!\n";
	do {
		cout << "Please enter the name of the file containing your questions: ";

		cin >> fileName;

		ifstream inSS;
		inSS.open(fileName);
		string check = "";

		if (!inSS.is_open()) {
			cout << "Could not open file " << fileName << endl;
			check = "bad";
		}

		inSS.close();

		QuestionBank qb(fileName);
		QuestionBank* ptrQB;
		ptrQB = &qb;
		Game game = Game(ptrQB);

		int numQ = 0;
		while (check == "" && choice != -1) {
			cout << "Question #" << ++numQ << endl;
			cout << "Current score: " << game.GetCurrentScore() << endl;
			int cs = game.AskQuestion();

			if (cs <= 0) choice = -1;
		}
		if (check == "") {
			int finalScore = game.GetCurrentScore();
			cout << "#############################\n";
			cout << "Final score: " << finalScore << endl;
			if (finalScore > 0) cout << "You beat the house! Congrats!\n";
			else cout << "Better luck next time!\n";
		}
		
		cout << "Would you like to:\n 1. Play a new game\n 2. Quit the game\n";
		cout << "Selection: ";
		cin >> menuChoice;
	} while (menuChoice == 1);
	return 0;
}