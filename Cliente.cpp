#include "Cliente.h"

Cliente::Cliente(string username,string password,string nombre,int edad,int id,int telefono, string direccion,int rating): Usuario(username,password, nombre,edad, id, telefono){
	this->direccion=direccion;
	this->rating=rating;
}
Cliente::Cliente(){

}void Cliente::setDireccion(string direccion){
   this-> direccion=direccion;
}
string Cliente::getDireccion(){
   return direccion;
}
void Cliente::setRating(int rating){
   this-> rating=rating;
}
int Cliente::getRating(){
   return rating;
}

string Cliente::toString(){

}

Cliente::~Cliente(){

}
