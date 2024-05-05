#include "../Headers/red.h"
red::red(){
    this -> nroLineas = 0;

}

red::~red(){
    cout << "destructor red";
}

void red::insertarLinea(linea *linea, int indice)
{
    lineas.insertar(new nodo(linea), indice);
    nroLineas++;
}

void red::insertarLinea(linea *linea)
{
    nroLineas++;
    lineas.insertar(new nodo(linea), nroLineas);

}

void red::eliminarLinea(int indice){
    lineas.eliminar(indice);
    nroLineas--;
}

string* red::generarOpciones(){
    string *opciones = new string[this->getNroLineas() + 1];
    for(int cont = 1; cont <= lineas.getElementos(); cont++){
        opciones[cont - 1] = to_string(cont);
    }
    return opciones;
}

string red::strLineas(){
    string aux;
    for(int cont = 1; cont <= lineas.getElementos(); cont++){
        aux += to_string(cont) + ". " + lineas[cont]->getNombre() + "\n";
    }
    return aux;
}

bool red::buscarLinea(string nombre){
    nombre = removeSeparator(toLowerCase(nombre), ' ');
    for(int cont = 1; cont <= lineas.getElementos(); cont++){
        if(removeSeparator(toLowerCase(lineas[cont]->getNombre()), ' ') == nombre) return true;
    }
    return false;
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
lista<linea*> &red::getLineas(){
    return this -> lineas;
}
void red::setLineas(lista<linea*> &lineas){
    this -> lineas = lineas;
}

