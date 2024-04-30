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

    int decision = 0;
    int aux = 0;
    int aux2 = 0;
    string nombre = "carlos";
    string opciones[9];
    string *opcAux = nullptr;
    red.insertarLinea(new linea("bartolo"));
    red.insertarLinea(new linea("carlos"));
    red.insertarLinea(new linea("juan"));
    for(int cont = 0; cont < 9; cont++) opciones[cont] = to_string(cont+1);
    while(bandera){
        decision = menuOpcion("mensaje aleatorio", opciones, 9);
        switch(decision){
            case 1:
                if(red.getNroLineas() > 0){
                    aux = menuOpcion("red", opciones, 3);
                    if(red.getLineas()[aux]->getNroEstaciones() == 0){
                        red.getLineas()[aux] -> insertar(new estacion(), 0);
                    }
                    else{
                        delete[] opcAux;
                        opcAux = red.getLineas()[aux]->generarOpciones();
                        aux2 = menuOpcion("posicion", opcAux, red.getLineas()[aux]->getNroEstaciones() + 1);
                        red.getLineas()[aux] -> insertar(new estacion(nombre), aux2);
                    }
                    red.setNroEstaciones(red.getNroEstaciones() + 1);
                    cout << red.getLineas()[aux]->strEstaciones();
                }
                else{
                    //Imprimir un error
                }
                break;
            case 2:
                if(red.getNroLineas() > 0){
                        aux = menuOpcion("red", opciones, 3);
                        if(red.getLineas()[aux]->getNroEstaciones() > 0){
                            delete[] opcAux;
                            opcAux = red.getLineas()[aux]->generarOpciones();
                            aux2 = menuOpcion("estacion", opcAux, red.getLineas()[aux]->getNroEstaciones());
                            red.getLineas()[aux] -> eliminar(aux2);
                            red.setNroEstaciones(red.getNroEstaciones() - 1);
                        }
                        else{
                            //error
                        }
                }
                else{
                    //Imprimir un error
                }
                break;
            case 3:
                menuOpcion("lineas metro" + to_string(red.getNroLineas()), opciones, 1);
                break;
            case 4:
                delete [] opcAux;
                opcAux = red.generarOpciones();
                aux = menuOpcion("lineas escoger", opcAux, red.getNroLineas());
                menuOpcion("ver estaciones" + to_string(red.getLineas()[aux]->getNroEstaciones()), opciones, 1);
                break;
            case 5:
                //Saber si una estacion pertenece
            case 6:
                //agregar linea
            case 7:
                if(red.getNroLineas() > 0){
                    delete [] opcAux;
                    opcAux = red.generarOpciones();
                    aux = menuOpcion("lineaElim", opcAux, red.getNroLineas());
                    if(!red.getLineas()[aux]->getTieneTransf()){
                        red.eliminarLinea(aux);
                    }
                    else{
                        //error
                    }
                }
                else{
                    //error
                }
                break;
            case 8:
                menuOpcion("nro est red"  + to_string(red.getNroEstaciones()), opciones, 1);
            case 9:
                //programa de tiempos
            case 10:
                bandera = false;
        }
    }
}
