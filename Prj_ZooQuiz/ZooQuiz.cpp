#include "ZooQuiz.h"

int main()
{
	ZooQuiz quiz;

	quiz.setAnimalQuizFile("판다 문제.txt");
	quiz.loadQuizFile();

	quiz.play();


	return 0;
}