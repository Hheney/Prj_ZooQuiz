// ZooQuizGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <fstream>
#include <string>
#include "Life.h"
#include "Animal.h"
#include "Plant.h"
#include "Panda.h"

#define NUM_ANS (3)

int main()
{
	using namespace std;
	Panda panda;
	cout << panda << endl;

	ifstream file("판다 문제.txt");


	//문제 읽기

	string str;
	string qusetion;

	while (1)
	{
		getline(file, str);

		if (str == "===")
		{
			break;
		}
		else if (file.eof()) //eof: end of file(파일의 끝, eof 함수는 EOF를 만나면 true를 반환)
		{
			break;
		}
		
		qusetion += str + "\n";
	}
	cout << qusetion << endl;


	//보기 읽기
	string arAns[NUM_ANS];

	for (int i = 0; i < NUM_ANS; i++)
	{
		getline(file, str);
		arAns[i] = str;
	}

	for (string& s : arAns)
	{
		cout << s << endl;
	}

	return 0;
}