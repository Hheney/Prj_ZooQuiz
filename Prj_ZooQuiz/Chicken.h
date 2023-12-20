#pragma once

#include "Animal.h"

//»ó¼Ó Èå¸§
//Life ¡æ Animal ¡æ Chicken

//µ¿¹° - ±â¸° Å¬·¡½º
class Chicken : public Animal
{
public:
	Chicken(void);

private:
};

inline Chicken::Chicken(void)
{
	setParam("´ß", LifeType::LT_ANIMAL, "Gallus gallus domesticus", "²æ°ú", "¿À½ºÆ®¸®¾Æ");

	m_food = "¾¾¾Ñ";	
	m_isPet = false;
	m_voice = "²¿³¢¿À";
}
