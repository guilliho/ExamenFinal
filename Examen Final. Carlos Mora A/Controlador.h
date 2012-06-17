#pragma once
#include"Interfaz.h"
#include<iostream>
using namespace std;

class Controlador
{
private:
	Interfaz* i;
public:
	Controlador();
	~Controlador();
	void inicio();
	void menuPrincipal();
	void menuCreacionyMantenimiento();
};

