#pragma once

#include "Animal.h"

//��� �帧
//Life �� Animal �� Killerwhale

//���� - ���� Ŭ����
class Killerwhale : public Animal
{
public:
	Killerwhale(void);

private:
};

inline Killerwhale::Killerwhale(void)
{
	setParam("����", LifeType::LT_ANIMAL, "Orcinus orca", "������", "�ٴ�");

	m_food = "����";
	m_isPet = false;
	m_voice = "��������";
}