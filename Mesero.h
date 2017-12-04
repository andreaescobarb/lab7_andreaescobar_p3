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
		vector<Usuario*> listaPlatillos;
	public:
		Mesero(vector<Usuario*>);
		Mesero();
		vector<Usuario*> getListaPlatillos();
		void setListaPlatillos(Usuario*);

};
#endif
