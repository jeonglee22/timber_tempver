#pragma once
#include "SpriteGO.h"
class BackgroundElementGO : public SpriteGO
{
protected:
	float speed = 0.f;
	sf::Vector2f direction;
public:
	BackgroundElementGO(const std::string& textid = "", const std::string& name = "");

	float getSpeed() const { return speed; };
	void setSpeed(float speed) { this->speed = speed; };

	sf::Vector2f getDirection() const { return direction; };
	void setDirection(sf::Vector2f direction) { this->direction = direction; };

	void SetSide(Sides side);
	Sides chooseSide();

	void Reset() override;

	void Update(float dt) override;
};

