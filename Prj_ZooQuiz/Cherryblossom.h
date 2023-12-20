#pragma once

#include "Plant.h"

//��� �帧
//Life �� Plant �� Cherryblossom

//�Ĺ� - ���� Ŭ����
class Cherryblossom : public Plant
{
public:
	Cherryblossom(void);

private:
};

inline Cherryblossom::Cherryblossom(void)
{
	setParam("����", LifeType::LT_PLANT, "Prunus serrulata Lindley var", "��̰�", "�ѱ�");

	m_farm = "����";
	m_isFlower = true;
	m_FlowerLang = "������";
}