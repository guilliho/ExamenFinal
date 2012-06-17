#pragma once
#include<iostream>
#include<string>

using namespace std;

class Procesador
{
public:
	virtual string ObtenerTipoProcesador() = 0;
};