#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <stdexcept>
#include <iostream>
#include "listadoble.h"
#include "guerrero.h"
#include "colaprioridad.h"
#include "recurso.h"
#include "mapa.h"

template <class T>
class Civilizacion
{
private:
    T *arreglo;
    int tam;
    int indice;
    const static int MAX = 5;

    int filaMapa;
    int columnaMapa;

    ListaDoble<Guerrero> guerreros;
    ColaPrioridad<Recurso> recursos;
    //Mapa<Civilizacion*> mapa;


public:
    std::string nombreC = "SIN NOMBRE";

    Civilizacion();
    ~Civilizacion();
    std::string getNombreC();

    // Civilizacion y aldeanos
    void setNombreC(std::string s); //< Nombre civilizacion
    void agregarA(const T &dato); //< Agregar aldeano
    void eliminarA(int pos); //< Eliminar aldeano

    int linearFindData(const T &name);
    int poblacionT();
    int tamanio();

    bool isEmpty();

    T &operator[](int posicion);

    void toString();

    // Guerreros
    void agregarGuerrero(const Guerrero &g);
    int linerFindGuerrero(int idG); //< Busca si existe o no el ID y la pos!
    void eliminarG(int pos); //< Elimina el nodo en la pos dada
    Guerrero &datosG(int pos); //< Me regresa el guerrero en la pos dada
    int guerrerosSize(); //< Devuelve el tamaño de la lista doble

    void borrarPorTipo(std::string s); //< Busca por clase y los borra todos
    void borrarPorSalud(int salud); //< Busca por salud y los borra todos

    void saludMayorIgual(int salud); //< Busca por lo que dice
    void saludMenorQue(int salud); //< Busca por lo que dice
    void fuerzaMayorIgual(double fuerza); //< Busca por lo que dice
    void fuerzaMenorQue(double fuerza); //< Busca por lo que dice
    void tipoGuerrero(std::string clase); //< Busca por lo que dice

    // Recurso
    void agregarRecurso(Recurso &r);
    void elimiarRecurso();
    void elimiarRecursoPos(int pos);
    Recurso &retrieveRecurso(int pos);
    int findRecurso(int ID);
    int colaSize();
    void mayorIgualQueCola(int numero);
    void menorQueCola(int numero);
    void tipoRecurso(std::string tipoRecurso);

    //Mapa
    int getFilaMapa() const;
    void setFilaMapa(int value);
    int getColumnaMapa() const;
    void setColumnaMapa(int value);
};

// CIVILIZACION y ALDEANOS
template<class T>
int Civilizacion<T>::getFilaMapa() const
{
    return filaMapa;
}

template<class T>
void Civilizacion<T>::setFilaMapa(int value)
{
    filaMapa = value;
}

template<class T>
int Civilizacion<T>::getColumnaMapa() const
{
    return columnaMapa;
}

template<class T>
void Civilizacion<T>::setColumnaMapa(int value)
{
    columnaMapa = value;
}

template <class T>
Civilizacion<T>::Civilizacion()
{
    arreglo = new T[MAX];
    indice = 0;
    tam = MAX;
}

template <class T>
Civilizacion<T>::~Civilizacion()
{
    delete[]arreglo;
}

template<class T>
std::string Civilizacion<T>::getNombreC()
{
    return nombreC;
}

template<class T>
void Civilizacion<T>::setNombreC(std::string s)
{
    nombreC = s;
}

template<class T>
void Civilizacion<T>::agregarA(const T &dato)
{
    if(indice < tam){
        ///Si el indice es menor al tam total se agrega el aldeano
        arreglo[indice++] = dato;
    }else{
        ///Si no se aumenta el tam y se crea un nuevo arreglo y se agrega el aldeano
        T *nuevo = new T[tam+5];
        for (int i = 0; i < indice; ++i) {
            nuevo[i]=arreglo[i];
        }
        delete []arreglo;
        arreglo = nuevo;
        arreglo[indice++] = dato;
        tam = tam + 5;
    }
}

template <class T>
int Civilizacion<T>::linearFindData(const T& name) {
    ///Busca el nombre del aldeano si lo encuentra regresa su posicion
    int i(0);
    while( i <= indice){
        if(arreglo[i] == name){
            return i;
        }
        i++;
    }
    ///Si no lo encuentra regresa -1 (Inexistente)
    return -1;
}

template<class T>
void Civilizacion<T>::eliminarA(int pos)
{
    if (pos >= indice or pos < 0) {
        ///Revisa si hay espacio para eliminar(Obsoleto por 'isEmpty()')
        std::cout << "-=POSICION INVALIDA=-";
    }
    for (int i = pos; i < indice - 1; ++i) {
        ///Recorre el arreglo para sobreescribir la posicion
        arreglo[i] = arreglo[i+1];
    }
    ///Reduce el indice diciendo que hay un aldeano menos
    indice--;
}

template<class T>
int Civilizacion<T>::poblacionT()
{
    return indice;
}

template<class T>
int Civilizacion<T>::tamanio()
{
    return tam;
}

template<class T>
bool Civilizacion<T>::isEmpty()
{
    ///Si el indice es igual a '0' no hay nada en el arreglo
    int result = indice + guerreros.getSize();
    return result == 0;
}

