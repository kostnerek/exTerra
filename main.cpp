#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include <time.h>

using namespace sf;
using namespace std;




vector<vector<RectangleShape>>mesh;


int g_height = 500;
int g_width = 1000;






int main()
{
	float blockWidth = 10.0;
	float blockHeight = 10.0;

	int xField = 1000;
	int yField = 100;

	

	float offsetX = 5;
	float offsetY = 5;
	float offsetChange = 5;


	mesh.resize(xField, vector<RectangleShape>(yField));
	srand(time(NULL));

	for (int x = 0; x < xField; x++)
	{
		for (int y = 0; y < yField; y++)
		{

			RectangleShape tile;
			tile.setSize(Vector2f(blockWidth, blockHeight)); //w and h

			int random = rand() % 5 + 1;
			switch (random)
			{
			case 1:
			{
				tile.setFillColor(Color(120, 146, 15));
				break;
			}
			case 2:
			{
				tile.setFillColor(Color(156, 156, 156));
				break;
			}
			case 3:
			{
				tile.setFillColor(Color(90, 90, 90));
				break;
			}
			case 4:
			{
				tile.setFillColor(Color(233, 233, 139));
				break;
			}
			case 5:
			{
				tile.setFillColor(Color(42, 50, 218));
				break;
			}
			}

			tile.setPosition(x*blockHeight, y*blockWidth);
			mesh[x][y] = tile;
		}
	}


	RenderWindow window(sf::VideoMode(g_width, g_height), "tesciory");//100

	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	//Window::setVerticalSyncEnabled(true);
	
	//Window::setFramerateLimit(60);

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
							mesh[x][y].setSize(Vector2f(mesh[x][y].getSize().x + 0.5, mesh[x][y].getSize().y + 0.5));
							mesh[x][y].setPosition(Vector2f(mesh[x][y].getPosition().x + 0.5*x, mesh[x][y].getPosition().y + 0.5*y));
						}
					}
				}
				if (event.mouseWheel.delta == -1)
				{
					for (int x = 0; x < xField; x++)
					{
						for (int y = 0; y < yField; y++)
						{
							mesh[x][y].setSize(Vector2f(mesh[x][y].getSize().x - 0.5, mesh[x][y].getSize().y - 0.5));
							mesh[x][y].setPosition(Vector2f(mesh[x][y].getPosition().x - 0.5*x, mesh[x][y].getPosition().y - 0.5*y));
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
		int counter = 0;
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			cout<<counter;
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
			counter++;
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
		
		for (int x = 0; x < xField; x++)
		{
			for (int y = 0; y < yField; y++)
			{
				if (mesh[x][y].getPosition().x > 0-4*blockWidth && mesh[x][y].getPosition().y > 0-4*blockHeight
					&& mesh[x][y].getPosition().x <= g_width && mesh[x][y].getPosition().y <= g_height)
				{
					
					mesh[x][y].setPosition(mesh[x][y].getPosition().x + offsetX, mesh[x][y].getPosition().y + offsetY);
					window.draw(mesh[x][y]);
				}
				else
				{
					continue;
				}
			}
		}
		offsetX = 0;
		offsetY = 0;
		
		window.display();
	}

	return 0;
}