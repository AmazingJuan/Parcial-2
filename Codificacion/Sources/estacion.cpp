#include "../Headers/estacion.h"

estacion::estacion(){
    this -> nombre = "bartolo";
}

estacion::estacion(string nombre){
    this -> nombre = nombre;
}

void estacion::setNombre(string nombre){
    this -> nombre = nombre;
}

string estacion::getNombre(){
    return this -> nombre;
}
