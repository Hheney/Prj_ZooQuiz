#pragma once

#include "Life.h"

class Animal : public Life
{
public:
	Animal(void) {}

	// 생성자에 ':'를 사용하여 Animal 생성자에서 Life의 생성자를 호출하게 됨
	Animal(const std::string& name, LifeType nType, const std::string& sciName, 
		const std::string& family, const std::string& home) : Life(name, nType, sciName, family, home) {}

	//getter
	
	std::string getFood(void) const { return m_food; }
	bool isPet(void) const { return m_isPet; }
	std::string getVoice(void) const { return m_voice; }

protected:
	std::string m_food;		//먹이 변수
	bool m_isPet = false;	//애완동물 부울 변수
	std::string m_voice;	//울음소리

};

inline std::ostream& operator<<(std::ostream& stream, const Animal& animal)
{
	using namespace std;

	stream << Life(animal) << endl;
	stream << "먹이 : " << animal.getFood() << endl;
	stream << "애완동물 여부 : " << ((animal.isPet()) ? "맞음" : "아님") << endl;
	stream << "울음소리 : " << animal.getVoice() << endl;

	return stream;
}