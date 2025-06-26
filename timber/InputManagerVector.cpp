#include <algorithm>
#include "InputManagerVector.h"
#include <iostream>

std::vector<int> InputManagerVector::downKeys(sf::Keyboard::KeyCount);
std::vector<int> InputManagerVector::heldKeys(sf::Keyboard::KeyCount);
std::vector<int> InputManagerVector::upKeys(sf::Keyboard::KeyCount);

void InputManagerVector::Init()
{
	downKeys.resize(sf::Keyboard::KeyCount);
	upKeys.resize(sf::Keyboard::KeyCount);
}

void InputManagerVector::Clear()
{
	downKeys.clear();
	upKeys.clear();
}

void InputManagerVector::UpdateEvent(const sf::Event& ev)
{
	switch (ev.type)
	{
	case sf::Event::KeyPressed:
		if (!Contains(heldKeys, ev.key.code))
		{
			downKeys[ev.key.code] = 1;
			heldKeys[ev.key.code] = 1;
		}
		break;
	case sf::Event::KeyReleased:
		if (Contains(heldKeys, ev.key.code))
		{
			heldKeys[ev.key.code] = 0;
			upKeys[ev.key.code] = 1;
		}
		break;
	}
	
}

void InputManagerVector::Update(float dt)
{

}

bool InputManagerVector::GetKeyDown(sf::Keyboard::Key key)
{
	return Contains(downKeys, key);
}

bool InputManagerVector::GetKeyUp(sf::Keyboard::Key key)
{
	return Contains(upKeys, key);
}

bool InputManagerVector::GetKey(sf::Keyboard::Key key)
{
	return Contains(heldKeys, key);
}

bool InputManagerVector::Contains(const std::vector<int>& vector, sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Unknown)
	{
		return false;
	}
	return vector[key];
}

void InputManagerVector::Remove(std::vector<int>& vector, sf::Keyboard::Key key)
{
	if (key != sf::Keyboard::Unknown)
	{
		vector[key] = 0;
	}
}
