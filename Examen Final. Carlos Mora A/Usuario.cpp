#pragma once
#include "Usuario.h"

Usuario::Usuario() : pComputadoraActual(nullptr), pComputadoras(nullptr)
{

}

Usuario::~Usuario()
{
	delete pComputadoraActual;
	delete pComputadoras;
}

void Usuario::ConfigurarCedula(string cedula)
{
	this->cedula = cedula;
}

string Usuario::ObtenerCedula()
{
	return this->cedula;
}

void Usuario::ConfigurarTipoPC(int tipoPC)
{
	if (pComputadoraActual != nullptr)
	{
		pComputadoraActual = new Computador();
	}
	else
	{
		free(pComputadoraActual);
	}
	
	this->pComputadoraActual->ConfigurarTipoPC(tipoPC);

}

void Usuario::ConfigurarTipoMemoria(int tipoMemoria)
{
	this->pComputadoraActual->ConfigurarTipoMemoria(tipoMemoria);
}

void Usuario::ConfigurarTipoProcesador(int tipoProcesador)
{
	this->pComputadoraActual->ConfigurarTipoProcesador(tipoProcesador);
}

void Usuario::ConfigurarTipoSistemaOperativo(int tipoSistemaOperativo)
{
	this->pComputadoraActual->ConfigurarTipoSistemaOperativo(tipoSistemaOperativo);
}

void Usuario::MostrarPCS()
{
	Iterator<Computador>* i = new Iterator<Computador>();
	i->setActual(pComputadoras->getPrimero());
	if(!pComputadoras->isempty())
	{
		while(!i->isDone())
		{
			i->Mostrar();
			i->Siguiente();
		}
	}
	delete i;

	ManejadorArchivos::MostrarArchivo("data/" + this->cedula + "/maquinas.txt");
}

void Usuario::GuardarPCS()
{
	ManejadorArchivos::GuardarArchivo("data/" + this->cedula + "/maquinas.txt", this->pComputadoras);
}

void Usuario::CargarPCS()
{
	List<Computador>* pComputadorasArchivo = ManejadorArchivos::LeerArchivo("/data" + this->cedula + "/maquinas.txt");
	Iterator<Computador>* i = new Iterator<Computador>();
	i->setActual(pComputadorasArchivo->getPrimero());
	if(!pComputadorasArchivo->isempty())
	{
		while(!i->isDone())
		{
			this->pComputadoras->insertar(i->getActual()->getInfo());
			i->Siguiente();
		}
	}
	delete i;
	delete pComputadorasArchivo;
}

void Usuario::ModificarPC(int posicion)
{
	if (pComputadoraActual != nullptr)
	{
		pComputadoraActual = new Computador();
	}
	else
	{
		free(pComputadoraActual);
	}

	this->pComputadoraActual = this->pComputadoras->modificar(posicion);
}

void Usuario::EliminarPCS()
{
	this->pComputadoras->limpiar();
	ManejadorArchivos::LimpiarArchivo("data/" + this->cedula + "/maquinas.txt");
}
