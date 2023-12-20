#pragma once

#include <fstream>
#include "Panda.h"
#include "Chicken.h"
#include "Giraffe.h"
#include "Killerwhale.h"
#include "Wolf.h"

#define NUM_QUEST (5) //���������� 5�� �ӽ÷� 2������
#define NUM_ANS (3)

struct QuizQna
{
	std::string question;
	std::string arAns[NUM_ANS];
};

class ZooQuiz
{
public:
	ZooQuiz(void) {}

	void setAnimalQuizFile(const std::string& name)
	{
		m_animalQuizFile = name;
	}

	void loadQuizFile(void);

	void play(void);

private:
	std::string m_animalQuizFile;
	Panda m_panda;
	QuizQna m_animalQuiz[NUM_QUEST];

	void loadOneQuiz(std::ifstream& file, int nPos); //file�� �о m_animalQuiz [nPos] ��ġ�� ������ ���⸦ ä������
	
};

inline void ZooQuiz::loadQuizFile(void)
{
	using namespace std;
	
	//���� ����
	ifstream file(m_animalQuizFile);
	//cout << file.is_open() << endl; //���� ���� ��������

	for (int i = 0; i < NUM_QUEST; i++)
	{
		loadOneQuiz(file, i);
	}

}

inline void ZooQuiz::play(void)
{

}

inline void ZooQuiz::loadOneQuiz(std::ifstream& file, int nPos)
{
	using namespace std;

	//���� �б�

	string str;

	while (1)
	{
		getline(file, str);

		if (str == "===")
		{
			break;
		}
		else if (file.eof()) //eof: end of file(������ ��, eof �Լ��� EOF�� ������ true�� ��ȯ)
		{
			break;
		}

		m_animalQuiz[nPos].question += str + "\n";
	}
	cout << m_animalQuiz[nPos].question << endl;

	//���� �б�

	for (int i = 0; i < NUM_ANS; i++)
	{
		getline(file, str);
		m_animalQuiz[nPos].arAns[i] = str;
	}

	for (string& s : m_animalQuiz[nPos].arAns)
	{
		cout << s << endl;
	}
	
	getline(file, str); //"===" �б�

	cout << endl;
}