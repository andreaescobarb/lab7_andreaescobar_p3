#include "Administrador.h"

Administrador::Administrador(int contratados,int despedidos){
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
