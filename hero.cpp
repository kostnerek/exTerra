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
	heroSprite.setOrigin(Vector2f(8, 16));
	heroImage.loadFromFile("textures/hero.png");
	heroMove();


	inventory.setSize(Vector2f(560, 400));
	//inventory.setFillColor(Color::Magenta);
	inventoryTexture.loadFromFile("textures/inventory.png");
	inventory.setTexture(ptInventoryTexture);
}




void hero::heroMove(short direction)
{
	Clock clock;

	IntRect still(0, 0, 12, 32);

	IntRect leftStill(0, 32, 12, 32);
	IntRect leftMove(12, 32, 12, 32);

	IntRect rightStill(0, 64, 12, 32);
	IntRect rightMove(12, 64, 12, 32);

	//heroTexture.loadFromImage(heroImage, still);
	//heroTexture.loadFromImage(heroImage, rightStill);
	//heroTexture.loadFromImage(heroImage, rightMove);
	//heroTexture.loadFromImage(heroImage, leftStill);
	//heroTexture.loadFromImage(heroImage, leftMove);

	
	switch (direction)
	{
		case 0: //skok
		{
			heroSprite.move(0,-5);
			break;
		}
		case 1://lewo
		{
			heroSprite.move(-5,0);
			break;
		}
		case 2://prawo
		{
			heroSprite.move(5,0);
			break;
		}
		case 3://lewo
		{
			heroSprite.move(0,5);
			break;
		}
	}

	
	heroSprite.setTexture(ptHeroTexture);
}

void hero::heroMove()
{
	IntRect still(0, 0, 12, 32);
	heroTexture.loadFromImage(heroImage, still);
	heroSprite.setTexture(ptHeroTexture);
}

void hero::openInventory(bool isInvOpen)
{
	cout << isInvOpen << endl;


}
