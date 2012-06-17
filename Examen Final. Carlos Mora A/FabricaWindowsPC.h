#pragma once
#include "FabricaPC.h"
#include "Kingston.h"
#include "DDRTres.h"
#include "DDRCinco.h"
#include "AMD.h"
#include "Cyrix.h"
#include "SamSung.h"
#include "WindowsXP.h"
#include "WindowsSiete.h"
#include "WindowsVista.h"

class FabricaWindowsPC : public FabricaPC
{
public:
	Memoria* CrearMemoria(int tipo);
	Procesador* CrearProcesador(int tipo);
	SistemaOperativo* CrearSistemaOperativo(int tipo);
};