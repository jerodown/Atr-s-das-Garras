#include "mercado_1_0.hpp"

Button* papiro = nullptr;
Button* papel_a4 = nullptr;
Button* papel_reciclado = nullptr;

SDL_Surface* escolha1surf;
SDL_Texture* escolha1text;

SDL_Surface* escolha2surf;
SDL_Texture* escolha2text;

SDL_Surface* escolha3surf;
SDL_Texture* escolha3text;


void Mercado_1_0_Init() {
	if (papiro != nullptr)
		return;


	static SDL_Texture* buttontextures = buttontext();

	escolha1surf = TTF_RenderText_Blended(font, "Papíro do Egito ", 0, color);
	escolha2surf = TTF_RenderText_Blended(font, "Papel A4        ", 0, color);
	escolha3surf = TTF_RenderText_Blended(font, "Papel reciclável", 0, color);

	escolha1text = SDL_CreateTextureFromSurface(renderer, escolha1surf);
	escolha2text = SDL_CreateTextureFromSurface(renderer, escolha2surf);
	escolha3text = SDL_CreateTextureFromSurface(renderer, escolha3surf);

	SDL_DestroySurface(escolha1surf);
	SDL_DestroySurface(escolha2surf);
	SDL_DestroySurface(escolha3surf);



	papiro = new Button(
		resolution.x - resolution.x / 3,
		resolution.y - resolution.y / 1.5,
		350,
		50,
		buttontextures,
		escolha1text
	);
	papel_a4 = new Button(
		resolution.x - resolution.x / 3,
		resolution.y - resolution.y / 1.5 + 50,
		350,
		50,
		buttontextures,
		escolha2text
	);
	papel_reciclado = new Button(
		resolution.x - resolution.x / 3,
		resolution.y - resolution.y / 1.5 + 100,
		350,
		50,
		buttontextures,
		escolha3text
	);
}

void Mercado_1_0_Update()
{
	papiro->render(renderer);
	papel_a4->render(renderer);
	papel_reciclado->render(renderer);

	if (hasEvent && keyb.type == SDL_EVENT_KEY_DOWN && !keyb.key.repeat)
	{

		if (keyb.key.key == SDLK_1)
		{
			cena1papeis.papiro_egipcio = true;
			SDL_Log("Papiro do Egito");

			cena1papeis.ativo = false;
			hasEvent = true;
			keyb = SDL_Event{};
		}
		if (keyb.key.key == SDLK_2)
		{
			cena1papeis.papel_a4 = true;
			SDL_Log("Papel A4");

			cena1papeis.ativo = false;
			hasEvent = true;
			keyb = SDL_Event{};
		}
		if (keyb.key.key == SDLK_3)
		{
			cena1papeis.papel_reciclado = true;
			SDL_Log("Papel reciclável");

			cena1papeis.ativo = false;
			hasEvent = true;
			keyb = SDL_Event{};
		}

	}
}

void Mercado_1_0_Destroy()
{
	delete papiro;
	delete papel_a4;
	delete papel_reciclado;

	papiro = nullptr;
	papel_a4 = nullptr;
	papel_reciclado = nullptr;

	SDL_DestroyTexture(escolha1text);
	SDL_DestroyTexture(escolha2text);
	SDL_DestroyTexture(escolha3text);

	escolha1text = nullptr;
	escolha2text = nullptr;
	escolha3text = nullptr;
}
