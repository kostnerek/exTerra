#include "hero.h"
#include "worldGenerate.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <time.h>
#include <iostream>
using namespace std;
using namespace sf;

hero heroCharacter;


hero::hero()
{
	tDirt.loadFromFile("textures/dirtInv.png");
	tGrass.loadFromFile("textures/grassDirtInv.png");
	tOre1.loadFromFile("textures/ore1Inv.png");
	tOre2.loadFromFile("textures/ore2Inv.png");
	tOre3.loadFromFile("textures/ore3Inv.png");
	tOre4.loadFromFile("textures/ore4Inv.png");
	tStone.loadFromFile("textures/stoneInv.png");





	heroSprite.setSize(Vector2f(16, 32));
	heroSprite.setOrigin(Vector2f(8, 16));


	heroImage.loadFromFile("textures/hero.png");
	heroMove();


	inventoryShape.setSize(Vector2f(560, 400));
	inventoryTexture.loadFromFile("textures/inventory.png");
	inventoryShape.setTexture(ptInventoryTexture);


	inventory.resize(5, vector<RectangleShape>(4));
	inventoryNumbers.resize(5, vector<inventoryClass>(4));

	emptyTexture.create(84, 84);


	font.loadFromFile("arial.ttf");
	shownValues.resize(5, vector<Text>(4));
	
}



void hero::inventorySetup()
{
	

	RectangleShape invTile;
	invTile.setSize(Vector2f(84, 84));
	
	float invX = inventoryShape.getPosition().x+12.5;
	float invY = inventoryShape.getPosition().y+12.5;

	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			invTile.setPosition(Vector2f(invX + (13 * x)+84*x+x, invY + (12.5 * y)+84*y));
			invTile.setTexture(ptEmptyTexture);
			inventory[x][y] = invTile;
		}
	}
	updateInvTextures();
}

void hero::updateInvTextures()
{

	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (inventoryNumbers[x][y].type == "dirt") { inventory[x][y].setTexture(ptDirt); }
			if (inventoryNumbers[x][y].type == "grass") { inventory[x][y].setTexture(ptGrass); }
			if (inventoryNumbers[x][y].type == "stone") { inventory[x][y].setTexture(ptStone); }
			if (inventoryNumbers[x][y].type == "ore1") { inventory[x][y].setTexture(ptOre1); }
			if (inventoryNumbers[x][y].type == "ore2") { inventory[x][y].setTexture(ptOre2); }
			if (inventoryNumbers[x][y].type == "ore3") { inventory[x][y].setTexture(ptOre3); }
			if (inventoryNumbers[x][y].type == "ore4") { inventory[x][y].setTexture(ptOre4); }
		}
		
	}
}

void hero::textSetup()
{

	float invX = inventoryShape.getPosition().x + 12.5;
	float invY = inventoryShape.getPosition().y + 12.5;
	
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			Text textAmount;
			textAmount.setFont(font);
			textAmount.setCharacterSize(20);
			
			textAmount.setFillColor(Color::Black);

			if (inventoryNumbers[x][y].amount != 0)
			{
				string value = to_string(inventoryNumbers[x][y].amount);


				textAmount.setString(value);
			}
			else
			{
				textAmount.setString("");
			}


			

			textAmount.setPosition(Vector2f(invX + (13 * x) + 84 * x + x, invY + (12.5 * y) + 84 * y));

			shownValues[x][y] = textAmount;

		}
	}
}



void hero::inventoryNumbersSetup(string type, int amount, int x, int y)
{
	inventoryClass element;
	element.type = type;
	element.amount = amount;
	inventoryNumbers[x][y] = element;
}

int hero::inventoryNumbersSetup(string type, int amount)
{
	
	inventoryClass element;
	element.type = type;
	

	if (amount == 0)
	{
		return 0;
	}

	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (inventoryNumbers[x][y].amount == 0 || inventoryNumbers[x][y].type==type)
			{

				element.amount = amount+ inventoryNumbers[x][y].amount;
				inventoryNumbers[x][y] = element;

				return 0;

			}
		}
	}
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


}

