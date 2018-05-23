#ifndef RECURSO_H
#define RECURSO_H

#include <iostream>

class Recurso
{
    int idRecurso;
    int cantidadRecurso;
    std::string tipoRecurso;

public:
    Recurso();
    Recurso(int c){
        cantidadRecurso = c;
    }

    int getIdRecurso() const;
    void setIdRecurso(int value);

    int getCantidadRecurso() const;
    void setCantidadRecurso(int value);

    std::string getTipoRecurso() const;
    void setTipoRecurso(const std::string &value);

    ///ToString
    std::string toString();

    bool operator < (const Recurso &r){
        return cantidadRecurso < r.cantidadRecurso;
    }
    Recurso& operator = (const Recurso&g);
    friend std::ostream &operator << (std::ostream &o, Recurso &g);
    friend std::istream& operator >> (std::istream &is, Recurso &g);
};

#endif // RECURSO_H
