#pragma once

#include "Components.h"
#include <SDL.h>


class SpriteComponent : public Component
{
private:
	PositionComponent* position;
	SDL_Texture* texture;
	SDL_Rect sourceRect;
	SDL_Rect destinationRect;

public:
	SpriteComponent() = default;

	SpriteComponent(const char* path)
	{
		setTexture(path);
	}

	void setTexture(const char* path)
	{
		texture = TextureManager::LoadTexture(path);
	}
	
	void init() override
	{
		position = &entity->getComponent<PositionComponent>();

		sourceRect.x = 0;
		sourceRect.h = 0;
		sourceRect.w = 32;
		sourceRect.h = 32;

		destinationRect.w = 64;
		destinationRect.h = 64;
	}

	void update() override
	{
		destinationRect.x = position->x();
		destinationRect.y = position->y();
	}

	void draw() override
	{
		TextureManager::Draw(texture, sourceRect, destinationRect);
	}
};