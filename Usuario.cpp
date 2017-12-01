#include "Usuario.h"

Usuario::Usuario(){

}

Usuario::Usuario(string username, string password, string nombre, int edad, int id, int telefono){
  this->username=username;
  this->password=password;
  this->nombre=nombre;
  this->edad=edad;
  this->id=id;
  this->telefono=telefono;
}

string Usuario::getUsername(string username){
  return username;
}

void Usuario::setUsername(string username){
  this->username=username;
}

string Usuario::getPassword(string password){
  return password;
}

void Usuario::setPassword(string password){
  this->password=password;
}

string Usuario::getNombre(string nombre){
  return nombre;
}

void Usuario::setNombre(string nombre){
  this->nombre=nombre;
}
int Usuario::getEdad(int edad){
  return edad;
}

void Usuario::setEdad(int edad){
  this->nombre=nombre;
}

int Usuario::getId(int id){
  return id;
}

void Usuario::setId(int id){
  this->id=id;
}

Usuario::~Usuario(){
  
}
