#ifndef GUERRERO_H
#define GUERRERO_H

#include <iostream>
#include <cstdio>

class Guerrero
{
private:
    int idGuerrero;
    int saludGuerrero;
    double fuerzaGuerrero;
    double escudoGuerrero;
    std::string tipoGuerrero;
public:
    Guerrero();

    int getIdGuerrero() const;
    void setIdGuerrero(int value);

    int getSaludGuerrero() const;
    void setSaludGuerrero(int value);

    double getFuerzaGuerrero() const;
    void setFuerzaGuerrero(double value);

    double getEscudoGuerrero() const;
    void setEscudoGuerrero(double value);

    std::string getTipoGuerrero() const;
    void setTipoGuerrero(const std::string &value);

    ///ToString
    std::string toString();

    Guerrero& operator = (const Guerrero&g);
    friend std::ostream &operator << (std::ostream &o, Guerrero &g);
    friend std::istream& operator >> (std::istream &is, Guerrero &g);
};

#endif // GUERRERO_H
