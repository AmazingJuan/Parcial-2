#include "../Headers/red.h"

/**
 * Constructor de la clase red.
 *
 * Constructor para toda instancia de la clase red.
 */

red::red(){

    //Se inicializan los valores enteros de la red.
    lineas = *new lista<linea*>;
    this -> nroLineas = 0;
    this -> nroEstaciones = 0;
}

red::~red()
{
    lineas = nullptr;
}

/**
 * Breve descripciono del metodo insertarLinea.
 *
 * Inserta una linea de metro, el orden de inserción es el orden de llegada.
 *
 * @param linea puntero a una instancia de la clase linea, que representa la linea actual que se quiere insertar a la lista de lineas.
 */

void red::insertarLinea(linea *linea)
{
    nroLineas++; //Se aumenta el contador de lineas en uno.
    lineas.insertar(new nodo(linea), nroLineas); //Se llama al metodo insertar de la clase lista.
}

/**
 * Breve descripciono del metodo eliminarLinea.
 *
 * Borra la linea ubicada en el indice dado de la lista de lineas de metro.
 *
 * @param indice Posicion donde se encuentra la linea a eliminar.
 */

void red::eliminarLinea(int indice){
    lineas.eliminar(indice); //Se llama al metodo eliminar de la clase lista.
    nroLineas--; //Se disminuye el contador de lineas en uno.
}

/**
 * Breve descripcion del metodo generarOpciones.
 *
 * Permite obtener un arreglo de strings (como puntero), en cada posicion guarda un numero correspondiente a una posicion de una linea.
 *
 * @return String* que contiene los indices de todas las lineas.
 */

string* red::generarOpciones(){ //Recorre el arreglo para poner en cada posicion del arreglo un numero que corresponde a un string con un numero.
    string *opciones = new string[this->getNroLineas() + 1];
    for(int cont = 1; cont <= lineas.getElementos(); cont++){
        opciones[cont - 1] = to_string(cont);
    }
    return opciones;
}

/**
 * Breve descripcion del metodo strLineas.
 *
 * Permite obtener un string que muestra las lineas de la red, enumerandolas.
 *
 * @return String que contiene todas las lineas deseadas.
 */

string red::strLineas(){ //Recorre las lineas de la red obteniendo el nombre y enumerandolas.
    string aux;
    for(int cont = 1; cont <= lineas.getElementos(); cont++){
        aux += to_string(cont) + ". " + lineas[cont]->getNombre() + "\n";
    }
    return aux;
}

/**
 * Breve descripcion del metodo buscarLinea.
 *
 * Permite saber si una linea esta en una red o no.
 *
 * @return bool que habla acerca de la existencia de la linea ingresada.
 */

bool red::buscarLinea(string nombre){
    nombre = removeSeparator(toLowerCase(nombre), ' ');
    for(int cont = 1; cont <= lineas.getElementos(); cont++){ //Hace una busqueda lineal por todos los elementos de la lista, y compara los nombres con el nombre del parametro.
        if(removeSeparator(toLowerCase(lineas[cont]->getNombre()), ' ') == nombre) return true;
    }
    return false;
}

/**
 * SETTERS Y GETTERS.
 *
 * Se listan los setters y getters de la clase estación.
 */

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
lista<linea*> &red::getLineas(){
    return this -> lineas;
}
void red::setLineas(lista<linea*> &lineas){
    this -> lineas = lineas;
}
