#pragma once

#include "Animal.h"

//��� �帧
//Life �� Animal �� Panda

class Panda : public Animal
{
public:
	Panda(void);

private:
};

inline Panda::Panda(void)
{
	setParam("�Ǵ�", LifeType::LT_ANIMAL, "Ailuropoda melanoleuca", "����", "�߱� ��õ��");

	m_food = "�볪��";	//����
	m_isPet = false;		
	m_voice = "�پ��� �Ҹ��� ����";
}