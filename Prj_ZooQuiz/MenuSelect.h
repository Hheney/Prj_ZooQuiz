#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include "LibConsole.hpp"	//콘솔 출력 색깔 선택
#include "LibGameTool.hpp"	//난수 처리 기능

#include "ZooQuiz.h"

//콘솔 중앙정렬 위치
#define DEF_X_COORD (46)			//디폴트 X좌표 값
#define DEF_Y_COORD (13)			//디폴트 Y좌표 값
#define LOADING_SCREEN_DELAY (500)	//시작화면 지연시간 msec단위

enum class WASDKeyOrSpace
{
	Up = 0, Down, Left, Right, SpaceBar
};

class MenuSelect : public ZooQuiz
{
public:

	ZooQuiz zooquiz;

	MenuSelect(void) {
		nXPosition = DEF_X_COORD;	//디폴트 X좌표값으로 초기화
		nYPosition = DEF_Y_COORD;	//디폴트 Y좌표값으로 초기화
	}

	~MenuSelect() {

	}

	//setter
	void setXPos(int nXPos) { nXPosition = nXPos; } //콘솔 Y좌표값 설정 메소드
	void setYPos(int nYPos) { nYPosition = nYPos; } //콘솔 Y좌표값 설정 메소드

	//getter
	int getXPos(void) const { return nXPosition; }	//X좌표값 추출 메소드
	int getYPos(void) const { return nYPosition; }	//Y좌표값 추출 메소드

	void Menu(void);				//메뉴 출력 및 선택 주기능 메소드
	void InputUserName(void);		//사용자 이름을 입력받는 메소드

private:

	//필드
	int nXPosition = 0,
		nYPosition = 0;

	std::string strUserName;	//사용자 이름
	std::string strStartLogo;	//시작로고
	std::string strEndLogo;		//종료로고
	std::string strTitle;		//제목로고

	//메소드
	void MenuPrint(void);					//메뉴 출력 메소드
	void InitXYPos(void);					//X, Y좌표 초기화 메소드
	void GotoXY(int nXPos, int nYPos);		//콘솔화면 커서 좌표이동 함수
	int InputKey(void);						//WASD키 입력 메소드
	int MoveORSelect(void);					//메뉴 이동 및 선택 메소드

	//통계 관련 메소드
	void DisplayStats(void);

	//UI 관련 메소드
	void PrintDot(int nDot);					//로딩, 종료시 점을 출력하는 메소드
	void TitlePrint(std::ifstream& file);		//프로그램 제목 출력 메소드
	void StartLogoPrint(std::ifstream& file);	//Start 메시지 출력 메소드
	void EndLogoPrint(std::ifstream& file);		//End 메시지 출력 메소드

protected:
};

inline void MenuSelect::Menu(void)
{
	using namespace std;
	ifstream StartLogoFile("StartLogo.txt");
	ifstream EndLogoFile("EndLogo.txt");

	StartLogoPrint(StartLogoFile); //시작 로고 출력
	system("cls");

	InputUserName(); //사용자 이름 입력
	system("cls");

	while (1)
	{
		ifstream TitleFile("Title.txt");

		InitXYPos();			//XY좌표값 초기화
		TitlePrint(TitleFile);	//타이틀화면 출력
		MenuPrint();			//메뉴 출력

		switch (MoveORSelect())
		{
		case 0:
			//동물 공부: 동물 5종의 정보 출력
			system("cls");
			PrintAnimalInfo();
			system("Pause");
			break;

		case 1:
			//식물 공부 : 식물 5종의 정보 출력
			system("cls");
			PrintPlantInfo();
			system("Pause");
			break;

		case 2:
			//Zoo Quiz : 문제 10개를 무작위로 출력, 보기 3개도 무작위로 출력
			break;

		case 3:
			//게임 통계: 문제별 정답률, 득점, 플레이 시간 출력
			system("cls");
			InitXYPos();
			GotoXY(nXPosition, nYPosition - 5);
			cout << "게임 통계" << endl;
			//LoadStats(OpenFile); //저장된 통계 불러오기
			DisplayStats();		 //불러온 통계 출력
			break;

		case 4:
			//종료
			system("cls");
			InitXYPos();
			EndLogoPrint(EndLogoFile); //엔딩 로고 출력
			exit(0);

		default:
			break;
		}
		system("cls");
	}
}

inline void MenuSelect::InputUserName(void)
{
	using namespace std;

	GotoXY(nXPosition - 3, nYPosition);
	cout << "사용자 이름을 입력해주세요 : ";
	GotoXY(nXPosition + 10, nYPosition + 2);
	cin >> strUserName;
}

inline void MenuSelect::MenuPrint(void)
{
	using namespace mglib;
	using namespace std;

	GotoXY(nXPosition - 2, nYPosition);
	settextcol(GREEN);
	cout << "▶";
	settextcol(RED);
	cout << " 동물 공부" << endl;

	GotoXY(nXPosition, nYPosition + 1);
	cout << "식물 공부" << endl;

	GotoXY(nXPosition, nYPosition + 2);
	cout << "Zoo Quiz 게임" << endl;

	GotoXY(nXPosition, nYPosition + 3);
	cout << "게임 통계" << endl;

	GotoXY(nXPosition, nYPosition + 4);
	cout << "프로그램 종료" << endl;

	GotoXY(nXPosition + 1, nYPosition + 8);
	settextcol(WHITE);
	cout << "■ 조작법 ■";

	GotoXY(nXPosition - 19, nYPosition + 10);
	cout << "[w] 위로 이동 [s] 아래로 이동 [spacebar] 메뉴 선택";
}

