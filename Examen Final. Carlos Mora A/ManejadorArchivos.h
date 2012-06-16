#pragma once
#include<iostream>
#include<string>

using namespace std;

class ManejadorArchivos
{
public:
	static bool ExisteDirectorio(string nombreDirectorio);
	static bool ExisteArchivo(string nombreArchivo);
	static void CrearDirectorio(string nombreDirectorio);
	static void CrearArchivo(string nombreArchivo);
	static void LimpiarArchivo(string nombreArchivo);
	static void GuardarArchivo(string nombreArchivo);
};