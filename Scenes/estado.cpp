#include "estado.hpp"

SDL_Surface* Behind_SURF;
SDL_Texture* Texture;

SDL_Surface* titulo_surf;
SDL_Texture* titulo_text;

SDL_Surface* titulo_surf2;
SDL_Texture* titulo_text2;

SDL_FRect Titulo = { 0,0, 1920, 1080 };


void Introducao_Init()
{
	if (Behind_SURF != nullptr)
		return;

	Behind_SURF = IMG_Load("C:/Atrás das Garras/Assets/Sprites/BEHIND.png");
	Texture = SDL_CreateTextureFromSurface(renderer, Behind_SURF);

	titulo_surf = TTF_RenderText_Blended(font, "Pressione ESPAÇO para continuar", 0, color);
	titulo_text = SDL_CreateTextureFromSurface(renderer, titulo_surf);

	titulo_surf2 = TTF_RenderText_Blended(font, "ESC para sair", 0, color);
	titulo_text2 = SDL_CreateTextureFromSurface(renderer, titulo_surf2);


	SDL_DestroySurface(titulo_surf);
	SDL_DestroySurface(titulo_surf2);
	SDL_DestroySurface(Behind_SURF);
	Behind_SURF = nullptr;
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
		resolution.x/2 - 250,
		resolution.y/2 + 200,
		500,
		80
	);
	SDL_RenderTexture(
		renderer,
		titulo_text,
		nullptr,
		&Quadrado
	);
	SDL_FRect Quadrado2(
		resolution.x / 2 - 100,
		resolution.y / 2 + 400,
		200,
		80
	);
	SDL_RenderTexture(
		renderer,
		titulo_text2,
		nullptr,
		&Quadrado2
	);



	if (keyb.type == SDL_EVENT_KEY_DOWN	&& !keyb.key.repeat)
	{
		if (keyb.key.key == SDLK_SPACE)
		{
			estado.introducao = false;
			estado.jogo = true;
			cena1papeis.ativo = true;
		}
		if (keyb.key.key == SDLK_ESCAPE)
		{
			estado.ativo = false;
		}
	}
}

void Introducao_Destroy()
{
	SDL_DestroyTexture(Texture);
	Texture = nullptr;
	SDL_DestroyTexture(titulo_text);
	titulo_text = nullptr;
	SDL_DestroyTexture(titulo_text2);
	titulo_text2 = nullptr;

}