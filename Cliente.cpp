#include "Cliente.h"

Cliente::Cliente(){

}

Cliente::Cliente(string direccion, int rating):Usuario(string username, string password, string nombre, int edad, int id, int telefono){
  this->direccion=direccion;
  this->rating=rating;
  /*this->username=username;
  this->password=password;
  this->nombre=nombre;
  this->edad=edad;
  this->id=id;
  this->telefono=telefono;*/
}

string Cliente::getDireccion(string direccion){
  return direccion;
}

void Cliente::setDireccion(string direccion){
  this->direccion=direccion;
}

int Cliente::getRating(int rating){
  return rating;
}

void Cliente::setRating(int rating){
  this->rating=rating;
}

Cliente::~Cliente(){

}
