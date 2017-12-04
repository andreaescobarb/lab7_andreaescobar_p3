#include "Mesero.h"

Mesero::Mesero(string username,string password,string nombre,int edad,int id,int telefono,int contratacion, int sueldo,vector<string> listaPlatillos):Personal(username,password, nombre,edad, id, telefono, contratacion,sueldo){
	this->listaPlatillos=listaPlatillos;
}
Mesero::Mesero(){

}void Mesero::setListaPlatillos(string ClistaPlatillos){
   this-> listaPlatillos.push_back(ClistaPlatillos);
}
vector<string> Mesero::getListaPlatillos(){
   return listaPlatillos;
}
