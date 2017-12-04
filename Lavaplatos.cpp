#include "Lavaplatos.h"

Lavaplatos::Lavaplatos(int motivacion): Personal(contratacion,sueldo){
	this->motivacion=motivacion;
}
Lavaplatos::Lavaplatos(){

}void Lavaplatos::setMotivacion(int motivacion){
   this-> motivacion=motivacion;
}
int Lavaplatos::getMotivacion(){
   return motivacion;
}
