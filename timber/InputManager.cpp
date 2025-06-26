#include <algorithm>
#include "InputManager.h"
#include <iostream>

//std::list<sf::Keyboard::Key> InputManager::downKeys;
//std::list<sf::Keyboard::Key> InputManager::heldKeys;
//std::list<sf::Keyboard::Key> InputManager::upKeys;

std::vector<int> InputManager::downKeys(sf::Keyboard::KeyCount);
std::vector<int> InputManager::heldKeys(sf::Keyboard::KeyCount);
std::vector<int> InputManager::upKeys(sf::Keyboard::KeyCount);

void InputManager::Init()
{
	downKeys.resize(sf::Keyboard::KeyCount);
	upKeys.resize(sf::Keyboard::KeyCount);
}

void InputManager::Clear()
{
	downKeys.clear();
	upKeys.clear();
}

void InputManager::UpdateEvent(const sf::Event& ev)
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

void InputManager::Update(float dt)
{

}

bool InputManager::GetKeyDown(sf::Keyboard::Key key)
{
	return Contains(downKeys, key);
}

bool InputManager::GetKeyUp(sf::Keyboard::Key key)
{
	return Contains(upKeys, key);
}

bool InputManager::GetKey(sf::Keyboard::Key key)
{
	return Contains(heldKeys, key);
}

bool InputManager::Contains(const std::vector<int>& vector, sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Unknown)
	{
		return false;
	}
	return vector[key];
}

void InputManager::Remove(std::vector<int>& vector, sf::Keyboard::Key key)
{
	if (key != sf::Keyboard::Unknown)
	{
		vector[key] = 0;
	}
	
}