template<class T>
void Civilizacion<T>::toString()
{
    std::cout << std::endl << "\t\t\t-Nombre civilizacion: " << nombreC<< std::endl;
    std::cout << "\t\t\t-Coordenadas X,Y: " << getColumnaMapa() << " , " << getFilaMapa() << std::endl;
    std::cout << "\t\t\t-Poblacion total: " << poblacionT()+guerreros.getSize() << std::endl;
    std::cout << "\t\t\t-Aldeanos: " << std::endl;
    for (int i = 0; i < poblacionT(); ++i) {
        std::cout << arreglo[i] << std::endl;
    }
    std::cout << "\t\t\t-Guerreros: " << std::endl;
    for (int i = 0; i < guerreros.getSize(); ++i) {
        std::cout << guerreros[i] << std::endl;
    }
    std::cout << "\t\t\t-Recursos: " << std::endl;
    for (int i = 0; i < recursos.colaSize(); ++i) {
        std::cout << recursos[i] << std::endl;
    }
}

template<class T>
T &Civilizacion<T>::operator[](int posicion)
{
    ///Operador sobrecargado para poder imprimir el arreglo tipo T
    if (posicion < 0 or posicion >= indice){
        std::cout << "-=POSICION INVALIDA=-";
    }
    return arreglo[posicion];
}


// GUERRERO
template<class T>
void Civilizacion<T>::agregarGuerrero(const Guerrero &g)
{
    guerreros.insertarInicio(g);
}

template<class T>
int Civilizacion<T>::linerFindGuerrero(int idG)
{
    int i(0);
    while( i <= guerreros.getSize()){
        if(guerreros[i].getIdGuerrero() == idG){
            return i;
        }
        i++;
    }
    ///Si no lo encuentra regresa -1 (Inexistente)
    return -1;
}

template<class T> //> BORRAR POR TIPO DE GUERRERO
void Civilizacion<T>::borrarPorTipo(std::string s)
{
   int i(0);
   while(i <= guerreros.getSize()){
        if (guerreros[i].getTipoGuerrero() == s) {
            eliminarG(i);
        }else {
            i++;
        }
    }
}

template<class T> //> BORRAR POR SALUD DEL GUERRERO
void Civilizacion<T>::borrarPorSalud(int salud)
{
    int i(0);
    while(i <= guerreros.getSize()){
        if(guerreros[i].getSaludGuerrero() < salud){
            eliminarG(i);
        }else {
            i++;
        }
    }
}

template<class T>
void Civilizacion<T>::saludMayorIgual(int salud)
{
    int i(0);
    while(i <= guerreros.getSize()){
        if(guerreros[i].getSaludGuerrero() >= salud){
            std::cout << guerreros[i] << '\n';;
        }
        i++;
    }
}

template<class T>
void Civilizacion<T>::saludMenorQue(int salud)
{
    int i(0);
    while(i <= guerreros.getSize()){
        if(guerreros[i].getSaludGuerrero() < salud){
            std::cout << guerreros[i] << '\n';;
        }
        i++;
    }
}

template<class T>
void Civilizacion<T>::fuerzaMayorIgual(double fuerza)
{
    int i(0);
    while(i <= guerreros.getSize()){
        if(guerreros[i].getFuerzaGuerrero() >= fuerza){
            std::cout << guerreros[i] << '\n';;
        }
        i++;
    }
}

template<class T>
void Civilizacion<T>::fuerzaMenorQue(double fuerza)
{
    int i(0);
    while(i <= guerreros.getSize()){
        if(guerreros[i].getFuerzaGuerrero() < fuerza){
            std::cout << guerreros[i] << '\n';;
        }
        i++;
    }
}

template<class T>
void Civilizacion<T>::tipoGuerrero(std::string clase)
{
    int i(0);
    while(i <= guerreros.getSize()){
        if(guerreros[i].getTipoGuerrero() == clase){
            std::cout << guerreros[i] << '\n';
        }
        i++;
    }
}

template<class T>
void Civilizacion<T>::eliminarG(int pos)
{
    guerreros.eliminarPos(pos);
}

template<class T>
Guerrero& Civilizacion<T>::datosG(int pos)
{
    return guerreros[pos];
}

template<class T>
int Civilizacion<T>::guerrerosSize()
{
    return guerreros.getSize();
}


// RECURSO
template<class T>
void Civilizacion<T>::agregarRecurso(Recurso &r)
{
    recursos.encolar(r);
}

template<class T> //**
void Civilizacion<T>::elimiarRecurso()
{
    recursos.desencolar();
}

template<class T>
void Civilizacion<T>::elimiarRecursoPos(int pos)
{
    recursos.borrarPos(pos);
}

template<class T>
Recurso &Civilizacion<T>::retrieveRecurso(int pos)
{
    return recursos[pos];
}

template<class T>
int Civilizacion<T>::findRecurso(int ID)
{
    int i = 0;
    while (i < colaSize()) {
        if (recursos[i].getIdRecurso() == ID) {
            return i;
        }
        i++;
    }
    return -1;
}

template<class T>
int Civilizacion<T>::colaSize()
{
    return recursos.colaSize();
}

template<class T>
void Civilizacion<T>::mayorIgualQueCola(int numero)
{
    int i = 0;
    while (i < colaSize()) {
        if (recursos[i].getCantidadRecurso() >= numero) {
            std::cout << recursos[i] << '\n';
        }
        i++;
    }
}

template<class T>
void Civilizacion<T>::menorQueCola(int numero)
{
    int i = 0;
    while (i < colaSize()) {
        if (recursos[i].getCantidadRecurso() < numero) {
            std::cout << recursos[i] << '\n';
        }
        i++;
    }
}

template<class T>
void Civilizacion<T>::tipoRecurso(std::string tipoRecurso)
{
    int i = 0;
    while (i < colaSize()) {
        if (recursos[i].getTipoRecurso() == tipoRecurso) {
            std::cout << recursos[i] << '\n';
        }
        i++;
    }
}

#endif // CIVILIZACION_H
