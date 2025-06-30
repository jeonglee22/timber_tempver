#include "stdafx.h"
#include "TreeGO.h"

void TreeGO::setPosition(const sf::Vector2f& pos)
{
	tree.setPosition(pos);
	for (int i = 0; i < branches.size(); i++)
	{
		branches[i].setPosition({pos.x, i * 150.f});
	}
}

void TreeGO::UpdateBranches()
{
}

void TreeGO::Init()
{
	textIdTree = "graphics/tree.png";
	textIdBranch = "graphics/branch.png";

	branches.resize(6);
	branchSides.resize(6);
}

void TreeGO::Release()
{
}

void TreeGO::Reset()
{
	tree.setTexture(TEXTURE_MGR.Get(textIdTree), true);
	Utils::SetOrigin(tree, Origins::TC);

	sf::FloatRect bound = tree.getLocalBounds();

	for (int i = 0; i < branches.size(); i++)
	{
		branches[i].setTexture(TEXTURE_MGR.Get(textIdBranch));
		branches[i].setOrigin(bound.width * -0.5f, 0.f);

		branchSides[i] = (Sides) Utils::RandomRange(0, 3);
		switch (branchSides[i])
		{
		case Sides::Right:
			branches[i].setScale(1.f, 1.f);
			break;
		case Sides::Left:
			branches[i].setScale(-1.f, 1.f);
			break;
		}
	}
	branchSides[branches.size() - 1] = Sides::None;
	sf::FloatRect windowBound = FRAMEWORK.GetWindowBounds();
	setPosition({windowBound.width * 0.5f, 0.f});
}

void TreeGO::Update(float dt)
{
}

void TreeGO::Draw(sf::RenderWindow& window)
{
	window.draw(tree);

	for (int i = 0; i < branches.size(); i++)
	{
		if (branchSides[i] != Sides::None)
		{
			window.draw(branches[i]);
		}
	}
}
