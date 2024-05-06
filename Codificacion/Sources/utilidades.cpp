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


/**
 * Breve descripción de la función congelarPantalla.
 *
 * Simula el congelamiento de la pantalla.
 */

void congelarPantalla(int segundos){
    this_thread::sleep_for (chrono::seconds(segundos)); //Utiliza el espacio de nombres this_thread con el fin de congelar la pantalla o pausar el thread.
}

/**
 * Breve descripción de la función mensajes.
 *
 * Permite obtener un mensaje segun un parametro dado, los mensajes son completamente parte de la seccion de experiencia de usuario.
 *
 * @param parametro Numero que indica que mensaje se desea obtener.
 * @return String que contiene el mensaje deseado.
 */

string mensajes(int parametro){
    switch(parametro){
        case 1: //Mensaje de bienvenida que contiene las opciones disponibles para el usuario
            return "  ____    _                                         _       _         \n |  _ \\  (_)                                       (_)     | |        \n | |_) |  _    ___   _ __   __   __   ___   _ __    _    __| |   ___  \n |  _ <  | |  / _ \\ | '_ \\  \\ \\ / /  / _ \\ | '_ \\  | |  / _` |  / _ \\ \n | |_) | | | |  __/ | | | |  \\ V /  |  __/ | | | | | | | (_| | | (_) |\n |____/  |_|  \\___| |_| |_|   \\_/    \\___| |_| |_| |_|  \\__,_|  \\___/ \n                                                                    \nBienvenido a la red metro, usted tiene las siguientes opciones:\n\n1. Agregar una estacion a una linea.\n2. Eliminar una estacion de una linea.\n3. Saber cuantas lineas tiene la red.\n4. Saber cuantas estaciones tiene una linea.\n5. Buscar estacion en una linea.\n6. Agregar linea a la red Metro.\n7. Eliminar una linea de la red.\n8. Saber cuantas estaciones tiene la red metro.\n9. Calcular tiempo de llegada entre estaciones de la misma linea.\n10. Salir del programa.\n\n";
        case 2: //Muestra la palabra "linea".
            return " _        _                        \n | |      (_)                       \n | |       _   _ __     ___    __ _ \n | |      | | | '_ \\   / _ \\  / _` |\n | |____  | | | | | | |  __/ | (_| |\n |______| |_| |_| |_|  \\___|  \\__,_|\n                                    \n";
        case 3: //Muestra la palabra "estacion"
            return "  ______         _                    _                 \n |  ____|       | |                  (_)                \n | |__     ___  | |_    __ _    ___   _    ___    _ __  \n |  __|   / __| | __|  / _` |  / __| | |  / _ \\  | '_ \\ \n | |____  \\__ \\ | |_  | (_| | | (__  | | | (_) | | | | |\n |______| |___/  \\__|  \\__,_|  \\___| |_|  \\___/  |_| |_|\n\n";
        case 4: //Muestra la palabra "transferencia"
            return "  _______                                 __                                       _         \n |__   __|                               / _|                                     (_)        \n    | |     _ __    __ _   _ __    ___  | |_    ___   _ __    ___   _ __     ___   _    __ _ \n    | |    | '__|  / _` | | '_ \\  / __| |  _|  / _ \\ | '__|  / _ \\ | '_ \\   / __| | |  / _` |\n    | |    | |    | (_| | | | | | \\__ \\ | |   |  __/ | |    |  __/ | | | | | (__  | | | (_| |\n    |_|    |_|     \\__,_| |_| |_| |___/ |_|    \\___| |_|     \\___| |_| |_|  \\___| |_|  \\__,_|\n\n";
        case 5: //Muestra la palabra tiempo
            return "  _______   _                                    \n |__   __| (_)                                   \n    | |     _    ___   _ __ ___    _ __     ___  \n    | |    | |  / _ \\ | '_ ` _ \\  | '_ \\   / _ \\ \n    | |    | | |  __/ | | | | | | | |_) | | (_) |\n    |_|    |_|  \\___| |_| |_| |_| | .__/   \\___/ \n                                  | |            \n                                  |_|            \n\n";
        case 6: //Muestra la palabra nombre
            return "  _   _                       _                   \n | \\ | |                     | |                  \n |  \\| |   ___    _ __ ___   | |__    _ __    ___ \n | . ` |  / _ \\  | '_ ` _ \\  | '_ \\  | '__|  / _ \\\n | |\\  | | (_) | | | | | | | | |_) | | |    |  __/\n |_| \\_|  \\___/  |_| |_| |_| |_.__/  |_|     \\___|\n\n";
        }
}


/**
 * Breve descripción de la función mostrarError.
 *
 * Permite enseñar un dibujo de error, indicandole al usuario que surgió un problema. Según la entrada que ingrese el usuario
 *
 * @param mensaje Texto que se le quiere mostrar al usuario, adicional al cartel de error.
 */

void mostrarError(string mensaje){
    //Limpia la pantalla, muestra el cartel de error y el mensaje que el usuario indique, posteriormente congela la pantalla por 5 segundos.
    limpiarPantalla();
    cout << "  ______                              \n |  ____|                             \n | |__     _ __   _ __    ___    _ __ \n |  __|   | '__| | '__|  / _ \\  | '__|\n | |____  | |    | |    | (_) | | |   \n |______| |_|    |_|     \\___/  |_|   \n\n";
    cout << mensaje;
    congelarPantalla(5);
}

/**
 * Breve descripción de la función mostrarExito.
 *
 * Permite enseñar un dibujo de exito, indicandole al usuario que la operacion que estaba haciendo fue exitosa.
 *
 * @param mensaje Texto que se le quiere mostrar al usuario, adicional al cartel de exito.
 */

void mostrarExito(string mensaje){
    //Limpia la pantalla, muestra el cartel de exito y el mensaje que el usuario indique, posteriormente congela la pantalla por 5 segundos.
    limpiarPantalla();
    cout << "  ______          _   _           \n |  ____|        (_) | |          \n | |__    __  __  _  | |_    ___  \n |  __|   \\ \\/ / | | | __|  / _ \\ \n | |____   >  <  | | | |_  | (_) |\n |______| /_/\\_\\ |_|  \\__|  \\___/ \n\n";
    cout << mensaje;
    congelarPantalla(5);
}

/**
 * Breve descripción de la función toLowerCase.
 *
 * Permite poner todos los caracteres alfabeticos del la cadena ingresada en minusculas.
 *
 * @param cadena String que contiene el contenido que se quiere convertir en minusculas.
 * @return String que contiene la cadena deseada.
 */

string toLowerCase(string cadena){
    string aux = ""; //Define un string vacio.
    for(int cont = 0; cont < cadena.size(); cont++){
        aux += tolower(cadena.at(cont)); //Va añadiendole al string 'aux' todos los caracteres de la cadena en minuscula (los que pueden ponerse en minuscula).
    }
    return aux; //Devuelve el string en minusculas
}

/**
 * Breve descripción de la función removeSeparator.
 *
 * Permite remover los caracteres que el usuario indique en un string.
 *
 * @param cadena String que contiene el contenido original.
 * @param separador Char que denota el caracter que se desea remover completamente de la cadena original.
 * @return String que contiene el mensaje deseado.
 */

string removeSeparator(string cadena, char separador){
    string aux = ""; //Define un string vacioo.
    for(int cont = 0; cont < cadena.size(); cont++){
        if(cadena.at(cont) != separador) aux += cadena.at(cont); //Remueve el separador de la cadena
    }
    return aux; //Retorna la cadena deseada.
}
