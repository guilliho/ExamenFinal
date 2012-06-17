#pragma once
#include "Usuario.h"

Usuario::Usuario() : pComputadoraActual(nullptr), pComputadoras(nullptr)
{
	this->haCargadoArchivo = false;
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
	if (pComputadoraActual == nullptr)
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
	int contador = 0;
	Iterator<Computador>* i = new Iterator<Computador>();
	i->setActual(pComputadoras->getPrimero());
	if(!pComputadoras->isempty())
	{
		while(!i->isDone())
		{
			cout<<contador<<" - "<<i->Mostrar();
			i->Siguiente();
			contador++;
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
	if (pComputadoraActual == nullptr)
	{
		this->pComputadoraActual = new Computador();
		this->pComputadoraActual = this->pComputadoras->modificar(posicion);
	}
	else
	{
		free(pComputadoraActual);
		this->pComputadoraActual = this->pComputadoras->modificar(posicion);
	}
}

void Usuario::EliminarPCS()
{
	this->pComputadoras->limpiar();
	ManejadorArchivos::LimpiarArchivo("data/" + this->cedula + "/maquinas.txt");
}

bool Usuario::ObtenerHaCargadoArchivo()
{
	return this->haCargadoArchivo;
}

void Usuario::ConfigurarHaCargadoArchivo(bool haCargadoArchivo)
{
	this->haCargadoArchivo = haCargadoArchivo;
}

Computador* Usuario::ObtenerComputadorActual()
{
	return this->pComputadoraActual;
}