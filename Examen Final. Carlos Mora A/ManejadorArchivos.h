#pragma once
#include<iostream>
#include<string>
#include<io.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<windows.h>
#include<fstream>
#include "Lista.h"
#include "Computador.h"

using namespace std;

class ManejadorArchivos
{
private:
	static string ObtenerTexto(string frase, string fraseInicial, string fraseFinal);
	static int ObtenerTipoProcesador(string tipoPC, string tipoProcesador);
	static int ObtenerTipoMemoria(string tipoPC, string tipoMemoria);
	static int ObtenerTipoSistemaOperativo(string tipoPC, string tipoSistemaOperativo);
public:
	static bool ExisteDirectorio(string nombreDirectorio);
	static bool ExisteArchivo(string nombreArchivo);
	static void CrearDirectorioData();
	static void CrearDirectorio(string nombreDirectorio);
	static void CrearArchivo(string nombreArchivo);
	static void LimpiarArchivo(string nombreArchivo);
	static void GuardarArchivo(string nombreArchivo, List<Computador>* computadoras);
	static List<Computador>* LeerArchivo(string nombreArchivo);
	static void MostrarArchivo(string nombreArchivo);
};