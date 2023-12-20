#pragma once

#include "Animal.h"

//상속 흐름
//Life → Animal → Panda

//동물 - 판다 클래스
class Panda : public Animal
{
public:
	Panda(void);

private:
};

inline Panda::Panda(void)
{
	setParam("판다", LifeType::LT_ANIMAL, "Ailuropoda melanoleuca", "곰과", "중국 사천성");

	m_food = "대나무";
	m_isPet = false;		
	m_voice = "알 수 없음";
}