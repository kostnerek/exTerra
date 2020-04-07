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
	
	

public:
	RectangleShape heroSprite;

	RectangleShape inventory;

	Texture heroTexture;
	Image heroImage;

	const Texture* ptHeroTexture = &heroTexture;

	Texture inventoryTexture;
	const Texture* ptInventoryTexture = &inventoryTexture;


	hero();

	void heroMove(short direction);
	void heroMove();

	void openInventory(bool isInvOpen);
};