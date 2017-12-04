#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"
#include <sstream>

using namespace std;

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
class Administrador : public Personal{
	protected:
		int contratados;
		int despedidos;
	public:
		Administrador(string,string,string,int,int,int,int,int,int,int);
		Administrador();
		int getContratados();
		void setContratados(int);

		int getDespedidos();
		void setDespedidos(int);

		//funcion para escribir un soString y poder escrbir archivo
		virtual string toString();
		//destructor
		virtual ~Administrador();
};
#endif
