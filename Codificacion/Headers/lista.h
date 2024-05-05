#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"
#include "importaciones.h"
template <typename T>
class lista
{
private:
    nodo<T> *inicio;
    nodo<T> *final;
    int elementos;

public:
    lista(){
        elementos = 0;
        inicio = nullptr;
        final = nullptr;
    }

    lista(nodo<T> *nodo)
    {
        elementos = 1;
        inicio = nodo;
        inicio -> setSiguiente(nullptr);
        final = nodo;
    }

    ~lista() {
        nodo<T>* actual = inicio;
        while (actual != nullptr) {
            nodo<T>* siguiente = actual->getSiguiente();
            delete actual;
            actual = siguiente;
        }
        inicio = nullptr;
        final = nullptr;
        elementos = 0;
    }

    void insertar(nodo<T> *_nodo, int posicion)
    {
        if(elementos != 0){
            posicion--;
            nodo<T> *aux = inicio;
            for(int cont = 0; cont <= elementos; cont++){
                if(cont == posicion){
                    if(cont == 0){
                        inicio = _nodo;
                        _nodo->setSiguiente(aux);
                    }
                    else{
                        _nodo->setSiguiente(aux -> getSiguiente());
                        aux -> setSiguiente(_nodo);
                        if(cont + 1 == elementos){
                            final = _nodo;
                        }
                    }
                    elementos++;
                    break;
                }
                if(cont != 0){
                    aux = aux -> getSiguiente();
                }
            }
        }
        else{
            inicio = _nodo;
            final = _nodo;
            elementos++;
        }
    }

    void insertar(nodo <T> *_nodo){
        if(elementos != 0){
            final ->setSiguiente(_nodo);
            final = _nodo;
        }
        else{
            inicio = _nodo;
            final = _nodo;
        }
        elementos++;
    }

    void eliminar(int posicion){
        posicion--;
        nodo<T> *aux = inicio;
        for(int cont = 0; cont <= elementos; cont++){
            if(cont == posicion){
                if(cont == 0){
                    inicio = aux->getSiguiente();
                }
                else{

                    aux->setSiguiente(aux->getSiguiente()->getSiguiente());
                }
                elementos--;
                break;
            }
            if(cont != 0){
                aux = aux -> getSiguiente();
            }
        }
    }

    T &operator[](int indice){
        indice--;
        nodo<T> *aux = inicio;
        for(int cont = 0; cont < elementos; cont++){
            if(indice == cont) {
                return aux -> getDatoActual();
            }
            aux = aux->getSiguiente();
        }
    }

    nodo<T> *getInicio(){
        return inicio;
    }

    int getElementos(){
        return elementos;
    }
};

#endif // LISTA_H
