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
	}
	Question GetNextQuestion() {
		
		if (questions.size() == 0) return Question();
		
		Question qstn = questions.at(0);
		questions.erase(questions.begin());
		
		return qstn;
	}

private:
	vector<Question> questions;
	ifstream questionsFile;
	void LoadQuestions() {

		while (questionsFile.good()) {
			string ans;
			string qstn;
			Question question;

			questionsFile >> ans;
			getline(questionsFile, qstn);

			questions.emplace_back(ans, qstn);
		}
	}
};

#endif