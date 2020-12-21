#include "Map.h"
#include "TextureManager.h"


int level1[10][15] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
	{ 0,1,0,0,0,0,0,0,0,0,0,0,0,1,0 },
	{ 0,1,0,0,0,0,0,0,0,0,0,0,0,1,0 },
	{ 0,1,0,0,0,0,2,2,2,0,0,0,0,1,0 },
	{ 0,1,0,0,0,0,2,2,2,0,0,0,0,1,0 },
	{ 0,1,0,0,0,0,0,0,0,0,0,0,0,1,0 },
	{ 0,1,0,0,0,0,0,0,0,0,0,0,0,1,0 },
	{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};

Map::Map()
{
	dirt = TextureManager::LoadTexture("assets/dirt.png");
	grass = TextureManager::LoadTexture("assets/grass.png");
	water = TextureManager::LoadTexture("assets/water.png");

	LoadMap(level1);

	source.x = 0;
	source.y = 0;
	source.w = 32;
	source.h = 32;

	destination.x = 0;
	destination.y = 0;
	destination.w = 32;
	destination.h = 32;
}

void Map::LoadMap(int arr[10][15])
{
	for (int row = 0; row < 10; row++)
	{
		for (int column = 0; column < 15; column++)
		{
			map[row][column] = arr[row][column];
		}
	}
}

void Map::DrawMap()
{
	int type = 0;
	for (int row = 0; row < 10; row++)
	{
		for (int column = 0; column < 15; column++)
		{
			type = map[row][column];
			
			destination.x = column * 32;
			destination.y = row * 32;

			switch (type)
			{
			case 0:
				TextureManager::Draw(water, source, destination);
				break;
			case 1:
				TextureManager::Draw(grass, source, destination);
				break;
			case 2:
				TextureManager::Draw(dirt, source, destination);
				break;
			default:
				break;
			}
		}
	}
}