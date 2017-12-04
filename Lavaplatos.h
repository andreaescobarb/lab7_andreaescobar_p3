#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"

using namespace std;

#ifndef LAVAPLATOS_H
#define LAVAPLATOS_H
class Lavaplatos : public Personal{
	protected:
		int motivacion;
	public:
		Lavaplatos(int);
		Lavaplatos();
		int getMotivacion();
		void setMotivacion(int);

};
#endif
