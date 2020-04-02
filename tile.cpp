#include "tile.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace std;
using namespace sf;

tile::tile()
{
	//this->loadTexture();
	this->setTexture();
}

tile::tile( float blockWidth, float blockHeight, string type )
{
	this->height = blockHeight;
	this->width  = blockWidth;
	this->type   = type;
	this->setTexture();
}

void tile::loadTexture()
{

}

void tile::setTexture()
{
	//cout << ".";
	//cout << "Loading textures!" << endl;
	this->tileShape.setSize( Vector2f( this->height, this->width ) ); // w and h

	Texture texture;

	//texture.loadFromMemory()

	const Texture* pTexture = &texture;
	texture.create( 10, 10 );
	this->tileShape.setTexture( pTexture );


	//if( this->type == "dirt" )		{ this->tileShape.setTexture( ptDirt ); }
	//if( this->type == "grassDirt" )   { this->tileShape.setTexture( ptGrass ); }
	//if( this->type == "ore1" )		{ this->tileShape.setTexture( ptOre1 ); }
	//if( this->type == "ore2" )		{ this->tileShape.setTexture( ptOre2 ); }
	//if( this->type == "ore3" )		{ this->tileShape.setTexture( ptOre3 ); }
	//if( this->type == "ore4" )		{ this->tileShape.setTexture( ptOre4 ); }
	//if( this->type == "stone" )		{ this->tileShape.setTexture( ptStone ); }


}

void tile::setColor()
{
	//if( this->type == "dirt" )		{ this->tileShape.setFillColor(); }
	//if( this->type == "grassDirt" )   { this->tileShape.setFillColor(); }
	//if( this->type == "ore1" )		{ this->tileShape.setFillColor(); }
	//if( this->type == "ore2" )		{ this->tileShape.setFillColor(); }
	//if( this->type == "ore3" )		{ this->tileShape.setFillColor(); }
	//if( this->type == "ore4" )		{ this->tileShape.setFillColor(); }
	//if( this->type == "stone" )		{ this->tileShape.setFillColor(); }
}