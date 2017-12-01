#ifndef Usuario_h
#define Usuario_h

#include <string>
#include <iostream>

class Usuario{
    private:
      string username;
      string password;
      string nombre;
      int edad, id, telefono;

    public:
      Usuario();
      Usuario(string, string, string, int, int, int);

      string getUsername();
		  void setUsername(string);

		  string getPassword();
		  void setPassword(string);

		  string getNombre();
		  void setNombre(string);

      int getEdad();
      void setEdad();

      int getId();
      void setID();

      int getTelefono();
      void setTelefono();

      ~Usario();

};
#endif
