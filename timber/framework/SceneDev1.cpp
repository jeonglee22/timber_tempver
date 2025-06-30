#include "stdafx.h"
#include "SceneDev1.h"
#include "TextGO.h"

SceneDev1::SceneDev1()
	:Scene(SceneIds::Dev1)
{
}

void SceneDev1::Init()
{
	fontIds.push_back("fonts/KOMIKAP_.ttf");

	TextGO* go = new TextGO("fonts/KOMIKAP_.ttf");
	go->setText("DEV 1");
	go->setOrigin(Origins::MC);
	go->setPosition({ 1366 / 2.f, 768 / 2.f });
	AddGameObject(go);

	Scene::Init();
}

void SceneDev1::Update(float dt)
{
	if (InputManager::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::Dev2);
	}
	Scene::Update(0);
}