#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"
#include "Usuario.h"
#include <sstream>

using namespace std;

#ifndef MESERO_H
#define MESERO_H
class Mesero : public Personal{
	protected:
		vector<string> listaPlatillos;
	public:
		Mesero(string,string,string,int,int,int,int,int,vector<string>);
		Mesero();
		vector<string> getListaPlatillos();
		void setListaPlatillos(string);
		void deliver();

		//funcion para escribir un soString y poder escrbir archivo
		virtual string toString();
		//destructor
		virtual ~Mesero();
};
#endif
