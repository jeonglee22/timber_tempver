#include "stdafx.h"
#include "Utils.h"
#include <ctime>

void Utils::Init()
{
	srand((int)time(0));
	rand();
}

sf::Vector2f Utils::SetOrigin(sf::Sprite& obj, Origins preset)
{
	sf::FloatRect Rect = obj.getLocalBounds();
	sf::Vector2f newOrigin = { Rect.width, Rect.height };

	newOrigin.x *= ((int)preset % 3) / 2.f;
	newOrigin.y *= ((int)preset / 3) / 2.f;
	
	obj.setOrigin(newOrigin);

	return newOrigin;
}

sf::Vector2f Utils::SetOrigin(sf::Text& obj, Origins preset)
{
	sf::FloatRect Rect = obj.getLocalBounds();
	sf::Vector2f newOrigin = { Rect.width, Rect.height };

	newOrigin.x *= ((int)preset % 3) / 2.f;
	newOrigin.y *= ((int)preset / 3) / 2.f;

	obj.setOrigin(newOrigin);

	return newOrigin;
}

float Utils::RandomValue()
{
	return (float) rand() / RAND_MAX;
}

int Utils::RandomRange(int min, int maxExclude)
{
	return rand() % (maxExclude - min) + min;
}

float Utils::RandomRange(float min, float max)
{
	return ((float)rand() / RAND_MAX) * (max - min) + min;
}
