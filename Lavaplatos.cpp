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
