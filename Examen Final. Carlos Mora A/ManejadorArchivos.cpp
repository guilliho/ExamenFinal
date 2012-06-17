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

void ManejadorArchivos::GuardarArchivo(string nombreArchivo, List<Computador>* computadoras)
{
	if (ManejadorArchivos::ExisteArchivo(nombreArchivo))
	{
		ManejadorArchivos::LimpiarArchivo(nombreArchivo);
		fstream stream;
		stream.open(nombreArchivo.c_str(), ios::in | ios::out);
		Iterator<Computador>* i = new Iterator<Computador>();
		i->setActual(computadoras->getPrimero());
		if(!computadoras->isempty())
		{
			while(!i->isDone())
			{
				stream << i->Mostrar();
				i->Siguiente();
			}
		}
		stream.close();
		delete i;
	}
}

List<Computador>* ManejadorArchivos::LeerArchivo(string nombreArchivo)
{
	if (ManejadorArchivos::ExisteArchivo(nombreArchivo))
	{
		List<Computador>* computadoras = new List<Computador>();
		string line;
		fstream stream;
		stream.open(nombreArchivo.c_str(), ios::in | ios::out);
		while(stream.good())
		{
			getline (stream, line);
			Computador* computador = new Computador();
			
			string tipoPC = ManejadorArchivos::ObtenerTexto(line, "Tipo de PC: ", " Sistema Operativo:");
			string tipoSistemaOperativo = ManejadorArchivos::ObtenerTexto(line, "Sistema Operativo: ", " Tipo de Memoria:");
			string tipoMemoria = ManejadorArchivos::ObtenerTexto(line, "Tipo de Memoria: ", " Tipo de Procesador:");
			string tipoProcesador = ManejadorArchivos::ObtenerTexto(line, "Tipo de Procesador:", "");
			
			int tSistemaOperativo = ManejadorArchivos::ObtenerTipoSistemaOperativo(tipoPC, tipoSistemaOperativo);
			int tMemoria = ManejadorArchivos::ObtenerTipoMemoria(tipoPC, tipoMemoria);
			int tProcesador = ManejadorArchivos::ObtenerTipoProcesador(tipoPC, tipoProcesador);

			if (tipoPC == "Windows PC")
			{
				computador->ConfigurarTipoPC(1);
			}
			else
			{
				computador->ConfigurarTipoPC(2);
			}

			computador->ConfigurarTipoSistemaOperativo(tSistemaOperativo);
			computador->ConfigurarTipoMemoria(tMemoria);
			computador->ConfigurarTipoProcesador(tProcesador);

			computadoras->insertar(computador);
			delete computador;
		}
		stream.close();
		return computadoras;
	}
}

string ManejadorArchivos::ObtenerTexto(string frase, string fraseInicial, string fraseFinal)
{
	size_t inicio = frase.find(fraseInicial);
	size_t final;
	if (fraseFinal == "")
	{
		final = frase.length();
	}
	else 
	{
		final = frase.find(fraseFinal);
	}
	

	return frase.substr(inicio, final);
}

int ManejadorArchivos::ObtenerTipoProcesador(string tipoPC, string tipoProcesador)
{
	if (tipoPC == "Windows PC")
	{
		if (tipoProcesador == "AMD")
		{
			return 1;
		}
		else if (tipoProcesador == "Cyrix")
		{
			return 2;
		}
		else 
		{
			return 3;
		}
	}
	else
	{
		if (tipoProcesador == "INTEL")
		{
			return 1;
		}
		else if (tipoProcesador == "CELL")
		{
			return 2;
		}
		else 
		{
			return 3;
		}
	}
}

int ManejadorArchivos::ObtenerTipoMemoria(string tipoPC, string tipoMemoria)
{
	if (tipoPC == "Windows PC")
	{
		if (tipoMemoria == "Kingston")
		{
			return 1;
		}
		else if (tipoMemoria == "DDR3")
		{
			return 2;
		}
		else 
		{
			return 3;
		}
	}
	else
	{
		if (tipoMemoria == "Simm")
		{
			return 1;
		}
		else if (tipoMemoria == "Varna")
		{
			return 2;
		}
		else 
		{
			return 3;
		}
	}
}

int ManejadorArchivos::ObtenerTipoSistemaOperativo(string tipoPC, string tipoSistemaOperativo)
{
	if (tipoPC == "Windows PC")
	{
		if (tipoSistemaOperativo == "Windows XP")
		{
			return 1;
		}
		else if (tipoSistemaOperativo == "Windows 7")
		{
			return 2;
		}
		else 
		{
			return 3;
		}
	}
	else
	{
		if (tipoSistemaOperativo == "Mac OS")
		{
			return 1;
		}
		else if (tipoSistemaOperativo == "Unix")
		{
			return 2;
		}
		else 
		{
			return 3;
		}
	}
}

void ManejadorArchivos::MostrarArchivo(string nombreArchivo)
{
	if (ManejadorArchivos::ExisteArchivo(nombreArchivo))
	{
		string line;
		fstream stream;
		stream.open(nombreArchivo.c_str(), ios::in | ios::out);
		while(stream.good())
		{
			getline (stream, line);
			cout << line << endl;
		}
		stream.close();
	}
}