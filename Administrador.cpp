#include "Administrador.h"

Administrador::Administrador(string username,string password,string nombre,int edad,int id,int telefono,int contratacion, int sueldo, int contratados,int despedidos): Personal(username,password, nombre,edad, id, telefono, contratacion,sueldo){
	this->contratados=contratados;
	this->despedidos=despedidos;
}
Administrador::Administrador(){

}void Administrador::setContratados(int contratados){
   this-> contratados=contratados;
}
int Administrador::getContratados(){
   return contratados;
}
void Administrador::setDespedidos(int despedidos){
   this-> despedidos=despedidos;
}
int Administrador::getDespedidos(){
   return despedidos;
}

string Administrador::toString(){

}

Administrador::~Administrador(){

}
