#pragma once
#include "GameObject.h"
class TextGO : public GameObject
{
protected:
	sf::Text text;
	std::string textString;
	std::string fontID;

	int fontSize;
	sf::Color color;

public:
	TextGO(const std::string& fontID = "", const std::string& name = "");
	~TextGO() override = default;

	void setFontID(const std::string& fontID) { this->fontID = fontID; };
	const std::string& getFontID() const { return fontID; };
	
	void setText(const std::string& text);
	const std::string& getText() const { return textString; };

	void setColor(const sf::Color& color);
	sf::Color getColor() const { return color; };

	void setFontSize(int fontSize);
	int getFontSize() const { return fontSize; };

	void setPosition(const sf::Vector2f& position) override;
	void setRotation(float rotation) override;
	void setScale(const sf::Vector2f& scale) override;
	void setOrigin(const sf::Vector2f& origin) override;
	void setOrigin(Origins preset) override;

	// GameObject을(를) 통해 상속됨
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

