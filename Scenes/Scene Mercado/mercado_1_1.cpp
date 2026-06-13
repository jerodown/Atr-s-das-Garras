#include "mercado_1_1.hpp"

Button* roubar = nullptr;
Button* nao_sou_assim = nullptr;

SDL_Surface* escolha1surf_1_1;
SDL_Texture* escolha1text_1_1;


SDL_Surface* escolha2surf_1_1;
SDL_Texture* escolha2text_1_1;


void Mercado_1_1_Init() {
	if (roubar != nullptr)
		return;


	static SDL_Texture* buttontextures_1_1 = buttontext();

	escolha1surf_1_1 = TTF_RenderText_Blended(font, "Roubar       ", 0, color);
	escolha1text_1_1 = SDL_CreateTextureFromSurface(renderer, escolha1surf_1_1);

	escolha2surf_1_1 = TTF_RenderText_Blended(font, "Não sou assim", 0, color);
	escolha2text_1_1 = SDL_CreateTextureFromSurface(renderer, escolha2surf_1_1);

	SDL_DestroySurface(escolha1surf_1_1);
	SDL_DestroySurface(escolha2surf_1_1);



	roubar = new Button(
		resolution.x - resolution.x / 3,
		resolution.y - resolution.y / 1.5,
		350,
		50,
		buttontextures_1_1,
		escolha1text_1_1
	);
	nao_sou_assim = new Button(
		resolution.x - resolution.x / 3,
		resolution.y - resolution.y / 1.5 + 50,
		350,
		50,
		buttontextures_1_1,
		escolha2text_1_1
	);
}

void Mercado_1_1_Update()
{
	roubar->render(renderer);
	nao_sou_assim->render(renderer);

	if (hasEvent && keyb.type == SDL_EVENT_KEY_DOWN && !keyb.key.repeat)
	{

		if (keyb.key.key == SDLK_1)
		{
			cena1roubo.Roubar = true;
			SDL_Log("Roubar");

			cena1roubo.ativo = false;
			hasEvent = true;
			keyb = SDL_Event{};
		}
		if (keyb.key.key == SDLK_2)
		{
			cena1roubo.NaoSouAssim = true;
			cena1papeis.papiro_egipcio = false;
			SDL_Log("Nao sou assim");

			cena1roubo.ativo = false;
			hasEvent = true;
			keyb = SDL_Event{};
		}
	}
}

void Mercado_1_1_Destroy()
{
	delete roubar;
	delete nao_sou_assim;

	roubar = nullptr;
	nao_sou_assim = nullptr;

	SDL_DestroyTexture (escolha1text_1_1);
	SDL_DestroyTexture (escolha2text_1_1);

	escolha1text_1_1 = nullptr;
	escolha2text_1_1 = nullptr;
}
