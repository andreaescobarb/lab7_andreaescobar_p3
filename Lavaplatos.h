#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"
#include <sstream>

using namespace std;

#ifndef LAVAPLATOS_H
#define LAVAPLATOS_H
class Lavaplatos : public Personal{
	protected:
		int motivacion;
	public:
		Lavaplatos(string,string,string,int,int,int,int,int,int);
		Lavaplatos();
		int getMotivacion();
		void setMotivacion(int);

		virtual string toString();
		//destructor
		virtual ~Lavaplatos();

};
#endif
