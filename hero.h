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


	Texture heroTexture;
	Image heroImage;

	const Texture* ptHeroTexture = &heroTexture;

	hero();
	
	void loadTexture();
	void heroMove();
};

