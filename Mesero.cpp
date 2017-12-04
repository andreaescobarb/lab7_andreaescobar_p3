#include "Mesero.h"

Mesero::Mesero(vector<string> listaPlatillos):Personal(int contratacion,int sueldo){
	this->listaPlatillos=listaPlatillos;
}
Mesero::Mesero(){

}void Mesero::setListaPlatillos(string ClistaPlatillos){
   this-> listaPlatillos.push_back(ClistaPlatillos);
}
vector<string> Mesero::getListaPlatillos(){
   return listaPlatillos;
}
