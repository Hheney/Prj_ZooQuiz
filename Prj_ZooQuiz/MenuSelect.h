#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include "LibConsole.hpp"	//�ܼ� ��� ���� ����
#include "LibGameTool.hpp"	//���� ó�� ���

#include "ZooQuiz.h"

//�ܼ� �߾����� ��ġ
#define DEF_X_COORD (46)			//����Ʈ X��ǥ ��
#define DEF_Y_COORD (13)			//����Ʈ Y��ǥ ��
#define LOADING_SCREEN_DELAY (500)	//����ȭ�� �����ð� msec����

enum class WASDKeyOrSpace
{
	Up = 0, Down, Left, Right, SpaceBar
};

class MenuSelect : public ZooQuiz
{
public:


	MenuSelect(void) {
		nXPosition = DEF_X_COORD;	//����Ʈ X��ǥ������ �ʱ�ȭ
		nYPosition = DEF_Y_COORD;	//����Ʈ Y��ǥ������ �ʱ�ȭ
	}

	~MenuSelect() {

	}

	//setter
	void setXPos(int nXPos) { nXPosition = nXPos; } //�ܼ� Y��ǥ�� ���� �޼ҵ�
	void setYPos(int nYPos) { nYPosition = nYPos; } //�ܼ� Y��ǥ�� ���� �޼ҵ�

	//getter
	int getXPos(void) const { return nXPosition; }	//X��ǥ�� ���� �޼ҵ�
	int getYPos(void) const { return nYPosition; }	//Y��ǥ�� ���� �޼ҵ�

	void Menu(void);				//�޴� ��� �� ���� �ֱ�� �޼ҵ�
	void InputUserName(void);		//����� �̸��� �Է¹޴� �޼ҵ�

private:

	//�ʵ�
	int nXPosition = 0,
		nYPosition = 0;

	std::string strUserName;	//����� �̸�
	std::string strStartLogo;	//���۷ΰ�
	std::string strEndLogo;		//����ΰ�
	std::string strTitle;		//����ΰ�

	//�޼ҵ�
	void MenuPrint(void);					//�޴� ��� �޼ҵ�
	void InitXYPos(void);					//X, Y��ǥ �ʱ�ȭ �޼ҵ�
	void GotoXY(int nXPos, int nYPos);		//�ܼ�ȭ�� Ŀ�� ��ǥ�̵� �Լ�
	int InputKey(void);						//WASDŰ �Է� �޼ҵ�
	int MoveORSelect(void);					//�޴� �̵� �� ���� �޼ҵ�

	//��� ���� �޼ҵ�
	void DisplayStats(void);

	//UI ���� �޼ҵ�
	void PrintDot(int nDot);					//�ε�, ����� ���� ����ϴ� �޼ҵ�
	void TitlePrint(std::ifstream& file);		//���α׷� ���� ��� �޼ҵ�
	void StartLogoPrint(std::ifstream& file);	//Start �޽��� ��� �޼ҵ�
	void EndLogoPrint(std::ifstream& file);		//End �޽��� ��� �޼ҵ�

protected:
};

