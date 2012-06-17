#include "Controlador.h"

Controlador::Controlador() : i(nullptr)
{

}

Controlador::~Controlador()
{
	delete i;
}

void Controlador::inicio()
{
	int opc = i->Ingresar();
	do{
		switch(opc)
		{
			case 1:
				i->IngresarUsuario();
				this->menuPrincipal();
				break;
			case 2:
				exit(0);
				break;
		}
	}while(opc!=2);
}

void Controlador::menuPrincipal()
{
	int opc = i->MenuPrincipal();
	i->CrearPC(opc);
}

void Controlador::menuCreacionyMantenimiento()
{
	int opc = i->MenuCreacionYMantenimiento();
	switch(opc)
	{
		case 1:
			i->CrearMaquina();
			break;
		case 2:
			i->MostrarMaquinas(); 
			break;
		case 3:
			i->GuardarMaquinas(); //Manejador de archivos, guardararchivo
			break;
		case 4:
			i->CargarMaquinas(); //Manjador de archivos, leerarchivos
			break;
		case 5:
			i->ModificarMaquinas();
			break;
		case 6:
			i->EliminarMaquinas();
			break;
		case 7:
			menuPrincipal();
			break;
		default:
			menuCreacionyMantenimiento();
			break;
	}
}
