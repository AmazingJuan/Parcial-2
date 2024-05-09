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
    { //Se crea el constructor para un nodo que no posee dato siguiente
        this -> datoActual = datoActual;
        this -> datoSiguiente = nullptr;
    }

    nodo(T datoActual, nodo<T> *datoSiguiente)
    { //Se crea el constructor para un nodo que si posee dato siguiente
        this -> datoActual = datoActual;
        this -> datoSiguiente = datoSiguiente;
    }

    ~nodo(){ //Se elimina el dato que contiene el nodo.
        delete datoActual;
        this -> datoSiguiente = nullptr;
    }

    //Setters y getters.

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
    void setDatoActual(T &newDatoActual){
        datoActual = newDatoActual;
    }

private:
    T datoActual; //Variable que contiene el dato actual.
    nodo *datoSiguiente; //Puntero que contiene el siguietne nodo.
};

#endif // NODO_H
