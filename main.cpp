#include <iostream>
#include <string>


#include "question.h"
#include "question_bank.h"
#include "game.h"

using namespace std;

int main() {

	string fileName;
	cout << "Welcome to Numberical Wagers!\n";
	cout << "Please enter the name of the file containing your questions: ";

	//cin >> fileName;
	fileName = "questions.txt";

	QuestionBank qb(fileName);
	QuestionBank* ptrQB;
	ptrQB = &qb;
	Game game = Game(ptrQB);
	
	int choice = 0;
	int numQ = 0;
	do {
		cout << "Question #" << ++numQ << endl;
		cout << "Current score: " << game.GetCurrentScore() << endl;
		int cs = game.AskQuestion();

		if (cs <= 0) choice = -1;

	} while (choice != -1);
	
	int finalScore = game.GetCurrentScore();
	cout << "#############################\n";
	cout << "Final score: " << finalScore << endl;
	if (finalScore > 0) cout << "You beat the house! Congrats!\n";
	else cout << "Better luck next time!\n";

	return 0;
}