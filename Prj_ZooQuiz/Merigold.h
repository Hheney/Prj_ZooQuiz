#pragma once

#include "Plant.h"

//상속 흐름
//Life → Plant → Merigold

//식물 - 메리골드 클래스
class Merigold : public Plant
{
public:
	Merigold(void);

private:
};

inline Merigold::Merigold(void)
{
	setParam("메리골드", LifeType::LT_PLANT, "Tagetes erecta L.", "국화과", "아르헨티나");

	m_farm = "양지바른 풀밭";
	m_isFlower = true;
	m_FlowerLang = "우정";
}
