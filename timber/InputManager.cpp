#include <algorithm>
#include "InputManager.h"
#include <iostream>

std::list<sf::Keyboard::Key> InputManager::downKeys;
std::list<sf::Keyboard::Key> InputManager::heldKeys;
std::list<sf::Keyboard::Key> InputManager::upKeys;

void InputManager::Init()
{
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
			downKeys.push_back(ev.key.code);
			heldKeys.push_back(ev.key.code);
		}
		break;
	case sf::Event::KeyReleased:
		Remove(heldKeys, ev.key.code);
		upKeys.push_back(ev.key.code);
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

bool InputManager::Contains(const std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key)
{
	return std::find(list.begin(), list.end(), key) != list.end();
}

void InputManager::Remove(std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key)
{
	list.remove(key);
}
