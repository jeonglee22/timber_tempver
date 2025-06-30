#include "stdafx.h"
#include "BackgroundBee.h"

BackgroundBee::BackgroundBee(const std::string& textid, const std::string& name)
	:SpriteGO(textid, name)
{
}

void BackgroundBee::setRotation(float r)
{
	sprite.setRotation(r);
	SpriteGO::setRotation(r);
}

void BackgroundBee::SetSide(Sides side)
{
	sf::FloatRect window = FRAMEWORK.GetWindowBounds();
	float scale = Utils::RandomRange(0.8f, 1.2f);
	moveType = Utils::RandomRange(0,2);
	setRotation(0);
	switch (side)
	{
	case Sides::Left:
		direction = { -1.f, 0.f };
		setScale({ scale, scale });
		setPosition({ window.width + 150.f, Utils::RandomRange(500.f, 800.f) });
		setSpeed(Utils::RandomRange(300.f, 500.f));
		break;
	case Sides::Right:
		direction = { 1.f, 0.f };
		setScale({ -scale, scale });
		setPosition({ -150.f, Utils::RandomRange(500.f, 800.f) });
		setSpeed(Utils::RandomRange(300.f, 500.f));
		break;
	}
}

void BackgroundBee::Reset()
{
	SpriteGO::Reset();

	setOrigin(Origins::MC);
	SetSide(Utils::ChooseSide());
	setPosition({ Utils::RandomRange(600.f, 1300.f), Utils::RandomRange(500.f, 800.f) });
}

void BackgroundBee::Update(float dt)
{
	auto pos = getPosition();
	pos += speed * direction * dt;
	if (moveType == 1)
	{
		float ySpeed = yspeed * std::cos(FRAMEWORK.GetRealTime() * 5);
		pos += ySpeed * yDirection * dt;

		if (direction == sf::Vector2f({ 1.f,0.f }))
		{
			setRotation(45.f * std::cos(FRAMEWORK.GetRealTime() * 5));
		}
		else
		{
			setRotation(-45.f * std::cos(FRAMEWORK.GetRealTime() * 5));
		}
	}
	setPosition(pos);

	sf::FloatRect window = FRAMEWORK.GetWindowBounds();

	if (pos.x < -200.f || pos.x > window.width + 200.f)
	{
		SetSide(Utils::ChooseSide());
	}
}