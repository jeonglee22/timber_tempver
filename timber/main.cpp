#include "stdafx.h"
#include "SpriteGO.h"
#include "TextGO.h"
#include "SceneGame.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML works!");

    TEXTURE_MGR.Load("graphics/player.png");
    FONT_MGR.Load("fonts/KOMIKAP_.ttf");

    SceneGame sceneGame;
    sceneGame.Init();
    sceneGame.Enter();

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
        sceneGame.Update(0);

        // draw
        window.clear();
        sceneGame.Draw(window);
        window.display();
    }

    sceneGame.Release();

    return 0;
}