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
    lista(){ //Se crea un constructor para una lista vacia.
        elementos = 0;
        inicio = nullptr;
        final = nullptr;
    }

    lista(nodo<T> *nodo)
    { //Se crea un constructor para una lista inicializada con un nodo
        elementos = 1;
        inicio = nodo;
        inicio -> setSiguiente(nullptr);
        final = nodo;
    }

    ~lista() { //Destructor de la lista.
        inicio = nullptr;
        final = nullptr;
        elementos = 0;
    }

    void insertar(nodo<T> *_nodo, int posicion)
    {
        if(elementos != 0){ //Verifica si la lista esta vacia o no
            posicion--;
            nodo<T> *aux = inicio; //Se inicializa un puntero auxiliar en el inicio de la lista
            for(int cont = 0; cont <= elementos; cont++){ //Se recorre la lista hasta encontrar la posicion deseada
                if(cont == posicion){ //Si se encuentra la posicion deseada se agrega a la lista.
                    if(cont == 0){ //Si la posicion es cero, se pone como inicio y se enlaza con el nodo que antes estaba de primero.
                        inicio = _nodo;
                        _nodo->setSiguiente(aux);
                    }
                    else{ //Si la posicion es distinta de cero se enlaza el nodo que se quiere insertar con el nodo siguiente al del a posicion deseada, y se inserta el mismo.
                        _nodo->setSiguiente(aux -> getSiguiente());
                        aux -> setSiguiente(_nodo);
                        if(cont + 1 == elementos){
                            final = _nodo; //Si  se ingresa un nodo al final entonces el atributo final se define como el nodo a ingresar.
                        }
                    }
                    elementos++; //Se aumenta el atributo elementos del a lista.
                    break;
                }
                if(cont != 0){
                    aux = aux -> getSiguiente(); //Se pasa al siguiente nodo si no se encuentra en la posicion actual.
                }
            }
        }
        else{ //Si esta vacia se pone como primera y ultimo elemento el nodo ingresado.
            inicio = _nodo;
            final = _nodo;
            elementos++;
        }
    }

    void insertar(nodo <T> *_nodo){ //Inserta un nodo al final.
        if(elementos != 0){ //Verifica si lista esta vacia
            final ->setSiguiente(_nodo); //Si no esta vacia enlaza el nodo que era final anteriormente con el nuevo final.
            final = _nodo; //Se establece como el final el nuevo nodo.
        }
        else{
            inicio = _nodo; //Si la lista esta vacia se establece como inicio el nodo y como final ese mismo nodo
            final = _nodo;
        }
        elementos++;
    }

    void eliminar(int posicion){ //Sirve para eliminar un nodo en una posición dada
        posicion--;
        nodo<T> *aux = inicio;
        for(int cont = 0; cont < elementos; cont++){ //Recorre la lista hasta encontrar la posicion deseada.
            if(cont == posicion){
                if(cont == 0){ //Si la posicion es 0 entonces se toma como inicio el elemento siguiente al inicio.
                    inicio = aux->getSiguiente();
                }
                else{
                    aux->setSiguiente(aux->getSiguiente()->getSiguiente()); //De otra manera se enlaza el nodo anterior al de la posicion dada con el nodo siguiente de la posicion dada
                }
                elementos--; //Se disminuye los elementos en 1
                break;
            }
            if(cont != 0){
                aux = aux -> getSiguiente(); //Si el contador no se encuentra en la posicion dada entonces se cambia de puntero auxiliar al siguiente.
            }
        }
    }

    T &operator[](int indice){ //Se define el operador [] conel cual se podra acceder a un elemento de la lista.
        indice--;
        nodo<T> *aux = inicio;
        for(int cont = 0; cont < elementos; cont++){
            if(indice == cont) {
                return aux -> getDatoActual(); //Si se encuentra el inidice deseado se retorna el dato actual del nodo.
            }
            aux = aux->getSiguiente(); //De otro modo se avanza al siguiente nodo.
        }
    }

    //setters y getters

    nodo<T> *getInicio(){
        return inicio;
    }

    void setInicio(nodo<T>*nodo){
        inicio = nodo;
    }

    nodo<T> *getFinal(){
        return final;
    }

    void setFinal(nodo<T>*nodo){
        final = nodo;
    }

    int getElementos(){
        return elementos;
    }

    void setElementos(int elementos){
        this -> elementos = elementos;
    }


};

#endif // LISTA_H
