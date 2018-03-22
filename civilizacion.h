#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <stdexcept>
#include <iostream>
using namespace std;

template <class T>
class Civilizacion
{
private:
    T *arreglo;
    int indice;
    int tam;
    const static int MAX = 5;
    ///Nombre por defecto de la civ.
public:
    string nombreC = "SIN NOMBRE";
    Civilizacion();
    ~Civilizacion();
    string getNombreC();
    void setNombreC(string s);
    void agregarA(const T &dato);
    int linearFindData(const T &name);
    void eliminarA(int pos);
    int poblacionT();
    int tamanio();
    bool isEmpty();

    T &operator[](int posicion);

};

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
string Civilizacion<T>::getNombreC()
{
    return nombreC;
}

template<class T>
void Civilizacion<T>::setNombreC(string s)
{
    nombreC = s;
}

template<class T>
void Civilizacion<T>::agregarA(const T &dato)
{
    if(indice < tam){
        ///Si el indice es menor al tam total se agrega el aldeano
        arreglo[indice++] = dato;
        cout << endl << "-=ALDEANO AGREGADO=-" << endl << endl;
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
        cout << endl << "-=ALDEANO AGREGADO=-" << endl << endl;
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
        cout << "-=POSICION INVALIDA=-";
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
    return indice == 0;
}

template<class T>
T &Civilizacion<T>::operator[](int posicion)
{
    ///Operador sobrecargado para poder imprimir el arreglo tipo T
    if (posicion < 0 or posicion >= indice){
        cout << "-=POSICION INVALIDA=-";
    }
    return arreglo[posicion];
}

#endif // CIVILIZACION_H
