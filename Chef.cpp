#include "Chef.h"

Chef::Chef(string platillo): Personal(contratacion,sueldo){
	this->platillo=platillo;
}
Chef::Chef(){

}void Chef::setPlatillo(string platillo){
   this-> platillo=platillo;
}
string Chef::getPlatillo(){
   return platillo;
}
