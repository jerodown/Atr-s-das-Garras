#include "roubar_ou_nao.hpp"

Button* roubar = nullptr;
Button* nao_sou_assim = nullptr;

Button* b14 = nullptr;
Button* b24 = nullptr;


SDL_Surface* botao14surf;
SDL_Texture* botao14text;

SDL_Surface* botao24surf;
SDL_Texture* botao24text;

SDL_Surface* escolha1surf_1_1;
SDL_Texture* escolha1text_1_1;


SDL_Surface* escolha2surf_1_1;
SDL_Texture* escolha2text_1_1;


void RoubarOuNao_Init() {
	if (roubar != nullptr)
		return;


	static SDL_Texture* buttontextures_1_1 = buttontext();

	escolha1surf_1_1 = TTF_RenderText_Blended(font, "Roubar       ", 0, color);
	escolha1text_1_1 = SDL_CreateTextureFromSurface(renderer, escolha1surf_1_1);

	escolha2surf_1_1 = TTF_RenderText_Blended(font, "Não sou assim", 0, color);
	escolha2text_1_1 = SDL_CreateTextureFromSurface(renderer, escolha2surf_1_1);

	SDL_DestroySurface(escolha1surf_1_1);
	SDL_DestroySurface(escolha2surf_1_1);

	botao14surf = TTF_RenderText_Blended(font, "   1   ", 0, color);
	botao24surf = TTF_RenderText_Blended(font, "   2   ", 0, color);

	botao14text = SDL_CreateTextureFromSurface(renderer, botao14surf);
	botao24text = SDL_CreateTextureFromSurface(renderer, botao24surf);

	SDL_DestroySurface(botao14surf);
	SDL_DestroySurface(botao24surf);


	roubar = new Button(
		resolution.x - resolution.x / 3,
		resolution.y - resolution.y / 1.5,
		350,
		50,
		buttontextures_1_1,
		escolha1text_1_1,
		CHOICEBUTTON
	);

	b14 = new Button(
		resolution.x - resolution.x / 3 - 60,
		resolution.y - resolution.y / 1.5,
		50,
		50,
		buttontextures_1_1,
		botao14text,
		ENUMBUTTON
	);

	nao_sou_assim = new Button(
		resolution.x - resolution.x / 3,
		resolution.y - resolution.y / 1.5 + 55,
		350,
		50,
		buttontextures_1_1,
		escolha2text_1_1,
		CHOICEBUTTON
	);

	b24 = new Button(
		resolution.x - resolution.x / 3 - 60,
		resolution.y - resolution.y / 1.5 + 55,
		50,
		50,
		buttontextures_1_1,
		botao24text,
		ENUMBUTTON
	);

}

void RoubarOuNao_Update()
{
	roubar->render(renderer);
	nao_sou_assim->render(renderer);

	b14->render(renderer);
	b24->render(renderer);

	if (hasEvent && keyb.type == SDL_EVENT_KEY_DOWN && !keyb.key.repeat)
	{

		if (keyb.key.key == SDLK_1)
		{
			cena1roubo.Roubar = true;
			cena1papeis.papiro_egipcio = false;
			SDL_Log("Roubar");

			hasEvent = true;
			keyb = SDL_Event{};
		}
		if (keyb.key.key == SDLK_2)
		{
			cena1roubo.NaoSouAssim = true;
			cena1papeis.papiro_egipcio = false;
			SDL_Log("Nao sou assim");

			hasEvent = true;
			keyb = SDL_Event{};
		}
	}
}

void RoubarOuNao_Destroy()
{
	delete roubar;
	delete nao_sou_assim;

	roubar = nullptr;
	nao_sou_assim = nullptr;

	SDL_DestroyTexture(escolha1text_1_1);
	SDL_DestroyTexture(escolha2text_1_1);

	escolha1text_1_1 = nullptr;
	escolha2text_1_1 = nullptr;

	delete b14;
	delete b24;

	b14 = nullptr;
	b24 = nullptr;

	SDL_DestroyTexture(botao14text);
	SDL_DestroyTexture(botao24text);

	botao14text = nullptr;
	botao24text = nullptr;
}



void CutsceneRoubo_Init()
{
	if (!cutsceneFrames.empty())
		return;


	frameatual = 0;
	ultimoframe = SDL_GetTicks();

	for (int i = 1; ; i++)
	{
		char caminho[125];
		sprintf_s(caminho,
			sizeof(caminho),
			"C:/Atrás das Garras/Assets/Sprites/Video 1/roubocutscene (%d).png",
			i);

		SDL_Surface* surf = IMG_Load(caminho);

		if (!surf)
			break;

		SDL_Texture* tex =
			SDL_CreateTextureFromSurface(
				renderer,
				surf
			);

		cutsceneFrames.push_back(tex);

		SDL_DestroySurface(surf);
	}
}
void CutsceneRoubo_Update()
{

	Uint64 agora = SDL_GetTicks();

	if (frameatual >= cutsceneFrames.size())
	{
		estado.cutscene = false;
		cena1roubo.Roubar = false;
		estado.introducao = true;
		return;
	}

	SDL_FRect tela = {
		0,
		0,
		(float)resolution.x,
		(float)resolution.y
	};

	SDL_RenderTexture(
		renderer,
		cutsceneFrames[frameatual],
		nullptr,
		&tela
	);

	if (agora - ultimoframe >= 33)
	{
		frameatual++;
		ultimoframe = agora;
	}
}
void CutsceneRoubo_Destroy()
{
	for (SDL_Texture* tex : cutsceneFrames)
	{
		SDL_DestroyTexture(tex);
	}

	cutsceneFrames.clear();
}