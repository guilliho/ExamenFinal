#pragma once
#include "FabricaPC.h"
#include "Simm.h"
#include "Varna.h"
#include "Sigma.h"
#include "INTEL.h"
#include "CELL.h"
#include "MOTOROLA.h"
#include "MacOS.h"
#include "Unix.h"
#include "FreeBSD.h"

class FabricaMacPC : public FabricaPC
{
public:
	Memoria* CrearMemoria(int tipo);
	Procesador* CrearProcesador(int tipo);
	SistemaOperativo* CrearSistemaOperativo(int tipo);
};