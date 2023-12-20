#pragma once

#include "Plant.h"

//상속 흐름
//Life → Plant → Cherryblossom

//식물 - 벚꽃 클래스
class Cherryblossom : public Plant
{
public:
	Cherryblossom(void);

private:
};

inline Cherryblossom::Cherryblossom(void)
{
	setParam("벚꽃", LifeType::LT_PLANT, "Prunus serrulata Lindley var", "장미과", "한국");

	m_farm = "산지";
	m_isFlower = true;
	m_FlowerLang = "순수함";
}