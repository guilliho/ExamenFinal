#include "ManejadorArchivos.h"

bool ManejadorArchivos::ExisteDirectorio(string nombreDirectorio)
{
	if (access(nombreDirectorio.c_str(), 0) == 0)
	{
		struct stat status;
		stat(nombreDirectorio.c_str(), &status);
		if (status.st_mode & S_IFDIR)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool ManejadorArchivos::ExisteArchivo(string nombreArchivo)
{
	struct stat status;
	if (stat(nombreArchivo.c_str(), &status) != -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ManejadorArchivos::CrearDirectorioData()
{
	if (!ManejadorArchivos::ExisteDirectorio("data"))
	{
		CreateDirectory("data", NULL);
	}
}

void ManejadorArchivos::CrearDirectorio(string nombreDirectorio)
{
	string directorioCompleto = "data/" + nombreDirectorio;
	CreateDirectory(directorioCompleto.c_str(), NULL);
}

void ManejadorArchivos::CrearArchivo(string nombreArchivo)
{
	if (!ManejadorArchivos::ExisteArchivo(nombreArchivo))
	{
		fstream stream;
		stream.open(nombreArchivo.c_str(), ios::in | ios::out | ios::trunc);
		stream.close();
	}
}

void ManejadorArchivos::LimpiarArchivo(string nombreArchivo)
{
	if (ManejadorArchivos::ExisteArchivo(nombreArchivo))
	{
		fstream stream;
		stream.open(nombreArchivo.c_str(), ios::out | ios::trunc);
		stream.close();
	}
}

void ManejadorArchivos::GuardarArchivo(string nombreArchivo)
{
	if (ManejadorArchivos::ExisteArchivo(nombreArchivo))
	{
		ManejadorArchivos::LimpiarArchivo(nombreArchivo);
		fstream stream;
		stream.open(nombreArchivo.c_str(), ios::in | ios::out);
		// Logic for saving the list into the file

		stream.close();
	}
}

void ManejadorArchivos::LeerArchivo(string nombreArchivo)
{
	if (ManejadorArchivos::ExisteArchivo(nombreArchivo))
	{
		fstream stream;
		stream.open(nombreArchivo.c_str(), ios::in | ios::out);
		// Read file and return list

		stream.close();
	}
}