#include "Mesero.h"

Mesero::Mesero(vector<Usuario*> listaPlatillos):Personal(int contratacion,int sueldo){
	this->listaPlatillos=listaPlatillos;
}
Mesero::Mesero(){

}void Mesero::setListaPlatillos(Usuario* ClistaPlatillos){
   this-> listaPlatillos.push_back(ClistaPlatillos);
}
vector<Usuario*> Mesero::getListaPlatillos(){
   return listaPlatillos;
}
