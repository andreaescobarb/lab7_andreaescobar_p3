#include "Personal.h"

Personal::Personal(){

}

Personal::Personal(int ano, int sueldo):Usuario(string username, string password, string nombre, int edad, int id, int telefono){
  this->ano=ano;
  this->sueldo=sueldo;
  /*this->username=username;
  this->password=password;
  this->nombre=nombre;
  this->edad=edad;
  this->id=id;
  this->telefono=telefono;*/
}

int Personal::getAno(int ano){
  return ano;
}

void Personal::setAno(int ano){
  this->ano=ano;
}

int Personal::getSueldo(int sueldo){
  return sueldo;
}

void Personal::setSueldo(int sueldo){
  this->sueldo=sueldo;
}
 Personal::~Personal(){

 }
