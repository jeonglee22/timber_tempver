#include "stdafx.h"
#include "SceneGame.h"
#include "SpriteGO.h"
#include "TextGO.h"
#include "BackgroundElementGO.h"

SceneGame::SceneGame()
	:Scene(SceneIds::Game)
{

}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
    textIds.push_back("graphics/background.png");
    textIds.push_back("graphics/cloud.png");

    AddGameObject(new SpriteGO("graphics/background.png"));

    auto element = (BackgroundElementGO*) AddGameObject(new BackgroundElementGO("graphics/cloud.png"));
    element->setSpeed(100.f);
    element->setDirection({ 1.f,0.f });
    Scene::Init();
}

void SceneGame::Enter()
{
    Scene::Enter();

}

void SceneGame::Exit()
{
    Scene::Exit();

}