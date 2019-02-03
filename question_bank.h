#ifndef QUESTION_BANK_H
#define QUESTION_BANK_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "question.h"

using namespace std;

class QuestionBank {
public:
	QuestionBank();
	QuestionBank(string fileName) {

		questionsFile.open(fileName);
		if (!questionsFile.is_open()) {
			cout << "Could not open file " << questionsFile << endl;
		}
		else LoadQuestions();
		questionsFile.close();
	};
	Question GetNextQuestion() { return Question(); };

private:
	vector<Question> questions;
	ifstream questionsFile;
	void LoadQuestions() {

		while (questionsFile.good()) {
			string ans;
			string qstn;
			string junk;
			Question question;

			questionsFile >> ans >> junk; //junk is space char between ans and qstn on file line
			getline(questionsFile, qstn);

			questions.push_back(Question(ans, qstn));
		}
	};
};

#endif