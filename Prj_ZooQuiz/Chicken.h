#pragma once

#include "Animal.h"

//��� �帧
//Life �� Animal �� Chicken

//���� - �⸰ Ŭ����
class Chicken : public Animal
{
public:
	Chicken(void);

private:
};

inline Chicken::Chicken(void)
{
	setParam("��", LifeType::LT_ANIMAL, "Gallus gallus domesticus", "���", "����Ʈ����");

	m_food = "����";	
	m_isPet = false;
	m_voice = "������";
}
