#include "ZooQuiz.h"

int main()
{
	ZooQuiz quiz;

	quiz.setAnimalQuizFile("�Ǵ� ����.txt");
	quiz.loadQuizFile();

	quiz.play();


	return 0;
}