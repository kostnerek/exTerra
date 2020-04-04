#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include <time.h>
#include <thread>
#include <mutex>

#include "worldGenerate.h"
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





float blockWidth = 16.0;
float blockHeight = 16.0;

int blockSize = 16;

int worldWidth = 100;
int worldHeight = 100;





int main()
{
	worldGenerate world(worldWidth, worldHeight, blockSize);
	world.showGenStats();


	RenderWindow window(VideoMode(g_width, g_height), "exTerra");//100

	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	View visibleArea(FloatRect(g_width/2, 0.f, g_width, g_height));


	//=====================Test hero==============================

		RectangleShape test;

		test.setFillColor(Color::Black);
		test.setSize(Vector2f(20.f,20.f));

	//============================================================


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
			}

			if (event.type == sf::Event::MouseWheelMoved)
			{
				if (event.mouseWheel.delta == 1)
				{
					for (int x = 0; x < worldWidth; x++)
					{
						for (int y = 0; y < worldHeight; y++)
						{
							world.worldStructure[x][y].tileShape.setSize(Vector2f(world.worldStructure[x][y].tileShape.getSize().x + 0.5, world.worldStructure[x][y].tileShape.getSize().y + 0.5));
							world.worldStructure[x][y].tileShape.setPosition(Vector2f(world.worldStructure[x][y].tileShape.getPosition().x + 0.5*x, world.worldStructure[x][y].tileShape.getPosition().y + 0.5*y));
						}
					}
				}
				if (event.mouseWheel.delta == -1)
				{
					for (int x = 0; x < worldWidth; x++)
					{
						for (int y = 0; y < worldHeight; y++)
						{
							world.worldStructure[x][y].tileShape.setSize(Vector2f(world.worldStructure[x][y].tileShape.getSize().x - 0.5, world.worldStructure[x][y].tileShape.getSize().y - 0.5));
							world.worldStructure[x][y].tileShape.setPosition(Vector2f(world.worldStructure[x][y].tileShape.getPosition().x - 0.5*x, world.worldStructure[x][y].tileShape.getPosition().y - 0.5*y));
						}
					}
				}

			}
		}


		//=====VIEW=======================
		window.setView(visibleArea);
		View currentView = window.getView();
		//=====EO_VIEW====================

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
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			test.setPosition(currentView.getCenter().x, currentView.getCenter().y);
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
			cout << "fovY: " << fovY << endl<<endl;
			cout << "Left: " << leftFovEdge << endl;
			cout << "Right: " << rightFovEdge << endl;
			cout << "Up: " << upFovEdge << endl;
			cout << "Down: " << downFovEdge << endl;
			cout << "=================================================\n";
		}

		window.clear(Color::White);
		
		
		float fovX = currentView.getCenter().x;
		float fovY = currentView.getCenter().y;
		
		float leftFovEdge = fovX - (g_width / 2);
		float rightFovEdge = fovX + (g_width / 2);
		float upFovEdge = fovY + (g_height / 2);
		float downFovEdge = fovY - (g_height / 2);

		for (int x = 0; x < worldWidth; x++)
		{
			for (int y = 0; y < worldHeight; y++)
			{
				float worldStructure_X = world.worldStructure[x][y].tileShape.getPosition().x;
				float worldStructure_Y = world.worldStructure[x][y].tileShape.getPosition().y;
				
				if (worldStructure_X >=leftFovEdge-40 && worldStructure_X <=rightFovEdge && worldStructure_Y <=upFovEdge+40 && worldStructure_Y >=downFovEdge-40)
				{
					window.draw(world.worldStructure[x][y].tileShape);
				}
				else
				{
					continue;
				}
			}
		}
		
		//window.draw(test);
		
		window.display();
	}

	return 0;
}