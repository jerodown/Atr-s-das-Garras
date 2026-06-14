#include "gamevoid.hpp"

void fullscene()
{
	if (cena1papeis.ativo)
	{
		DecidirPapeis_Init();
		DecidirPapeis_Update();

	}
	if (cena1papeis.papiro_egipcio)
	{
		cena1roubo.ativo = true;
		cena1papeis.ativo = false;
		RoubarOuNao_Init();
		RoubarOuNao_Update();

		DecidirPapeis_Destroy();
	}
	if (cena1roubo.NaoSouAssim)
	{
		cena1papeis.papiro_egipcio = false;
		cena1roubo.ativo = false;
		cena1papeis.ativo = true;
		cena1roubo.NaoSouAssim = false;

		RoubarOuNao_Destroy();
	}
	if (cena1roubo.Roubar)
	{
		cena1papeis.ativo = false;
		cena1roubo.ativo = false;
		cena1roubo.Roubar = false;

		RoubarOuNao_Destroy();
	}
	if (cena1papeis.papel_a4)
	{
		cena1decisaopapel.ativo = true;

		QuemFicaComOsPapeis_Init();
		QuemFicaComOsPapeis_Update();

		DecidirPapeis_Destroy();
	}
	if (cena1decisaopapel.Para_Velha)
	{
		cena1papeis.papel_a4 = false;

		QuemFicaComOsPapeis_Destroy();
	}
	if (cena1decisaopapel.Para_Biologo)
	{
		cena1papeis.papel_a4 = false;


		QuemFicaComOsPapeis_Destroy();
	}
	if (cena1decisaopapel.Egoista)
	{
		cena1papeis.papel_a4 = false;


		QuemFicaComOsPapeis_Destroy();
	}






	if (cena1papeis.papel_reciclado && !cena1decisaopapelreciclado.perguntar_sobre)
	{
		cena1decisaopapelreciclado.ativo = true;


		DarPapelProBiologo_Init();
		DarPapelProBiologo_Update();

		DecidirPapeis_Destroy();
	}

	if (cena1decisaopapelreciclado.perguntar_sobre)
	{
		DarPapelProBiologo_Destroy();

		cena1decisaopapelreciclado.perguntar_sobre = false;
	}



}