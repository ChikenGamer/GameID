#ifndef ALDEANO_H
#define ALDEANO_H

#include <iostream>
#include <cstdio>
using namespace std;

class Aldeano
{
private:
    string nombreA;
    int edadA;
    string generoA;
    int saludA;

public:
    Aldeano();
    Aldeano(const Aldeano&);
    ///Nombre
    string getNombreA() const;
    void setNombreA(const string &value);
    ///Edad
    int getEdadA() const;
    void setEdadA(int value);
    ///Genero
    string getGeneroA() const;
    void setGeneroA(const string &value);
    ///Salud;
    int getSaludA() const;
    void setSaludA(int value);
    ///ToString
    string toString();

    ///Operadoradores sobrecargados
    Aldeano& operator = (const Aldeano&a);
    friend ostream &operator << (ostream &o, Aldeano &a);
    friend istream& operator >> (istream &is, Aldeano&a);
    bool operator == (const Aldeano&);
    bool operator != (const Aldeano&);
    bool operator <= (const Aldeano&);
    bool operator >= (const Aldeano&);
    bool operator < (const Aldeano&);
    bool operator > (const Aldeano&);
};

#endif // ALDEANO_H
