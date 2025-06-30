#pragma once
#include "SpriteGO.h"
class BackgroundBee : public SpriteGO
{
protected:
	float speed = 0.f;
	float yspeed = 300.f;
	sf::Vector2f direction;
	sf::Vector2f yDirection = { 0.f, 1.f };

	int moveType = 0;

public:
	BackgroundBee(const std::string& textid = "", const std::string& name = "");

	float getSpeed() const { return speed; };
	void setSpeed(float speed) { this->speed = speed; };

	sf::Vector2f getDirection() const { return direction; };
	void setDirection(sf::Vector2f direction) { this->direction = direction; };

	void setRotation(float r) override;

	void SetSide(Sides side);

	void Reset() override;

	void Update(float dt) override;
};

