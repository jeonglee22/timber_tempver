#include "stdafx.h"
#include "BackgroundElementGO.h"

BackgroundElementGO::BackgroundElementGO(const std::string& textid, const std::string& name)
	:SpriteGO(textid, name)
{

}

void BackgroundElementGO::Update(float dt)
{
	auto pos = getPosition();
	pos += speed * direction * dt;
	setPosition(pos);
}