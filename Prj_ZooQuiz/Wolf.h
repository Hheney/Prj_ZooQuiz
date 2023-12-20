#pragma once

#include "Animal.h"

//��� �帧
//Life �� Animal �� Wolf

//���� - ���� Ŭ����
class Wolf : public Animal
{
public:
	Wolf(void);

private:
};

inline Wolf::Wolf(void)
{
	setParam("����", LifeType::LT_ANIMAL, "Canis lupus", "����", "��");

	m_food = "�罿";
	m_isPet = false;
	m_voice = "�ƿ���";
}