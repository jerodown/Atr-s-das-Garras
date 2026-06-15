#pragma once
#include <SDL3/SDL.h>
#include <SDL3/SDL_ttf.h>
#include <SDL3/SDL_image.h>
#include <vector>

struct Estado
{
	bool introducao = true;
	bool pause = false;
	bool jogo = false;
	bool cutscene = false;
	bool cutscene2 = false;
	bool ativo = true;
};

struct Papiro_PapelNormal_PapelReciclado
{

	bool ativo = false;
	bool papiro_egipcio = false;
	bool papel_a4 = false;
	bool papel_reciclado = false;

};

struct Roubar_NaoSouAssim
{
	bool ativo = false;
	bool Roubar = false;
	bool NaoSouAssim = false;

};

struct ParaVelha_ParaBiologo_Egoista_RasgarPapel
{
	bool ativo = false;
	bool Para_Velha = false;
	bool Para_Biologo = false;
	bool Egoista = false;
};

struct PerguntarSobre_Esconder_EntregarPapeis
{
	bool ativo = false;
	bool perguntar_sobre = false;
	bool esconder = false;
	bool entregar_papeis = false;

};

struct Choice_1e
{
	bool choice1_1e;
	bool choice2_1e;
	bool choice3_1e;
	bool choice4_1e;

};

struct Choice_1f
{
	bool choice1_1f = false;
	bool choice2_1f = false;
	bool choice3_1f = false;
	bool choice4_1f = false;

};

struct Choice_1g
{
	bool choice1_1g = false;
	bool choice2_1g = false;
	bool choice3_1g = false;
	bool choice4_1g = false;

};

extern Papiro_PapelNormal_PapelReciclado cena1papeis;

extern Roubar_NaoSouAssim cena1roubo;

extern ParaVelha_ParaBiologo_Egoista_RasgarPapel cena1decisaopapel;

extern PerguntarSobre_Esconder_EntregarPapeis cena1decisaopapelreciclado;

extern Estado estado;

extern SDL_Renderer* renderer;

extern SDL_Event* event;

extern SDL_Event keyb;

extern bool hasEvent;

extern SDL_Color color;

extern void debug();

extern std::vector<SDL_Texture*> cutsceneFrames;

extern int frameatual;
extern Uint64 ultimoframe;