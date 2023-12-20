#pragma once

#include "Animal.h"

//��� �帧
//Life �� Animal �� Giraffe

//���� - �⸰ Ŭ����
class Giraffe : public Animal
{
public:
	Giraffe(void);

private:
};

inline Giraffe::Giraffe(void)
{
	setParam("�⸰", LifeType::LT_ANIMAL, "Giraffa camelopardalis", "�⸰��", "����� �긲");

	m_food = "��ī�þ�";
	m_isPet = false;
	m_voice = "�� �� ����";
}