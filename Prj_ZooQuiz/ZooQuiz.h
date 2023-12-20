#pragma once

#include <vector>
#include <fstream>
#include "LibConsole.hpp"	//�ܼ� ��� ���� ����
#include "LibGameTool.hpp"	//���� ó�� ���
#include "Panda.h"			//�Ǵ�
#include "Chicken.h"		//��
#include "Giraffe.h"		//�⸰
#include "Killerwhale.h"	//����
#include "Wolf.h"			//����
#include "Chamomile.h"		//ĳ����
#include "Cherryblossom.h"	//����
#include "Lilac.h"			//���϶�
#include "Merigold.h"		//�޸����
#include "Sunflower.h"		//�عٶ��

//#define NUM_FILES (10) //�� ������ ����
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

	//�޼ҵ�
	void setAnimalQuizFile(const std::string& name) { m_animalQuizFile = name; }	//�������� ���� ���� �޼ҵ�
	void setPlantQuizFile(const std::string& name) { m_plantQuizFile = name; }		//�Ĺ����� ���� ����	�޼ҵ�
	void loadQuizFile(void);
	void play(void);
	
	void PrintOneQuiz(int nPos);

protected:

	//�޼ҵ�
	void PrintAnimalInfo(void); //�������� ��� �޼ҵ�
	void PrintPlantInfo(void);	//�Ĺ����� ��� �޼ҵ�

private:

	//�ʵ�
	

	std::string m_animalQuizFile;
	std::string m_plantQuizFile;
	//QuizQna m_animalQuiz[NUM_FILES][NUM_QUEST];
	QuizQna m_animalQuiz[NUM_QUEST];

	//�޼ҵ�
	void loadOneQuiz(std::ifstream& file, int nPos); //file�� �о m_animalQuiz [nPos] ��ġ�� ������ ���⸦ ä������
	
};

inline void ZooQuiz::loadQuizFile(void)
{
	using namespace std;
	
	ifstream file(m_animalQuizFile);

	for (int i = 0; i < NUM_QUEST; i++)
	{
		loadOneQuiz(file, i);
	}
	
	PrintOneQuiz(1);

	//vector<string> QuizFiles = { "�Ǵ� ����.txt", "�� ����.txt" };
	/*
	for (const auto& filename : QuizFiles)
	{
		ifstream file(filename);

		loadOneQuiz(file);
	}
	*/

	/*
	//���� ����
	ifstream file(m_animalQuizFile);
	
	for (int i = 0; i < NUM_QUEST; i++)
	{
		loadOneQuiz(file, i);
	}*/
}

inline void ZooQuiz::play(void)
{
	using namespace std;
}

inline void ZooQuiz::PrintAnimalInfo(void)
{
	using namespace mglib;
	using namespace std;

	Panda panda;
	Chicken chicken;
	Giraffe giraffe;
	Killerwhale killerwhale;
	Wolf wolf;
	
	settextcol(RED);
	cout << "[���� ����]" << endl << endl;

	//������ �������ߺ� ���
	settextcol(WHITE);
	cout << panda << endl;
	cout << chicken << endl;
	cout << giraffe << endl;
	cout << killerwhale << endl;
	cout << wolf << endl;
	settextcol(RED);
}

inline void ZooQuiz::PrintPlantInfo(void)
{
	using namespace mglib;
	using namespace std;

	Chamomile chamomile;
	Cherryblossom cherryblossom;
	Lilac lilac;
	Merigold merigold;
	Sunflower sunflower;

	settextcol(GREEN);
	cout << "[�Ĺ� ����]" << endl << endl;

	//������ �������ߺ� ���
	settextcol(WHITE);
	cout << chamomile << endl;		
	cout << cherryblossom << endl;
	cout << lilac << endl;
	cout << merigold << endl;
	cout << sunflower << endl;
	settextcol(GREEN);
}

inline void ZooQuiz::loadOneQuiz(std::ifstream& file, int nPos)
{
	using namespace std;

	//���� �б�
	string str;

	while (1)
	{
		getline(file, str);

		if (str == "===") break;

		else if (file.eof()) break; // eof: end of file(������ ��); eof() �Լ��� EOF�� ������ true ��ȯ

		m_animalQuiz[nPos].question += str + "\n";
	}

	//���� �б�
	for (int i = 0; i < NUM_ANS; i++)
	{
		getline(file, str);
		m_animalQuiz[nPos].arAns[i] = str;
	}

	getline(file, str); //"===" �б�
}

inline void ZooQuiz::PrintOneQuiz(int nPos)
{
	using namespace std;

	cout << m_animalQuiz[nPos].question << endl;
	cout << m_animalQuiz[nPos].arAns[0] << endl;
	cout << m_animalQuiz[nPos].arAns[1] << endl;
	cout << m_animalQuiz[nPos].arAns[2] << endl;
	
}