#include "screen.hpp"

SDL_Window* window = nullptr;

Resolution resolution;

	void Display_found() {

	SDL_DisplayID CurrentDisplay = SDL_GetPrimaryDisplay();
		
	const SDL_DisplayMode* mode = SDL_GetCurrentDisplayMode(CurrentDisplay);

	resolution.x = mode->w;
	resolution.y = mode->h;

	SDL_Log("Altura: %d", mode->h);
	SDL_Log("Largura: %d", mode->w);

}

	void Create_screen() {
		window = SDL_CreateWindow(
			"The Game",
			resolution.x,
			resolution.y,
			0
		);

		if (window == nullptr)
		{
			SDL_Log("Erro: %s", SDL_GetError());
		}
	}