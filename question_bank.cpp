#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "question.h"
#include "question_bank.h"

using namespace std;

QuestionBank::QuestionBank(string fileName) {

	questionsFile.open(fileName);

	if (questionsFile.is_open()) LoadQuestions();
		
	questionsFile.close();
}
Question QuestionBank::GetNextQuestion() {

	if (questions.size() == 0) return Question();

	Question qstn = questions.at(0);
	questions.erase(questions.begin());

	return qstn;
	}
	
void QuestionBank::LoadQuestions() {

	while (questionsFile.good()) {
		string ans;
		string qstn;
		Question question;

		questionsFile >> ans;
		getline(questionsFile, qstn);

		questions.emplace_back(ans, qstn);
	}
}