inline void MenuSelect::Menu(void)
{
	using namespace std;
	ifstream StartLogoFile("StartLogo.txt");
	ifstream EndLogoFile("EndLogo.txt");

	StartLogoPrint(StartLogoFile); //���� �ΰ� ���
	system("cls");

	InputUserName(); //����� �̸� �Է�
	system("cls");

	while (1)
	{
		ifstream TitleFile("Title.txt");

		InitXYPos();			//XY��ǥ�� �ʱ�ȭ
		TitlePrint(TitleFile);	//Ÿ��Ʋȭ�� ���
		MenuPrint();			//�޴� ���

		switch (MoveORSelect())
		{
		case 0:
			//���� ����: ���� 5���� ���� ���
			system("cls");
			PrintAnimalInfo();
			system("Pause");
			break;

		case 1:
			//�Ĺ� ���� : �Ĺ� 5���� ���� ���
			system("cls");
			PrintPlantInfo();
			system("Pause");
			break;

		case 2:
			//Zoo Quiz : ���� 10���� �������� ���, ���� 3���� �������� ���
			//���� ������ �ۼ��Ϸ� �Ͽ�����, �ٹ����� ���׿� �ɷ��� �Ѱ�� �ۼ����� ����.
			//loadQuizFile();

			PrintOneQuiz(2);
			break;

		case 3:
			//���� ���: ������ �����, ����, �÷��� �ð� ���
			system("cls");
			InitXYPos();
			GotoXY(nXPosition, nYPosition - 5);
			cout << "���� ���" << endl;
			//LoadStats(OpenFile); //����� ��� �ҷ�����
			DisplayStats();		 //�ҷ��� ��� ���
			break;

		case 4:
			//����
			system("cls");
			InitXYPos();
			EndLogoPrint(EndLogoFile); //���� �ΰ� ���
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
	cout << "����� �̸��� �Է����ּ��� : ";
	GotoXY(nXPosition + 10, nYPosition + 2);
	cin >> strUserName;
}

inline void MenuSelect::MenuPrint(void)
{
	using namespace mglib;
	using namespace std;

	GotoXY(nXPosition - 2, nYPosition);
	settextcol(GREEN);
	cout << "��";
	settextcol(RED);
	cout << " ���� ����" << endl;

	GotoXY(nXPosition, nYPosition + 1);
	cout << "�Ĺ� ����" << endl;

	GotoXY(nXPosition, nYPosition + 2);
	cout << "Zoo Quiz ����" << endl;

	GotoXY(nXPosition, nYPosition + 3);
	cout << "���� ���" << endl;

	GotoXY(nXPosition, nYPosition + 4);
	cout << "���α׷� ����" << endl;

	GotoXY(nXPosition + 1, nYPosition + 8);
	settextcol(WHITE);
	cout << "�� ���۹� ��";

	GotoXY(nXPosition - 19, nYPosition + 10);
	cout << "[w] ���� �̵� [s] �Ʒ��� �̵� [spacebar] �޴� ����";
}

inline void MenuSelect::InitXYPos(void)
{
	setXPos(DEF_X_COORD);
	setYPos(DEF_Y_COORD);
}

inline void MenuSelect::GotoXY(int nXPos, int nYPos)
{
	COORD Position; //Short X,Y typedef��, X, Y��ǥ�� Ŀ�� ��ġ�� �ű�� ������ ���࿹��

	Position.X = nXPos;
	Position.Y = nYPos;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position); //�� �޼ҵ带 ���� �ܼ�ȭ�� ��ǥ �̵�
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
				cout << "��";
			}
			break;

		case (int)WASDKeyOrSpace::Down:

			if (nYPosition < DEF_Y_COORD + 4) //������ǥ + 4 : 5���� �޴��� �����ϸ�, Ŀ�� ������ ����
			{
				GotoXY(nXPosition - 2, nYPosition);
				cout << " ";

				GotoXY(nXPosition - 2, ++nYPosition);
				settextcol(GREEN);
				cout << "��";
			}
			break;

		case (int)WASDKeyOrSpace::SpaceBar:

			return nYPosition - DEF_Y_COORD; //(����) - (�⺻ y��ǥ)�� ���� switch���� ���� ���� ��ȯ 

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

	cout << endl << "\t\t\t\t\t����� �̸�\t:" << strUserName << endl;
	//cout << "\t\t\t\t\t�÷��� ���̵�\t:" << nSelectDiff << "Lv." << endl;
	//cout << "\t\t\t\t\t���� ����\t:" << correctRatio << '%' << endl;
	//cout << "\t\t\t\t\t��� Ǯ�� �ӵ�\t:" << avgCalcTime << " ��" << endl;

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
		getline �Լ��� �Է� ��Ʈ������ ���ڵ��� �о, ���ڷ� ���� ���ڿ��� ����
		�Է� ��Ʈ������ ���ڸ� �дٰ� delim ���ڸ� �аԵǸ�, �ش� ���ڸ� ������, �о���̱⸦ ����
		���࿡ delim ���ڸ� �������� �ʾҴٸ�, ����Ʈ�� ���� ����('\n')�� ������.
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
