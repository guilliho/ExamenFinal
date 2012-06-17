#pragma once
#include<iostream>
#include<fstream>
#include<Windows.h>
#include "Usuario.h"
#include "ManejadorArchivos.h"
using namespace std;
class Interfaz
{
private:
	Usuario* usuario;
	int tipoPC;
public:
	Interfaz();
	~Interfaz();
	int Ingresar();
	int MenuPrincipal();
	int MenuCreacionYMantenimiento();
	int MenuOSWindows(); //menu de SO para maquinas windows
	int MenuRAMWindows(); //menu de memorias para windows
	int MenuCPUWindows();  //menu de procesadores para windows
	int MenuOSMac(); //menu de SO maquinas Mac
	int MenuRAMMac(); // menu de memorias para Mac
	int MenuCPUMac(); // menu de procesadores para Mac
	Usuario* IngresarUsuario();
	void CrearPC(int tipoPC);
	
	void CrearMaquina();
	void MostrarMaquinas();
	void GuardarMaquinas();
	void CargarMaquinas();
	void ModificarMaquinas();
	void EliminarMaquinas();
	void ComponentesWindows();
	void ComponentesMac();
	//seguro hay q agregar mas metodos...


};

