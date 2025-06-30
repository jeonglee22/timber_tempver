#include "stdafx.h"
#include "SceneDev2.h"
#include "TextGO.h"

SceneDev2::SceneDev2()
	:Scene(SceneIds::Dev2)
{
}

void SceneDev2::Init()
{
	fontIds.push_back("fonts/KOMIKAP_.ttf");

	TextGO* go = new TextGO("fonts/KOMIKAP_.ttf");
	go->setText("DEV 2");
	go->setOrigin(Origins::MC);
	go->setPosition({ 1366 / 2.f, 768 / 2.f });
	AddGameObject(go);

	Scene::Init();
}

void SceneDev2::Update(float dt)
{
	if (InputManager::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::Dev1);
	}
}