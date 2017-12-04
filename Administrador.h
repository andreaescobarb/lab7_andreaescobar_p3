#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"

using namespace std;

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
class Administrador : public Personal{
	protected:
		int contratados;
		int despedidos;
	public:
		Administrador(int,int);
		Administrador();
		int getContratados();
		void setContratados(int);

		int getDespedidos();
		void setDespedidos(int);

};
#endif
