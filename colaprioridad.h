#ifndef COLAPRIORIDAD_H
#define COLAPRIORIDAD_H

#include "listadoble.h"

template<class T>
class ColaPrioridad
{
    ListaDoble<T> colaPrioridad;
public:
    ColaPrioridad();
    bool vacia();
    void borrarPos(int pos);
    void encolar(T &dato);
    T desencolar();
    int colaSize();

    T &operator [](int posicion);
};

template<class T>
ColaPrioridad<T>::ColaPrioridad(){}

template<class T>
bool ColaPrioridad<T>::vacia()
{
    return colaPrioridad.vacia();
}

template<class T>
void ColaPrioridad<T>::borrarPos(int pos)
{
    if (pos > colaPrioridad.getSize()) {
        throw std::out_of_range("Posicion invalida, colaprioridad");
    }
    colaPrioridad.eliminarPos(pos);
}

template<class T>
void ColaPrioridad<T>::encolar(T &dato)
{
    if (colaPrioridad.vacia()) {
        colaPrioridad.insertarInicio(dato);
    }else{
        int i;
        for (i=0; i < colaPrioridad.getSize(); ++i) {
            if (dato < colaPrioridad[i]) {
                colaPrioridad.insertar(dato, i);
                break;
            }
        }
        if (i == colaPrioridad.getSize()) {
            colaPrioridad.insertarFinal(dato);
        }
    }
}

template<class T>
T ColaPrioridad<T>::desencolar()
{
    if (colaPrioridad.vacia()) {
        throw std::out_of_range("Cola de prioridad vacia");
    }
    T copia = colaPrioridad[0];
    colaPrioridad.eliminarInicio();

    return copia;
}

template<class T>
int ColaPrioridad<T>::colaSize()
{
    return colaPrioridad.getSize();
}

template<class T>
T &ColaPrioridad<T>::operator [](int posicion)
{
    if (posicion > colaPrioridad.getSize()) {
        throw std::out_of_range("Posicion invalida, colaprioridad");
    }
    return colaPrioridad[posicion];
}

#endif // COLAPRIORIDAD_H
