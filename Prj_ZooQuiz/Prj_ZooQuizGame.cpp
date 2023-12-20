#include "MenuSelect.h"


int main()
{
	MenuSelect menu;
	ZooQuiz quiz;
	quiz.setAnimalQuizFile("판다 문제.txt");

	menu.Menu();

	return 0;
}