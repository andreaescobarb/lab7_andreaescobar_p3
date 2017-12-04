#include <iostream>
#include <string>
#include <vector>
#include "Usuario.h"

using namespace std;

#ifndef CLIENTE_H
#define CLIENTE_H
class Cliente : public Usuario{
	protected:
		string direccion;
		int rating;
	public:
		Cliente(string,string,string,int,int,int,string,int);
		Cliente();
		string getDireccion();
		void setDireccion(string);

		int getRating();
		void setRating(int);

		virtual string toString();

};
#endif
