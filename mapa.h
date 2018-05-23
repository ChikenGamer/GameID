#ifndef MAPA_H
#define MAPA_H

#include <vector>
#include <stdexcept>

using namespace std;

template<class T>
class Mapa
{
    vector<vector<T>> *matriz;
    int fila_;
    int columna_;
public:
    Mapa();
    Mapa(int filas, int columas);
    Mapa(int filas, int columas, const T &dato);

    vector<vector<T>> &getMatriz();
    vector<T> &operator[](int fila);

    void mostrarArreglo(const vector<T> &arreglo);
    void mostrarMatriz(const vector<vector<T>> &matriz);
};

template<class T>
Mapa<T>::Mapa()
{
    matriz = new vector<vector<T>> (3, vector<T>(3)); //< FILAS - COLUMNAS
    fila_ = columna_ = 3;
}

template<class T>
Mapa<T>::Mapa(int filas, int columas)
{
    matriz = new vector<vector<T>> (filas, vector<T>(columas)); //< FILAS - COLUMNAS
    fila_ = filas;
    columna_ = columas;
}

template<class T>
Mapa<T>::Mapa(int filas, int columas, const T &dato)
{
    matriz = new vector<vector<T>> (filas, vector<T>(columas, dato)); //< FILAS - COLUMNAS - DATO
    fila_ = filas;
    columna_ = columas;
}

template<class T>
vector<vector<T>> &Mapa<T>::getMatriz()
{
    return *matriz;
}

template<class T>
vector<T> &Mapa<T>::operator[](int fila)
{
    if (fila > fila_) {
        throw out_of_range("Fila no valida, [] mapa");
    }
    return (*matriz)[fila];
}

template<class T>
void Mapa<T>::mostrarArreglo(const vector<T> &arreglo)
{
    for (int i = 0; i < arreglo.size(); ++i) {
        cout << "\t" << arreglo[i];
    }
}

template<class T>
void Mapa<T>::mostrarMatriz(const vector<vector<T> > &matriz)
{
    for (int i = 0; i < matriz.size(); ++i) {
        mostrarArreglo(matriz[i]);
        cout << "\n";
    }
}

#endif // MAPA_H
