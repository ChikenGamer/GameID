#ifndef ALDEANO_H
#define ALDEANO_H

#include <iostream>
#include <cstdio>

class Aldeano
{
private:
    std::string nombreA;
    int edadA;
    std::string generoA;
    int saludA;

public:
    Aldeano();
    Aldeano(const Aldeano&);
    ///Nombre
    std::string getNombreA() const;
    void setNombreA(const std::string &value);
    ///Edad
    int getEdadA() const;
    void setEdadA(int value);
    ///Genero
    std::string getGeneroA() const;
    void setGeneroA(const std::string &value);
    ///Salud;
    int getSaludA() const;
    void setSaludA(int value);
    ///ToString
    std::string toString();

    ///Operadoradores sobrecargados
    Aldeano& operator = (const Aldeano&a);
    friend std::ostream &operator << (std::ostream &o, Aldeano &a);
    friend std::istream& operator >> (std::istream &is, Aldeano&a);
    bool operator == (const Aldeano&);
    bool operator != (const Aldeano&);
    bool operator <= (const Aldeano&);
    bool operator >= (const Aldeano&);
    bool operator < (const Aldeano&);
    bool operator > (const Aldeano&);
};

#endif // ALDEANO_H
