#pragma once

#include "Animal.h"

//»ó¼Ó Èå¸§
//Life ¡æ Animal ¡æ Wolf

//µ¿¹° - ´Á´ë Å¬·¡½º
class Wolf : public Animal
{
public:
	Wolf(void);

private:
};

inline Wolf::Wolf(void)
{
	setParam("´Á´ë", LifeType::LT_ANIMAL, "Canis lupus", "°³°ú", "½£");

	m_food = "»ç½¿";
	m_isPet = false;
	m_voice = "¾Æ¿ì¿ì¿ì";
}