#include "stdafx.h"
#include "SpriteGO.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    TEXTURE_MGR.Load("graphics/player.png");

    SpriteGO spriteGo("graphics/player.png");
    spriteGo.Init();
    spriteGo.Reset();

    while (window.isOpen())
    {
        InputManager::Clear();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        
            InputManager::UpdateEvent(event);
        }

        // update
        InputManager::Update(0);
        spriteGo.Update(0);

        // draw
        window.clear();
        //window.draw(shape);
        spriteGo.Draw(window);
        window.display();
    }

    spriteGo.Release();

    return 0;
}