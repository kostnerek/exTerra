#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include <time.h>

#include "tile.h"

using namespace sf;
using namespace std;




vector<vector<tile>>mesh;


int g_height = 500;
int g_width = 1000;






int main()
{


	Texture tDirt;
	Texture tGrass;
	Texture tOre1;
	Texture tOre2;
	Texture tOre3;
	Texture tOre4;
	Texture tStone;

	const Texture* ptDirt = &tDirt;
	const Texture* ptGrass = &tGrass;
	const Texture* ptOre1 = &tOre1;
	const Texture* ptOre2 = &tOre2;
	const Texture* ptOre3 = &tOre3;
	const Texture* ptOre4 = &tOre4;
	const Texture* ptStone = &tStone;


	tDirt.loadFromFile("textures/dirt.png");
	tGrass.loadFromFile("textures/grassDirt.png");
	tOre1.loadFromFile("textures/ore1.png");
	tOre2.loadFromFile("textures/ore2.png");
	tOre3.loadFromFile("textures/ore3.png");
	tOre4.loadFromFile("textures/ore4.png");
	tStone.loadFromFile("textures/stone.png");

	//cout << tDirt.getSize().x<<" "<<tDirt.getSize().y;

	//tDirt.setSmooth(true);
	//tGrass.setSmooth(true);
	//tStone.setSmooth(true);
	//tOre1.setSmooth(true);
	//tOre2.setSmooth(true);
	//tOre3.setSmooth(true);
	//tOre4.setSmooth(true);


	float blockWidth = 10.0;
	float blockHeight = 10.0;

	int xField = 1000;
	int yField = 100;

	int blockAmount = xField * yField;

	float offsetX = 5;
	float offsetY = 5;
	float offsetChange = 5;


	mesh.resize(xField, vector<tile>(yField));

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

	srand(time(NULL));
	

	



	for (int x = 1; x < xField; x++)
	{
		for (int y = 1; y < yField; y++)
		{

			

			//RectangleShape tile;
			//tile.setSize(Vector2f(blockWidth, blockHeight)); //w and h
			//piece.width = 10;

			tile piece;
			piece.height = blockHeight;
			piece.width = blockWidth;

			int random = rand() % 100;

			

			if (random >= 0 && random <= 20)
			{
				dirtCount++;

				piece.type = "dirt";
				piece.tileShape.setTexture(ptDirt);
			}
			if (random > 20 && random <= 70)
			{
				stoneCount++;

				piece.type = "stone";
				piece.tileShape.setTexture(ptStone);
			}
			if (random > 70 && random <=82 )
			{
				ore1Count++;

				piece.type = "ore1";
				piece.tileShape.setTexture(ptOre1);
			}
			if (random>82&&random<=89)
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
			//switch (random)
			//{
			//	case 1<10:
			//	{
			//		piece.type = "dirt";
			//		piece.tileShape.setTexture(ptDirt);
			//		break;
			//	}
			//	case 2:
			//	{
			//		piece.type = "grassDirt";
			//		piece.tileShape.setTexture(ptGrass);
			//		break;
			//	}
			//	case 3:
			//	{
			//		piece.type = "stone";
			//		piece.tileShape.setTexture(ptStone);
			//		break;
			//	}
			//	case 4:
			//	{
			//		piece.type="ore1";
			//		piece.tileShape.setTexture(ptOre1);
			//		break;
			//	}
			//	case 5:
			//	{
			//		piece.type="ore2";
			//		piece.tileShape.setTexture(ptOre2);
			//		break;
			//	}
			//	case 6:
			//	{
			//		piece.type="ore3";
			//		piece.tileShape.setTexture(ptOre3);
			//		break;
			//	}
			//	case 7:
			//	{
			//		piece.type="ore4";
			//		piece.tileShape.setTexture(ptOre4);
			//		break;
			//	}
			//}
			
			piece.tileShape.setPosition(x*blockHeight, y*blockWidth);
			mesh[x][y] = piece;
		}
	}
	cout << "All loaded" << endl;

	cout << "=============================" << endl;
	cout << "Dirt: " << dirtCount / blockAmount * 100 << endl;
	cout << "Grass: " << grassCount / blockAmount * 100 << endl;
	cout << "Stone: " << stoneCount / blockAmount * 100 << endl;
	cout << "Ore1: " << ore1Count / blockAmount * 100 << endl;
	cout << "Ore2: " << ore2Count / blockAmount * 100 << endl;
	cout << "Ore3: " << ore3Count / blockAmount * 100 << endl;
	cout << "Ore4: " << ore4Count / blockAmount * 100 << endl;
	cout << "=============================" << endl;


	RenderWindow window(sf::VideoMode(g_width, g_height), "tesciory");//100

	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

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

		


		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			offsetY += offsetChange;

			//for (int x = 0; x < xField; x++)
			//{
			//	for (int y = 0; y < yField; y++)
			//	{
			//		if (mesh[x][y].getPosition().x >= 0 - blockWidth && mesh[x][y].getPosition().y >= 0 - blockHeight
			//			&& mesh[x][y].getPosition().x <= g_width && mesh[x][y].getPosition().y <= g_height)
			//		{

			//			mesh[x][y].setPosition(mesh[x][y].getPosition().x, mesh[x][y].getPosition().y + offsetY);

			//		}
			//		else
			//		{
			//			continue;
			//		}
			//	}
			//}
			////offsetX = 0;
			////offsetY = 0;

			


			/*for (int x = 0; x < xField; x++)
			{
				for (int y = 0; y < yField; y++)
				{
					mesh[x][y].setPosition(mesh[x][y].getPosition().x, mesh[x][y].getPosition().y + offsetY);
				}
			}*/
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			
			offsetY -= offsetChange;
			//
			//for (int x = 0; x < xField; x++)
			//{
			//	for (int y = 0; y < yField; y++)
			//	{
			//		if (mesh[x][y].getPosition().x >= 0 - blockWidth && mesh[x][y].getPosition().y >= 0 - blockHeight
			//			&& mesh[x][y].getPosition().x <= g_width && mesh[x][y].getPosition().y <= g_height)
			//		{
			//
			//			mesh[x][y].setPosition(mesh[x][y].getPosition().x, mesh[x][y].getPosition().y - offsetY);
			//
			//		}
			//		else
			//		{
			//			continue;
			//		}
			//	}
			//}
			//offsetX = 0;
			//offsetY = 0;
			/*for (int x = 0; x < xField; x++)
			{
				for (int y = 0; y < yField; y++)
				{
					mesh[x][y].setPosition(mesh[x][y].getPosition().x, mesh[x][y].getPosition().y - offsetY);
				}
			}*/
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			offsetX -= offsetChange;
			//
			//for (int x = 0; x < xField; x++)
			//{
			//	for (int y = 0; y < yField; y++)
			//	{
			//		if (mesh[x][y].getPosition().x >= 0 - blockWidth && mesh[x][y].getPosition().y >= 0 - blockHeight
			//			&& mesh[x][y].getPosition().x <= g_width && mesh[x][y].getPosition().y <= g_height)
			//		{
			//
			//			mesh[x][y].setPosition(mesh[x][y].getPosition().x - offsetX, mesh[x][y].getPosition().y );
			//
			//		}
			//		else
			//		{
			//			continue;
			//		}
			//	}
			//}
			//offsetX = 0;
			//offsetY = 0;
			/*int start = clock();
			for (int x = 0; x < xField; x++)
			{
				for (int y = 0; y < yField; y++)
				{
					mesh[x][y].setPosition(mesh[x][y].getPosition().x - offsetX, mesh[x][y].getPosition().y);
				}
			}
			int stop = clock();
			cout << "Czas: " << stop - start << endl;*/
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			offsetX += offsetChange;
			//
			//for (int x = 0; x < xField; x++)
			//{
			//	for (int y = 0; y < yField; y++)
			//	{
			//		if (mesh[x][y].getPosition().x >= 0 - blockWidth && mesh[x][y].getPosition().y >= 0 - blockHeight
			//			&& mesh[x][y].getPosition().x <= g_width && mesh[x][y].getPosition().y <= g_height)
			//		{
			//
			//			mesh[x][y].setPosition(mesh[x][y].getPosition().x + offsetX, mesh[x][y].getPosition().y);
			//
			//		}
			//		else
			//		{
			//			continue;
			//		}
			//	}
			//}
			//offsetX = 0;
			//offsetY = 0;
			/*for (int x = 0; x < xField; x++)
			{
				for (int y = 0; y < yField; y++)
				{
					mesh[x][y].setPosition(mesh[x][y].getPosition().x + offsetX, mesh[x][y].getPosition().y);
				}
			}*/
		}

		

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		window.clear(Color::White);
		
		int start = clock();
		for (int x = 0; x < xField; x++)
		{
			for (int y = 0; y < yField; y++)
			{
				mesh[x][y].tileShape.setPosition(mesh[x][y].tileShape.getPosition().x + offsetX, mesh[x][y].tileShape.getPosition().y + offsetY);
				if (mesh[x][y].tileShape.getPosition().x > 0-4*blockWidth && mesh[x][y].tileShape.getPosition().y > 0-4*blockHeight
					&& mesh[x][y].tileShape.getPosition().x <= g_width && mesh[x][y].tileShape.getPosition().y <= g_height)
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
		
		//cout << "Time: " << stop - start << " ";
		
		offsetX = 0;
		offsetY = 0;
		
		window.display();
	}

	return 0;
}