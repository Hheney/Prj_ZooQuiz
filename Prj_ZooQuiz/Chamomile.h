#pragma once

#include "Plant.h"

//��� �帧
//Life �� Plant �� Chamomile

//�Ĺ� - ĳ���� Ŭ����
class Chamomile : public Plant
{
public:
	Chamomile(void);

private:
};

inline Chamomile::Chamomile(void)
{
	setParam("ĳ����", LifeType::LT_PLANT, "Matricaria chamomilla", "��ȭ��", "����");

	m_farm = "�����ٸ� ����";
	m_isFlower = true;
	m_FlowerLang = "�γ�";
}