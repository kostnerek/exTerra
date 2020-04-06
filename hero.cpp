#include "hero.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <time.h>
#include <iostream>
using namespace std;
using namespace sf;

hero::hero()
{
	heroSprite.setSize(Vector2f(16, 32));
	heroImage.loadFromFile("textures/hero.png");
	heroMove();
}


void hero::loadTexture()
{
	heroTexture.loadFromFile("textures/hero.png");
}

void hero::heroMove()
{
	//heroSprite.setColor(color)
	IntRect still(0, 0, 12, 32);
	heroTexture.loadFromImage(heroImage, still);
	//heroSprite.setTextureRect(still);
	heroSprite.setTexture(ptHeroTexture);
}