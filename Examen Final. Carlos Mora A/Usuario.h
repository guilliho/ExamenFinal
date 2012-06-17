#pragma once
#include<iostream>
#include<string>
#include "Lista.h"
#include "Computador.h"
#include "ManejadorArchivos.h"
#include "Iterator.h"

using namespace std;

class Usuario
{
private:
	string cedula;
	Computador* pComputadoraActual;
	List<Computador>* pComputadoras;
public:
	Usuario();
	~Usuario();
	void ConfigurarCedula(string cedula);
	string ObtenerCedula();
	void ConfigurarTipoPC(int tipoPC);
	void ConfigurarTipoMemoria(int tipoMemoria);
	void ConfigurarTipoProcesador(int tipoProcesador);
	void ConfigurarTipoSistemaOperativo(int tipoSistemaOperativo);
	void MostrarPCS();
	void GuardarPCS();
	void CargarPCS();
	void ModificarPC(int posicion);
	void EliminarPCS();
};