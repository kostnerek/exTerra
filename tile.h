#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>

using namespace std;
using namespace sf;

class tile
{
	//RectangleShape tileShape;
public:
	float width, height;
	string type;
	RectangleShape tileShape;

	tile(float blockWidth, float blockHeight);
	tile();
	void loadTexture();
	void setTexture(float widthT, float heightT);
	void setColor();


	// dirt		
	// grassDirt  
	// ore1		
	// ore2		
	// ore3		
	// ore4		
	// stone

};