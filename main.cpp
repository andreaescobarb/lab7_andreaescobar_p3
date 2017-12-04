#include <iostream>
#include <string>
#include <vector>
#include "Usuario.h"
#include "Cliente.h"
#include "Personal.h"
#include "Administrador.h"
#include "Lavaplatos.h"
#include "Chef.h"
#include "Mesero.h"

#include <fstream>

bool mayorDeEdad(int);
double promedioRating();
void wFile(vector<Usuario*>);
void addDish(vector<Usuario*>);
vector<string> menorSalario(vector<Usuario*>);
vector<string> mayorSalario(vector<Usuario*>);
vector<Usuario*> agregarPersonal(vector<Usuario*> , Usuario*);
vector<Usuario*> fire(vector<Usuario*> , Usuario*);

using namespace std;

int main(){
  vector<Usuario*> users;
  Usuario* user;
  bool program = true;
  int opc;
  int op;

  while (program) {
    cout<<"             MENU PRINCIPAL"<<endl<<"________________________________________________________"<<endl;
    cout<<"Ingrese opcion"<<endl;
    cout<<"1- Log in"<<endl<<"2- Crear Cuentar"<<endl<<"3- Salir"<<endl;;
    cin>>opc;
    while(opc>3||opc<1){
      cout<<"Opcion inexistente, Ingrese de nuevo"<<endl;
      cin>>opc;
    }

    switch (opc) {
      case 1:{


        break;
      }//fin de case 1 switch original

      case 2:{

        cout<<"               SUB-MENU"<<endl<<"________________________________________________________"<<endl;
        cout<<"Ingrese la opcion de la cuenta que desea crear"<<endl;
        cout<<"1- Cliente"<<endl<<"2- Personal"<<endl;
        cin>>op;
        while(op>2||op<1){
          cout<<"Opcion inexistente, Ingrese de nuevo"<<endl;
          cin>>op;
        }

        switch (op) {
          case 1:{//comienza del case 1 sub menu
            char resp='s';
            while(resp=='s'||resp=='S'){
              cout<<"               CUENTA DE CLIENTE<<endl<<________________________________________________________"<<endl;

              string username="", password="", nombre="", direccion="";
              int edad=0, id=0, tel=0, rate=0;

              cout<<"Ingrese username: "<<endl;
              cin>>username;
              cout<<"Ingrese password: "<<endl;
              cin>>password;
              cout<<"Ingrese nombre: "<<endl;
              cin>>nombre;
              cout<<"Ingrese edad: "<<endl;
              cin>>edad;
              while (!mayorDeEdad(edad)) {
                cout<<"Tiene que ser mayor de edad, intente de nuevo"<<endl;
                cin>>edad;
              }
              cout<<"Ingrese ID: "<<endl;
              cin>>id;
              cout<<"Ingrese numero de telefono: "<<endl;
              cin>>tel;
              cout<<"Ingrese direccion"<<endl;
              cin>>direccion;
              cout<<"Ingrese rating de mi restaurante (numero entre 1-5)"<<endl;
              cin>>rate;
              while (rate>5||rate<1) {
                cout<<"Rating invalido, intente de nuevo"<<endl;
                cin>>rate;
              }

              users.push_back(new Cliente(username, password, nombre, edad,id,tel, direccion, rate));

              cout<<"Desea agregar mas usuarios administradores [S/N]"<<endl;
              cin>>resp;
            }//fin del while

            break;
          }//fin del case 1 sub menu

          case 2:{//comienza del case 2 sub menu
            char resp = 's';
            while(resp=='s'||resp=='S'){
              cout<<"               CUENTA DE ADMINISTRADOR<<endl<<________________________________________________________"<<endl;

              string username="", password="", nombre="";
              int edad=0, id=0, tel=0, ano=0, sueldo=0;

              cout<<"Ingrese username: "<<endl;
              cin>>username;
              cout<<"Ingrese password: "<<endl;
              cin>>password;
              cout<<"Ingrese nombre: "<<endl;
              cin>>nombre;
              cout<<"Ingrese edad: "<<endl;
              cin>>edad;
              while (!mayorDeEdad(edad)) {
                cout<<"Tiene que ser mayor de edad, intente de nuevo"<<endl;
                cin>>edad;
              }
              cout<<"Ingrese ID: "<<endl;
              cin>>id;
              cout<<"Ingrese numero de telefono: "<<endl;
              cin>>tel;
              cout<<"Ingrese ano de contratacion"<<endl;
              cin>>ano;
              cout<<"Ingrese sueldo"<<endl;
              cin>>sueldo;

              users.push_back(new Administrador(username, password, nombre, edad,id,tel, ano, sueldo,0,0));

              cout<<"Desea agregar mas usuarios administradores [S/N]"<<endl;
              cin>>resp;
            }//fin del while

            break;
          }//fin del case 2 sub menu
        }

        break;
      }//fin de case 2 switch original

      case 3:{
        program = false;
        break;
      } // fin de case 3 original
    } //switch
  } //while



     return 0;
}

bool mayorDeEdad(int edad){
  bool age=false;
  if (edad>=18) {
    age = true;
  }
  return age;
}

