#pragma once

class Scene
{
protected:
	std::list<GameObject*> gameObjects;

public:
	const SceneIds Id;

	Scene(SceneIds Id);
	virtual ~Scene() = default;

	virtual void Init();
	virtual void Release();

	virtual void Enter();
	virtual void Exit();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);

	void AddGameObject(GameObject* go);
	void RemoveGameObject(GameObject* go);

	GameObject* findGameObject(const std::string& name);
};

