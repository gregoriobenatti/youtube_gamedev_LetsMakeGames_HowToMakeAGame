#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"


Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;

auto& player(manager.addEntity());

Game::Game()
{
}

Game::~Game()
{
}


void Game::Init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) 
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL_Init ok" << std::endl;

		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (window)
		{
			std::cout << "SDL_Window ok" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "SDL_Renderer ok" << std::endl;
		}

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	map = new Map();

	//ECS implementation
	player.addComponent<PositionComponent>(50, 100);
	player.addComponent<SpriteComponent>("assets/player.png");
}

void Game::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::Update()
{
	manager.refresh();
	manager.update();

	if (player.getComponent<PositionComponent>().x() > 150)
	{
		player.getComponent<SpriteComponent>().setTexture("assets/player2.png");
	}
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	
	map->DrawMap();
	manager.draw();
	
	SDL_RenderPresent(renderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(window);	
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	
	std::cout << "Game::Clean ok" << std::endl;
}
