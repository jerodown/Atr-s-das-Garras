#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_image.h>
#include <SDL3/SDL_ttf.h>
#include <vector>
#include "include/conditions.hpp"

#include "Assets/Button/buttonchoice.hpp"
#include "Assets/Screen/screen.hpp"
#include "Scenes/Scene Mercado/decidir_papeis.hpp"
#include "Scenes/Scene Mercado/roubar_ou_nao.hpp"
#include "Scenes/Scene Mercado/escolher_quem_fica_com_os_papeis.hpp"
#include "Scenes/Scene Mercado/dar_papel_pro_biologo.hpp"
#include "gamevoid.hpp"
#include "Scenes/estado.hpp"

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();

	cena1papeis.ativo = true;

	Display_found();

	Create_screen();


	renderer = SDL_CreateRenderer(window, nullptr);


	ttf();

	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
	keyb = *event;

	if (event->type == SDL_EVENT_KEY_DOWN)
	{
		SDL_Log("Tecla pressionada: %d", event->key.key);
	}


	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate)
{

	SDL_SetRenderDrawColor(renderer, 255, 100, 100, 255);
	SDL_RenderClear(renderer);

	if (estado.introducao)
	{
		Introducao_Init();
		CutsceneRoubo_Destroy();
		cena1decisaopapel.ativo = false;
		cena1decisaopapel.Egoista = false;
		cena1decisaopapel.Para_Biologo = false;
		cena1decisaopapel.Para_Velha = false;

		cena1decisaopapelreciclado.ativo = false;
		cena1decisaopapelreciclado.entregar_papeis = false;
		cena1decisaopapelreciclado.esconder = false;
		cena1decisaopapelreciclado.perguntar_sobre = false;

		cena1papeis.ativo = false;
		cena1papeis.papel_a4 = false;
		cena1papeis.papel_reciclado = false;
		cena1papeis.papiro_egipcio = false;

		cena1roubo.ativo = false;
		cena1roubo.NaoSouAssim = false;
		cena1roubo.Roubar = false;
		estado.cutscene2 = true;
		estado.cutscene = false;
	}
	if (estado.cutscene2 == true)
	{
		Introducao_Update();
	}
	debug();


	if (estado.jogo)
	{
		estado.cutscene2 = false;
		Introducao_Destroy();
		fullscene();
	}

	SDL_RenderPresent(renderer);

	if (!estado.ativo)
	{
		return SDL_APP_SUCCESS;
	}

	return SDL_APP_CONTINUE;
}
void SDL_AppQuit(void* appstate, SDL_AppResult result)
{

	Introducao_Destroy();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();

	SDL_Quit();
}