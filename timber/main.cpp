#include "stdafx.h"
#include "SpriteGO.h"
#include "TextGO.h"
#include "SceneGame.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML works!");

    TEXTURE_MGR.Load("graphics/player.png");
    FONT_MGR.Load("fonts/KOMIKAP_.ttf");

    SCENE_MGR.Init();

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
        SCENE_MGR.Update(0);

        // draw
        window.clear();
        SCENE_MGR.Draw(window);
        window.display();
    }

    SCENE_MGR.Release();

    return 0;
}