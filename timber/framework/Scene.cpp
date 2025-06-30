#include "stdafx.h"
#include "Scene.h"

Scene::Scene(SceneIds Id)
	: Id(Id)
{

}

void Scene::Init()
{
	for (auto obj : gameObjects)
	{
		obj->Init();
	}
}

void Scene::Release()
{
	for (auto obj : gameObjects)
	{
		obj->Release();
		delete obj;
	}
	gameObjects.clear();
}

void Scene::Enter()
{
	TEXTURE_MGR.Load(textIds);
	FONT_MGR.Load(fontIds);
	SOUNDBUFFER_MGR.Load(soundIds);

	for (auto obj : gameObjects)
	{
		obj->Reset();
	}
}

void Scene::Exit()
{
	TEXTURE_MGR.UnLoad(textIds);
	FONT_MGR.UnLoad(fontIds);
	SOUNDBUFFER_MGR.UnLoad(soundIds);
}

void Scene::Update(float dt)
{
	for (auto obj : gameObjects)
	{
		obj->Update(dt);
	}
}

void Scene::Draw(sf::RenderWindow& window)
{
	for (auto obj : gameObjects)
	{
		obj->Draw(window);
	}
}

void Scene::AddGameObject(GameObject* go)
{
	if(std::find(gameObjects.begin(), gameObjects.end(), go) == gameObjects.end())
	{
		gameObjects.push_back(go);
	}
}

void Scene::RemoveGameObject(GameObject* go)
{
	gameObjects.remove(go);
}

GameObject* Scene::findGameObject(const std::string& name)
{
	for (auto obj : gameObjects)
	{
		if (obj->getName() == name)
		{
			return obj;
		}
	}
	return nullptr;
}