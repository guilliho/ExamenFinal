#include "Interfaz.h"

Interfaz::Interfaz() : usuario(nullptr)
{

}

Interfaz::~Interfaz()
{
	delete usuario;
}

//al compilar tira unos warnings
int Interfaz::Ingresar()
{
	// llamar al creador de carpeta "data"
	ManejadorArchivos::CrearDirectorioData();

	int opc = 0;
	cout<<"\tBienvenido al Sistema\n"<<endl;
	cout<<"1 - Ingresar Usuario"<<endl;
	cout<<"2 - Salir del Sistema\n"<<endl;
	cout<<"Digite la opcion que desea"<<endl;
	cin>>opc;
	return opc;
}
Usuario* Interfaz::IngresarUsuario()
{
	string ced;
	cout<<"Ingrese el numero de cedula del usuario"<<endl;
	cin.ignore();
	getline(cin, ced);
	Usuario* usuario = new Usuario();
	usuario->ConfigurarCedula(ced);
	return usuario;
	
	//llamar a creador de carpetas
	ManejadorArchivos::CrearDirectorio(ced);
	ManejadorArchivos::CrearArchivo(ced + "/maquinas.txt");
}
int Interfaz::MenuPrincipal()
{
	int opc = 0;
	cout<<"       Menu Principal    "<<endl;
	cout<<usuario->ObtenerCedula()<<endl;
	cout<<"n"<<endl;
	cout<<"Que tipo de maquina desea crear"<<endl;
	cout<<"1 - Maquina tipo Windows"<<endl;
	cout<<"2 - Maquina tipo Mac"<<endl;
	cout<<"3 - Volver al menu de inicio"<<endl;
	cout<<"Ingrese la opcion deseada"<<endl;
	cin>>opc;
	return opc;
}
int Interfaz::MenuCreacionYMantenimiento()
{
	int opc = 0;
	cout<<"          Menu          "<<endl;
	cout<<"Creacion y Mantenimiendo"<<endl;
	cout<<usuario->ObtenerCedula()<<endl;
	cout<<"\n"<<endl;
	cout<<"1 - Crear una nueva maquina"<<endl;
	cout<<"2 - Mostrar las maquinas"<<endl;
	cout<<"3 - Guardar las maquinas"<<endl;
	cout<<"4 - Cargar las maquinas"<<endl;
	cout<<"5 - Modificar las maquinas"<<endl;
	cout<<"6 - Eliminar todas las maquinas"<<endl;
	cout<<"7 - Volver al menu principal"<<endl;
	cin>>opc;
	return opc;
}
int Interfaz::MenuOSWindows()
{
	int opc = 0;
	cout<<"Menu de Sistemas Operativos"<<endl;
	cout<<"PC's tipo Windows"<<endl;
	cout<<"1 - SO Windows XP"<<endl;
	cout<<"2 - SO Windows 7"<<endl;
	cout<<"3 - SO Windows Vista"<<endl;
	cin>>opc;
	usuario->ConfigurarTipoSistemaOperativo(opc);
	return opc;
}
int Interfaz::MenuRAMWindows()
{
	int opc = 0;
	cout<<"Menu de Memoria RAM"<<endl;
	cout<<"PC's tipo Windows"<<endl;
	cout<<"1 - Memoria Kingston"<<endl;
	cout<<"2 - Memoria DDR3"<<endl;
	cout<<"3 - Memoria DDR5"<<endl;
	cin>>opc;
	usuario->ConfigurarTipoMemoria(opc);
	return opc;
}
int Interfaz::MenuCPUWindows()
{
	int opc = 0;
	cout<<"Menu de Microprocesadores"<<endl;
	cout<<"PC's tipo Windows"<<endl;
	cout<<"1 - Procesador AMD"<<endl;
	cout<<"2 - Procesador Cyrix"<<endl;
	cout<<"3 - Procesador Samsung"<<endl;
	cin>>opc;
	usuario->ConfigurarTipoProcesador(opc);
	return opc;
}
int Interfaz::MenuOSMac()
{
	int opc = 0;
	cout<<"Menu de Sistemas Operativos"<<endl;
	cout<<"PC's tipo Mac"<<endl;
	cout<<"1 - SO Macos"<<endl;
	cout<<"2 - SO Unix"<<endl;
	cout<<"3 - SO FreeBSD"<<endl;
	cin>>opc;
	usuario->ConfigurarTipoSistemaOperativo(opc);
	return opc;
}
int Interfaz::MenuRAMMac()
{
	int opc = 0;
	cout<<"Menu de Memoria RAM"<<endl;
	cout<<"PC's tipo Mac"<<endl;
	cout<<"1 - Memoria SIMM"<<endl;
	cout<<"2 - Memoria VARNA"<<endl;
	cout<<"3 - Memoria SIGNMA"<<endl;
	cin>>opc;
	usuario->ConfigurarTipoMemoria(opc);
	return opc;
}
int Interfaz::MenuCPUMac()
{
	int opc = 0;
	cout<<"Menu de Microprocesadores"<<endl;
	cout<<"PC's tipo Mac"<<endl;
	cout<<"1 - Procesador Intel"<<endl;
	cout<<"2 - Procesador Cell"<<endl;
	cout<<"3 - Procesador Motorola"<<endl;
	cin>>opc;
	usuario->ConfigurarTipoProcesador(opc);
	return opc;
}
void Interfaz::CrearMaquina()
{
	usuario->ConfigurarTipoPC(tipoPC);
	if (this->tipoPC == 1)
	{
		Interfaz::ComponentesWindows();
	}
	else 
	{
		Interfaz::ComponentesMac();
	}
}
void Interfaz::CrearPC(int tipoPC)
{
	//llamar al metodo que crea computadoras windows
	this->tipoPC = tipoPC;
}

