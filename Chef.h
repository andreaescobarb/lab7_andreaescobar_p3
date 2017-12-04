#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"
#include <sstream>

using namespace std;

#ifndef CHEF_H
#define CHEF_H
class Chef : public Personal{
	protected:
		string platillo;
	public:
		Chef(string,string,string,int,int,int,int,int,string);
		Chef();
		string getPlatillo();
		void setPlatillo(string);

		//funcion para escribir un soString y poder escrbir archivo
		virtual string toString();

		//destructor
		virtual ~Chef();

};
#endif
