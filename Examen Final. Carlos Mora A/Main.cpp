#pragma once
#include"Controlador.h"
#include<iostream>
using namespace std;

int main()
{
	Controlador* control = new Controlador();
	control->inicio();
	system("pause");
	return 0;
}