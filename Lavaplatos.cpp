#include "Lavaplatos.h"

Lavaplatos::Lavaplatos(string username,string password,string nombre,int edad,int id,int telefono,int contratacion, int sueldo, int motivacion): Personal(username,password, nombre,edad, id, telefono, contratacion,sueldo){
	this->motivacion=motivacion;
}
Lavaplatos::Lavaplatos(){

}void Lavaplatos::setMotivacion(int motivacion){
   this-> motivacion=motivacion;
}
int Lavaplatos::getMotivacion(){
   return motivacion;
}

string Lavaplatos::toString(){
	stringstream st;
	string conversion;
	char tip ='L';
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
	st<<motivacion;
	st<<";";
	conversion=st.str();
	return conversion;
}

Lavaplatos::~Lavaplatos(){

}
