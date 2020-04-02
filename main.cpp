#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include <time.h>
#include <thread>
#include <mutex>

#include "tile.h"

using namespace sf;
using namespace std;





float g_height = 480;
float g_width = 640;

bool gameLoad;

void loadingScreen()
{
	RectangleShape splashScreen;

	splashScreen.setSize(Vector2f(g_height, g_width));

	Texture tSplashScreen;
	const Texture* ptSplashScreen = &tSplashScreen;

	tSplashScreen.loadFromFile("texture/splashScreen.png");

	splashScreen.setTexture(ptSplashScreen);

	splashScreen.setPosition(0, 0);
}




vector<vector<tile>>mesh;
float blockWidth = 16.0;
float blockHeight = 16.0;

int xField = 100;
int yField = 100;

int blockAmount = xField * yField;


Texture tDirt;
Texture tGrass;
Texture tOre1;
Texture tOre2;
Texture tOre3;
Texture tOre4;
Texture tStone;
Texture tWhite;


Texture* ptDirt;
Texture* ptGrass;
Texture* ptOre1;
Texture* ptOre2;
Texture* ptOre3;
Texture* ptOre4;
Texture* ptStone;
Texture* ptWhite;


void worldGenerate()
{
	

	/*
	dirt
	grassDirt
	ore1
	ore2
	ore3
	ore4
	stone
	*/

	float dirtCount = 0;
	float grassCount = 0;
	float stoneCount = 0;
	float ore1Count = 0;
	float ore2Count = 0;
	float ore3Count = 0;
	float ore4Count = 0;
	mesh.resize(xField, vector<tile>(yField));

	srand(time(NULL));



	//==============================================================================
	int start = clock();
	for (int x = 1; x < xField; x++)
	{
		for (int y = 1; y < yField; y++)
		{

			tile piece(16, 16);

			int random = rand() % 100;


			if (random >= 0 && random <= 20)//&& y>=2&&y<=20)
			{
				dirtCount++;

				piece.type = "dirt";
				//piece.tileShape.setTexture(ptDirt);
				piece.tileShape.setFillColor(Color::Blue);

			}
			if (random > 20 && random <= 70)
			{
				stoneCount++;

				piece.type = "stone";
				piece.tileShape.setTexture(&ptStone);
			}
			if (random > 70 && random <= 82)
			{
				ore1Count++;

				piece.type = "ore1";
				piece.tileShape.setTexture(ptOre1);
			}
			if (random > 82 && random <= 89)
			{
				ore2Count++;

				piece.type = "ore2";
				piece.tileShape.setTexture(ptOre2);
			}
			if (random > 89 && random <= 95)
			{
				ore3Count++;

				piece.type = "ore3";
				piece.tileShape.setTexture(ptOre3);
			}
			if (random > 95 && random <= 100)
			{
				ore4Count++;

				piece.type = "ore4";
				piece.tileShape.setTexture(ptOre4);
			}

			if (y == 1)
			{
				grassCount++;

				piece.type = "grass";
				piece.tileShape.setTexture(ptGrass);
			}

			piece.tileShape.setPosition(x*blockHeight, y*blockWidth);
			mesh[x][y] = piece;
		}
	}


	for (int x = 0; x < xField; x++)
	{
		tile piece;
		piece.height = blockHeight;
		piece.width = blockWidth;

		piece.tileShape.setTexture(ptWhite);

		piece.tileShape.setPosition(x * blockHeight, 0 * blockWidth);
		mesh[x][0] = piece;
	}
	int stop = clock();
	//====================================================================


	cout << "All loaded" << endl;

	cout << "=============================" << endl;
	cout << "Dirt: " << dirtCount / blockAmount * 100 << endl;
	cout << "Grass: " << grassCount / blockAmount * 100 << endl;
	cout << "Stone: " << stoneCount / blockAmount * 100 << endl;
	cout << "Ore1: " << ore1Count / blockAmount * 100 << endl;
	cout << "Ore2: " << ore2Count / blockAmount * 100 << endl;
	cout << "Ore3: " << ore3Count / blockAmount * 100 << endl;
	cout << "Ore4: " << ore4Count / blockAmount * 100 << endl;
	cout << "Generation time: " << (stop - start) / 1000.0 << "s" << endl;
	cout << "=============================" << endl;
}


