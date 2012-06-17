#pragma once
#include<iostream>
using namespace std;

template<class T>
class Nodo
{
private:
	T *info;
	Nodo<T> *sig;
public:
	Nodo()
	{
		info=NULL;
		sig=NULL;
	}
	Nodo(T *info)
	{
		this->info=info;
		sig=NULL;
	}
	void setSig(Nodo *sig)
	{
		this->sig=sig;
	}
	Nodo<T>* getSig()
	{
		return sig;
	}
	void setInfo(T *info)
	{
		this->info=info;
	}
	T *getInfo()
	{
		return info;
	}
};

