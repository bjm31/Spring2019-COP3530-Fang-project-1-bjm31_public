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
	QuestionBank() {};
	QuestionBank(string fileName);
	Question GetNextQuestion();

private:
	vector<Question> questions;
	ifstream questionsFile;

	void LoadQuestions();
};

#endif