#include "decidir_papeis.hpp"

Button* papiro = nullptr;
Button* papel_a4 = nullptr;
Button* papel_reciclado = nullptr;

SDL_Surface* escolha1surf;
SDL_Texture* escolha1text;

SDL_Surface* escolha2surf;
SDL_Texture* escolha2text;

SDL_Surface* escolha3surf;
SDL_Texture* escolha3text;

Button* b11 = nullptr;
Button* b21 = nullptr;
Button* b31 = nullptr;

SDL_Surface* botao11surf;
SDL_Texture* botao11text;

SDL_Surface* botao21surf;
SDL_Texture* botao21text;

SDL_Surface* botao31surf;
SDL_Texture* botao31text;

void DecidirPapeis_Init() {
	if (papiro != nullptr)
		return;


	static SDL_Texture* buttontextures = buttontext();

	escolha1surf = TTF_RenderText_Blended(font, "Papíro do Egito ", 0, color);
	escolha2surf = TTF_RenderText_Blended(font, "Papel A4        ", 0, color);
	escolha3surf = TTF_RenderText_Blended(font, "Papel reciclável", 0, color);

	escolha1text = SDL_CreateTextureFromSurface(renderer, escolha1surf);
	escolha2text = SDL_CreateTextureFromSurface(renderer, escolha2surf);
	escolha3text = SDL_CreateTextureFromSurface(renderer, escolha3surf);

	botao11surf = TTF_RenderText_Blended(font, "   1   ", 0, color);
	botao21surf = TTF_RenderText_Blended(font, "   2   ", 0, color);
	botao31surf = TTF_RenderText_Blended(font, "   3   ", 0, color);

	botao11text = SDL_CreateTextureFromSurface(renderer, botao11surf);
	botao21text = SDL_CreateTextureFromSurface(renderer, botao21surf);
	botao31text = SDL_CreateTextureFromSurface(renderer, botao31surf);



	SDL_DestroySurface(escolha1surf);
	SDL_DestroySurface(escolha2surf);
	SDL_DestroySurface(escolha3surf);

	SDL_DestroySurface(botao11surf);
	SDL_DestroySurface(botao21surf);
	SDL_DestroySurface(botao31surf);

	papiro = new Button(
		resolution.x - resolution.x / 3,
		resolution.y - resolution.y / 1.5,
		350,
		50,
		buttontextures,
		escolha1text,
		CHOICEBUTTON
	);
	b11 = new Button(
		resolution.x - resolution.x / 3 - 60,
		resolution.y - resolution.y / 1.5,
		50,
		50,
		buttontextures,
		botao11text,
		ENUMBUTTON
	);



	papel_a4 = new Button(
		resolution.x - resolution.x / 3,
		resolution.y - resolution.y / 1.5 + 55,
		350,
		50,
		buttontextures,
		escolha2text,
		CHOICEBUTTON
	);
	b21 = new Button(
		resolution.x - resolution.x / 3 - 60,
		resolution.y - resolution.y / 1.5 + 55,
		50,
		50,
		buttontextures,
		botao21text,
		ENUMBUTTON
	);



	papel_reciclado = new Button(
		resolution.x - resolution.x / 3,
		resolution.y - resolution.y / 1.5 + 110 ,
		350,
		50,
		buttontextures,
		escolha3text,
		CHOICEBUTTON
	);
	b31 = new Button(
		resolution.x - resolution.x / 3 - 60,
		resolution.y - resolution.y / 1.5 + 110,
		50,
		50,
		buttontextures,
		botao31text,
		ENUMBUTTON
	);




}

void DecidirPapeis_Update()
{
	papiro->render(renderer);
	papel_a4->render(renderer);
	papel_reciclado->render(renderer);

	b11->render(renderer);
	b21->render(renderer);
	b31->render(renderer);

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

void DecidirPapeis_Destroy()
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

	delete b11;
	delete b21;
	delete b31;

	b11 = nullptr;
	b21 = nullptr;
	b31 = nullptr;

	SDL_DestroyTexture(botao11text);
	SDL_DestroyTexture(botao21text);
	SDL_DestroyTexture(botao31text);

	botao11text = nullptr;
	botao21text = nullptr;
	botao31text = nullptr;
}