#include <iostream>
#include <fstream>
#include <string>

#include "game.h"
#include "question.h"
#include "question_bank.h"

using namespace std;

int main() {

	ifstream inSS;
	string questionsFile;
	cout << "Welcome to Numberical Wagers!\n";
	cout << "Please enter the name of the file containing your questions: ";
	
	cin >> questionsFile;

	inSS.open(questionsFile);

	if (!inSS.is_open()) {
		cout << "Could not open file " << questionsFile << endl;
	}

	while (inSS.good()) {
		int ans;
		string qstn;
		Question question;

		inSS >> ans;
		getline(inSS, qstn);

		cout << "Answer: " << ans << endl;
		cout << "Question: " << qstn << endl;

	}

	inSS.close();
}