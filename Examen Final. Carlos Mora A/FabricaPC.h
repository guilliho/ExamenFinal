#pragma once
#include<iostream>
#include<string>
#include "Memoria.h"
#include "Procesador.h"
#include "SistemaOperativo.h"

using namespace std;

class FabricaPC
{
public:
	 virtual Memoria* CrearMemoria(int tipo) = 0;
	 virtual Procesador* CrearProcesador(int tipo) = 0;
	 virtual SistemaOperativo* CrearSistemaOperativo(int tipo) = 0;
};