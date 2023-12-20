#pragma once

#include "Life.h"

class Plant : public Life
{
public:

	Plant(void) {}

	Plant(const std::string& name, LifeType nType, const std::string& sciName,
		const std::string& family, const std::string& home) : Life(name, nType, sciName, family, home) {}

	//getter
	std::string getFarm(void) const { return m_farm; }

	bool isFlower(void) const { return m_isFlower; }

	std::string getFlowerLang(void) const { return m_FlowerLang; }

protected:
	std::string m_farm;			//��� ���?
	bool m_isFlower = false;	//�� �ο� ����
	std::string m_FlowerLang;	//�ɸ�
};


inline std::ostream& operator<<(std::ostream& stream, const Plant& plant)
{
	using namespace std;

	stream << Life(plant) << endl;
	stream << "��� : " << plant.getFarm() << endl;
	stream << "�� ���� : " << ((plant.isFlower()) ? "����" : "�ƴ�") << endl;
	stream << "�ɸ� : " << plant.getFlowerLang() << endl;

	return stream;
}