void Interfaz::CargarMaquinas()
{
	usuario->CargarPCS();
	usuario->ConfigurarHaCargadoArchivo(true);
}
void Interfaz::GuardarMaquinas()
{
	int opc = 0;
	if (usuario->ObtenerHaCargadoArchivo())
	{
		usuario->GuardarPCS();
		cout<<"Se han guardado satisfactoriamente las maquinas en el archivo"<<endl;
		cout<<"Digite 1 para continuar"<<endl;
	}
	else
	{
		cout<<"Debe cargar las maquinas antes de guardar las maquinas"<<endl;
		cout<<"Digite 1 para continuar"<<endl;
	}
	
	cin>>opc;
	do
	{
		switch(opc)
		{
			case 1:
				MenuCreacionYMantenimiento();
				break;
		}
	}while(opc!=1);
}
void Interfaz::EliminarMaquinas()//EliminarMaquinas(List<Computador> &pComputador)
{
	int opc=0;
	usuario->EliminarPCS();
	cout<<"Eliminando maquinas"<<endl;
	cout<<"Se han eliminado todas las maquinas satisfactoriamente"<<endl;
	cout<<"Digite 1 para continuar"<<endl;
	cin>>opc;
	do
	{
		switch(opc)
		{
			case 1:
				MenuCreacionYMantenimiento();
				break;
		}
	}while(opc!=1);
}
void Interfaz::MostrarMaquinas()//MostrarMaquinas(List<Computador> &pComputador)
{
	int opc = 0;
	cout<<"mostrando listado de maquinas"<<endl;
	
	usuario->MostrarPCS();

	cout<<"\n"<<endl;
	cout<<"Digite 1 para continuar"<<endl;
	cin>>opc;
	do
	{
		switch(opc)
		{
			case 1:
				MenuCreacionYMantenimiento();
				break;
		}
	}while(opc!=1);
}
void Interfaz::ModificarMaquinas()//ModificarMaquinas(List<Computador> &pComputador)
{
	int opc = 0;
	int numMaquina;
	
	if(usuario->ObtenerHaCargadoArchivo())
	{
		cout<<"mostrando listado de maquinas"<<endl;
		usuario->MostrarPCS();
		cout<<"\n"<<endl;
		cout<<"Digite el numero de maquina la cual desea modificar"<<endl;
		cin>>numMaquina;
		usuario->ModificarPC(numMaquina);
		string so = usuario->ObtenerComputadorActual()->ObtenerTipoSistemaOperativo();
		if(so == "Windows 7" || so == "Windows Vista" || so == "Windows XP")
		{
			this->tipoPC = 1;
		}
		else
		{
			this->tipoPC = 2;
		}
	
		Interfaz::CrearMaquina();
		cout<<"Se ha modificado la maquina de manera correcta\n"<<endl;
	}
	else
	{
		cout<<"Debe cargar las maquinas antes de modificar una maquina"<<endl;
	}

	cout<<"Digite 1 para continuar"<<endl;
	cin>>opc;

	do
	{
		switch(opc)
		{
			case 1:
				MenuCreacionYMantenimiento();
				break;
		}
	}while(opc!=1);

}
void Interfaz::ComponentesWindows()
{
	cout<<"Primero indique el sistema operativo windows que desea"<<endl;
	MenuOSWindows();
	cout<<"Ahora, ingrese el tipo de memoria RAM"<<endl;
	MenuRAMWindows();
	cout<<"Por ultimo, ingrese la opcion de procesador que desea"<<endl;
	MenuCPUWindows();
	cout<<"Ha sido creada una computadora windows"<<endl;
}
void Interfaz::ComponentesMac()
{
	cout<<"Primero indique el sistema operativo Mac que desea"<<endl;
	MenuOSMac();
	cout<<"Ahora, ingrese el tipo de memoria RAM"<<endl;
	MenuRAMMac();
	cout<<"Por ultimo, ingrese la opcion de procesador que desea"<<endl;
	MenuCPUMac();
	cout<<"Ha sido creada una computadora Mac"<<endl;
}