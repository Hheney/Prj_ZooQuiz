#pragma once

#include "Plant.h"

//��� �帧
//Life �� Plant �� Merigold

//�Ĺ� - �޸���� Ŭ����
class Merigold : public Plant
{
public:
	Merigold(void);

private:
};

inline Merigold::Merigold(void)
{
	setParam("�޸����", LifeType::LT_PLANT, "Tagetes erecta L.", "��ȭ��", "�Ƹ���Ƽ��");

	m_farm = "�����ٸ� Ǯ��";
	m_isFlower = true;
	m_FlowerLang = "����";
}
