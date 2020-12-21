#pragma once

#include "Game.h"


class Map
{
public:
	Map();
	~Map();

	void LoadMap(int arr[10][15]);
	void DrawMap();

private:
	SDL_Rect source, destination;
	
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][25];
};