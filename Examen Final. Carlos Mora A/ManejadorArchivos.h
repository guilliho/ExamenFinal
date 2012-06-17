#pragma once
#include<iostream>
#include<string>
#include<io.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<windows.h>
#include<fstream>

using namespace std;

class ManejadorArchivos
{
public:
	static bool ExisteDirectorio(string nombreDirectorio);
	static bool ExisteArchivo(string nombreArchivo);
	static void CrearDirectorioData();
	static void CrearDirectorio(string nombreDirectorio);
	static void CrearArchivo(string nombreArchivo);
	static void LimpiarArchivo(string nombreArchivo);
	static void GuardarArchivo(string nombreArchivo);
	static void LeerArchivo(string nombreArchivo);
};