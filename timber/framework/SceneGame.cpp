#include "stdafx.h"
#include "SceneGame.h"
#include "SpriteGO.h"
#include "TextGO.h"
#include "BackgroundElementGO.h"
#include "BackgroundBee.h"
#include "TreeGo.h"

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
    textIds.push_back("graphics/bee.png");
    textIds.push_back("graphics/tree.png");
    textIds.push_back("graphics/branch.png");

    AddGameObject(new SpriteGO("graphics/background.png"));

    for (int i = 0; i < 3; i++)
    {
        auto element = (BackgroundElementGO*)AddGameObject(new BackgroundElementGO("graphics/cloud.png"));
    }
   
    AddGameObject(new TreeGO());

    for (int i = 0; i< 2; i++)
    {
        auto beeEle = (BackgroundBee*)AddGameObject(new BackgroundBee("graphics/bee.png", "bee"));
    }

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