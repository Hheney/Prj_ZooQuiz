#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include "ZooQuiz.h"
#include "LibConsole.hpp"	//�ܼ� ��� ���� ����
#include "LibGameTool.hpp"	//���� ó�� ���

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

	ZooQuiz zooquiz;

	MenuSelect(void) {
		nXPosition = DEF_X_COORD;
	}

	~MenuSelect() {

	}

	//setter
	void setXPos(int nXPos) //�ܼ� X��ǥ�� ���� �޼ҵ�
	{
		nXPosition = nXPos;
	}

	void setYPos(int nYPos) //�ܼ� Y��ǥ�� ���� �޼ҵ�
	{
		nYPosition = nYPos;
	}

	//getter
	int getXPos(void) const { return nXPosition; }
	int getYPos(void) const { return nYPosition; }

	void Menu(void);							//�޴� ��� �� ���� �ֱ�� �޼ҵ�
	void InputUserName(void);					//����� �̸��� �Է¹޴� �޼ҵ�

private:

	std::string strUserName;	//����� �̸�
	std::string strStartLogo;	//���۷ΰ�
	std::string strEndLogo;		//����ΰ�
	std::string strTitle;		//����ΰ�


	int nXPosition = DEF_X_COORD, nYPosition = DEF_Y_COORD;

	void MenuPrint(void);						//�޴� ��� �޼ҵ�
	void InitXYPos(void);						//X, Y��ǥ �ʱ�ȭ �޼ҵ�
	void GotoXY(int nXPos, int nYPos);			//�ܼ�ȭ�� Ŀ�� ��ǥ�̵� �Լ�
	int InputKey(void);							//WASDŰ �Է� �޼ҵ�
	int MoveORSelect(void);						//�޴� �̵� �� ���� �޼ҵ�
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
	ifstream TitleFile("Title.txt");

	StartLogoPrint(StartLogoFile); //���� �ΰ� ���
	system("cls");

	InputUserName(); //����� �̸� �Է�
	system("cls");

	while (1)
	{
		InitXYPos(); //XY��ǥ�� �ʱ�ȭ
		TitlePrint(TitleFile);	//Ÿ��Ʋȭ�� ���
		MenuPrint(); //�޴� ���

		switch (MoveORSelect())
		{
		case 0:
			//���� ����: ���� 5���� ���� ���
			break;

		case 1:
			//�Ĺ� ���� : �Ĺ� 5���� ���� ���
			break;

		case 2:
			//Zoo Quiz : ���� 10���� �������� ���, ���� 3���� �������� ���
			break;

		case 3:
			//���� ���: ������ �����, ����, �÷��� �ð� ���
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
