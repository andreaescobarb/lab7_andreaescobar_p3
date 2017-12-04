#include "Chef.h"

Chef::Chef(string username,string password,string nombre,int edad,int id,int telefono,int contratacion, int sueldo, string platillo): Personal(username,password, nombre,edad, id, telefono, contratacion,sueldo){
	this->platillo=platillo;
}
Chef::Chef(){

}void Chef::setPlatillo(string platillo){
   this-> platillo=platillo;
}
string Chef::getPlatillo(){
   return platillo;
}

string Chef::toString(){

}

Chef::~Chef(){

}
