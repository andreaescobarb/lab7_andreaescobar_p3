#include "Chef.h"

Chef::Chef(string platillo): Personal(int contratacion,int sueldo){
	this->platillo=platillo;
}
Chef::Chef(){

}void Chef::setPlatillo(string platillo){
   this-> platillo=platillo;
}
string Chef::getPlatillo(){
   return platillo;
}
