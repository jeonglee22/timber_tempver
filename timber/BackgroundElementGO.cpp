#include "stdafx.h"
#include "BackgroundElementGO.h"

BackgroundElementGO::BackgroundElementGO(const std::string& textid, const std::string& name)
	:SpriteGO(textid, name)
{
}

void BackgroundElementGO::SetSide(Sides side)
{
	sf::FloatRect window = FRAMEWORK.GetWindowBounds();
	float scale = Utils::RandomRange(0.5f, 1.5f);
	switch(side)
	{
	case Sides::Left:
		direction = { -1.f, 0.f };
		setScale({ scale, scale });
		setPosition({ window.width + 150.f, Utils::RandomRange(100.f, 400.f) });
		setSpeed(Utils::RandomRange(300.f, 500.f));
		break;
	case Sides::Right:
		direction = { 1.f, 0.f };
		setScale({ -scale, scale });
		setPosition({ -150.f, Utils::RandomRange(100.f, 400.f) });
		setSpeed(Utils::RandomRange(300.f, 500.f));
		break;
	}
}

Sides BackgroundElementGO::chooseSide()
{
	if (Utils::RandomValue() < 0.5f)
		return Sides::Left;
	else
		return Sides::Right;
}

void BackgroundElementGO::Reset()
{
	SpriteGO::Reset();

	setOrigin(Origins::MC);
	SetSide(chooseSide());
	setPosition({ Utils::RandomRange(600.f, 1300.f), Utils::RandomRange(100.f, 400.f) });
}

void BackgroundElementGO::Update(float dt)
{
	auto pos = getPosition();
	pos += speed * direction * dt;
	setPosition(pos);

	sf::FloatRect window = FRAMEWORK.GetWindowBounds();

	if (pos.x < -200.f || pos.x > window.width + 200.f)
	{
		SetSide(chooseSide());
	}
}