#pragma once

#include "Animal.h"

//상속 흐름
//Life → Animal → Giraffe

//동물 - 기린 클래스
class Giraffe : public Animal
{
public:
	Giraffe(void);

private:
};

inline Giraffe::Giraffe(void)
{
	setParam("기린", LifeType::LT_ANIMAL, "Giraffa camelopardalis", "기린과", "개방된 산림");

	m_food = "아카시아";
	m_isPet = false;
	m_voice = "알 수 없음";
}