#include "../Headers/linea.h"

linea::linea(string nombre){
    this -> nombre = nombre;
    this -> nroEstaciones = 0;
    this -> nroTransf = 0;
}

void linea::insertar(estacion *estacion, int posicion){
    this->setNroEstaciones(this->getNroEstaciones() + 1);
    if(posicion == 0){
        this->getEstaciones().insert(pair(this->getNroEstaciones(), estacion));
    }
    else{
        this->getEstaciones().insert(pair(this->getNroEstaciones(), nullptr));
        for(int cont = this -> getNroEstaciones(); cont > 0; cont--){
            if(cont == posicion){
                this->getEstaciones()[cont] = estacion;
                break;
            }
            else{
                this->getEstaciones()[cont] = this->getEstaciones()[cont - 1];
            }
        }
    }
}

void linea::insertar(estacion  *estacion){
    this->setNroTransf(this->getNroTransf() + 1);
    this -> getTransferencia().insert(pair(this ->getNroTransf(), estacion));
}

void linea::eliminar(int posicion){
    //consultar destruccion de objeto y destruir la estacion aca;
    this -> setNroEstaciones(this ->getNroEstaciones() - 1);
    for(int cont = posicion; cont < this ->getNroEstaciones() + 1; cont++){
        this -> getEstaciones()[cont] = this -> getEstaciones()[cont + 1];
    }
    this -> getEstaciones().erase(this ->getNroEstaciones() + 1);
}

string linea::strEstaciones(){
    string aux;
    for(auto it = this -> getEstaciones().begin(); it != this -> getEstaciones().end(); it++){
        aux += to_string(it->first) + ". " + it->second->getNombre() + " " + it->second->getSufijo() + "\n";
    }
    return aux;
}

string linea::strTransferencia(){
    string aux;
    for(auto it = this -> getTransferencia().begin(); it != this -> getTransferencia().end(); it++){
        aux += to_string(it->first) + ". " + it->second->getNombre() + "\n";
    }
    return aux;
}


string* linea::generarOpciones(){
    string *opciones = new string[this->getNroEstaciones() + 1];
    for(auto it = this -> getEstaciones().begin(); it != this -> getEstaciones().end();it++){
        opciones[it -> first - 1] = to_string(it -> first);
    }
    opciones[this->getNroEstaciones()] = to_string(this->getNroEstaciones() + 1);
    return opciones;
}

bool linea::buscarEstacion(string nombre){
    nombre = removeSeparator(toLowerCase(nombre), ' ');
    for(auto it = this -> getEstaciones().begin(); it != this -> getEstaciones().end();it++){
        if(removeSeparator(toLowerCase(it->second->getNombre()), ' ') == nombre || removeSeparator(toLowerCase(it->second->getNombre() + " " + it ->second->getSufijo()), ' ') == nombre ) return true;
    }
    return false;
}

int linea::calcularTrayecto(int origen, int destino){
    int tiempo = 0;
    map<int, estacion*> estaciones = this -> getEstaciones();
    int aux = origen;
    if(destino < origen){
        origen = destino;
        destino = aux;
    }
    for(int cont = origen; cont < destino; cont++){
        tiempo += estaciones[origen]->getTiempoSgt();
    }
    return tiempo;
}

map<int, estacion*> &linea::getTransferencia(){
    return this -> transferencia;
}

void linea::setTransferencia(map<int, estacion*> &transferencia){
    this -> transferencia = transferencia;
}

string linea::getNombre(){
    return this -> nombre;
}
void linea::setNombre(string nombre){
    this -> nombre = nombre;
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

map<int, estacion*> &linea::getEstaciones(){
    return this -> estaciones;
}

int linea::getNroTransf(){
    return this -> nroTransf;
}

void linea::setNroTransf(int nroTransf){
    this -> nroTransf = nroTransf;
}

