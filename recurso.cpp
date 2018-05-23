#include "recurso.h"

Recurso::Recurso(){}

int Recurso::getIdRecurso() const
{
    return idRecurso;
}

void Recurso::setIdRecurso(int value)
{
    idRecurso = value;
}

int Recurso::getCantidadRecurso() const
{
    return cantidadRecurso;
}

void Recurso::setCantidadRecurso(int value)
{
    cantidadRecurso = value;
}

std::string Recurso::getTipoRecurso() const
{
    return tipoRecurso;
}

void Recurso::setTipoRecurso(const std::string &value)
{
    tipoRecurso = value;
}

std::string Recurso::toString()
{
    char miId[sizeof(idRecurso)];
    sprintf(miId, "%d", idRecurso);

    char miCantidad[sizeof(cantidadRecurso)];
    sprintf(miCantidad, "%d", cantidadRecurso);

    std::string result = "\t\t\t+> ";
    result += miId;
    result += " | ";
    result += miCantidad;
    result += " | ";
    result += tipoRecurso;

    return result;
}

Recurso &Recurso::operator =(const Recurso &g)
{
    idRecurso = g.idRecurso;
    cantidadRecurso = g.cantidadRecurso;
    tipoRecurso = g.tipoRecurso;
    return *this;
}

std::ostream &operator <<(std::ostream &o, Recurso &g)
{
    char miId[sizeof(g.idRecurso)];
    sprintf(miId, "%d", g.idRecurso);

    char miCantidad[sizeof(g.cantidadRecurso)];
    sprintf(miCantidad, "%d", g.cantidadRecurso);

    o << "\t\t\t+> "
      << miId
      << " | " << miCantidad
      << " | " << g.tipoRecurso;

    return o;
}

//std::istream &Recurso::operator >>(std::istream &is, Recurso &g)
//{
//    char miId[sizeof(idRecurso)];
//    sprintf(miId, "%d", idRecurso);

//    char miCantidad[sizeof(cantidadRecurso)];
//    sprintf(miCantidad, "%d", cantidadRecurso);

//    return is;
//}

