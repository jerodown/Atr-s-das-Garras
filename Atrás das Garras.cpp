#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_image.h>
#include <SDL3/SDL_ttf.h>
#include <vector>
#include "include/conditions.hpp"

#include "Assets/Button/buttonchoice.hpp"
#include "Assets/Screen/screen.hpp"
#include "Scenes/Scene Mercado/mercado_1_0.hpp"
#include "Scenes/Scene Mercado/mercado_1_1.hpp"
#include "Scenes/Scene Mercado/mercado_1_2.hpp"
#include "Scenes/Scene Mercado/mercado_1_3.hpp"
#include "Scenes/Scene Mercado/mercado_1_4.hpp"
#include "gamevoid.hpp"

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

	debug();

		if (cena1roubo.ativo == false && cena1decisaopapel.ativo == false)
		{
			Mercado_1_0_Init();
			Mercado_1_0_Update();

		}
		if (cena1papeis.papiro_egipcio)
		{
			cena1roubo.ativo = true;
			Mercado_1_1_Init();
			Mercado_1_1_Update();

			Mercado_1_0_Destroy();
		}
		if (cena1roubo.NaoSouAssim)
		{
			cena1papeis.papiro_egipcio = false;
			cena1roubo.ativo = false;
			cena1roubo.NaoSouAssim = false;

			Mercado_1_1_Destroy();
		}
		if (cena1roubo.Roubar)
		{
			cena1papeis.ativo = false;
			cena1roubo.ativo = false;

			Mercado_1_0_Destroy();
			Mercado_1_1_Destroy();
		}
		if (cena1papeis.papel_a4)
		{
			cena1decisaopapel.ativo = true;

			Mercado_1_2_Init();
			Mercado_1_2_Update();

			Mercado_1_0_Destroy();
		}
		if (cena1decisaopapel.Para_Velha)
		{

			Mercado_1_2_Destroy();
		}
		if (cena1decisaopapel.Para_Biologo)
		{


			Mercado_1_2_Destroy();
		}
		if (cena1decisaopapel.Egoista)
		{


			Mercado_1_2_Destroy();
		}
		if (cena1decisaopapel.Rasgar_Papel)
		{


			Mercado_1_2_Destroy();
		}


	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;
}
void SDL_AppQuit(void* appstate, SDL_AppResult result)
{


	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();

	SDL_Quit();
}