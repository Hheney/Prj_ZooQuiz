#pragma once

#include "Plant.h"

//상속 흐름
//Life → Plant → Sunflower

//식물 - 해바라기 클래스
class Sunflower : public Plant
{
public:
	Sunflower(void);

private:
};

inline Sunflower::Sunflower(void)
{
	setParam("해바라기", LifeType::LT_PLANT, "Helianthus annuus", "국화과", "중앙아메리카");

	m_farm = "양지바른 공간";
	m_isFlower = true;
	m_FlowerLang = "존경";
}
