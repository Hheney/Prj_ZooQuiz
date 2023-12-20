#pragma once

#include "Plant.h"

//상속 흐름
//Life → Plant → Lilac

//식물 - 메리골드 클래스
class Lilac : public Plant
{
public:
	Lilac(void);

private:
};

inline Lilac::Lilac(void)
{
	setParam("라일락", LifeType::LT_PLANT, "Syringa vulgaris", "물푸레나무과", "카프카스");

	m_farm = "양지바른 공간";
	m_isFlower = true;
	m_FlowerLang = "첫사랑";
}