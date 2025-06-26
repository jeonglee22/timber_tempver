#include <SFML/Graphics.hpp>
#include <iostream>
#include "InputManager.h"
#include "ResourceMgr.h"
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    InputManager::Init();
    InputManager::GetKeyDown(sf::Keyboard::A);

    std::vector<std::string> files({
            "graphics/player.png",
            "graphics/player.png",
            "graphics/player.png",
            "graphics/player.png",
            "graphics/player.png",
            "graphics/player.png",
            "graphics/player.png"
        });

    ResourceMgr<sf::Texture>::Instance().Load(files);

    sf::Sprite player;
    player.setTexture(ResourceMgr<sf::Texture>::Instance().Get("graphics/player.png"));

    while (window.isOpen())
    {
        InputManager::Clear();
        InputManager::Init();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        
            InputManager::UpdateEvent(event);
        }

        // update
        InputManager::Update(0);

        if (InputManager::GetKeyDown(sf::Keyboard::A))
        {
            std::cout << "Key Down: A" << std::endl;
        }

        if (InputManager::GetKeyUp(sf::Keyboard::A))
        {
            std::cout << "Key Up: A" << std::endl;
        }

        // draw
        window.clear();
        //window.draw(shape);
        window.draw(player);
        window.display();
    }

    return 0;
}