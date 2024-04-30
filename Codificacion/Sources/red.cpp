#include "../Headers/red.h"
red::red(){
    this -> nroLineas = 0;
}

void red::insertarLinea(linea *linea){
    this -> setNroLineas(this -> getNroLineas() + 1);
    this -> getLineas().insert(pair(this ->getNroLineas(), linea));
}

void red::eliminarLinea(int posicion){
    //consultar destruccion de objeto y destruir la linea aca;
    this -> setNroLineas(this ->getNroLineas() - 1);
    for(int cont = posicion; cont < this ->getNroLineas() + 1; cont++){
        this -> getLineas()[cont] = this -> getLineas()[cont + 1];
    }
    this -> getLineas().erase(this ->getNroLineas() + 1);
}

string* red::generarOpciones(){
    string *opciones = new string[this->getNroLineas() + 1];
    for(auto it = this -> getLineas().begin(); it != this -> getLineas().end();it++){
        opciones[it -> first - 1] = to_string(it -> first);
    }
    return opciones;
}

void red::setNroEstaciones(int nroEstaciones){
    this -> nroEstaciones = nroEstaciones;
}
int red::getNroEstaciones(){
    return this -> nroEstaciones;
}

void red::setNroLineas(int nroLineas){
    this -> nroLineas = nroLineas;
}
int red::getNroLineas(){
    return this -> nroLineas;
}
map<int, linea*> &red::getLineas(){
    return this -> lineas;
}
void red::setLineas(map<int, linea*> &lineas){
    this -> lineas = lineas;
}
