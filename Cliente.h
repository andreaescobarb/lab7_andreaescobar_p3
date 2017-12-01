#ifndef Cliente_h
#define Cliente_h

#include <string>
#include <iostream>

class Cliente: public Usuario{
  private:
    string direccion;
    int rating;

  public:
    Cliente();
    Cliente(string, int):

    string getDireccion();
    void setDireccion();

    int getRating();
    void setDireccion();

    ~Cliente();
};
#endif
