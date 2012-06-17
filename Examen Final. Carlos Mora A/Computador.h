#pragma once
#include<iostream>
#include<string>
#include "FabricaPC.h"
#include "FabricaWindowsPC.h"
#include "FabricaMacPC.h"
#include "Memoria.h"
#include "Procesador.h"
#include "SistemaOperativo.h"

using namespace std;

class Computador
{
private:
	FabricaPC* pFabricaPC;
	Memoria* pMemoria;
	Procesador* pProcesador;
	SistemaOperativo* pSistemaOperativo;
public:
	Computador();
	~Computador();
	void ConfigurarTipoPC(int tipoPC);
	void ConfigurarTipoMemoria(int tipoMemoria);
	void ConfigurarTipoProcesador(int tipoProcesador);
	void ConfigurarTipoSistemaOperativo(int tipoSistemaOperativo);
	string ObtnerTipoMemoria();
	string ObtenerTipoProcesador();
	string ObtenerTipoSistemaOperativo();
}