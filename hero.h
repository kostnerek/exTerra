#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <time.h>
#include <iostream>
using namespace std;
using namespace sf;

class hero
{
	
	Texture tDirt;
	Texture tGrass;
	Texture tOre1;
	Texture tOre2;
	Texture tOre3;
	Texture tOre4;
	Texture tStone;
	const Texture* ptDirt = &tDirt;
	const Texture* ptGrass = &tGrass;
	const Texture* ptOre1 = &tOre1;
	const Texture* ptOre2 = &tOre2;
	const Texture* ptOre3 = &tOre3;
	const Texture* ptOre4 = &tOre4;
	const Texture* ptStone = &tStone;

public:

	class inventoryClass
	{
	public:
		string type="none";
		int amount=0;
	};


	RectangleShape inventoryShape;
	Texture inventoryTexture;
	const Texture* ptInventoryTexture = &inventoryTexture;//cale inventory
	Texture emptyTexture;
	const Texture* ptEmptyTexture = &emptyTexture;


	RectangleShape heroSprite;
	Texture heroTexture;
	Image heroImage;

	const Texture* ptHeroTexture = &heroTexture;


	

	vector<vector<RectangleShape>>inventory;//inv
	vector<vector<inventoryClass>>inventoryNumbers;//matematyczna czesc

	Font font;
	vector<vector<Text>>shownValues;


	hero();

	void heroMove(short direction);
	void heroMove();

	void openInventory(bool isInvOpen);

	void inventorySetup();
	void inventoryNumbersSetup(string type, int amount, int x, int y);
	int inventoryNumbersSetup(string type, int amount);


	void updateInvTextures();


	void textSetup();
	
};



extern hero heroCharacter;