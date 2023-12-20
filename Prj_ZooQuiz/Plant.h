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
	std::string m_farm;			//犁硅 规侥?
	bool m_isFlower = false;	//采 何匡 函荐
	std::string m_FlowerLang;	//采富
};


inline std::ostream& operator<<(std::ostream& stream, const Plant& plant)
{
	using namespace std;

	stream << Life(plant) << endl;
	stream << "犁硅 : " << plant.getFarm() << endl;
	stream << "采 咯何 : " << ((plant.isFlower()) ? "嘎澜" : "酒丛") << endl;
	stream << "采富 : " << plant.getFlowerLang() << endl;

	return stream;
}