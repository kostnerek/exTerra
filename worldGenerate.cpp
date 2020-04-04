#include "worldGenerate.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <time.h>
#include <iostream>

using namespace std;
using namespace sf;


worldGenerate::worldGenerate(int worldWidth, int worldHeight, int blockSize):worldHeight(worldHeight), worldWidth(worldWidth), blockSize(blockSize)
{
	this->blockAmount = worldHeight * worldWidth;
	loadTextures();
	generate();
}

void worldGenerate::loadTextures()
{
	tDirt.loadFromFile("textures/dirt.png");
	tGrass.loadFromFile("textures/grassDirt.png");
	tOre1.loadFromFile("textures/ore1.png");
	tOre2.loadFromFile("textures/ore2.png");
	tOre3.loadFromFile("textures/ore3.png");
	tOre4.loadFromFile("textures/ore4.png");
	tStone.loadFromFile("textures/stone.png");
	tWhite.loadFromFile("textures/white.png");
}


void worldGenerate::showGenStats()
{
	cout << "All loaded" << endl;

	cout << "=============================" << endl;
	cout << "Dirt: " << dirtCount / blockAmount * 100 << endl;
	cout << "Grass: " << grassCount / blockAmount * 100 << endl;
	cout << "Stone: " << stoneCount / blockAmount * 100 << endl;
	cout << "Ore1: " << ore1Count / blockAmount * 100 << endl;
	cout << "Ore2: " << ore2Count / blockAmount * 100 << endl;
	cout << "Ore3: " << ore3Count / blockAmount * 100 << endl;
	cout << "Ore4: " << ore4Count / blockAmount * 100 << endl;
	cout << "Generation time: " << (stopClock - startClock) / 1000.0 << "s" << endl;
	cout << "=============================" << endl;
}

void worldGenerate::generate()
{
	worldStructure.resize(this->worldWidth, vector<tile>(this->worldHeight));
	srand(time(NULL));

	this->startClock = clock();
	for (int x = 1; x < this->worldWidth; x++)
	{
		for (int y = 1; y < this->worldHeight; y++)
		{

			tile element(blockSize, blockSize);

			int random = rand() % 100;


			if (random >= 0 && random <= 20)
			{
				dirtCount++;

				element.type = "dirt";
				element.tileShape.setTexture(ptDirt);
				//element.tileShape.setFillColor(Color::Blue);

			}
			if (random > 20 && random <= 70)
			{
				stoneCount++;

				element.type = "stone";
				element.tileShape.setTexture(ptStone);
			}
			if (random > 70 && random <= 82)
			{
				ore1Count++;

				element.type = "ore1";
				element.tileShape.setTexture(ptOre1);
			}
			if (random > 82 && random <= 89)
			{
				ore2Count++;

				element.type = "ore2";
				element.tileShape.setTexture(ptOre2);
			}
			if (random > 89 && random <= 95)
			{
				ore3Count++;

				element.type = "ore3";
				element.tileShape.setTexture(ptOre3);
			}
			if (random > 95 && random <= 100)
			{
				ore4Count++;

				element.type = "ore4";
				element.tileShape.setTexture(ptOre4);
			}

			if (y == 1)
			{
				grassCount++;

				element.type = "grass";
				element.tileShape.setTexture(ptGrass);
			}

			element.tileShape.setPosition(x * blockSize, y * blockSize);
			worldStructure[x][y] = element;
		}
	}


	for (int x = 0; x < worldWidth; x++)
	{
		tile element;
		element.height = blockSize;
		element.width = blockSize;

		element.tileShape.setTexture(ptWhite);

		element.tileShape.setPosition(x * blockSize, 0 );
		worldStructure[x][0] = element;
	}
	this->stopClock = clock();


}