#include "guerrero.h"
using namespace std;

int Guerrero::getIdGuerrero() const
{
    return idGuerrero;
}

void Guerrero::setIdGuerrero(int value)
{
    idGuerrero = value;
}

int Guerrero::getSaludGuerrero() const
{
    return saludGuerrero;
}

void Guerrero::setSaludGuerrero(int value)
{
    saludGuerrero = value;
}

double Guerrero::getFuerzaGuerrero() const
{
    return fuerzaGuerrero;
}

void Guerrero::setFuerzaGuerrero(double value)
{
    fuerzaGuerrero = value;
}

double Guerrero::getEscudoGuerrero() const
{
    return escudoGuerrero;
}

void Guerrero::setEscudoGuerrero(double value)
{
    escudoGuerrero = value;
}

string Guerrero::getTipoGuerrero() const
{
    return tipoGuerrero;
}

void Guerrero::setTipoGuerrero(const string &value)
{
    tipoGuerrero = value;
}

string Guerrero::toString()
{
    char miId[sizeof(idGuerrero)];
    sprintf(miId, "%d", idGuerrero);

    char miSalud[sizeof(saludGuerrero)];
    sprintf(miSalud, "%d", saludGuerrero);

    char miFuerza[sizeof(fuerzaGuerrero)];
    sprintf(miFuerza, "%f", fuerzaGuerrero);

    char miEscudo[sizeof(escudoGuerrero)];
    sprintf(miEscudo, "%f", escudoGuerrero);

    string result = "+> ";
    result += miId;
    result += " | ";
    result += miSalud;
    result += " HP | ";
    result += miFuerza;
    result += " F | ";
    result += miEscudo;
    result += " E | ";
    result += tipoGuerrero;

    //return "+> " + miId + " | " + miSalud + " | " + miFuerza + " | " + miEscudo + " | " + tipoGuerrero;
    return result;

}

Guerrero &Guerrero::operator = (const Guerrero &g){
    //Ahora el compilador puede igualar
    idGuerrero = g.idGuerrero;
    saludGuerrero = g.saludGuerrero;
    fuerzaGuerrero = g.fuerzaGuerrero;
    escudoGuerrero = g.escudoGuerrero;
    tipoGuerrero = g.tipoGuerrero;
    return *this;
}

//bool Guerrero::operator == (const Guerrero &g)
//{
//    return idGuerrero == g.idGuerrero;
//}

//istream &Guerrero::operator >>(istream &is, Guerrero &g)
//{
//    string myStr;
//    getline(is, myStr) >> g.idGuerrero;
//    g.idGuerrero = atof(myStr.c_str());

//    getline(is, myStr) >> g.saludGuerrero;
//    g.saludGuerrero = atof(myStr.c_str());

//    getline(is, myStr) >> g.fuerzaGuerrero;
//    g.fuerzaGuerrero = atof(myStr.c_str());

//    getline(is, myStr) >> g.escudoGuerrero;
//    g.escudoGuerrero = atof(myStr.c_str());

//    is >> g.tipoGuerrero;
//    return is;
//}

ostream &operator <<(ostream &o, Guerrero &g){
    //Se convierte la salud y la edad a una string para poder imprimir
    char miId[sizeof(g.idGuerrero)];
    sprintf(miId, "%d", g.idGuerrero);

    char miSalud[sizeof(g.saludGuerrero)];
    sprintf(miSalud, "%d", g.saludGuerrero);

    char miFuerza[sizeof(g.fuerzaGuerrero)];
    sprintf(miFuerza, "%.2f", g.fuerzaGuerrero);

    char miEscudo[sizeof(g.escudoGuerrero)];
    sprintf(miEscudo, "%.2f", g.escudoGuerrero);

    o << "+> "
      << miId
      << " | " << miSalud
      << " HP | " << miFuerza
      << " F | " << miEscudo
      << " E | " << g.tipoGuerrero;

    return o;
}

Guerrero::Guerrero(){}

//Guerrero::Guerrero(const Guerrero &g) : id(g.id), salud(g.salud), fuerza(g.fuerza), escudo(g.escudo), tipoGuerrero(g.tipoGuerrero){}
