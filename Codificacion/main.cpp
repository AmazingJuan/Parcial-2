#include "Headers/estacion.h"
#include "Headers/linea.h"
#include "Headers/red.h"
#include "Headers/menus.h"
using namespace std;

int main()
{
    red red; //Se crea una instancia de la clase red.
    bool bandera = true; //Booleano que indica la salida del programa.
    bool isTransferencia = false; //Indica si la estacion a crear es de transferencia
    //Variables auxiliares que se inicializan, estas varibles serviran a lo largo del desarrrollo del codigo
    int decision = 0;
    int aux = -1;
    int aux2 = -1;
    int tiempoAnt = -1;
    int tiempoSgt = -1;
    int origen = 0;
    int destino = 0;
    string nombre = "";
    string opciones[10]; //Creacion del arreglo de opciones
    string *opcAux = nullptr; //Se define un puntero nulo, más adelante representara las opciones a escoger del usuario.
    for(int cont = 0; cont < 10; cont++) opciones[cont] = to_string(cont+1); //Se llena el arreglo de opciones del  al
    while(bandera){ //Se inicia el ciclo del programa
        decision = menuOpcion(mensajes(1), opciones, 10); //Se le da a escoger al usuario una de las 10 opciones
        switch(decision){
            case 1: //Agregar estacion
                if(red.getNroLineas() > 0){ //Permite escoger al usuario una linea donde quiere que se cree su estacion
                    delete [] opcAux;
                    opcAux = red.generarOpciones();
                    aux = menuOpcion(mensajes(2) + "Ingrese la linea donde desea crear la estacion\n\n" + red.strLineas() + "\n", opcAux, red.getNroLineas());
                    if(red.getLineas()[aux]->getNroEstaciones() == 0){ //Se discierne entre el caso de que no haya estaciones en la linea o no
                        aux2 = 1;
                    }
                    else{
                        delete[] opcAux;
                        opcAux = red.getLineas()[aux]->generarOpciones();
                        aux2 = menuOpcion(mensajes(3) + "Ingrese la posicion donde quiere que se posicione la estacion:\n\n" + red.getLineas()[aux]->strEstaciones() + to_string(red.getLineas()[aux]->getNroEstaciones() + 1) + ". Agregar al final\n\n" , opcAux, red.getLineas()[aux]->getNroEstaciones() + 1);
                    }
                    //Se le pregunta al usuario el nombre de la estacion y si es de transferencia o no.
                    nombre = menuNombre(mensajes(6), red.getLineas()[aux]);
                    isTransferencia = (menuOpcion(mensajes(4) + "Diga si la estacion a crear es de transferencia: \n\n1. Si\n2. No\n\n", opciones, 2)) % 2;
                    if(isTransferencia) {
                        red.getLineas()[aux] -> insertar(new estacion(nombre, red.getLineas()[aux]->getNombre()), aux2);
                    }
                    else red.getLineas()[aux] -> insertar(new estacion(nombre), aux2);
                    red.setNroEstaciones(red.getNroEstaciones() + 1);


                    //Ciclos que permiten preguntarle al usuario el tiempo para desplazarse de una estacion a otra segun corresponda.
                    if(aux2 - 1 != 0){
                        nombre = red.getLineas()[aux]->getEstaciones()[aux2 - 1]->getNombreFull();
                        tiempoAnt = menuNumero(mensajes(5), "el tiempo para desde la estacion " + nombre + " hasta la estacion actual");
                        red.getLineas()[aux]->getEstaciones()[aux2]->setTiempoAnt(tiempoAnt);
                        red.getLineas()[aux]->getEstaciones()[aux2 - 1]->setTiempoSgt(tiempoAnt);
                    }
                    if(aux2 + 1 <= red.getLineas()[aux]->getNroEstaciones()){
                        nombre = red.getLineas()[aux]->getEstaciones()[aux2 + 1]->getNombreFull();
                        tiempoSgt = menuNumero(mensajes(5), "el tiempo para desde la estacion actual hasta la estacion " + nombre);
                        red.getLineas()[aux]->getEstaciones()[aux2 + 1]->setTiempoAnt(tiempoSgt);
                        red.getLineas()[aux]->getEstaciones()[aux2]->setTiempoSgt(tiempoSgt);
                        if(aux2 + 1 == red.getLineas()[aux]->getNroEstaciones()){
                            red.getLineas()[aux]->getEstaciones()[aux2 + 1]->setTiempoSgt(-1);
                        }
                    }
                    //Se finaliza la creacion de la estacion y se muestra un mensaje de exito.
                    //mostrarExito("La estacion se ha creado correctamente...");
                }
                else{
                    mostrarError("No puede crear estaciones dado que no existen lineas...");
                }
                break;
            case 2: //Eliminacion de estaciones
                delete[] opcAux;
                opcAux = red.generarOpciones();
                if(red.getNroLineas() > 0){ //Se verifica que el numero de lineas sea mayor a cero.
                    aux = menuOpcion(mensajes(2) + "Ingrese la linea donde se encuentra la estacion a eliminar\n\n" + red.strLineas() + "\n", opcAux, red.getNroLineas());
                    if(red.getLineas()[aux]->getNroEstaciones() > 0){//Se verifica que el numero de estaciones en la linea sea mayor a cero
                        delete[] opcAux;
                        opcAux = red.getLineas()[aux]->generarOpciones();
                        aux2 = menuOpcion(mensajes(3) + "Ingrese la estacion:\n\n" + red.getLineas()[aux]->strEstaciones() + "\n", opcAux, red.getLineas()[aux]->getNroEstaciones());
                        if(!red.getLineas()[aux]->getEstaciones()[aux2]->getTransferencia()){ //Verifica si la estacion es de transferencia o no
                            if(aux2 - 1 != 0) { //Si la estación tiene alguna estacion antes que ella entonces se suma el tiempo que se demora de desde la anterior hasta la actual con el tiempo que se tarde de ir desde la actual hjasta la siguiente.
                                if(aux2 + 1 <= red.getLineas()[aux]->getNroEstaciones()) {
                                    tiempoAnt = red.getLineas()[aux]->getEstaciones()[aux2 - 1]->getTiempoSgt() + red.getLineas()[aux]->getEstaciones()[aux2 + 1]->getTiempoAnt();
                                    red.getLineas()[aux]->getEstaciones()[aux2 + 1]->setTiempoAnt(tiempoAnt);
                                }
                                else tiempoAnt = -1;
                                red.getLineas()[aux]->getEstaciones()[aux2 - 1]->setTiempoSgt(tiempoAnt);
                            }
                            red.getLineas()[aux] -> eliminar(aux2);
                            red.setNroEstaciones(red.getNroEstaciones() - 1);
                            //mostrarExito("La estacion se ha eliminado correctamente...");
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
            case 3: //Mostrar las lineas de la red.
                if(red.getNroLineas() > 0){
                    menuOpcion(mensajes(2) + "Hay en total " + to_string(red.getNroLineas()) + " lineas en la red, observe sus nombres aca:\n\n" + red.strLineas() + "\n1. Seleccione esta opcion si desea volver al menu principal.\n\n", opciones, 1);
                }
                else{
                    mostrarError("No hay lineas para mostrar, no existen lineas en la red...");
                }
                break;
            case 4:
                if(red.getNroLineas() > 0){ //Muestra las estaciones de la linea seleccionada, si no existen lineas entonces se muestra un error
                    delete [] opcAux;
                    opcAux = red.generarOpciones();
                    aux = menuOpcion(mensajes(2) + "Ingrese la linea que desea consultar:\n\n" + red.strLineas() + "\n", opcAux, red.getNroLineas());
                    if(red.getLineas()[aux]->getNroEstaciones() > 0){ //Si no existen estaciones en la linea se genera un error y no muestra nada.
                        nombre = red.getLineas()[aux]->getNombre();
                        menuOpcion(mensajes(3) + "Hay en total " + to_string(red.getLineas()[aux]->getNroEstaciones()) + " estaciones en la red, visualicelas aca:\n\n" + red.getLineas()[aux]->strEstaciones() +"\n1. Ingrese esta opcion si desea volver al menu principal\n\n" , opciones, 1);
                    }
                    else{
                        mostrarError("No hay estaciones para mostrar, la linea seleccionada no posee estaciones...");
                    }
                }
                else{
                    mostrarError("No hay lineas para mostrar...");
                }
                break;
            case 5: //Busca si una estacion pertenece a un a linea.
                if(red.getNroLineas() > 0){ //Se verifica que el numero de lineas sea mayor a cero.
                    delete [] opcAux;
                    opcAux = red.generarOpciones();
                    aux = menuOpcion(mensajes(2) + "Ingrese la linea que desea consultar:\n\n" + red.strLineas() + "\n", opcAux, red.getNroLineas()); //Se le pide al usuario ingresar una linea
                    if(red.getLineas()[aux]->getNroEstaciones() > 0){
                        if(menuNombre(red.getLineas()[aux], mensajes(6))){ //Se le pide al usuario ingresar un nombre y posteriormente se verifica si está en la linea o no.
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
                if(red.getNroLineas() > 0){ //Opción para crear linea nueva, verifica si hay lineas disponibles sino crea automaticamente la linea.
                    delete [] opcAux;
                    opcAux = red.generarOpciones();
                    aux = menuOpcion(mensajes(2) + "Ingrese la linea a la cual estara conectada la nueva linea:\n\n" + red.strLineas() + "\n", opcAux, red.getNroLineas());
                    if(red.getLineas()[aux]->getNroTransf() > 0){ //Se verifica si la linea tiene estaciones de transferencia, sino devuelve error.
                        cout << "PASE ACA";
                        delete [] opcAux;
                        opcAux = red.getLineas()[aux]->generarOpciones();
                        //Se muestra las estaciones de transferencia de la linea, permitiendole al usuario escoger.
                        aux2 = menuOpcion(mensajes(4) + "Ingrese la estacion de transferencia que conectara la linea " + red.getLineas()[aux]->getNombre() + " con esta nueva linea: \n\n" + red.getLineas()[aux]->strTransferencia() + "\n", opcAux, red.getLineas()[aux]->getNroTransf());
                        nombre = menuNombre(mensajes(6), &red);
                        red.insertarLinea(new linea(nombre));
                        //Se ingresa la linea a la red y posteriormente se ingresa una estacion de transferencia en la primera posición.
                        red.getLineas()[red.getNroLineas()]->insertar(new estacion(red.getLineas()[aux]->getTransferencia()[aux2]->getNombre(), nombre), 1);
                        //mostrarExito("La linea se ha creado correctamente...");
                    }
                    else{
                        mostrarError("La linea actual no posee estaciones de transferencia, no se puede crear la linea...");
                    }
                }
                else{
                    nombre = menuNombre(mensajes(6), &red); //pide el nombre de la nueva linea
                    red.insertarLinea(new linea(nombre)); //inserta la linea a la red.
                    //mostrarExito("La linea se ha creado correctamente...");
                }
                break;
            case 7: //Permite eliminar una linea dada
                if(red.getNroLineas() > 0){ //Se verifica que existan lineas
                    delete [] opcAux;
                    opcAux = red.generarOpciones();
                    aux = menuOpcion(mensajes(2) + "Ingrese la linea que desea eliminar:\n\n" + red.strLineas() + "\n", opcAux, red.getNroLineas());
                    if(!(red.getLineas()[aux]->getNroTransf() > 0)){ //Se verifica que la linea ingresada no tenga estaciones de transferencia, si no tiene se elimina la red correctamente.
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
            case 8://Mostrar la totalidad de estaciones de la red, se tienen en cuenta las estaciones de transferencia.
                if(red.getNroEstaciones() > 0){ //Si la red tiene estaciones entonces muestra el numero.
                    menuOpcion(mensajes(3) + "La red tiene un total de: "  + to_string(red.getNroEstaciones()) + " estaciones.\n\n1. Ingrese esta opcion si desea volver al menu principal\n\n", opciones, 1);
                }
                else{
                    mostrarError("La red no posee estaciones...");
                }
                break;
            case 9: //Opcion para calcular el trayecto de una estacion a otra en una linea
                if(red.getNroLineas() > 0){ //Se verifica que hayan lineas disponbiles
                    delete [] opcAux;
                    opcAux = red.generarOpciones();
                    aux = menuOpcion(mensajes(2) + "Ingrese la linea en donde quiere calcular el trayecto:\n\n" + red.strLineas() + "\n", opcAux, red.getNroLineas());
                    if(red.getLineas()[aux]->getNroEstaciones() > 1){ //Se verifica que la linea tenga al menos dos estaciones
                        delete [] opcAux;
                        opcAux = red.getLineas()[aux]->generarOpciones();
                        //Se pide el origen y el destino.
                        origen = menuOpcion(mensajes(3) + "Ingrese la estacion de ORIGEN:\n\n" + red.getLineas()[aux]->strEstaciones() + "\n", opcAux, red.getLineas()[aux]->getNroEstaciones());
                        destino = menuOpcion(mensajes(3) + "Ingrese la estacion de DESTINO:\n\n" + red.getLineas()[aux]->strEstaciones() + "\n", opcAux, red.getLineas()[aux]->getNroEstaciones());
                        if(origen == destino){ //Muestra error si las estaciones de origen y destino son las mismas
                            mostrarError("La estacion de origen es igual a la estacion de destino, por lo tanto se demora 0 segundos en el trayecto...");
                        }
                        else{ //Muestra el mensaje deseado si se pudo calcular el trayecto correctamente
                            menuOpcion(mensajes(5) + "El tiempo que se demora al hacer el trayecto indicado es de " + to_string(red.getLineas()[aux]->calcularTrayecto(origen, destino)) + " segundos.\n\n1. Ingrese esta opcion si desea volver al menu principal.\n\n", opciones, 1);
                        }
                    }
                    else if(red.getLineas()[aux]->getNroEstaciones() == 1){
                        mostrarError("La linea actual solo posee una estacion, por lo tanto se demora 0 segundos en cualquier trayecto...");
                    }
                    else{
                        mostrarError("La linea actual no posee estaciones...");
                    }
                }
                else {
                    mostrarError("La red actual no posee lineas...");
                }
                break;
            case 10: //Caso para salir de programa.
                bandera = false;
        }
    }
}
