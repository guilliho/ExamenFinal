#pragma once
#include"Nodo.h"

template<class T>
class Iterator
{
private:
    Nodo<T> *actual;
public:
    Iterator()
	{
		actual=NULL;
	}
    void setActual(Nodo<T> *)
	{
		this->actual=actual;
	}
    Nodo<T> *getActual()
	{
		return actual;
	}
    void Siguiente()
	{
		this->actual=actual->getSig();
	}
	string Mostrar()
	{
		return this->actual->getInfo()->tostring();
	}
	bool isDone()
	{
		return actual==NULL;
	}
	bool isEmpty()
	{
		return actual==NULL;
	}
};


