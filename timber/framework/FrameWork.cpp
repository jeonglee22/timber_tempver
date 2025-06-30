#include "stdafx.h"
#include "FrameWork.h"

void FrameWork::Init(int w, int h, const std::string& t)
{
	window.create(sf::VideoMode(w, h), t);

	TEXTURE_MGR.Load(textIds);
	FONT_MGR.Load(fontIds);
	SOUNDBUFFER_MGR.Load(soundIds);

	InputManager::Init();
	SCENE_MGR.Init();
}

void FrameWork::Do()
{
    while (window.isOpen())
    {
        sf::Time dt = clock.restart();
        realDeltaTime = dt.asSeconds();
        deltaTime = realDeltaTime * timeScale;
        time += deltaTime;
        realTime += realDeltaTime;

        InputManager::Clear();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            InputManager::UpdateEvent(event);
        }

        // update
        InputManager::Update(deltaTime);
        SCENE_MGR.Update(deltaTime);

        // draw
        window.clear();
        SCENE_MGR.Draw(window);
        window.display();
    }
}

void FrameWork::Release()
{
	SCENE_MGR.Release();

	SOUNDBUFFER_MGR.UnLoad(soundIds);
	FONT_MGR.UnLoad(fontIds);
	TEXTURE_MGR.UnLoad(textIds);
}