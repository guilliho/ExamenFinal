#pragma once 
#include "Computador.h"

Computador::Computador() : pFabricaPC(nullptr), pMemoria(nullptr), pProcesador(nullptr), pSistemaOperativo(nullptr)
{

}

Computador::~Computador()
{
	delete pFabricaPC;
	delete pMemoria;
	delete pProcesador;
	delete pSistemaOperativo;
}

void Computador::ConfigurarTipoPC(int tipoPC)
{
	/*
		1 - Windows
		2 - Mac
	*/
	switch (tipoPC)
	{
	case 1:
		pFabricaPC = new FabricaWindowsPC();
		break;
	case 2:
		pFabricaPC = new FabricaMacPC();
		break;
	default:
		pFabricaPC = new FabricaWindowsPC();
		break;
	}
}

void Computador::ConfigurarTipoMemoria(int tipoMemoria)
{
	pMemoria = pFabricaPC->CrearMemoria(tipoMemoria);
}

void Computador::ConfigurarTipoProcesador(int tipoProcesador)
{
	pProcesador = pFabricaPC->CrearProcesador(tipoProcesador);
}

void Computador::ConfigurarTipoSistemaOperativo(int tipoSistemaOperativo)
{
	pSistemaOperativo = pFabricaPC->CrearSistemaOperativo(tipoSistemaOperativo);
}

string Computador::ObtnerTipoMemoria()
{
	pMemoria->ObtenerTipoMemoria();
}

string Computador::ObtenerTipoProcesador()
{
	pProcesador->ObtenerTipoProcesador();
}

string Computador::ObtenerTipoSistemaOperativo()
{
	pSistemaOperativo->ObtenerTipoSistemaOperativo();
}