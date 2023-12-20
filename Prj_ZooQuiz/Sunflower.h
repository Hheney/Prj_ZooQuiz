#pragma once

#include "Plant.h"

//��� �帧
//Life �� Plant �� Sunflower

//�Ĺ� - �عٶ�� Ŭ����
class Sunflower : public Plant
{
public:
	Sunflower(void);

private:
};

inline Sunflower::Sunflower(void)
{
	setParam("�عٶ��", LifeType::LT_PLANT, "Helianthus annuus", "��ȭ��", "�߾ӾƸ޸�ī");

	m_farm = "�����ٸ� ����";
	m_isFlower = true;
	m_FlowerLang = "����";
}
