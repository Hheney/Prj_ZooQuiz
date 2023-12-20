#pragma once

#include "Plant.h"

//상속 흐름
//Life → Plant → Chamomile

//식물 - 캐모마일 클래스
class Chamomile : public Plant
{
public:
	Chamomile(void);

private:
};

inline Chamomile::Chamomile(void)
{
	setParam("캐모마일", LifeType::LT_PLANT, "Matricaria chamomilla", "국화과", "영국");

	m_farm = "양지바른 공간";
	m_isFlower = true;
	m_FlowerLang = "인내";
}