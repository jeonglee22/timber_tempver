#include "stdafx.h"
#include "SpriteGO.h"

SpriteGO::SpriteGO(const std::string& textID, const std::string& name)
	:textureID(textID), GameObject(name)
{
}

void SpriteGO::Init()
{
}

void SpriteGO::setPosition(const sf::Vector2f& position)
{
	this->position = position;
	sprite.setPosition(position);
}

void SpriteGO::setRotation(float rotation)
{
	this->rotation = rotation;
	sprite.setRotation(rotation);
}

void SpriteGO::setScale(const sf::Vector2f& scale)
{
	this->scale = scale;
	sprite.setScale(scale);
}

void SpriteGO::setOrigin(const sf::Vector2f& origin) 
{
	originPreset = Origins::Custom;
	this->origin = origin;
	sprite.setOrigin(origin);
}

void SpriteGO::setOrigin(Origins preset) 
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		this->origin = Utils::SetOrigin(sprite, originPreset);
	}
}

void SpriteGO::Release()
{
}

void SpriteGO::Reset()
{
	sprite.setTexture(TEXTURE_MGR.Get(textureID));
	setOrigin(originPreset);
}

void SpriteGO::Update(float dt)
{
}

void SpriteGO::Draw(sf::RenderWindow& window)
{
	if (active)
	{
		window.draw(sprite);
	}
}
