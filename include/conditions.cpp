#include "conditions.hpp"

SDL_Renderer* renderer = nullptr;

Estado estado;

Papiro_PapelNormal_PapelReciclado cena1papeis;

Roubar_NaoSouAssim cena1roubo;

ParaVelha_ParaBiologo_Egoista_RasgarPapel cena1decisaopapel;

PerguntarSobre_Esconder_EntregarPapeis cena1decisaopapelreciclado;

SDL_Event* event;

SDL_Event keyb;
bool hasEvent = false;

SDL_Color color = { 0, 0, 0, 255 };


void debug(){
	hasEvent = true;

}