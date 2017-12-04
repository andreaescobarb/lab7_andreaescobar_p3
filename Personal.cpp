#include "Personal.h"

Personal::Personal(int contratacion,int sueldo):Usuario(string username,string password,string nombre,int edad,int id,int telefono){
	this->contratacion=contratacion;
	this->sueldo=sueldo;
}
Personal::Personal(){

}void Personal::setContratacion(int contratacion){
   this-> contratacion=contratacion;
}
int Personal::getContratacion(){
   return contratacion;
}
void Personal::setSueldo(int sueldo){
   this-> sueldo=sueldo;
}
int Personal::getSueldo(){
   return sueldo;
}
