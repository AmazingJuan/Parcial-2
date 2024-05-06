#include "../Headers/estacion.h"

/**
 * Constructor de la clase estacion.
 *
 * Constructor diseñado para las estaciones de transferencia.
 *
 * @param nombre Nombre de la estacion.
 * @param sufijo Nombre de la linea a la que la estacion de transferencia va a pertenecer.
 */

estacion::estacion(string nombre, string sufijo){
    this -> nombre = nombre;
    this -> transferencia = true;
    this -> sufijo = sufijo;
    this -> tiempoAnt = -1;
    this -> tiempoSgt = -1;
}

/**
 * Constructor de la clase estacion.
 *
 * Constructor diseñado para las estaciones que no son de transferencia.
 *
 * @param nombre Nombre de la estacion.
 */

estacion::estacion(string nombre){
    this -> nombre = nombre;
    this -> transferencia = false;
    this -> sufijo = "";
    this -> tiempoAnt = -1;
    this -> tiempoSgt = -1;
}

/**
 * SETTERS Y GETTERS.
 *
 * Se listan los setters y getters de la clase estación.
 */


void estacion::setNombre(string nombre){
    this -> nombre = nombre;
}

string estacion::getNombreFull()
{ //Obtiene el nombre completo de la estación, si es de transferencia le añade el sufijo correspondiente.
    string name = nombre;
    if(sufijo != ""){
        name += " " + sufijo;
    }
    return name;
}

string estacion::getNombre(){
    return this -> nombre;
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
