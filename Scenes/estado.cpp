#include "estado.hpp"

SDL_Surface* Behind_SURF;
SDL_Texture* Texture;

SDL_Surface* titulo_surf;
SDL_Texture* titulo_text;

SDL_FRect Titulo = { 0,0, 1920, 1080 };


void Introducao_Init()
{
	if (Behind_SURF != nullptr)
		return;

	Behind_SURF = IMG_Load("C:/Atrás das Garras/Assets/Sprites/BEHIND.png");
	Texture = SDL_CreateTextureFromSurface(renderer, Behind_SURF);

	titulo_surf = TTF_RenderText_Blended(font, "Pressione ESPAÇO para continuar", 0, color);
	titulo_text = SDL_CreateTextureFromSurface(renderer, titulo_surf);



	SDL_DestroySurface(Behind_SURF);
}

void Introducao_Update()
{
	SDL_SetRenderDrawColor(renderer, 120, 250, 100, 255);

	SDL_RenderTexture(
		renderer,
		Texture,
		nullptr,
		&Titulo
	);

	SDL_FRect Quadrado(
		resolution.x/2 - 200,
		resolution.y/2 + 200,
		400,
		80
	);
	SDL_RenderTexture(
		renderer,
		titulo_text,
		nullptr,
		&Quadrado
	);




	if (keyb.type == SDL_EVENT_KEY_DOWN	&& !keyb.key.repeat)
	{
		if (keyb.key.key == SDLK_SPACE)
		{
			estado.introducao = false;
			estado.jogo = true;
		}
	}
}

void Introducao_Destroy()
{
	SDL_DestroyTexture(Texture);
	Texture = nullptr;




}