#pragma once

#include <vector>
#include <fstream>
#include "LibConsole.hpp"	//콘솔 출력 색깔 선택
#include "LibGameTool.hpp"	//난수 처리 기능
#include "Panda.h"			//판다
#include "Chicken.h"		//닭
#include "Giraffe.h"		//기린
#include "Killerwhale.h"	//범고래
#include "Wolf.h"			//늑대
#include "Chamomile.h"		//캐모마일
#include "Cherryblossom.h"	//벚꽃
#include "Lilac.h"			//라일락
#include "Merigold.h"		//메리골드
#include "Sunflower.h"		//해바라기

//#define NUM_FILES (10) //총 파일의 갯수
#define NUM_QUEST (5) //과제에서는 5개 임시로 2개설정
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

	//메소드
	void setAnimalQuizFile(const std::string& name) { m_animalQuizFile = name; }	//동물퀴즈 파일 선택 메소드
	void setPlantQuizFile(const std::string& name) { m_plantQuizFile = name; }		//식물퀴즈 파일 선택	메소드
	void loadQuizFile(void);
	void play(void);
	
	void PrintOneQuiz(int nPos);

protected:

	//메소드
	void PrintAnimalInfo(void); //동물정보 출력 메소드
	void PrintPlantInfo(void);	//식물정보 출력 메소드

private:

	//필드
	

	std::string m_animalQuizFile;
	std::string m_plantQuizFile;
	//QuizQna m_animalQuiz[NUM_FILES][NUM_QUEST];
	QuizQna m_animalQuiz[NUM_QUEST];

	//메소드
	void loadOneQuiz(std::ifstream& file, int nPos); //file을 읽어서 m_animalQuiz [nPos] 위치에 문제와 보기를 채워넣음
	
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

	//vector<string> QuizFiles = { "판다 문제.txt", "닭 문제.txt" };
	/*
	for (const auto& filename : QuizFiles)
	{
		ifstream file(filename);

		loadOneQuiz(file);
	}
	*/

	/*
	//동물 퀴즈
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
	cout << "[동물 정보]" << endl << endl;

	//각각의 연산자중복 출력
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
	cout << "[식물 정보]" << endl << endl;

	//각각의 연산자중복 출력
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

	//문제 읽기
	string str;

	while (1)
	{
		getline(file, str);

		if (str == "===") break;

		else if (file.eof()) break; // eof: end of file(파일의 끝); eof() 함수는 EOF를 만나면 true 반환

		m_animalQuiz[nPos].question += str + "\n";
	}

	//보기 읽기
	for (int i = 0; i < NUM_ANS; i++)
	{
		getline(file, str);
		m_animalQuiz[nPos].arAns[i] = str;
	}

	getline(file, str); //"===" 읽기
}

inline void ZooQuiz::PrintOneQuiz(int nPos)
{
	using namespace std;

	cout << m_animalQuiz[nPos].question << endl;
	cout << m_animalQuiz[nPos].arAns[0] << endl;
	cout << m_animalQuiz[nPos].arAns[1] << endl;
	cout << m_animalQuiz[nPos].arAns[2] << endl;
	
}