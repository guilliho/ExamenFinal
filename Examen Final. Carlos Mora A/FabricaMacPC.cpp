#pragma once
#include "FabricaMacPC.h"

Memoria* FabricaMacPC::CrearMemoria(int tipo)
{
	/*
		1 - Simm
		2 - Varna
		3 - Sigma
	*/
	switch(tipo)
	{
	case 1 :
		return new Simm();
	case 2 :
		return new Varna();
	case 3:
		return new Sigma();	
	default:
		return new Simm();
	}
}

Procesador* FabricaMacPC::CrearProcesador(int tipo)
{
	/*
		1 - INTEL
		2 - CELL
		3 - MOTOROLA
	*/
	switch(tipo)
	{
	case 1 :
		return new INTEL();
	case 2 :
		return new CELL();
	case 3:
		return new MOTOROLA();	
	default:
		return new INTEL();
	}
}

SistemaOperativo* FabricaMacPC::CrearSistemaOperativo(int tipo)
{
	/*
		1 - Mac OS
		2 - Unix
		3 - FreeBSD
	*/
	switch(tipo)
	{
	case 1 :
		return new MacOS();
	case 2 :
		return new Unix();
	case 3:
		return new FreeBSD();	
	default:
		return new MacOS();
	}
}