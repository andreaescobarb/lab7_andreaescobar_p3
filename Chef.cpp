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
	stringstream st;
	string conversion;
	char tip ='C';
	st<<tip;
	st<<",";
	st<<username;
	st<<",";
	st<<password;
	st<<",";
	st<<nombre;
	st<<",";
	st<<edad;
	st<<",";
	st<<id;
	st<<",";
	st<<telefono;
	st<<",";
	st<<contratacion;
	st<<",";
	st<<sueldo;
	st<<",";
	st<<platillo;
	st<<";";

	conversion=st.str();
	return conversion;
}

Chef::~Chef(){

}
