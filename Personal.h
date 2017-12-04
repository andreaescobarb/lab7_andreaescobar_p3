#include <iostream>
#include <string>
#include <vector>
#include "Usuario.h"
#include <sstream>

using namespace std;

#ifndef PERSONAL_H
#define PERSONAL_H
class Personal : public Usuario{
	protected:
		int contratacion;
		int sueldo;
	public:
		Personal(string,string,string,int,int,int,int,int);
		Personal();
		int getContratacion();
		void setContratacion(int);

		int getSueldo();
		void setSueldo(int);

		//funcion para escribir un soString y poder escrbir archivo
		virtual string toString();
		//destructor
		virtual ~Personal();

};
#endif
