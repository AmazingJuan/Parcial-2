#include <iostream>
#include <map>
#include "Headers/estacion.h"
#include "Headers/linea.h"
#include "Headers/red.h"
#include "Headers/menus.h"
using namespace std;

int main()
{
    red red;
    bool bandera = true;
    bool isTransferencia = false;
    int decision = 0;
    int aux = -1;
    int aux2 = -1;
    int posicion = 0;
    int tiempoAnt = -1;
    int tiempoSgt = -1;
    int origen = 0;
    int destino = 0;
    string nombre = "";
    red.insertarLinea(new linea("hola"));
    string opciones[10];
    string *opcAux = nullptr;
    for(int cont = 0; cont < 10; cont++) opciones[cont] = to_string(cont+1);
    while(bandera){
        decision = menuOpcion(mensajes(1), opciones, 10);
        switch(decision){
            case 1:
                if(red.getNroLineas() > 0){
                    delete [] opcAux;
                    opcAux = red.generarOpciones();
                    aux = menuOpcion(mensajes(2) + "Ingrese la linea donde desea crear la estacion\n\n" + red.strLineas() + "\n", opcAux, red.getNroLineas());
                    if(red.getLineas()[aux]->getNroEstaciones() == 0){
                        aux2 = 0;
                        posicion = 1;
                    }
                    else{
                        delete[] opcAux;
                        opcAux = red.getLineas()[aux]->generarOpciones();
                        aux2 = menuOpcion(mensajes(3) + "Ingrese la posicion donde quiere que se posicione la estacion:\n\n" + red.getLineas()[aux]->strEstaciones() + to_string(red.getLineas()[aux]->getNroEstaciones() + 1) + ". Agregar al final\n\n" , opcAux, red.getLineas()[aux]->getNroEstaciones() + 1);
                        posicion = aux2;
                        if(aux2 == red.getLineas()[aux]->getNroEstaciones() + 1) {
                            aux2 = 0;
                        }
                    }
                    nombre = menuNombre(mensajes(6), red.getLineas()[aux]);
                    isTransferencia = (menuOpcion(mensajes(4) + "Diga si la estacion a crear es de transferencia: \n\n1. Si\n2. No\n\n", opciones, 2)) % 2;
                    if(isTransferencia) {
                        red.getLineas()[aux] -> insertar(new estacion(nombre, red.getLineas()[aux]->getNombre()), aux2);
                        red.getLineas()[aux]-> insertar(red.getLineas()[aux]->getEstaciones()[posicion]);
                    }
                    else red.getLineas()[aux] -> insertar(new estacion(nombre), aux2);
                    red.setNroEstaciones(red.getNroEstaciones() + 1);

                    if(posicion - 1 != 0){
                        nombre = red.getLineas()[aux]->getEstaciones()[posicion - 1]->getNombre() + " " + red.getLineas()[aux]->getEstaciones()[posicion - 1]->getSufijo();
                        tiempoAnt = menuNumero(mensajes(5), "el tiempo para desde la estacion " + nombre + " hasta la estacion actual");
                        red.getLineas()[aux]->getEstaciones()[posicion]->setTiempoAnt(tiempoAnt);
                        red.getLineas()[aux]->getEstaciones()[posicion - 1]->setTiempoSgt(tiempoAnt);
                    }
                    if(posicion + 1 <= red.getLineas()[aux]->getNroEstaciones()){
                        nombre = red.getLineas()[aux]->getEstaciones()[posicion + 1]->getNombre() + " " + red.getLineas()[aux]->getEstaciones()[posicion + 1]->getSufijo();
                        tiempoSgt = menuNumero(mensajes(5), "el tiempo para desde la estacion actual hasta la estacion " + nombre);
                        red.getLineas()[aux]->getEstaciones()[posicion + 1]->setTiempoAnt(tiempoSgt);
                        red.getLineas()[aux]->getEstaciones()[posicion]->setTiempoSgt(tiempoSgt);
                        if(posicion + 1 == red.getLineas()[aux]->getNroEstaciones()){
                            red.getLineas()[aux]->getEstaciones()[posicion + 1]->setTiempoSgt(-1);
                        }
                    }
                    cout << red.getLineas()[aux]->strEstaciones();
                }
                else{
                    mostrarError("No puede crear estaciones dado que no existen lineas...");
                }
                break;
            case 2:
                delete[] opcAux;
                opcAux = red.generarOpciones();
                if(red.getNroLineas() > 0){
                    aux = menuOpcion(mensajes(2) + "Ingrese la linea donde se encuentra la estacion a eliminar\n\n" + red.strLineas() + "\n", opcAux, red.getNroLineas());
                    if(red.getLineas()[aux]->getNroEstaciones() > 0){
                        delete[] opcAux;
                        opcAux = red.getLineas()[aux]->generarOpciones();
                        aux2 = menuOpcion(mensajes(3) + "Ingrese la estacion:\n\n" + red.getLineas()[aux]->strEstaciones() + "\n", opcAux, red.getLineas()[aux]->getNroEstaciones());
                        if(!red.getLineas()[aux]->getEstaciones()[aux2]->getTransferencia()){
                            if(aux2 - 1 != 0) {
                                if(aux2 + 1 <= red.getLineas()[aux]->getNroEstaciones()) {
                                    tiempoAnt = red.getLineas()[aux]->getEstaciones()[aux2 - 1]->getTiempoSgt() + red.getLineas()[aux]->getEstaciones()[aux2 + 1]->getTiempoAnt();
                                    red.getLineas()[aux]->getEstaciones()[aux2 + 1]->setTiempoAnt(tiempoAnt);
                                }
                                else tiempoAnt = -1;
                                red.getLineas()[aux]->getEstaciones()[aux2 - 1]->setTiempoSgt(tiempoAnt);
                            }
                            red.getLineas()[aux] -> eliminar(aux2);
                            red.setNroEstaciones(red.getNroEstaciones() - 1);
                        }
                        else{
                            mostrarError("No puede eliminar esta estacion ya que es una estacion de transferencia...");
                        }
                    }
                    else{
                        mostrarError("No puede eliminar estaciones dado que no existen estaciones en la linea seleccionada...");
                    }
                }
                else{
                    mostrarError("No puede eliminar estaciones dado que no existen lineas...");
                }
                break;
            case 3:
                if(red.getNroLineas() > 0){
                    menuOpcion(mensajes(2) + "Hay en total " + to_string(red.getNroLineas()) + " lineas en la red, observe sus nombres aca:\n\n" + red.strLineas() + "\n1. Seleccione esta opcion si desea volver al menu principal.\n\n", opciones, 1);
                }
                else{
                    mostrarError("No hay lineas para mostrar, no existen lineas en la red...");
                }
                break;
            case 4:
                if(red.getNroLineas() > 0){
                    delete [] opcAux;
                    opcAux = red.generarOpciones();
                    aux = menuOpcion(mensajes(2) + "Ingrese la linea que desea consultar:\n\n" + red.strLineas() + "\n", opcAux, red.getNroLineas());
                    if(red.getLineas()[aux]->getNroEstaciones() > 0){
                        nombre = red.getLineas()[aux]->getNombre();
                        menuOpcion(mensajes(3) + "Hay en total " + to_string(red.getLineas()[aux]->getNroEstaciones()) + " estaciones en la red " + nombre + ", visualicelas aca:\n\n" + red.getLineas()[aux]->strEstaciones() +"\n1. Ingrese esta opcion si desea volver al menu principal\n\n" , opciones, 1);
                    }
                    else{
                        mostrarError("No hay estaciones para mostrar, la linea seleccionada no posee estaciones...");
                    }
                }
                else{
                    mostrarError("No hay lineas para mostrar...");
                }
                break;
            case 5:
                if(red.getNroLineas() > 0){
                    delete [] opcAux;
                    opcAux = red.generarOpciones();
                    aux = menuOpcion(mensajes(2) + "Ingrese la linea que desea consultar:\n\n" + red.strLineas() + "\n", opcAux, red.getNroLineas());
                    if(red.getLineas()[aux]->getNroEstaciones() > 0){
                        if(menuNombre(red.getLineas()[aux], "mensaje aleatorio")){
                            mostrarExito("La estacion que usted proporciono si pertenece a la linea " + red.getLineas()[aux]->getNombre());
                        }
                        else{
                            mostrarError("La estacion que usted proporciono no pertenece a la linea " + red.getLineas()[aux]->getNombre());
                        }
                    }
                    else{
                        mostrarError("No hay estaciones para buscar, la linea seleccionada no posee estaciones...");
                    }
                }
                else{
                    mostrarError("No existen estaciones para buscar, dado que no hay lineas...");
                }
                break;
            case 6:
                if(red.getNroLineas() > 0){
                    delete [] opcAux;
                    opcAux = red.generarOpciones();
                    aux = menuOpcion(mensajes(2) + "Ingrese la linea a la cual estara conectada la nueva linea:\n\n" + red.strLineas() + "\n", opcAux, red.getNroLineas());
                    if(red.getLineas()[aux]->getNroTransf() > 0){
                        delete [] opcAux;
                        opcAux = red.getLineas()[aux]->generarOpciones();
                        aux2 = menuOpcion(mensajes(4) + "Ingrese la estacion de transferencia que conectara la linea " + red.getLineas()[aux]->getNombre() + " con esta nueva linea: \n\n" + red.getLineas()[aux]->strTransferencia() + "\n", opcAux, red.getLineas()[aux]->getNroTransf());
                        nombre = menuNombre("nombre", &red);
                        red.insertarLinea(new linea(nombre));
                        red.getLineas()[red.getNroLineas()]->insertar(new estacion(red.getLineas()[aux]->getTransferencia()[aux2]->getNombre(), nombre), 0);
                        red.getLineas()[red.getNroLineas()]->insertar(red.getLineas()[red.getNroLineas()]->getEstaciones()[1]);
                    }
                    else{
                        //error
                    }
                }
                else{
                    nombre = menuNombre("nombre", &red);
                    red.insertarLinea(new linea(nombre));
                }
                break;
            case 7:
                if(red.getNroLineas() > 0){
                    delete [] opcAux;
                    opcAux = red.generarOpciones();
                    aux = menuOpcion(mensajes(2) + "Ingrese la linea que desea eliminar:\n\n" + red.strLineas() + "\n", opcAux, red.getNroLineas());
                    if(!(red.getLineas()[aux]->getNroTransf() > 0)){
                        red.setNroEstaciones(red.getNroEstaciones() - red.getLineas()[aux]->getNroEstaciones());
                        red.eliminarLinea(aux);
                    }
                    else{
                        mostrarError("La linea que seleccionaste posee estaciones de transferencia, no se puede eliminar...");
                    }
                }
                else{
                    mostrarError("No existen lineas para eliminar...");
                }
                break;
            case 8:
                if(red.getNroEstaciones() > 0){
                    menuOpcion(mensajes(3) + "La red tiene un total de: "  + to_string(red.getNroEstaciones()) + " estaciones.\n\n1. Ingrese esta opcion si desea volver al menu principal\n\n", opciones, 1);
                }
                else{
                    mostrarError("La red no posee estaciones...");
                }
                break;
            case 9:
                if(red.getNroLineas() > 0){
                    delete [] opcAux;
                    opcAux = red.generarOpciones();
                    aux = menuOpcion(mensajes(2) + "Ingrese la linea en donde quiere calcular el trayecto:\n\n" + red.strLineas() + "\n", opcAux, red.getNroLineas());
                    if(red.getLineas()[aux]->getNroEstaciones() > 1){
                        delete [] opcAux;
                        opcAux = red.getLineas()[aux]->generarOpciones();
                        origen = menuOpcion(mensajes(3) + "Ingrese la estacion de ORIGEN:\n\n" + red.getLineas()[aux]->strEstaciones() + "\n", opcAux, red.getLineas()[aux]->getNroEstaciones());
                        destino = menuOpcion(mensajes(3) + "Ingrese la estacion de DESTINO:\n\n" + red.getLineas()[aux]->strEstaciones() + "\n", opcAux, red.getLineas()[aux]->getNroEstaciones());
                        if(origen == destino){
                            //error
                        }
                        else{
                            int tiempo = red.getLineas()[aux]->calcularTrayecto(origen, destino);
                            menuOpcion("resultado" + to_string(tiempo), opciones, 1);
                        }
                    }
                    else if(red.getLineas()[aux]->getNroEstaciones() == 1){
                        //error
                    }
                    else{
                        //error
                    }
                }
                else {
                    //error
                }
                break;
            case 10:
                bandera = false;
        }
    }
}
