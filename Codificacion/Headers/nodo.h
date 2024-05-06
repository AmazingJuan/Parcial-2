#ifndef NODO_H
#define NODO_H
#include <string>
#include <iostream>
using namespace std;
template<class T>
class nodo
{
public:
    nodo(T datoActual)
    {
        this -> datoActual = datoActual;
        this -> datoSiguiente = nullptr;
    }

    nodo(T datoActual, nodo<T> *datoSiguiente)
    {
        this -> datoActual = datoActual;
        this -> datoSiguiente = datoSiguiente;
    }

    ~nodo(){
        delete datoActual;
    }

    nodo *getSiguiente()
    {
        return datoSiguiente;
    };
    void setSiguiente(nodo<T> *datoSiguiente){
        this -> datoSiguiente = datoSiguiente;
    }
    T &getDatoActual()
    {
        return datoActual;
    }

private:
    T datoActual;
    nodo *datoSiguiente;
};

#endif // NODO_H
