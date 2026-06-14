#include "escolher_quem_fica_com_os_papeis.hpp"

Button* para_a_velha = nullptr;
Button* para_o_biologo = nullptr;
Button* egoista = nullptr;

SDL_Surface* escolha1surf_1_2;
SDL_Texture* escolha1text_1_2;


SDL_Surface* escolha2surf_1_2;
SDL_Texture* escolha2text_1_2;


SDL_Surface* escolha3surf_1_2;
SDL_Texture* escolha3text_1_2;


void QuemFicaComOsPapeis_Init() {
	if (para_a_velha != nullptr)
		return;


	static SDL_Texture* buttontextures_1_2 = buttontext();

	escolha1surf_1_2 = TTF_RenderText_Blended(font, "Para a velha   ", 0, color);
	escolha1text_1_2 = SDL_CreateTextureFromSurface(renderer, escolha1surf_1_2);

	escolha2surf_1_2 = TTF_RenderText_Blended(font, "Para o biólogo", 0, color);
	escolha2text_1_2 = SDL_CreateTextureFromSurface(renderer, escolha2surf_1_2);

	escolha3surf_1_2 = TTF_RenderText_Blended(font, "Egoísta       ", 0, color);
	escolha3text_1_2 = SDL_CreateTextureFromSurface(renderer, escolha3surf_1_2);

	SDL_DestroySurface(escolha1surf_1_2);
	SDL_DestroySurface(escolha2surf_1_2);
	SDL_DestroySurface(escolha3surf_1_2);

	para_a_velha = new Button(
		resolution.x - resolution.x / 3,
		resolution.y - resolution.y / 1.5,
		350,
		50,
		buttontextures_1_2,
		escolha1text_1_2
	);
	para_o_biologo = new Button(
		resolution.x - resolution.x / 3,
		resolution.y - resolution.y / 1.5 + 50,
		350,
		50,
		buttontextures_1_2,
		escolha2text_1_2
	);
	egoista = new Button(
		resolution.x - resolution.x / 3,
		resolution.y - resolution.y / 1.5 + 100,
		350,
		50,
		buttontextures_1_2,
		escolha3text_1_2
	);
}

void QuemFicaComOsPapeis_Update()
{
	para_a_velha->render(renderer);
	para_o_biologo->render(renderer);
	egoista->render(renderer);

	if (hasEvent && keyb.type == SDL_EVENT_KEY_DOWN && !keyb.key.repeat)
	{

		if (keyb.key.key == SDLK_1)
		{
			cena1decisaopapel.Para_Velha = true;
			SDL_Log("Para a velha");

			cena1roubo.ativo = false;
			hasEvent = true;
			keyb = SDL_Event{};
		}
		if (keyb.key.key == SDLK_2)
		{
			cena1decisaopapel.Para_Biologo = true;
			cena1papeis.papiro_egipcio = false;
			SDL_Log("Para o biologo");

			cena1roubo.ativo = false;
			hasEvent = true;
			keyb = SDL_Event{};
		}
		if (keyb.key.key == SDLK_3)
		{
			cena1decisaopapel.Egoista = true;
			SDL_Log("Egoista");

			cena1roubo.ativo = false;
			hasEvent = true;
			keyb = SDL_Event{};
		}

	}
}

void QuemFicaComOsPapeis_Destroy()
{
	delete para_a_velha;
	delete para_o_biologo;
	delete egoista;

	para_a_velha = nullptr;
	para_o_biologo = nullptr;
	egoista = nullptr;

	SDL_DestroyTexture(escolha1text_1_2);
	SDL_DestroyTexture(escolha2text_1_2);
	SDL_DestroyTexture(escolha3text_1_2);

	escolha1text_1_2 = nullptr;
	escolha2text_1_2 = nullptr;
	escolha3text_1_2 = nullptr;
}