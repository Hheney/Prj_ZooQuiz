#pragma once

#include "Life.h"

class Animal : public Life
{
public:
	Animal(void) {}

	// �����ڿ� ':'�� ����Ͽ� Animal �����ڿ��� Life�� �����ڸ� ȣ���ϰ� ��
	Animal(const std::string& name, LifeType nType, const std::string& sciName, 
		const std::string& family, const std::string& home) : Life(name, nType, sciName, family, home) {}

	//getter
	
	std::string getFood(void) const { return m_food; }
	bool isPet(void) const { return m_isPet; }
	std::string getVoice(void) const { return m_voice; }

protected:
	std::string m_food;		//���� ����
	bool m_isPet = false;	//�ֿϵ��� �ο� ����
	std::string m_voice;	//�����Ҹ�

};

inline std::ostream& operator<<(std::ostream& stream, const Animal& animal)
{
	using namespace std;

	stream << Life(animal) << endl;
	stream << "���� : " << animal.getFood() << endl;
	stream << "�ֿϵ��� ���� : " << ((animal.isPet()) ? "����" : "�ƴ�") << endl;
	stream << "�����Ҹ� : " << animal.getVoice() << endl;

	return stream;
}