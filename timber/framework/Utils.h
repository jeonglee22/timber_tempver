#pragma once
class Utils
{
public:
	static void Init();

	static sf::Vector2f SetOrigin(sf::Sprite& obj, Origins preset);
	static sf::Vector2f SetOrigin(sf::Text& obj, Origins preset);

	static float RandomValue(); // 0.f ~ 1.f
	static int RandomRange(int min, int maxExclude); // int min ~ max
	static float RandomRange(float min, float max); // float min ~ max

};

