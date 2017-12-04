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

#include <cstdlib>
#include <fstream>

bool mayorDeEdad(int);
double promedioRating(vector<Usuario*>);
void wFile(vector<Usuario*>);
vector<Usuario*> readFile();
//funciones del administradores
void addDish(vector<Usuario*>);
vector<string> menorSalario(vector<Usuario*>);
vector<string> mayorSalario(vector<Usuario*>);
vector<Usuario*> agregarPersonal(vector<Usuario*> , Usuario*);
vector<Usuario*> fire(vector<Usuario*> , Usuario*);
double promSueldos(vector<Usuario*> );

//funciones de Lavaplatos
bool lavaplatosSalario(int);
int aumentoLavap(Usuario*);
bool renuncioLP(Usuario*);

//funciones del chef
void gritarLP(vector<Usuario*> users);
void agradarLP(vector<Usuario*> users);


using namespace std;

int main(){
  vector<Usuario*> users = readFile();
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
      int usuario;
      case 1:{
        int contu=0, contp=0;
        bool p=false, u=false;
        string pass, username;
        string pass1="", username1="";
        cout<<"Ingrese su username: "<<endl;
        cin>>username;
        cout<<"Ingrese su password"<<endl;
        cin>>pass;
        for (int i = 0; i < users.size(); i++) {
          pass1=users.at(i)->getPassword();
          username1=users.at(i)->getUsername();
          if (pass1.size()==pass.size()) {
            for (int j = 0; j < pass.size(); j++) {
              if (pass.at(j)==pass.at(j)) {
                contp++;
                if (contp==pass.size()) {
                  p=true;
                }
              }
            }//fin del for de password
          }
          if (username.size()==username1.size()) {
            for (int k = 0; k < username.size(); k++) {
              if (username1.at(k)==username.at(k)) {
                contu++;
                if (contu==username.size()) {
                  u=true;
                  if (p&&u) {
                    user=users.at(i);
                    cout<<user->getNombre();
                    break;
                  }
                }
              }
            }//fin del for de username
          }
        }//fin del for de la lista de users


        if (p&&u) {
          if (dynamic_cast<Administrador*>(user)) {
            usuario=1;
          }
          if (dynamic_cast<Chef*>(user)) {
            usuario=2;
          }
          if (dynamic_cast<Lavaplatos*>(user)) {
            usuario=3;
          }
          if (dynamic_cast<Mesero*>(user)) {
            usuario=4;
          }
          if (dynamic_cast<Cliente*>(user)) {
            usuario=5;
          }
        } else{
          usuario=6;
        }

        switch(usuario){//inicio de switch
          int opt;
          case 1:{//Administrador
            char res='s';
            while (res=='s'||res=='S') {
              cout<<"         MENU DE ADMINISTRADOR"<<endl<<"_______________________________________________"<<endl;
              cout<<"1- Contratar empleado"<<endl<<"2- Despedir empleado"<<endl<<"3-Empleado(s) con menor sueldo"<<endl<<"4-Empleado(s) con mayor sueldo"<<endl<<"5- Agregar platillo a mesero"<<endl<<"6- Promedio de sueldos de empleados"<<endl;
              cin>>opt;
              while(opt<0||opt>6){
                cout<<"Opcion invalida, intente de nuevo"<<endl;
                cin>>opt;
              }// fin del while de validacion de opcion

              switch (opt) {
                case 1:{
                  users=agregarPersonal(users, user);
                  break;
                }//fin del case 1 menu de admin
                case 2:{
                  users=fire(users, user);
                  break;
                }//fin del case 2 de menu de admin

                case 3:{
                  vector<string> menorsueldo=menorSalario(users);
                  break;
                }//fin del case 3 de menu de admin

                case 4:{
                  vector<string> maysueldo=mayorSalario(users);
                  break;
                }//fin del case 4 de menu de admin

                case 5:{
                  addDish(users);
                  break;
                }//fin del case 5 de menu de admin

                case 6:{
                  double promedio = promSueldos(users);
                  cout<<"El promedio de los sueldos es: "<< promedio;
                  break;
                }//fin del case 6 de menu de admin
              }//fin del switch de menu de administradores
              cout<<"Desea continuar en el menu de administradores [s/n]"<<endl;
              cin>>res;
            }//fin del while de admins

            break;
          }//fin del case 1

          case 2:{//Chef
            char res='s';
            while (res=='s'||res=='S') {
              cout<<"         MENU DE CHEF"<<endl<<"_______________________________________________"<<endl;
              cout<<"1- Gritar a lava platos"<<endl<<"2- Agradar a lava platos"<<endl;
              cin>>opt;
              while (opt<0||opt>2) {
                cout<<"Opcion invalida, intente de nuevo"<<endl;
                cin>>opt;
              }
              switch (opt) {
                case 1:{
                  gritarLP(users);
                  break;
                }//fin decase 1 Chef

                case 2:{
                  agradarLP(users);
                  break;
                }//fin de case 2 de Chef
              }
              cout<<"Desea continuar en el menu de chefs[s/n]"<<endl;
              cin>>res;
            }//fin del while del chef

            break;
          }//fin del case 2

          case 3:{//Lavaplatos
            char res='s';
            while (res=='s'||res=='S') {
              cout<<"         MENU DE LAVAPLATOS"<<endl<<"_______________________________________________"<<endl;
              cout<<"1- RENUNCIAR"<<endl<<"2- PEDIR AUMENTO"<<endl;
              cin>>opt;
              while (opt<0||opt>2) {
                cout<<"Opcion invalida, intente de nuevo"<<endl;
                cin>>opt;
              }
              switch (opt) {
                case 1:{
                  bool quit = renuncioLP(user);
                  if (quit) {
                    cout<<"Carta de renuncia entregada exitosamente"<<endl;
                  }
                  for (int i = 0; i < users.size(); i++) {
                    if (dynamic_cast<Lavaplatos*>(users.at(i))->getId()==dynamic_cast<Lavaplatos*>(user)->getId()) {
                      users.erase(users.begin()+i);
                    }
                  }
                  break;
                }//fin decase 1 Chef

                case 2:{
                  int mot=dynamic_cast<Lavaplatos*>(user)->getMotivacion();
                  int dinero;
                  bool aumento=lavaplatosSalario(mot);
                  if (aumento) {
                    dinero=aumentoLavap(user)+dynamic_cast<Lavaplatos*>(user)->getSueldo();
                    for (int i = 0; i < users.size(); i++) {
                      if (dynamic_cast<Lavaplatos*>(users.at(i))->getId()==dynamic_cast<Lavaplatos*>(user)->getId()) {
                        dynamic_cast<Lavaplatos*>(users.at(i))->setSueldo(dinero);
                      }
                    }

                  } else{
                    cout<<"Lo sentimos, necesitas una motivacion mayor a 100 para pedir aumento"<<endl;
                  }
                  break;
                }//fin de case 2 de Chef
              }
              cout<<"Desea continuar en el menu de lava platos [s/n]"<<endl;
              cin>>res;
            }//fin del while del chef

            break;
          }//fin del case 3

          case 4:{//Mesero
            char res='s';
            while (res=='s'||res=='S') {
              cout<<"         MENU DE MESERO"<<endl<<"_______________________________________________"<<endl;
              dynamic_cast<Mesero*>(user)->deliver();
              cout<<"Desea continuar en el menu de mesero [s/n]"<<endl;
              cin>>res;
            }
            break;
          }//fin del case 4

          case 5:{//CLIENTE
            char res='s';
            while (res=='s'||res=='S') {
              cout<<"         MENU DE CLIENTE"<<endl<<"_______________________________________________"<<endl;
              double prom=promedioRating(users);
              cout<<"El promedio del Rating del restaurante es: "<<prom<<endl;
              cout<<"Desea continuar en el menu de cliente [s/n]"<<endl;
              cin>>res;
            }
            break;
          }//fin del case 5

          case 6:{
            cout<<endl;
            cout<<"Username o password incorrectas"<<endl;
            cout<<"Asegurese de haber creado una cuenta primero"<<endl;
            break;
          }//fin del case 6
        }//fin del switch
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
              cout<<"               CUENTA DE CLIENTE"<<endl<<"________________________________________________________"<<endl;

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
              cout<<"               CUENTA DE ADMINISTRADOR"<<endl<<"________________________________________________________"<<endl;

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
        wFile(users);
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
  ofstream archivo("File.txt");
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
    cout<<"____________________________________________________"<<endl;
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
bool lavaplatosSalario(int motivacion){
  bool aumento=false;
  if (motivacion>=100) {
    aumento=true;
  }
  return aumento;
}
int aumentoLavap(Usuario* lp){
  int money=0;
  cout<<"Ingrese la cantidad de dinero que desea aumentar"<<endl;
  cin>>money;
  if (dynamic_cast<Lavaplatos*>(lp)) {
    Lavaplatos* lp1 = dynamic_cast<Lavaplatos*>(lp);
    int salario = lp1->getSueldo();
    while (money>=salario) {
      cout<<"Lo sentimos! Mucho aumento. Ingresa una cantidad menor a la de tu salario actual"<<endl;
      cin>>money;
    }
  }
  return money;
}
bool renuncioLP(Usuario* lp){
  bool quit = false;
  int motivation=0;
  if (dynamic_cast<Lavaplatos*>(lp)) {
    motivation=dynamic_cast<Lavaplatos*>(lp)->getMotivacion();
    if (motivation<=25) {
      quit = true;
    }
  }
  return quit;
}

void gritarLP(vector<Usuario*> users){

  int opc, humilliate;
  for (int i = 0; i < users.size(); i++) {
    if (dynamic_cast<Lavaplatos*>(users.at(i))) {
      cout<<i<<"- "<<users.at(i)->getNombre()<<endl;
    }
  }

  cout<<"Ingrese a quien desea gritarle: ";
  cin>>opc;
  cout<<"Ingrese el nivel de humillacion ";
  cin>>humilliate;
  Lavaplatos* l = dynamic_cast<Lavaplatos*>(users.at(opc));
  l->setMotivacion(l->getMotivacion()-humilliate);
}

void agradarLP(vector<Usuario*> users){
  int opc,nice;
  for (int i = 0; i < users.size(); i++) {
    if (dynamic_cast<Lavaplatos*>(users.at(i))) {
      cout<<i<<"- "<<users.at(i)->getNombre()<<endl;
    }
  }

  cout<<"Ingrese la posicion de quien desea agradar: ";
  cin>>opc;
  cout<<"ingrese el nivel de agrado: ";
  cin>>nice;
  Lavaplatos* l = dynamic_cast<Lavaplatos*>(users.at(opc));
  l->setMotivacion(l->getMotivacion()+nice);
}

double promSueldos(vector<Usuario*> users){
  int cont=0, acum=0;
  for (int i = 0; i < users.size(); i++) {
    if (dynamic_cast<Personal*>(users.at(i))) {
      acum+=dynamic_cast<Personal*>(users.at(i))->getSueldo();
      cont++;
    }
  }
  return (acum/cont);
}

vector<Usuario*> readFile(){
  vector<Usuario*> users;
  fstream file("File.txt");
  if (file.is_open()) {
  while(!file.eof()){
    string tipo;
    string line,username,passcode,nombre,id,numero,edad,year,sal;
    int age, id1, numb, ano;
    int salario;
    getline(file,tipo,',');
    if (!tipo.compare("A")) {
      int contra, desp;
      string contras,despes;
      getline(file,username,',');
      getline(file,passcode,',');
      getline(file,nombre,',');
      getline(file,edad,',');
      age = atoi(edad.c_str());
      getline(file,id,',');
      id1= atoi(id.c_str());
      getline(file,numero,',');
      numb=atoi(numero.c_str());
      getline(file,year,',');
      ano=atoi(year.c_str());
      getline(file,sal,',');
      salario = atoi(sal.c_str());
      getline(file,contras,',');
      contra = atoi(contras.c_str());
      getline(file,despes,';');
      desp = atoi(despes.c_str());
      users.push_back(new Administrador(username,passcode,nombre,age,id1,numb,ano,salario,contra,desp));
    }

    if (!tipo.compare("C")) {
      string plato;
      getline(file,username,',');
      getline(file,passcode,',');
      getline(file,nombre,',');
      getline(file,edad,',');
      age = atoi(edad.c_str());
      getline(file,id,',');
      id1= atoi(id.c_str());
      getline(file,numero,',');
      numb=atoi(numero.c_str());
      getline(file,year,',');
      ano=atoi(year.c_str());
      getline(file,sal,',');
      salario = atoi(sal.c_str());
      getline(file,plato,';');
      users.push_back(new Chef(username,passcode,nombre,age,id1,numb,ano,salario,plato));
    }


    if (!tipo.compare("B")) {
      string direccion,srate;
      int rate;
      getline(file,username,',');
      getline(file,passcode,',');
      getline(file,nombre,',');
      getline(file,edad,',');
      age = atoi(edad.c_str());
      getline(file,id,',');
      id1= atoi(id.c_str());
      getline(file,numero,',');
      numb=atoi(numero.c_str());
      getline(file,direccion,',');
      getline(file,srate,';');
      rate = atoi(srate.c_str());
      users.push_back(new Cliente(username,passcode,nombre,age,id1,numb,direccion,rate));
    }

    if (!tipo.compare("M")) {
      vector<string> pl;
      getline(file,username,',');
      getline(file,passcode,',');
      getline(file,nombre,',');
      getline(file,edad,',');
      age = atoi(edad.c_str());
      getline(file,id,',');
      id1= atoi(id.c_str());
      getline(file,numero,',');
      numb=atoi(numero.c_str());
      getline(file,year,',');
      ano=atoi(year.c_str());
      getline(file,sal,';');
      salario = atoi(sal.c_str());
      users.push_back(new Mesero(username,passcode,nombre,age,id1,numb,ano,salario, pl));
    }

    if (!tipo.compare("L")) {
      string motiv;
      int motivacion;
      getline(file,username,',');
      getline(file,passcode,',');
      getline(file,nombre,',');
      getline(file,edad,',');
      age = atoi(edad.c_str());
      getline(file,id,',');
      id1= atoi(id.c_str());
      getline(file,numero,',');
      numb=atoi(numero.c_str());
      getline(file,year,',');
      ano=atoi(year.c_str());
      getline(file,sal,',');
      salario = atoi(sal.c_str());
      getline(file,motiv,';');
      motivacion = atoi(motiv.c_str());
      users.push_back(new Lavaplatos(username,passcode,nombre,age,id1,numb,ano,salario,motivacion));
    }
  }

    file.close();
    return users;

  }
}
