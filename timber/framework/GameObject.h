#pragma once
#include "stdafx.h"
class GameObject
{
protected:
	std::string name;

	bool active;

	sf::Vector2f position;
	float rotation;
	sf::Vector2f scale;
	sf::Vector2f origin;

public:
	GameObject(const std::string& name = "");
	virtual ~GameObject() {};

	void setName(const std::string& name) { this->name = name; };
	virtual void setActive(bool active) { this->active = active; };
	virtual void setPosition(const sf::Vector2f& position) { this->position = position; };
	virtual void setRotation(float rotation) { this->rotation = rotation; };
	virtual void setScale(const sf::Vector2f& scale) { this->scale = scale; };
	virtual void setOrigin(const sf::Vector2f& origin) { this->origin = origin; };

	std::string getName() const { return name; };
	bool getActive() const { return active; };
	sf::Vector2f getPosition() const { return position; };
	float getRotation() const { return rotation; };
	sf::Vector2f getScale() const { return scale; };
	sf::Vector2f getOrigin() const { return origin; };

	virtual void Init() = 0;
	virtual void Release() = 0;
	virtual void Reset() = 0;

	virtual void Update(float dt) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
};