int main()
{
	Texture* ptDirt = &tGrass;
	Texture* ptGrass = &tGrass;
	Texture* ptOre1 = &tOre1;
	Texture* ptOre2 = &tOre2;
	Texture* ptOre3 = &tOre3;
	Texture* ptOre4 = &tOre4;
	Texture* ptStone = &tStone;
	Texture* ptWhite = &tWhite;


	tDirt.loadFromFile("textures/dirt.png");
	tGrass.loadFromFile("textures/grassDirt.png");
	tOre1.loadFromFile("textures/ore1.png");
	tOre2.loadFromFile("textures/ore2.png");
	tOre3.loadFromFile("textures/ore3.png");
	tOre4.loadFromFile("textures/ore4.png");
	tStone.loadFromFile("textures/stone.png");
	tWhite.loadFromFile("textures/white.png");


	//float blockWidth = 16.0;
	//float blockHeight = 16.0;

	//int xField = 1000;
	//int yField = 100;

	//int blockAmount = xField * yField;

	//float offsetX = 5;
	//float offsetY = 5;


	//mesh.resize(xField, vector<tile>(yField));

	///*
	//dirt
	//grassDirt
	//ore1
	//ore2
	//ore3
	//ore4
	//stone
	//*/

	//float dirtCount  = 0;
	//float grassCount = 0;
	//float stoneCount = 0;
	//float ore1Count  = 0;
	//float ore2Count  = 0;
	//float ore3Count  = 0;
	//float ore4Count  = 0;


	//srand(time(NULL));
	//

	//
	////==============================================================================
	//int start = clock();
	//for (int x = 1; x < xField; x++)
	//{
	//	for (int y = 1; y < yField; y++)
	//	{

	//		tile piece(16,16);

	//		int random = rand() % 100;


	//		if (random >= 0 && random <= 20 )//&& y>=2&&y<=20)
	//		{
	//			dirtCount++;

	//			piece.type = "dirt";
	//			piece.tileShape.setTexture(ptDirt);
	//		}
	//		if (random > 20 && random <= 70)
	//		{
	//			stoneCount++;

	//			piece.type = "stone";
	//			piece.tileShape.setTexture(ptStone);
	//		}
	//		if (random > 70 && random <=82 )
	//		{
	//			ore1Count++;

	//			piece.type = "ore1";
	//			piece.tileShape.setTexture(ptOre1);
	//		}
	//		if (random>82&&random<=89)
	//		{
	//			ore2Count++;

	//			piece.type = "ore2";
	//			piece.tileShape.setTexture(ptOre2);
	//		}
	//		if (random > 89 && random <= 95)
	//		{
	//			ore3Count++;

	//			piece.type = "ore3";
	//			piece.tileShape.setTexture(ptOre3);
	//		}
	//		if (random > 95 && random <= 100)
	//		{
	//			ore4Count++;

	//			piece.type = "ore4";
	//			piece.tileShape.setTexture(ptOre4);
	//		}

	//		if (y == 1)
	//		{
	//			grassCount++;

	//			piece.type = "grass";
	//			piece.tileShape.setTexture(ptGrass);
	//		}
	//		
	//		piece.tileShape.setPosition(x*blockHeight, y*blockWidth);
	//		mesh[x][y] = piece;
	//	}
	//}
	//

	//for (int x = 0; x < xField; x++)
	//{
	//	tile piece;
	//	piece.height = blockHeight;
	//	piece.width = blockWidth;

	//	piece.tileShape.setTexture(ptWhite);

	//	piece.tileShape.setPosition(x * blockHeight, 0 * blockWidth);
	//	mesh[x][0] = piece;
	//}
	//int stop = clock();
	////====================================================================

	//cout << "All loaded" << endl;

	//cout << "=============================" << endl;
	//cout << "Dirt: " << dirtCount   / blockAmount * 100 << endl;
	//cout << "Grass: " << grassCount / blockAmount * 100 << endl;
	//cout << "Stone: " << stoneCount / blockAmount * 100 << endl;
	//cout << "Ore1: " << ore1Count   / blockAmount * 100 << endl;
	//cout << "Ore2: " << ore2Count   / blockAmount * 100 << endl;
	//cout << "Ore3: " << ore3Count   / blockAmount * 100 << endl;
	//cout << "Ore4: " << ore4Count   / blockAmount * 100 << endl;
	//cout << "Generation time: " << (stop - start) / 1000.0 << "s" << endl;
	//cout << "=============================" << endl;

	worldGenerate();


	RenderWindow window(sf::VideoMode(g_width, g_height), "tesciory");//100

	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	sf::View visibleArea(FloatRect(g_width/2, 0.f, g_width, g_height));


	//=========================================================
	RectangleShape test;

	test.setFillColor(Color::Black);
	test.setSize(Vector2f(20.f,20.f));


	//RectangleShape leftRect;
	//RectangleShape rightRect;
	//RectangleShape upRect;
	//RectangleShape downRect;
	//
	//
	//leftRect.setFillColor(Color::Black);
	//rightRect.setFillColor(Color::Black);
	//upRect.setFillColor(Color::Red);
	//downRect.setFillColor(Color::Black);
	//
	//leftRect.setSize(Vector2f(20.f, 20.f));
	//rightRect.setSize(Vector2f(20.f, 20.f));
	//upRect.setSize(Vector2f(20.f, 20.f));
	//downRect.setSize(Vector2f(20.f, 20.f));
	//=========================================================


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			//==============================================================================================================================
			if (event.type == Event::KeyPressed)
			{
				
			}

			if (event.type == sf::Event::MouseWheelMoved)
			{
				if (event.mouseWheel.delta == 1)
				{
					for (int x = 0; x < xField; x++)
					{
						for (int y = 0; y < yField; y++)
						{
							mesh[x][y].tileShape.setSize(Vector2f(mesh[x][y].tileShape.getSize().x + 0.5, mesh[x][y].tileShape.getSize().y + 0.5));
							mesh[x][y].tileShape.setPosition(Vector2f(mesh[x][y].tileShape.getPosition().x + 0.5*x, mesh[x][y].tileShape.getPosition().y + 0.5*y));
						}
					}
				}
				if (event.mouseWheel.delta == -1)
				{
					for (int x = 0; x < xField; x++)
					{
						for (int y = 0; y < yField; y++)
						{
							mesh[x][y].tileShape.setSize(Vector2f(mesh[x][y].tileShape.getSize().x - 0.5, mesh[x][y].tileShape.getSize().y - 0.5));
							mesh[x][y].tileShape.setPosition(Vector2f(mesh[x][y].tileShape.getPosition().x - 0.5*x, mesh[x][y].tileShape.getPosition().y - 0.5*y));
						}
					}
				}

			}
		}


		// activate it
		window.setView(visibleArea);


		View currentView = window.getView();


		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			visibleArea.move(0, -5);
			test.setPosition(currentView.getCenter().x, currentView.getCenter().y);
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			visibleArea.move(0, 5);
			test.setPosition(currentView.getCenter().x, currentView.getCenter().y);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			visibleArea.move(5, 0);
			test.setPosition(currentView.getCenter().x, currentView.getCenter().y);
		}

		if (Keyboard::isKeyPressed(Keyboard::C))
		{
			float fovX = currentView.getCenter().x;
			float fovY = currentView.getCenter().y;


			float leftFovEdge = fovX - (g_width / 2);
			float rightFovEdge = fovX + (g_width / 2);
			float upFovEdge = fovY - (g_height / 2);
			float downFovEdge = fovY + (g_height / 2);

			cout << "===============================================\n";
			cout << "fovX: " << fovX << endl;
			cout << "fovY: " << fovY << endl<<endl;
			cout << "Left: " << leftFovEdge << endl;
			cout << "Right: " << rightFovEdge << endl;
			cout << "Up: " << upFovEdge << endl;
			cout << "Down: " << downFovEdge << endl;
			cout << "===============================================\n";
		}


		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			test.setPosition(currentView.getCenter().x, currentView.getCenter().y);
			visibleArea.move(-5, 0);
		}


		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}


		window.clear(Color::White);
		
		
		float fovX = currentView.getCenter().x;
		float fovY = currentView.getCenter().y;
		
		float leftFovEdge = fovX - (g_width / 2);
		float rightFovEdge = fovX + (g_width / 2);
		float upFovEdge = fovY + (g_height / 2);
		float downFovEdge = fovY - (g_height / 2);

		int start = clock();
		for (int x = 0; x < xField; x++)
		{
			for (int y = 0; y < yField; y++)
			{
				float meshX = mesh[x][y].tileShape.getPosition().x;
				float meshY = mesh[x][y].tileShape.getPosition().y;
				//mesh[x][y].tileShape.setPosition(mesh[x][y].tileShape.getPosition().x + offsetX, mesh[x][y].tileShape.getPosition().y + offsetY);

				//currentView.getCenter().x, currentView.getCenter().y

				
				//window.draw(mesh[x][y].tileShape);
				if (meshX>=leftFovEdge-40 && meshX<=rightFovEdge && meshY<=upFovEdge+40 && meshY >=downFovEdge-40)
				{
					window.draw(mesh[x][y].tileShape);
				}
				else
				{
					continue;
				}
			}
		}
		int stop = clock();
		
		
		//window.draw(test);
		
		
		//window.draw(leftRect);
		//window.draw(rightRect);
		//window.draw(upRect);
		//window.draw(downRect);
		//cout << "Time: " << stop - start << " " << endl;
		
		window.display();
	}

	return 0;
}