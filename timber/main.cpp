#include "stdafx.h"
#include "SpriteGO.h"
#include "TextGO.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    TEXTURE_MGR.Load("graphics/player.png");
    FONT_MGR.Load("fonts/KOMIKAP_.ttf");

    SpriteGO spriteGo("graphics/player.png");
    spriteGo.Init();
    spriteGo.setOrigin(Origins::TC);
    spriteGo.Reset();

    TextGO textGo("fonts/KOMIKAP_.ttf");
    textGo.Init();
    textGo.setOrigin(Origins::MC);
    textGo.Reset();
    textGo.setText("test string");
    textGo.setPosition({ window.getSize().x /2.f, window.getSize().y / 2.f });

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
        textGo.Update(0);

        // draw
        window.clear();
        //window.draw(shape);
        spriteGo.Draw(window);
        textGo.Draw(window);
        window.display();
    }

    spriteGo.Release();

    return 0;
}