#ifndef QUESTION_BANK_H
#define QUESTION_BANK_H

#include <string>
#include <vector>

#include "question.h"

class QuestionBank {
public:
	//QuestionBank();
	QuestionBank(vector<Question> questions) { this->questions = questions; }
	void addQuestion(Question question) { questions.push_back(question); }

private:
	vector<Question> questions;
};

#endif