#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include <time.h>
#include "tile.h"


using namespace std;
using namespace sf;

class worldGenerate
{

	Texture tDirt;
	Texture tGrass;
	Texture tOre1;
	Texture tOre2;
	Texture tOre3;
	Texture tOre4;
	Texture tStone;
	Texture tWhite;
	const Texture* ptDirt = &tDirt;
	const Texture* ptGrass = &tGrass;
	const Texture* ptOre1 = &tOre1;
	const Texture* ptOre2 = &tOre2;
	const Texture* ptOre3 = &tOre3;
	const Texture* ptOre4 = &tOre4;
	const Texture* ptStone = &tStone;
	const Texture* ptWhite = &tWhite;

	


	float dirtCount  = 0;
	float grassCount = 0;
	float stoneCount = 0;
	float ore1Count  = 0;
	float ore2Count  = 0;
	float ore3Count  = 0;
	float ore4Count  = 0;

public:

	vector<vector<int>>worldStructureNums;

	vector<vector<tile>>worldStructure;


	int worldWidth, worldHeight, blockSize, startClock, stopClock;
	int blockAmount;

	worldGenerate(int worldWidth, int worldHeight, int blockSize);

	void showGenStats();

	void generate();

	void placeBlocks();

	void deleteTile(int x, int y);
};

extern worldGenerate world;