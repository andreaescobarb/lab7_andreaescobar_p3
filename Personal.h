#ifndef Personal_h
#define Personal_h

class Personal: public Usuario{
  private:
    int ano, sueldo;

  public:
    Personal():
    Personal(int, int);

    int getAno();
    void setAno();

    int getSueldo();
    void setSueldo();

    ~Personal();

};
#endif
