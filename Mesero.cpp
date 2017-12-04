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

void Mesero::deliver(){
	for (int i = 0; i < listaPlatillos.size(); i++) {
		cout<<i<<"- "<<listaPlatillos.at(i)<<endl;
	}
	cout<<"Ingrese opcion"<<endl;
	cout<<"1- Entregar un platillo especifico"<<endl<<"2- Entregar todos los platillos"<<endl;

	int opc;
	cin>>opc;
	while (opc>2||opc<1) {
		cout<<"Opcion erronea, ingrese opcion de nuevo"<<endl;
		cin>>opc;
	}
	if (opc==1) {
		cout<<"Ingrese posicion de platillo en la lista"<<endl;
		int pos;
		cin>>pos;

		listaPlatillos.erase(listaPlatillos.begin()+pos);
	} else{
		for (int i = 0; i < listaPlatillos.size(); i++) {
			listaPlatillos.erase(listaPlatillos.begin()+i);
		}
	}

}

string Mesero::toString(){
	stringstream st;
	string conversion;
	char tip ='A';
	st<<tip;
	st<<",";
	st<<username;
	st<<",";
	st<<password;
	st<<",";
	st<<nombre;
	st<<",";
	st<<edad;
	st<<",";
	st<<id;
	st<<",";
	st<<telefono;
	st<<",";
	st<<contratacion;
	st<<",";
	st<<sueldo;
	st<<";";

	conversion=st.str();
	return conversion;
}

Mesero::~Mesero(){

}
