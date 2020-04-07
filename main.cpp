#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include <time.h>
#include <thread>
#include <mutex>
#include <math.h>

#include "worldGenerate.h"
#include "tile.h"
#include "hero.h"

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


float blockWidth = 16.0;
float blockHeight = 16.0;

int blockSize = 16;

int worldWidth = 100;
int worldHeight = 100;

float scale = 0.5;

short moveHero = -1;

bool isInvOpen = false;


int main()
{
	worldGenerate world(worldWidth, worldHeight, blockSize);
	world.showGenStats();


	RenderWindow window(VideoMode(g_width, g_height), "exTerra"); // 100

	window.setFramerateLimit(60);
	//window.setVerticalSyncEnabled(true);

	View visibleArea(FloatRect(/*g_width / 2*/0.f, 0.f, g_width, g_height));


	//=====================hero===================================

	hero heroCharacter;


	float heroDistanceOrigin = heroCharacter.heroSprite.getPosition().x;


	RectangleShape test;
	test.setFillColor(Color::Black);
	test.setPosition(0, 0);
	test.setSize(Vector2f(10, 10));


	//============================================================
	RectangleShape mousePoint;
	mousePoint.setSize(Vector2f(1, 1));
	//mousePoint.setPosition(mousePos);
	

	heroCharacter.heroSprite.setPosition(250, 250);


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Escape)
				{
					window.close();
				}

				if (event.key.code == Keyboard::E)
				{
					if (isInvOpen == true)
					{
						heroCharacter.openInventory(false);
						isInvOpen = false;
						break;
					}
					if(isInvOpen==false)
					{
						heroCharacter.openInventory(true);
						isInvOpen = true;
					}
				}
			}


			if (event.type == Event::MouseButtonPressed && isInvOpen==false)
			{
				if (event.key.code == Mouse::Left)
				{
					//Vector2i mousePos = Mouse::getPosition();
					mousePoint.setPosition(Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y));
					mousePoint.setFillColor(Color::Black);
					
					cout << Mouse::getPosition(window).x << " " << Mouse::getPosition(window).y << endl;

					for (int x = 0; x < worldWidth; x++)
					{
						for (int y = 0; y < worldHeight; y++)
						{
							if (world.worldStructure[x][y].tileShape.getGlobalBounds().intersects(mousePoint.getGlobalBounds())==true )
							{
								cout << x << "," << y << endl;
								if (abs(heroCharacter.heroSprite.getPosition().x - world.worldStructure[x][y].tileShape.getPosition().x) <= world.worldStructure[x][y].tileShape.getSize().x * 4)
								{
									if (abs(heroCharacter.heroSprite.getPosition().y - world.worldStructure[x][y].tileShape.getPosition().y) <= world.worldStructure[x][y].tileShape.getSize().y * 4)
									{
										world.worldStructure[x].erase(world.worldStructure[x].begin() + y);
									}
								}
							}
							//break;
						}
					}
				}
			}
			//scroll
			if (event.type == sf::Event::MouseWheelMoved)
			{
				float SizeX = world.worldStructure[0][0].tileShape.getSize().x;
				float SizeY = world.worldStructure[0][0].tileShape.getSize().y;

				float PositionHeroX = heroCharacter.heroSprite.getPosition().x;
				float PositionHeroY = heroCharacter.heroSprite.getPosition().y;
				float SizeHeroX = heroCharacter.heroSprite.getSize().x;
				float SizeHeroY = heroCharacter.heroSprite.getSize().y;
				
				if (event.mouseWheel.delta == 1)
				{
					for (int x = 0; x < worldWidth; x++)
					{
						for (int y = 0; y < worldHeight; y++)
						{
							world.worldStructure[x][y].tileShape.setPosition(Vector2f(world.worldStructure[x][y].tileShape.getPosition().x + 0.5 * x, world.worldStructure[x][y].tileShape.getPosition().y + 0.5 * y));
							world.worldStructure[x][y].tileShape.setSize(Vector2f(SizeX + 0.5, SizeY + 0.5));
						}
					}

					//scale = blockSize / world.worldStructure[0][0].tileShape.getSize().x;
					//cout << "Skala: " << scale << endl;
					//heroDistanceOrigin *= scale;
					//cout << "Odleglosc od punktu 0,0: " << heroDistanceOrigin << endl;

					heroCharacter.heroSprite.setPosition(Vector2f(PositionHeroX + 10, PositionHeroY-0.5 ));
					heroCharacter.heroSprite.setSize(Vector2f(SizeHeroX + 0.5, SizeHeroY + 1));
				}
				if (event.mouseWheel.delta == -1)
				{
					for (int x = 0; x < worldWidth; x++)
					{
						for (int y = 0; y < worldHeight; y++)
						{
							world.worldStructure[x][y].tileShape.setPosition(Vector2f(world.worldStructure[x][y].tileShape.getPosition().x - 0.5 * x, world.worldStructure[x][y].tileShape.getPosition().y - 0.5 * y));
							world.worldStructure[x][y].tileShape.setSize(Vector2f(SizeX - 0.5, SizeY - 0.5));
						}
					}


					//scale = blockSize / world.worldStructure[0][0].tileShape.getSize().x;
					//cout << "Skala: " << scale << endl;
					//heroDistanceOrigin *= scale;
					//cout << "Odleglosc od punktu 0,0: " << heroDistanceOrigin << endl;

					heroCharacter.heroSprite.setPosition(Vector2f(PositionHeroX - 10, PositionHeroY+0.5));
					heroCharacter.heroSprite.setSize(Vector2f(SizeHeroX - 0.5, SizeHeroY - 1));
				}

			}
		}

		//mouse===================================
		
		//eo_mouse================================

		//=====VIEW=======================
		window.setView(visibleArea);
		View currentView = window.getView();

		float fovX = currentView.getCenter().x;
		float fovY = currentView.getCenter().y;

		float leftFovEdge = fovX - (g_width / 2);
		float rightFovEdge = fovX + (g_width / 2);
		float upFovEdge = fovY + (g_height / 2);
		float downFovEdge = fovY - (g_height / 2);
		//=====EO_VIEW====================


		//heroCharacter.heroSprite.setPosition(Vector2f(leftFovEdge+g_width/2, downFovEdge+g_height/2-50));
		
		currentView.setCenter(heroCharacter.heroSprite.getPosition().x, heroCharacter.heroSprite.getPosition().y);
		
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			heroCharacter.heroMove(0);
			//visibleArea.move(0, -5);
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			heroCharacter.heroMove(3);
			//visibleArea.move(0, 5);
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			heroCharacter.heroMove(2);
			//visibleArea.move(5, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			heroCharacter.heroMove(1);
			//visibleArea.move(-5, 0);
		}
		

		
		if (Keyboard::isKeyPressed(Keyboard::C))
		{
			float fovX = currentView.getCenter().x;
			float fovY = currentView.getCenter().y;


			float leftFovEdge = fovX - (g_width / 2);
			float rightFovEdge = fovX + (g_width / 2);
			float upFovEdge = fovY - (g_height / 2);
			float downFovEdge = fovY + (g_height / 2);

			cout << "=============SCREEN EDGE COORDINATES=============\n";
			cout << "fovX: " << fovX << endl;
			cout << "fovY: " << fovY << endl << endl;
			cout << "Left: " << leftFovEdge << endl;
			cout << "Right: " << rightFovEdge << endl;
			cout << "Up: " << upFovEdge << endl;
			cout << "Down: " << downFovEdge << endl;
			cout << "=================================================\n";
		}

		window.clear(Color::White);


		


		for (int x = 0; x < worldWidth; x++)
		{
			for (int y = 0; y < worldHeight; y++)
			{
				float worldStructure_X = world.worldStructure[x][y].tileShape.getPosition().x;
				float worldStructure_Y = world.worldStructure[x][y].tileShape.getPosition().y;

				if (worldStructure_X >= leftFovEdge - 80 && worldStructure_X <= rightFovEdge && worldStructure_Y <= upFovEdge + 80 && worldStructure_Y >= downFovEdge - 80)
				{
					window.draw(world.worldStructure[x][y].tileShape);
				}
				else
				{
					continue;
				}
			}
		}

		if (isInvOpen == true)
		{
			
			heroCharacter.inventory.setPosition(Vector2f(heroCharacter.heroSprite.getPosition().x-heroCharacter.inventory.getSize().x/2, heroCharacter.heroSprite.getPosition().y - heroCharacter.inventory.getSize().y / 2));
			window.draw(heroCharacter.inventory);
		}

		//window.draw(test);
		window.draw(mousePoint);

		window.draw(heroCharacter.heroSprite);

		window.display();
	}

	return 0;
}