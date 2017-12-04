#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"
#include "Usuario.h"

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

		virtual string toString();
};
#endif
