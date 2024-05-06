#include "../Headers/linea.h"

/**
 * Constructor de la clase linea.
 *
 * Constructor para toda instancia de la clase linea.
 *
 * @param nombre Nombre de la linea.
 */


linea::linea(string nombre){
    this -> nombre = nombre;
    this -> nroEstaciones = 0;
    this -> nroTransf = 0;
    estaciones = *new lista<estacion*>(); //Crea espacio de memoria para una lista enlazada que va a contener las estaciones de la linea.
    transferencia = *new lista<estacion*>(); //Crea espacio de memoria para una lista enlazada que va a contener las estaciones de transferencia de la linea.
}

/**
 * Destructor de la clase linea.
 *
 * Destructor para las instancias de la clase linea.
 *
 */

linea::~linea() {
    //Llama al destructor de los objetos lista.
    estaciones.~lista();
    transferencia.~lista();
}

/**
 * Breve descripcion del metodo insertar.
 *
 * Permite agregar una estacion a la linea en una posición dada.
 *
 * @param estacion Puntero que contiene la direccion de memoria de la estación que se quiere agregar.
 * @param nombre Posicion donde se va a insertar la estacion.
 */

void linea::insertar(estacion *estacion, int indice)
{
    estaciones.insertar(new nodo(estacion), indice);
    nroEstaciones++;
    if(estacion -> getTransferencia()) {
        insertarTransferencia(estacion);
        nroTransf++;
    }
}

/**
 * Breve descripcion del metodo insertarTransferencia.
 *
 * Permite agregar una estacion a la lista de estaciones de transferencia, el orden es el orden de llegada.
 *
 * @param estacion Puntero que contiene la direccion de memoria de la estación que se quiere agregar.
 */

void linea::insertarTransferencia(estacion *estacion)
{
    transferencia.insertar(new nodo(estacion));
}

/**
 * Breve descripcion del metodo eliminar.
 *
 * Permite eliminar una estacion de la lista de estaciones.
 *
 * @param indice Entero que contiene la posicion donde se quiere eliminar la estación.
 */

void linea::eliminar(int indice)
{
    estaciones.eliminar(indice);
    nroEstaciones--;
}

/**
 * Breve descripcion del metodo strEstaciones.
 *
 * Permite obtener un string que muestra las estaciones de la linea, enumerandolas.
 *
 * @return String que contiene todas las estaciones deseadas.
 */

string linea::strEstaciones(){
    string aux;
    for(int cont = 1; cont <= estaciones.getElementos(); cont++){
        aux += to_string(cont) + ". " + estaciones[cont]->getNombreFull() + "\n";
    }
    return aux;
}

/**
 * Breve descripcion del metodo strTransferencia.
 *
 * Permite obtener un string que muestra las estaciones de transferencia de la linea, enumerandolas.
 *
 * @return String que contiene todas las estaciones de transferencia deseadas.
 */

string linea::strTransferencia(){
    string aux;
    for(int cont = 1; cont <= estaciones.getElementos(); cont++){
        aux += to_string(cont) + ". " + transferencia[cont]->getNombre() + "\n";
    }
    return aux;
}

/**
 * Breve descripcion del metodo generarOpciones.
 *
 * Permite optener un arreglo de strings (como puntero), en cada posicion guarda un numero correspondiente a una posicion de una estación.
 *
 * @return String* que contiene los indices de todas las estaciones.
 */

string* linea::generarOpciones(){
    string *opciones = new string[this->getNroEstaciones() + 1];
    for(int cont = 1; cont <= estaciones.getElementos(); cont++){
        opciones[cont - 1] = to_string(cont);
    }
    opciones[this->getNroEstaciones()] = to_string(this->getNroEstaciones() + 1);
    return opciones;
}

/**
 * Breve descripcion del metodo buscarEstacion.
 *
 * Permite saber si una estacion esta en una linea o no.
 *
 * @return bool que habla acerca de la existencia de la estacion ingresada.
 */

bool linea::buscarEstacion(string nombre){
    nombre = removeSeparator(toLowerCase(nombre), ' ');
    for(int cont = 1; cont <= estaciones.getElementos(); cont++){ //Hace una busqueda lineal por todos los elementos de la lista.
        if(removeSeparator(toLowerCase(estaciones[cont] -> getNombre()), ' ') == nombre || removeSeparator(toLowerCase(estaciones[cont] ->getNombreFull()), ' ') == nombre ) return true;
    }
    return false; //Si no encuentra el nombre devuelve falso
}

/**
 * Breve descripcion del metodo calcularTrayecto.
 *
 * Mide el tiempo que tarda ir de una estacion a otra en la linea actual.
 *
 * @return int Tiempo que tarda de ir desde una estacion de origen hasta una estacion de destino, en segundos.
 */

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

/**
 * SETTERS Y GETTERS.
 *
 * Se listan los setters y getters de la clase linea.
 */

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

