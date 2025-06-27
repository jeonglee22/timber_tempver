#pragma once
#include "GameObject.h"
class SpriteGO : public GameObject
{
protected:
	sf::Sprite sprite;
	std::string textureID;


public:
	SpriteGO(const std::string& textID = "", const std::string& name = "");
	~SpriteGO() override = default;

	void setSprite(sf::Sprite sprite) { this->sprite = sprite; };
	void setTextureID(const std::string& textureID) { this->textureID = textureID; };
	sf::Sprite getSprite() const { return sprite; };
	const std::string& getTextureID() const { return textureID; };

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

