#include "../Headers/linea.h"

linea::linea(string nombre){
    this -> nombre = nombre;
    this -> nroEstaciones = 0;
    this -> nroTransf = 0;
    estaciones = *new lista<estacion*>();
    transferencia = *new lista<estacion*>();
}

linea::~linea() {
    estaciones.~lista();
    transferencia.~lista();
}

void linea::insertar(estacion *estacion, int indice)
{
    estaciones.insertar(new nodo(estacion), indice);
    nroEstaciones++;
    if(estacion -> getTransferencia()) {
        insertarTransferencia(estacion);
        nroTransf++;
    }
}

void linea::insertar(estacion *estacion)
{
    estaciones.insertar(new nodo(estacion));
    nroEstaciones++;
}

void linea::insertarTransferencia(estacion *estacion)
{
    transferencia.insertar(new nodo(estacion));
}

void linea::eliminar(int indice)
{
    estaciones.eliminar(indice);
    nroEstaciones--;
}


string linea::strEstaciones(){
    string aux;
    for(int cont = 1; cont <= estaciones.getElementos(); cont++){
        aux += to_string(cont) + ". " + estaciones[cont]->getNombre() + " " + estaciones[cont]->getSufijo() + "\n";
    }
    return aux;
}

string linea::strTransferencia(){
    string aux;
    for(int cont = 1; cont <= estaciones.getElementos(); cont++){
        aux += to_string(cont) + ". " + transferencia[cont]->getNombre() + "\n";
    }
    return aux;
}


string* linea::generarOpciones(){
    string *opciones = new string[this->getNroEstaciones() + 1];
    for(int cont = 1; cont <= estaciones.getElementos(); cont++){
        opciones[cont - 1] = to_string(cont);
    }
    opciones[this->getNroEstaciones()] = to_string(this->getNroEstaciones() + 1);
    return opciones;
}

bool linea::buscarEstacion(string nombre){
    nombre = removeSeparator(toLowerCase(nombre), ' ');
    for(int cont = 1; cont <= estaciones.getElementos(); cont++){
        if(removeSeparator(toLowerCase(estaciones[cont] -> getNombre()), ' ') == nombre || removeSeparator(toLowerCase(estaciones[cont] ->getNombre() + " " + estaciones[cont]->getSufijo()), ' ') == nombre ) return true;
    }
    return false;
}

int linea::calcularTrayecto(int origen, int destino){
    int tiempo = 0;
    int aux = origen;
    if(destino < origen){
        origen = destino;
        destino = aux;
    }
    for(int cont = origen; cont < destino; cont++){
        tiempo += this -> getEstaciones()[origen]->getTiempoSgt();
    }
    return tiempo;
}

lista<estacion*> &linea::getTransferencia(){
    return this -> transferencia;
}

void linea::setTransferencia(lista<estacion*> &transferencia){
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

void linea::setEstaciones(lista<estacion*> &estaciones){
    this ->estaciones = estaciones;
}

lista<estacion*> &linea::getEstaciones(){
    return this -> estaciones;
}

int linea::getNroTransf(){
    return this -> nroTransf;
}

void linea::setNroTransf(int nroTransf){
    this -> nroTransf = nroTransf;
}

