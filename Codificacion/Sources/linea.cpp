#include "../Headers/linea.h"

linea::linea(){
    this -> nroEstaciones = 0;
}

void linea::insertar(estacion *estacion){
    this->setNroEstaciones(this->getNroEstaciones() + 1);
    this->getEstaciones().insert(pair(this->getNroEstaciones(), estacion));
}

string linea::strEstaciones(){
    string aux;
    for(auto it = this -> getEstaciones().begin(); it != this -> getEstaciones().end(); it++){
        aux += to_string(it->first) + it->second->getNombre() + "\n";
    }
    return aux;
}

void linea::setNroEstaciones(int nroEstaciones){
    this -> nroEstaciones = nroEstaciones;
}

int linea::getNroEstaciones(){
    return this -> nroEstaciones;
}

void linea::setEstaciones(map<int, estacion*> &estaciones){
    this ->estaciones = estaciones;
}

map<int, estacion*> linea::getEstaciones(){
    return this -> estaciones;
}

