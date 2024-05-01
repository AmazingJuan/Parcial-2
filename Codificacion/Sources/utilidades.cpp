#include "../Headers/utilidades.h"

/**
 * Breve descripción de la función limpiarPantalla.
 *
 * Imprime 50 saltos de linea, simulando que se elimino lo que habia previamente en la pantalla.
 *
 * @return Ninguno, solo son impresiones.
 */

void limpiarPantalla(){
    for(int cont = 0; cont < 50; cont++) cout << "\n";
}

void congelarPantalla(int segundos){
    this_thread::sleep_for (chrono::seconds(segundos));
}

string mensajes(int parametro){
    switch(parametro){
        case 1:
            return "  ____    _                                         _       _         \n |  _ \\  (_)                                       (_)     | |        \n | |_) |  _    ___   _ __   __   __   ___   _ __    _    __| |   ___  \n |  _ <  | |  / _ \\ | '_ \\  \\ \\ / /  / _ \\ | '_ \\  | |  / _` |  / _ \\ \n | |_) | | | |  __/ | | | |  \\ V /  |  __/ | | | | | | | (_| | | (_) |\n |____/  |_|  \\___| |_| |_|   \\_/    \\___| |_| |_| |_|  \\__,_|  \\___/ \n                                                                    \nBienvenido a la red metro, usted tiene las siguientes opciones:\n\n1. Agregar una estacion a una linea.\n2. Eliminar una estacion de una linea.\n3. Saber cuantas lineas tiene la red.\n4. Saber cuantas estaciones tiene una linea.\n5. Buscar estacion en una linea.\n6. Agregar linea a la red Metro.\n7. Eliminar una linea de la red.\n8. Saber cuantas estaciones tiene la red metro.\n9. Calcular tiempo de llegada entre estaciones de la misma linea.\n10. Salir del programa.\n\n";
        case 2:
            return " _        _                        \n | |      (_)                       \n | |       _   _ __     ___    __ _ \n | |      | | | '_ \\   / _ \\  / _` |\n | |____  | | | | | | |  __/ | (_| |\n |______| |_| |_| |_|  \\___|  \\__,_|\n                                    \n";
        case 3:
            return "  ______         _                    _                 \n |  ____|       | |                  (_)                \n | |__     ___  | |_    __ _    ___   _    ___    _ __  \n |  __|   / __| | __|  / _` |  / __| | |  / _ \\  | '_ \\ \n | |____  \\__ \\ | |_  | (_| | | (__  | | | (_) | | | | |\n |______| |___/  \\__|  \\__,_|  \\___| |_|  \\___/  |_| |_|\n\n";
        case 4:
            return "  _______                                 __                                       _         \n |__   __|                               / _|                                     (_)        \n    | |     _ __    __ _   _ __    ___  | |_    ___   _ __    ___   _ __     ___   _    __ _ \n    | |    | '__|  / _` | | '_ \\  / __| |  _|  / _ \\ | '__|  / _ \\ | '_ \\   / __| | |  / _` |\n    | |    | |    | (_| | | | | | \\__ \\ | |   |  __/ | |    |  __/ | | | | | (__  | | | (_| |\n    |_|    |_|     \\__,_| |_| |_| |___/ |_|    \\___| |_|     \\___| |_| |_|  \\___| |_|  \\__,_|\n\n";
        case 5:
            return "  _______   _                                    \n |__   __| (_)                                   \n    | |     _    ___   _ __ ___    _ __     ___  \n    | |    | |  / _ \\ | '_ ` _ \\  | '_ \\   / _ \\ \n    | |    | | |  __/ | | | | | | | |_) | | (_) |\n    |_|    |_|  \\___| |_| |_| |_| | .__/   \\___/ \n                                  | |            \n                                  |_|            \n\n";
        }
}

void mostrarError(string mensaje){
    limpiarPantalla();
    cout << "  ______                              \n |  ____|                             \n | |__     _ __   _ __    ___    _ __ \n |  __|   | '__| | '__|  / _ \\  | '__|\n | |____  | |    | |    | (_) | | |   \n |______| |_|    |_|     \\___/  |_|   \n\n";
    cout << mensaje;
    congelarPantalla(5);
}

void mostrarExito(string mensaje){
    limpiarPantalla();
    cout << "  ______          _   _           \n |  ____|        (_) | |          \n | |__    __  __  _  | |_    ___  \n |  __|   \\ \\/ / | | | __|  / _ \\ \n | |____   >  <  | | | |_  | (_) |\n |______| /_/\\_\\ |_|  \\__|  \\___/ \n\n";
    cout << mensaje;
    congelarPantalla(5);
}

string toLowerCase(string cadena){
    string aux = "";
    for(int cont = 0; cont < cadena.size(); cont++){
        aux += tolower(cadena.at(cont));
    }
    return aux;
}

string removeSeparator(string cadena, char separador){
    string aux = "";
    for(int cont = 0; cont < cadena.size(); cont++){
        if(cadena.at(cont) != separador) aux += cadena.at(cont);
    }
    return aux;
}
