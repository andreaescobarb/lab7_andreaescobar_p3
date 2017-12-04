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
		Mesero(vector<string>);
		Mesero();
		vector<string> getListaPlatillos();
		void setListaPlatillos(string);

};
#endif
