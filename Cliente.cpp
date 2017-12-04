#include "Cliente.h"

Cliente::Cliente(string direccion,int rating): Usuario(string username,string password,string nombre,int edad,int id,int telefono){
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
