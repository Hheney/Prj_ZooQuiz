#pragma once

#include "Plant.h"

//��� �帧
//Life �� Plant �� Lilac

//�Ĺ� - �޸���� Ŭ����
class Lilac : public Plant
{
public:
	Lilac(void);

private:
};

inline Lilac::Lilac(void)
{
	setParam("���϶�", LifeType::LT_PLANT, "Syringa vulgaris", "��Ǫ��������", "ī��ī��");

	m_farm = "�����ٸ� ����";
	m_isFlower = true;
	m_FlowerLang = "ù���";
}