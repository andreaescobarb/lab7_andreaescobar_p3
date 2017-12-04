#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"

using namespace std;

#ifndef CHEF_H
#define CHEF_H
class Chef : public Personal{
	protected:
		string platillo;
	public:
		Chef(string);
		Chef();
		string getPlatillo();
		void setPlatillo(string);

};
#endif