double promedioRating(vector<Usuario*> users){
  int cont = 0;
  int tot=0;
  int rate;
  for (int i = 0; i < users.size(); i++) {
    if (dynamic_cast<Cliente*>(users[i])) {
      int rate = dynamic_cast<Cliente*>(users[i])->getRating();
      tot+=rate;
      cont++;
    }
  }
  return tot/cont;
}

void wFile(vector<Usuario*> users){
  ofstream archivo("Dato.txt");
  if (archivo.is_open()) {
    for (int i = 0; i < users.size(); i++) {
      archivo<<users.at(i)->toString();
    }
    archivo.close();
  }
}

void addDish(vector<Usuario*> users){
  for (int i = 0; i < users.size(); i++) {
    if (dynamic_cast<Mesero*>(users.at(i))) {
      cout<<i<<"- "<<users.at(i)->getNombre()<<endl;
    }
  }

  int opc;
  string dish;
  cout<<"Ingrese a quien desea agregar: ";
  cin>>opc;
  cout<<"Nombre del plato: ";
  cin>>dish;
  Mesero* p = dynamic_cast<Mesero*>(users.at(opc));
  p->getListaPlatillos().push_back(dish);
}

vector<string> menorSalario(vector<Usuario*> users){
  Personal* aux;
  vector<string> menor;

  int low = 80000;
  for (int i = 0; i < users.size(); i++) {
    if (dynamic_cast<Personal*>(users.at(i))) {
      aux = dynamic_cast<Personal*>(users.at(i));
      if (aux->getSueldo() < low) {
        menor.push_back(aux->getNombre());
        low = aux->getSueldo();
      }
    }
  }

  for (int i = 0; i < menor.size(); i++) {
    cout<<menor.at(i)<<endl;
  }
  return menor;
}

vector<string> mayorSalario(vector<Usuario*> users){
  Personal* aux;
  vector<string> mayor;
  int may = 0;
  for (int i = 0; i < users.size(); i++) {
    if (dynamic_cast<Personal*>(users.at(i))) {
      aux = dynamic_cast<Personal*>(users.at(i));
      if (aux->getSueldo() > may) {
        mayor.push_back(aux->getNombre());
        may = aux->getSueldo();
      }
    }
  }

  for (int i = 0; i < mayor.size(); i++) {
    cout<<mayor.at(i)<<endl;
  }
  return mayor;
}

vector<Usuario*> agregarPersonal(vector<Usuario*> users, Usuario* personas){
  char resp = 's';
  string username, password, nombre;
  int edad, id, tel, ano, sueldo;
  int cont = 0;
  int op;
  while (resp=='s'||resp=='S') {
    cont++;
    cout<<"             MENU DE EMPLEADOS"<<endl;
    //cout<<"____________________________________________________"<<endl;
    cout<<"1- Chef"<<endl<<"2- Lavaplato"<<endl<<"3- Mesero"<<endl;
    cin>>op;
    while (op<0||op>3) {
      cout<<"Opcion inexistente, intente de nuevo"<<endl;
      cin>>op;
    }

    cout<<"Ingrese username"<<endl;
    cin>>username;
    cout<<"Ingrese password"<<endl;
    cin>>password;
    cout<<"Ingrese nombre"<<endl;
    cin>>nombre;
    cout<<"Ingrese edad"<<endl;
    cin>>edad;
    while (!mayorDeEdad(edad)) {
      cout<<"Tiene que ser mayor de edad, intente de nuevo"<<endl;
      cin>>edad;
    }
    cout<<"Ingrese ID"<<endl;
    cin>>id;
    cout<<"Ingrese numero de telefono"<<endl;
    cin>>tel;
    cout<<"Ingrese ano de contratacion"<<endl;
    cin>>ano;
    cout<<"Ingrese sueldo"<<endl;
    cin>>sueldo;


    switch (op) {
      case 1:{
        string platFav="";
        cout<<"Ingrese platillo favorito"<<endl;
        cin>>platFav;
        users.push_back(new Chef(username, password, nombre, edad, id, tel, ano, sueldo, platFav));
        cout<<"Chef agregado exitosamente!"<<endl;
        break;
      }//case 1

      case 2:{
        users.push_back(new Lavaplatos(username, password, nombre, edad, id, tel, ano, sueldo, 50));
        cout<<"Lavaplato agregado exitosamente!"<<endl;
        break;
      }//case 2

      case 3:{
        vector<string> platos;
        users.push_back(new Mesero(username, password, nombre, edad, id, tel, ano, sueldo, platos));
      } //case 3
    }
    cout<<"Desea agregar mas empleados [S/N]"<<endl;
    cin>>resp;
  }//fin de while
return users;

}

vector<Usuario*> fire(vector <Usuario*> users, Usuario* persona){
  int pos;
  for (int i = 0; i < users.size(); i++) {
    if (dynamic_cast<Personal*>(users.at(i))) {
      cout<<i<<"- "<<users.at(i)->getNombre()<<endl;
    }
  }

  cout<<"Cual desea eliminiar: ";
  cin>>pos;
  while (pos>users.size()||pos<0) {
    cout<<"Persona ingresada inexistente, intente de nuevo"<<endl;
    cin>>pos;
  }
  users.erase(users.begin()+pos);
  dynamic_cast<Administrador*>(persona)->setDespedidos(dynamic_cast<Administrador*>(persona)->getDespedidos()+1);
  return users;
}
