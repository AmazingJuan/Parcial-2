#include "../Headers/estacion.h"


estacion::estacion(string nombre, string sufijo){
    this -> nombre = nombre;
    this -> transferencia = true;
    this -> sufijo = sufijo;
    this -> tiempoAnt = -1;
    this -> tiempoSgt = -1;
}

estacion::estacion(string nombre){
    this -> nombre = nombre;
    this -> transferencia = false;
    this -> sufijo = "";
    this -> tiempoAnt = -1;
    this -> tiempoSgt = -1;
}

void estacion::setNombre(string nombre){
    this -> nombre = nombre;
}

string estacion::getNombre(){
    return this -> nombre;
}

string estacion::getSufijo(){
    return this -> sufijo;
}
void estacion::setSufijo(string sufijo){
    this -> sufijo = sufijo;
}

bool estacion::getTransferencia(){
    return this -> transferencia;
}

void estacion::setTransferencia(bool transferencia){
    this -> transferencia = transferencia;
}

int estacion::getTiempoSgt(){
    return this -> tiempoSgt;
}

void estacion::setTiempoSgt(int tiempoSgt){
    this -> tiempoSgt = tiempoSgt;
}
int estacion::getTiempoAnt(){
    return this -> tiempoAnt;
}

void estacion::setTiempoAnt(int tiempoAnt){
    this -> tiempoAnt = tiempoAnt;
}
