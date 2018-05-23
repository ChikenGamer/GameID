#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include <iostream>
#include <stdexcept>

template<class T>
class NodoD{
    private:
        T dato;
        NodoD<T> *sig;
        NodoD<T> *ant;
    public:
        NodoD(const T &d){
            dato = d;
            sig = nullptr;
            ant = nullptr;
        }
        template <class> friend class ListaDoble;
    };

template<class T>
class ListaDoble
{
    private:
        NodoD<T> *primero;
        NodoD<T> *ultimo;
        int size;
    public:
        ListaDoble();
        bool vacia();

        void insertarInicio(const T &dato);
        void insertarFinal(const T &dato);
        void insertar(const T &dato, int posicion);

        void eliminarInicio();
        void eliminarFinal();
        void eliminarPos(int posicion);

        T& operator[] (int posicion);
        int getSize();

        std::string toString();
};

template<class T>
ListaDoble<T>::ListaDoble()
{
    primero = ultimo = nullptr;
    size = 0;
}

template<class T>
int ListaDoble<T>::getSize()
{
    return size;
}

template<class T>
bool ListaDoble<T>::vacia()
{
    return primero == nullptr;
}

template<class T>
void ListaDoble<T>::insertarInicio(const T &dato)
{
    if (vacia()) {
       NodoD<T> *nuevo = new NodoD<T>(dato);
       primero = nuevo;
       ultimo = nuevo;
    }else{
        NodoD<T> *nuevo = new NodoD<T>(dato);
        nuevo->sig = primero;
        primero->ant = nuevo;
        primero = nuevo;
    }
    size++;
}

template<class T>
void ListaDoble<T>::insertarFinal(const T &dato)
{
    if (vacia()) {
       NodoD<T> *nuevo = new NodoD<T>(dato);
       primero = nuevo;
       ultimo = nuevo;
    }else{
        NodoD<T> *nuevo = new NodoD<T>(dato);
        nuevo->ant = ultimo;
        ultimo->sig = nuevo;
        ultimo = nuevo;
    }
    size++;
}

template<class T>
void ListaDoble<T>::insertar(const T &dato, int posicion)
{
    if(posicion < 0 || posicion >= size){
        throw std::out_of_range("Pos no valida, insertando");
    }else {
        if (posicion == 0) {
            insertarInicio(dato);
        }else {
            NodoD<T> *nuevo = new NodoD<T> (dato);
            NodoD<T> *temp = primero;
            unsigned int contador = 0;

            while (temp != nullptr) {
                if (contador++ == posicion) {
                    nuevo->ant = temp->ant;
                    nuevo->sig = temp;
                    temp->ant->sig = nuevo;
                    temp->ant = nuevo;
                    size++;
                    break;
                }
                temp = temp->sig;
            }
        }
    }
}

template<class T>
void ListaDoble<T>::eliminarInicio()
{
    if(vacia()){
        throw std::out_of_range("Lista vacia, eliminando");
    }
    if (primero==ultimo) {
        delete primero;
        primero = ultimo = nullptr;
    }else{
        NodoD<T> *temp = primero;
        temp->sig->ant = nullptr;
        primero = primero->sig;
        delete temp;
    }
    size--;
}

template<class T>
void ListaDoble<T>::eliminarFinal()
{
    if(vacia()){
        throw std::out_of_range("Lista vacia, eliminar final");
    }
    if (primero==ultimo) {
        delete primero;
        primero = ultimo = nullptr;
    }else{
        NodoD<T> *temp = ultimo;
        temp->ant->sig = nullptr;
        ultimo = temp->ant;
        delete temp;
    }
    size--;
}

template<class T>
void ListaDoble<T>::eliminarPos(int posicion)
{
    if(vacia()){
        throw std::out_of_range("Lista vacia, eliminar pos");
    }
    if(posicion < 0 || posicion >= size){
        throw std::out_of_range("Pos no valida, eliminar pos");
    }
    if (posicion == 0) {
        eliminarInicio();
    }else if (posicion == size - 1) {
        eliminarFinal();
    }else {
        NodoD<T> * temp = primero;
        int contador = 0;

        while (temp!= nullptr) {
            if (contador++ == posicion) {
                temp->ant->sig = temp->sig;
                temp->sig->ant = temp->ant;
                size--;
                delete temp;
            }
            temp = temp->sig;
        }
    }
}

template<class T>
T &ListaDoble<T>::operator[](int posicion)
{
    if(posicion < 0 || posicion >= size){
        throw std::out_of_range("Pos no valida, operador [], LD");
    }

    NodoD<T> *temp = primero;
    int contador = 0;

    while (temp != nullptr and contador != posicion) {
        temp = temp->sig;
        contador ++;
    }
    return temp->dato;
}

#endif // LISTADOBLE_H
