#pragma once

#include "Animal.h"

//상속 흐름
//Life → Animal → Killerwhale

//동물 - 범고래 클래스
class Killerwhale : public Animal
{
public:
	Killerwhale(void);

private:
};

inline Killerwhale::Killerwhale(void)
{
	setParam("범고래", LifeType::LT_ANIMAL, "Orcinus orca", "돌고래과", "바다");

	m_food = "물범";
	m_isPet = false;
	m_voice = "이이이이";
}