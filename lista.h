#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class Nodo
{
    T dato;
    Nodo<T> *sig;

public:
    Nodo(const T &d, Nodo<T> *s = nullptr)//Tipo - Nombre,Direccion(&)
    {
        dato = d;
        sig = s;
    }

    template <class>
    friend class Lista;
};

template <class T>
class Lista
{
    Nodo<T> *raiz;
public:
    Lista();
    ~Lista();
    void insertarIn(const T &d);
    void insertarFi(const T &d);
    void insertarPo(const T &d, int pos);

    void eliminarI();
    void eliminarF();

    int tamano();

    T &operator [](int pos);

    //string toString();
};

template <class T>
Lista<T>::Lista()
{
    //Raiz apunta a vacio
    raiz = nullptr;
}

template<class T>
Lista<T>::~Lista()
{
    Nodo<T> *temp = raiz;
    while(temp != nullptr){
        raiz = raiz->sig;
        delete temp;
        temp = raiz;
    }
}

template<class T>
void Lista<T>::insertarIn(const T &d)
{
    if (raiz==nullptr) {
        //Crea un nuevo nodo si raiz apunta a vacio y apunta raiz a ese nodo
        Nodo<T> *nuevo = new Nodo<T>(d);
        raiz = nuevo;
    } else {
        //Crea nodo y apunta la raiz a ese nuevo nodo enlazado a el anterior
        Nodo<T> *nuevo = new Nodo<T>(d);
        nuevo->sig = raiz;
        raiz = nuevo;
    }
}

template<class T>
void Lista<T>::insertarFi(const T &d)
{
    if (raiz==nullptr) {
        //Crea un nuevo nodo si raiz apunta a vacio y apunta raiz a ese nodo
        Nodo<T> *nuevo = new Nodo<T>(d);
        raiz = nuevo;
    } else {
        //Crea nodo y apunta la raiz a ese nuevo nodo enlazado a el anterior
        Nodo<T> *temp = raiz;

        while (temp->sig != nullptr) {//Busca una dirección nula para agregar al final
            temp = temp->sig;//Salto a siguiente nodo
        }

        Nodo<T> *nuevo = new Nodo<T>(d);//Nodo a agregar
        temp->sig = nuevo;//Temp apunta al nuevo nodo
    }
}

template<class T>
void Lista<T>::insertarPo(const T &d, int pos)
{
    if (pos < 0) {
        //Pos invalida
    }else{
        Nodo<T> *temp = raiz;
        int cont = 0;
        while (temp != nullptr) {
            if (cont++ == pos) {
                Nodo<T> *nuevo = new Nodo<T>(d);
                nuevo -> sig = temp->sig;
                temp->sig=nuevo;
                break;
            }
            temp = temp->sig;
        }
    }
}

template<class T>
void Lista<T>::eliminarI()
{
    if (raiz==nullptr) {
        throw out_of_range ("Lista vacia");
    }else{
        Nodo<T> *temp = raiz;
        raiz = raiz->sig;
        delete temp;
    }
}

template<class T>
void Lista<T>::eliminarF()
{
    if(raiz == nullptr){
        throw out_of_range("Lista vacia, eliminarf");
    }else if (raiz->sig==nullptr) {
        delete raiz;
        raiz = nullptr;
        //eliminarI();
    }else{
        Nodo<T> *temp = raiz;
        while (temp->sig->sig != nullptr) {
            temp = temp->sig;
        }
        delete temp->sig;
        temp->sig = nullptr;
    }
}

template<class T>
int Lista<T>::tamano()
{
    Nodo<T> *temp = raiz;
    int cont = 0;
    while (temp != nullptr) {
        cont++;
        temp = temp->sig;
    }
    return cont;
}

template<class T>
T &Lista<T>::operator [](int pos)
{
    if (pos < 0 || pos >= tamano()) {
        throw out_of_range("Posicion invalida");
    } else {
        Nodo<T> *temp = raiz;
        int cont = 0;

        while (temp != nullptr) {
            if (cont == pos) {
                return temp->dato;
            }
            temp = temp->sig;
            cont ++;
        }
    }
}

//template<class T>
//string Lista<T>::toString()
//{
//    Nodo<T> *temp = raiz;//Direccion temporal
//    string lista = "[ ";//Inicia string lista

//    while (temp != nullptr) {//Hasta que temp apunte a nullo
//        lista += temp->dato;//Se le añade lo que hay en dato
//        lista += " ";
//        temp = temp->sig; //Temp pasa a la direccion siguiente
//    }
//    lista += "]"; //Se cierra la lista
//    return lista;
//}

#endif // LISTA_H
