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
	//worldGenerate world(worldWidth, worldHeight, blockSize);
	world.blockSize = blockSize;
	world.worldWidth = worldWidth;
	world.worldHeight = worldHeight;
	world.showGenStats();


	RenderWindow window(VideoMode(g_width, g_height), "exTerra"); // 100

	window.setFramerateLimit(60);
	//window.setVerticalSyncEnabled(true);

	View visibleArea(FloatRect(worldWidth*blockSize/2, -190.f, g_width, g_height));


	//=====================hero===================================



	float heroDistanceOrigin = heroCharacter.heroSprite.getPosition().x;


	RectangleShape test;
	test.setFillColor(Color::Black);
	test.setPosition(0, 0);
	test.setSize(Vector2f(worldWidth*blockSize, worldHeight*blockSize));


	//============================================================
	RectangleShape mousePoint;
	mousePoint.setSize(Vector2f(1, 1));
	//mousePoint.setPosition(mousePos);
	

	heroCharacter.heroSprite.setPosition(250, 250);
	heroCharacter.heroTest.setPosition(250, 250);


	int buffX = -1, buffY;

	while (window.isOpen())
	{
		window.setView(visibleArea);
		View currentView = window.getView();
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
					if (isInvOpen == false)
					{
						heroCharacter.openInventory(true);
						isInvOpen = true;
					}
				}
				if (event.key.code == Keyboard::Z)
				{
					heroCharacter.inventoryNumbersSetup("dirt",  1);
					heroCharacter.inventoryNumbersSetup("grass", 2);
				}


				if (event.key.code == Keyboard::Q)
				{
					
					for (int y = 0; y < 4; y++)
					{
						for (int x = 0; x < 5; x++)
						{
							cout << heroCharacter.inventoryNumbers[x][y].amount << " ";
						}
						cout << endl;
					}
					for (int y = 0; y < 4; y++)
					{
						for (int x = 0; x < 5; x++)
						{
							cout << heroCharacter.inventoryNumbers[x][y].type << " ";
						}
						cout << endl;
					}

					
					
				}
			}


			if (event.type == Event::MouseButtonPressed && isInvOpen == true)
			{
				if (event.key.code == Mouse::Left)
				{
					Vector2i pixelPos = Mouse::getPosition(window);
					Vector2f worldPos = window.mapPixelToCoords(pixelPos);

					mousePoint.setPosition(Vector2f(worldPos.x, worldPos.y));
					
					

					for (int x = 0; x < 5; x++)
					{
						for (int y = 0; y < 4; y++)
						{
							if (heroCharacter.inventory[x][y].getGlobalBounds().intersects(mousePoint.getGlobalBounds()) == true)
							{
								buffX = x;
								buffY = y;
								//cout << heroCharacter.inventoryNumbers[x][y].type << endl;
								//cout << "Pressed: " << x << " " << y << endl;
							}
						}
					}
				}
			}

			if (event.type == Event::MouseButtonReleased && isInvOpen == true)
			{
				if (event.key.code == Mouse::Left)
				{
					Vector2i pixelPos = Mouse::getPosition(window);
					Vector2f worldPos = window.mapPixelToCoords(pixelPos);

					mousePoint.setPosition(Vector2f(worldPos.x, worldPos.y));
					for (int x = 0; x < 5; x++)
					{
						for (int y = 0; y < 4; y++)
						{
							if (heroCharacter.inventory[x][y].getGlobalBounds().intersects(mousePoint.getGlobalBounds()) == true)
							{
								cout << "Pressed(to znika)buff: " << buffX << " " << buffY << endl;

								cout <<"Release(to nie znika)x: "<< x << " " << y << endl;

								string typeBuff = heroCharacter.inventoryNumbers[x][y].type;
								int amountBuff = heroCharacter.inventoryNumbers[x][y].amount;
								if (buffX == x && buffY == y)
								{
									break;
								}
								if (heroCharacter.inventoryNumbers[buffX][buffY].type == heroCharacter.inventoryNumbers[x][y].type)
								{
									int amount = heroCharacter.inventoryNumbers[x][y].amount + heroCharacter.inventoryNumbers[buffX][buffY].amount;
					
									heroCharacter.inventoryNumbers[x][y].amount = amount;
									heroCharacter.inventoryNumbers[buffX][buffY].amount = 0;

									heroCharacter.inventoryNumbers[buffX][buffY].type = "none";
									
									heroCharacter.inventorySetup();
									break;
								}
								if (heroCharacter.inventoryNumbers[buffX][buffY].type != heroCharacter.inventoryNumbers[x][y].type)
								{
									heroCharacter.inventoryNumbers[x][y].type = heroCharacter.inventoryNumbers[buffX][buffY].type;
									heroCharacter.inventoryNumbers[x][y].amount = heroCharacter.inventoryNumbers[buffX][buffY].amount;
									heroCharacter.inventoryNumbers[buffX][buffY].type = typeBuff;
									heroCharacter.inventoryNumbers[buffX][buffY].amount = amountBuff;
									heroCharacter.inventorySetup();
									break;
								}
								

								

							}
						}
					}
				}
			}


			if (event.type == Event::MouseButtonPressed && isInvOpen==false)
			{
				if (event.key.code == Mouse::Left)
				{
					sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
					sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

					mousePoint.setPosition(Vector2f(worldPos.x, worldPos.y));

					mousePoint.setFillColor(Color::Black);

					for (int x = 0; x < worldWidth; x++)
					{
						for (int y = 0; y < worldHeight; y++)
						{
							if (world.worldStructure[x][y].tileShape.getGlobalBounds().intersects(mousePoint.getGlobalBounds())==true )
							{
								if (abs(heroCharacter.heroSprite.getPosition().x - world.worldStructure[x][y].tileShape.getPosition().x) <= world.worldStructure[x][y].tileShape.getSize().x * 4)
								{
									if (abs(heroCharacter.heroSprite.getPosition().y - world.worldStructure[x][y].tileShape.getPosition().y) <= world.worldStructure[x][y].tileShape.getSize().y * 4)
									{
										world.deleteTile(x, y);
										//world.worldStructure[x].erase(world.worldStructure[x].begin() + y);
									}
								}
							}
						}
					}
				}
			}
			//scroll
			//=====VIEW=======================
			

			
			//=====EO_VIEW====================

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
					heroCharacter.heroSprite.setPosition(Vector2f(PositionHeroX - 10, PositionHeroY+0.5));
					heroCharacter.heroSprite.setSize(Vector2f(SizeHeroX - 0.5, SizeHeroY - 1));
				}

			}
		}

		//mouse===================================
		
		//eo_mouse================================
		
		float fovX = currentView.getCenter().x;
		float fovY = currentView.getCenter().y;

		float leftFovEdge = fovX - (g_width / 2);
		float rightFovEdge = fovX + (g_width / 2);
		float upFovEdge = fovY + (g_height / 2);
		float downFovEdge = fovY - (g_height / 2);


		heroCharacter.heroSprite.setPosition(Vector2f(leftFovEdge+g_width/2, downFovEdge+g_height/2-50));
		
		currentView.setCenter(heroCharacter.heroSprite.getPosition().x, heroCharacter.heroSprite.getPosition().y);
		

		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			heroCharacter.heroMove(0);
			visibleArea.move(0, -5);
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			heroCharacter.heroMove(3);
			visibleArea.move(0, 5);
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			heroCharacter.heroMove(2);
			visibleArea.move(5, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			heroCharacter.heroMove(1);
			visibleArea.move(-5, 0);
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

		//window.draw(test);
		


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

		

		
		window.draw(mousePoint);

		window.draw(heroCharacter.heroSprite);
		window.draw(heroCharacter.heroTest);

		if (isInvOpen == true)
		{

			heroCharacter.inventoryShape.setPosition(Vector2f(heroCharacter.heroSprite.getPosition().x - heroCharacter.inventoryShape.getSize().x / 2, heroCharacter.heroSprite.getPosition().y - heroCharacter.inventoryShape.getSize().y / 2 + 50));
			window.draw(heroCharacter.inventoryShape);

			
			heroCharacter.inventorySetup();
			

			for (int x = 0; x < 5; x++)
			{
				for (int y = 0; y < 4; y++)
				{
					window.draw(heroCharacter.inventory[x][y]);
				}
			}

		}

		window.display();
	}

	return 0;
}