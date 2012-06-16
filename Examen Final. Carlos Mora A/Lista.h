#include"Nodo.h"
#include"Compare.h"
#include"Iterator.h"
#pragma once

template<class T>
class List
{
private:
	Nodo<T> *primero;
	Nodo<T> *ultimo;
public:
	List()
	{
		primero=ultimo=NULL;
	}
	~List()
	{
		while(!isempty())
		this->eliminar(0);
	}
	Nodo<T> *getPrimero()
	{
		return primero;
	}
	void insertar(T *info)
	{
		Nodo<T> *nuevoNodo=new Nodo<T>(info);
		if(isempty())
		primero=ultimo=nuevoNodo;
		else
		{
			ultimo->setSig(nuevoNodo);
			ultimo=nuevoNodo;
		}
	}
	void eliminar(int a)
	{
		Nodo<T> *eliminar;
		int n=0;
		if(a==0)
		{
			eliminar=primero;
			primero=primero->getSig();
			delete eliminar;
		}
		else{
			Iterator<T> *aux=new Iterator<T>();
			aux->setActual(primero);
			while(n<a-1){
				aux->Siguiente();
				n++;}
			if(aux->getActual()->getSig()==NULL)
			{
				eliminar=ultimo;
				ultimo=aux->getActual();
				delete eliminar;
			}
			else
			{
				eliminar=aux->getActual()->getSig();
				aux->getActual()->setSig(aux->getActual()->getSig());
				delete eliminar;
			}
		}
	}

	int busqueda(string dato)
	{
		Iterator<T> *aux=new Iterator<T>();
		aux->setActual(primero);
		int r=0;
		while(aux->getActual()!=NULL)
		if(*aux->getActual()->getInfo()==dato)
		return r;
		else
		{
			aux->Siguiente();
			r++;
		}
		return -1;
	}
	T * modificar(int n)
	{
		Iterator<T> *aux=new Iterator<T>();
		aux->setActual(primero);
		int a=0;
		while(a<n)
		{
			aux->Siguiente();
			a++;
		}
		return aux->getActual()->getInfo();
	}
	bool isempty()
	{
		if(primero==NULL)
			return true;
		else
			return false;
	}
};

