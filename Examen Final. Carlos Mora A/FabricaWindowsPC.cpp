#pragma once
#include "FabricaWindowsPC.h"

Memoria* FabricaWindowsPC::CrearMemoria(int tipo)
{
	/*
		1 - Kingston
		2 - DDR3
		3 - DDR5
	*/
	switch(tipo)
	{
	case 1 :
		return new Kingston();
	case 2 :
		return new DDRTres();
	case 3:
		return new DDRCinco();	
	default:
		return new Kingston();
	}
}

Procesador* FabricaWindowsPC::CrearProcesador(int tipo)
{
	/*
		1 - AMD
		2 - Cyrix
		3 - SamSung
	*/
	switch(tipo)
	{
	case 1 :
		return new AMD();
	case 2 :
		return new Cyrix();
	case 3:
		return new SamSung();	
	default:
		return new AMD();
	}
}

SistemaOperativo* FabricaWindowsPC::CrearSistemaOperativo(int tipo)
{
	/*
		1 - Windows XP
		2 - Windows 7
		3 - Windows Vista
	*/
	switch(tipo)
	{
	case 1 :
		return new WindowsXP();
	case 2 :
		return new WindowsSiete();
	case 3:
		return new WindowsVista();	
	default:
		return new WindowsXP();
	}
}