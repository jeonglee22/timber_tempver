#include "stdafx.h"
#include "TextGO.h"

TextGO::TextGO(const std::string& fontID, const std::string& name)
	:fontID(fontID), GameObject(name)
{
}

void TextGO::setText(const std::string& text)
{
	this->textString = text;
	this->text.setString(text);
	setOrigin(originPreset);
}

void TextGO::setColor(const sf::Color& color)
{
	this->color = color;
	text.setFillColor(color);
}

void TextGO::setFontSize(int fontSize)
{
	this->fontSize = fontSize;
	text.setCharacterSize(fontSize);
	setOrigin(originPreset);
}

void TextGO::setPosition(const sf::Vector2f& position)
{
	this->position = position;
	text.setPosition(position);
}

void TextGO::setRotation(float rotation) 
{
	this->rotation = rotation;
	text.setRotation(rotation);
}

void TextGO::setScale(const sf::Vector2f& scale) 
{
	this->scale = scale;
	text.setScale(scale);
}

void TextGO::setOrigin(const sf::Vector2f& origin) 
{
	originPreset = Origins::Custom;
	this->origin = origin;
	text.setOrigin(origin);
}

void TextGO::setOrigin(Origins preset) 
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		this->origin = Utils::SetOrigin(text, originPreset);
	}
}

// GameObject을(를) 통해 상속됨
void TextGO::Init() 
{
}

void TextGO::Release() 
{
}

void TextGO::Reset() 
{
	text.setFont(FONT_MGR.Get(fontID));
	setOrigin(originPreset);
}

void TextGO::Update(float dt) 
{

}

void TextGO::Draw(sf::RenderWindow& window) 
{
	if (active)
	{
		window.draw(text);
	}
}