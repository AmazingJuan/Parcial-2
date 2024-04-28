#include "../Headers/estacion.h"

estacion::estacion(){
    this -> nombre = "bartolo";
}
void estacion::setNombre(string nombre){
    this -> nombre = nombre;
}

string estacion::getNombre(){
    return this -> nombre;
}
