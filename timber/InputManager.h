#pragma once
#include <list>
#include <vector>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>

class InputManager
{
private:
	/*static std::list<sf::Keyboard::Key> downKeys;
	static std::list<sf::Keyboard::Key> heldKeys;
	static std::list<sf::Keyboard::Key> upKeys;*/

	static std::vector<int> downKeys;
	static std::vector<int> heldKeys;
	static std::vector<int> upKeys;

public:
	static void Init();
	static void Clear();

	static void UpdateEvent(const sf::Event& ev);
	static void Update(float dt);

	static bool GetKeyDown(sf::Keyboard::Key key);
	static bool GetKeyUp(sf::Keyboard::Key key);
	static bool GetKey(sf::Keyboard::Key key);

	static bool Contains(const std::vector<int>& vector, sf::Keyboard::Key key);
	static void Remove(std::vector<int>& vector, sf::Keyboard::Key key);

};

