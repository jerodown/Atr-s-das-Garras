#include "dar_papel_pro_biologo.hpp"

Button* perguntar_sobre = nullptr;
Button* esconder = nullptr;
Button* entregar_papeis = nullptr;

SDL_Surface* escolha1surf_1_3;
SDL_Texture* escolha1text_1_3;


SDL_Surface* escolha2surf_1_3;
SDL_Texture* escolha2text_1_3;


SDL_Surface* escolha3surf_1_3;
SDL_Texture* escolha3text_1_3;


void DarPapelProBiologo_Init() {
	if (perguntar_sobre != nullptr)
		return;


	static SDL_Texture* buttontextures_1_3 = buttontext();

	escolha1surf_1_3 = TTF_RenderText_Blended(font, "Perguntar sobre", 0, color);
	escolha1text_1_3 = SDL_CreateTextureFromSurface(renderer, escolha1surf_1_3);

	escolha2surf_1_3 = TTF_RenderText_Blended(font, "Esconder", 0, color);
	escolha2text_1_3 = SDL_CreateTextureFromSurface(renderer, escolha2surf_1_3);

	escolha3surf_1_3 = TTF_RenderText_Blended(font, "Entregar os papéis", 0, color);
	escolha3text_1_3 = SDL_CreateTextureFromSurface(renderer, escolha3surf_1_3);


	SDL_DestroySurface(escolha1surf_1_3);
	SDL_DestroySurface(escolha2surf_1_3);



	perguntar_sobre = new Button(
		resolution.x - resolution.x / 3,
		resolution.y - resolution.y / 1.5,
		350,
		50,
		buttontextures_1_3,
		escolha1text_1_3
	);
	esconder = new Button(
		resolution.x - resolution.x / 3,
		resolution.y - resolution.y / 1.5 + 50,
		350,
		50,
		buttontextures_1_3,
		escolha2text_1_3
	);
	entregar_papeis = new Button(
		resolution.x - resolution.x / 3,
		resolution.y - resolution.y / 1.5 + 100,
		350,
		50,
		buttontextures_1_3,
		escolha3text_1_3
	);
}

void DarPapelProBiologo_Update()
{
	perguntar_sobre->render(renderer);
	esconder->render(renderer);
	entregar_papeis->render(renderer);

	if (hasEvent && keyb.type == SDL_EVENT_KEY_DOWN && !keyb.key.repeat)
	{

		if (keyb.key.key == SDLK_1)
		{
			cena1decisaopapelreciclado.perguntar_sobre = true;
			SDL_Log("Perguntar sobre");

			cena1decisaopapelreciclado.ativo = false;
			hasEvent = true;
			keyb = SDL_Event{};
		}
		if (keyb.key.key == SDLK_2)
		{
			cena1decisaopapelreciclado.esconder = true;
			SDL_Log("Esconder");

			cena1decisaopapelreciclado.ativo = false;
			hasEvent = true;
			keyb = SDL_Event{};
		}
		if (keyb.key.key == SDLK_3)
		{
			cena1decisaopapelreciclado.entregar_papeis = true;
			SDL_Log("Entregar papeis");

			cena1decisaopapelreciclado.ativo = false;
			hasEvent = true;
			keyb = SDL_Event{};
		}
	}
}

void DarPapelProBiologo_Destroy()
{
	delete perguntar_sobre;
	delete esconder;
	delete entregar_papeis;

	perguntar_sobre = nullptr;
	esconder = nullptr;
	entregar_papeis = nullptr;

	SDL_DestroyTexture(escolha1text_1_3);
	SDL_DestroyTexture(escolha2text_1_3);
	SDL_DestroyTexture(escolha3text_1_3);

	escolha1text_1_3 = nullptr;
	escolha2text_1_3 = nullptr;
	escolha3text_1_3 = nullptr;
}