#include "aldeano.h"

using namespace std;

Aldeano::Aldeano(){}

Aldeano::Aldeano(const Aldeano& a) : nombreA(a.nombreA), edadA(a.edadA), generoA(a.generoA), saludA(a.saludA){ }

int Aldeano::getEdadA() const
{
    return edadA;
}

void Aldeano::setEdadA(int value)
{
    edadA = value;
}

string Aldeano::getGeneroA() const
{
    return generoA;
}

void Aldeano::setGeneroA(const string &value)
{
    generoA = value;
}

int Aldeano::getSaludA() const
{
    return saludA;
}

void Aldeano::setSaludA(int value)
{
    saludA = value;
}


string Aldeano::getNombreA() const
{
    return nombreA;
}

void Aldeano::setNombreA(const string &value)
{
    nombreA = value;
}

string Aldeano::toString(){
    ///Se convierte la salud y la edad a una string para poder imprimir
    char miEdad[7];
    char miSalud[7];
    sprintf(miEdad, "%d", edadA);
    sprintf(miSalud, "%d", saludA);
    return "+ " + nombreA + " | " + generoA + " | " + miEdad + " | " + miSalud;
}

Aldeano &Aldeano::operator = (const Aldeano &a)
{
    ///Ahora el compilador puede igualar
    nombreA = a.nombreA;
    edadA = a.edadA;
    generoA = a.generoA;
    saludA = a.saludA;

    return *this;
}

ostream &operator <<(ostream &o, Aldeano &a)
{
    ///Se convierte la salud y la edad a una string para poder imprimir
    char miSalud[7];
    sprintf(miSalud, "%d", a.saludA);
    char miEdad[7];
    sprintf(miEdad, "%d", a.edadA);

    o << "+ "
      << a.nombreA
      << " | " << miEdad
      << " | " << a.generoA
      << " | " << miSalud << " HP";

    return o;
}

istream &operator >> (istream &is, Aldeano &a)
{
    ///Se convierte la salud y la edad a una string para poder guardar
    is >> a.nombreA;

    string myStr;
    getline(is, myStr) >> a.edadA;
    a.edadA = atof(myStr.c_str());

    is >> a.generoA;

    string myStr2;
    getline(is, myStr2) >> a.saludA;
    a.saludA = atof(myStr2.c_str());

    return is;
}

bool Aldeano::operator == (const Aldeano &a)
{
    ///Operador sobrecargado para poder comparar
    return nombreA == a.nombreA;
}

///Resto de operadores existentes (Hacer posible cambio a la edad y no al nombre)
bool Aldeano::operator != (const Aldeano &a)
{
    return nombreA != a.nombreA;
}

bool Aldeano::operator <= (const Aldeano &a)
{
    return nombreA <= a.nombreA;
}

bool Aldeano::operator >= (const Aldeano &a)
{
    return nombreA >= a.nombreA;
}

bool Aldeano::operator < (const Aldeano &a)
{
    return nombreA < a.nombreA;
}

bool Aldeano::operator > (const Aldeano &a)
{
    return nombreA > a.nombreA;
}
