#include "stdafx.h"
#include "Utils.h"

sf::Vector2f Utils::SetOrigin(sf::Sprite& obj, Origins preset)
{
	sf::FloatRect Rect = obj.getLocalBounds();
	sf::Vector2f newOrigin = { Rect.width, Rect.height };

	newOrigin.x *= ((int)preset % 3) / 2.f;
	newOrigin.y *= ((int)preset / 3) / 2.f;
	
	obj.setOrigin(newOrigin);

	return newOrigin;
}
