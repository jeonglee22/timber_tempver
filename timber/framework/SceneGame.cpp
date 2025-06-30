#include "stdafx.h"
#include "SceneGame.h"
#include "SpriteGO.h"
#include "TextGO.h"

SceneGame::SceneGame()
	:Scene(SceneIds::Game)
{

}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
    textIds.push_back("graphics/player.png");
    fontIds.push_back("fonts/KOMIKAP_.ttf");

    SpriteGO* spriteGo = new SpriteGO("graphics/player.png");
    spriteGo->setOrigin(Origins::TC);

    TextGO* textGo = new TextGO("fonts/KOMIKAP_.ttf");
    textGo->setOrigin(Origins::MC);
    textGo->setFontSize(100);
    textGo->setText("test string");
    textGo->setPosition({ 1366 / 2.f, 768 / 2.f });

    AddGameObject(spriteGo);
    AddGameObject(textGo);

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