inline void MenuSelect::InitXYPos(void)
{
	setXPos(DEF_X_COORD);
	setYPos(DEF_Y_COORD);
}

inline void MenuSelect::GotoXY(int nXPos, int nYPos)
{
	COORD Position; //Short X,Y typedef임, X, Y좌표로 커서 위치를 옮기는 동작을 수행예정

	Position.X = nXPos;
	Position.Y = nYPos;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position); //이 메소드를 통해 콘솔화면 좌표 이동
}

inline int MenuSelect::InputKey(void)
{
	char chInput = _getch();

	if (chInput == 'w' || chInput == 'W')
	{
		return (int)WASDKeyOrSpace::Up;
	}
	else if (chInput == 'a' || chInput == 'A')
	{
		return (int)WASDKeyOrSpace::Left;
	}
	else if (chInput == 's' || chInput == 'S')
	{
		return (int)WASDKeyOrSpace::Down;
	}
	else if (chInput == 'd' || chInput == 'D')
	{
		return (int)WASDKeyOrSpace::Right;
	}
	else if (chInput == ' ')
	{
		return (int)WASDKeyOrSpace::SpaceBar;
	}
	else return 0;
}

inline int MenuSelect::MoveORSelect(void)
{
	using namespace mglib;
	using namespace std;

	while (1)
	{
		switch (InputKey())
		{
		case (int)WASDKeyOrSpace::Up:

			if (nYPosition > DEF_Y_COORD)
			{
				GotoXY(nXPosition - 2, nYPosition);
				cout << " ";

				GotoXY(nXPosition - 2, --nYPosition);
				settextcol(GREEN);
				cout << "▶";
			}
			break;

		case (int)WASDKeyOrSpace::Down:

			if (nYPosition < DEF_Y_COORD + 4) //시작좌표 + 4 : 5가지 메뉴가 존재하며, 커서 범위를 제한
			{
				GotoXY(nXPosition - 2, nYPosition);
				cout << " ";

				GotoXY(nXPosition - 2, ++nYPosition);
				settextcol(GREEN);
				cout << "▶";
			}
			break;

		case (int)WASDKeyOrSpace::SpaceBar:

			return nYPosition - DEF_Y_COORD; //(변수) - (기본 y좌표)를 통해 switch문에 사용될 정수 반환 

		default:
			break;
		}
	}
}

inline void MenuSelect::DisplayStats(void)
{
	using namespace std;
	using namespace mglib;

	settextcol(GREEN);

	cout << endl << "\t\t\t\t\t사용자 이름\t:" << strUserName << endl;
	//cout << "\t\t\t\t\t플레이 난이도\t:" << nSelectDiff << "Lv." << endl;
	//cout << "\t\t\t\t\t정답 비율\t:" << correctRatio << '%' << endl;
	//cout << "\t\t\t\t\t평균 풀이 속도\t:" << avgCalcTime << " 초" << endl;

	settextcol(RED);
	GotoXY(nXPosition - 13, nYPosition + 7);

	system("PAUSE");
}

inline void MenuSelect::PrintDot(int nDot)
{
	using namespace mglib;

	for (int i = 0; i < nDot; i++)
	{
		Sleep(LOADING_SCREEN_DELAY);
		settextcol(WHITE);
		std::cout << ".";
	}
}

inline void MenuSelect::TitlePrint(std::ifstream& file)
{
	using namespace mglib;
	using namespace std;

	cout << "\n\n\n\n\n";

	/*
		getline 함수는 입력 스트림에서 문자들을 읽어서, 인자로 받은 문자열에 저장
		입력 스트림에서 문자를 읽다가 delim 문자를 읽게되면, 해당 문자를 버리고, 읽어들이기를 종료
		만약에 delim 문자를 설정하지 않았다면, 디폴트로 개행 문자('\n')로 설정됨.
	*/
	while (getline(file, strTitle))
	{
		settextcol(YELLOW);
		cout << "\t\t" << strTitle << endl;
	}
}

inline void MenuSelect::StartLogoPrint(std::ifstream& file)
{
	using namespace mglib;
	using namespace std;

	cout << "\n\n\n\n\n\n";

	while (getline(file, strStartLogo))
	{
		settextcol(SKYBLUE);
		cout << "\t\t\t\t\t" << strStartLogo << endl;
	}

	InitXYPos();
	GotoXY(nXPosition + 5, nYPosition);

	cout << "Loading";
	PrintDot(4);
}

inline void MenuSelect::EndLogoPrint(std::ifstream& file)
{
	using namespace mglib;
	using namespace std;

	cout << "\n\n\n\n\n\n";
	settextcol(SKYBLUE);

	while (getline(file, strEndLogo))
	{
		cout << "\t\t\t\t" << strEndLogo << endl;
	}

	InitXYPos();
	GotoXY(nXPosition + 3, nYPosition);

	cout << "Program off";
	PrintDot(4);

	GotoXY(nXPosition + 3, nYPosition + 8);
}
