#include "../Headers/menus.h"

/**
 * Breve descripción de la función menuOpcion.
 *
 * Permite al usuario escoger una de las opciones que se le presenten (numericas).
 *
 * @param mensaje Contiene un mensaje que se le va a mostrar al usuario, permite orientarlo en su decision.
 * @param opciones Un arreglo de strings que contiene las opciones que el usuario puede escoger, se refiere a las entradas validas.
 * @param lenOpcion Longitud del arreglo de opciones.
 * @return Devuelve un entero que representa la opcion que el usuario escogio.
 */

int menuOpcion(string mensaje, string* opciones, int lenOpcion){
    bool bandera = true; //Se inicializa una bandera que indica si el usuario termino de escoger o no.
    bool error = false; //Se inicializa un booleano error, si este es verdadero entonces mostrara un mensaje indicando que el usuario se equivoco al escoger la opcion.
    string entrada = "";
    while(bandera){ //Ciclo que siempre esta presente hasta que el usuario escoja una opcion valida.
        limpiarPantalla(); //Se limpia la pantalla.
        cout << mensaje; //Se imprime el mensaje que se le quiere mostrar al usuario

        //De la linea 22 a 23 se discierne entre mostrarle al usuario un mensaje indicando que ingrese la entrada, o uno que le haga saber que se equivoco y que debe escoger una opcion valida.
        if(!error) cout << "Escoja la opcion que desee: ";
        else cout << "Ingreso una opcion incorrecta, vuelva a ingresar la opcion por favor: ";
        getline(cin, entrada); //Se obtiene la entrada del usuario
        if(validarOpcion(entrada, opciones, lenOpcion)){ //Valida la entrada del usuario haciendo uso de la funcion validarOpcion.
            return stoi(entrada); //Devuelve la entrada del usuario convertida a entero.
        }
        else error = true; //Si la opcion no es valida se activa el booleano error.
    }
}

/**
 * Breve descripción de la función menuNumero.
 *
 * Permite al usuario ingresar un numero positivo.
 *
 * @param mensaje Contiene un mensaje que se le va a mostrar al usuario, permite orientarlo en su decision.
 * @param tipoEntrada Mensaje que indica el tipo de entrada que se debe ingresar, hace parte del mensaje que se le mostrara al usuario.
 * @return Devuelve el numero positivo que el usuario ingreso.
 */

int menuNumero(string mensaje, string tipoEntrada){
    bool bandera = true; //Se inicializa una bandera que indica si el usuario termino de escoger o no.
    bool error = false; //Se inicializa un booleano error, si este es verdadero entonces mostrara un mensaje indicando que el usuario se equivoco al escoger la opcion.
    string entrada = "";
    while(bandera){ //Ciclo que siempre esta presente hasta que el usuario escoja una opcion valida.
        limpiarPantalla(); //Se limpia la pantalla.
        cout << mensaje; //Se imprime el mensaje que se le quiere mostrar al usuario
        //De la linea 50 a 52 se discierne entre mostrarle al usuario un mensaje indicando que ingrese la entrada, o uno que le haga saber que se equivoco y que debe escoger una opcion valida.
        if(!error) cout << "Ingrese " + tipoEntrada + ": ";
        else cout << "Ingreso una opcion incorrecta, vuelva a ingresar " + tipoEntrada + ": ";
        getline(cin, entrada); //Se obtiene la entrada del usuario
        if(validarNumero(entrada)){ //Se valida que la entrada sea un numero positivo.
            return stoi(entrada); //Se devuelve al entrada que el usuario ingreso, como entero.
        }
        else error = true; //Si la entrada no es valida se activa el booleano error.
    }
}

/**
 * Breve descripción de la función menuNombre.
 *
 * Permite al usuario ingresar el enombre de una linea nueva para crear.
 *
 * @param mensaje Contiene un mensaje que se le va a mostrar al usuario, permite orientarlo en su decision.
 * @param red Puntero a la red actual, que sirve para verificar si el nombre que el usuario va a ingresar se encuentra disponible o no.
 * @return Devuelve el nombre valido que el usuario ingreso.
 */

string menuNombre(string mensaje, red *red){
    bool bandera = true; //Se inicializa una bandera que indica si el usuario termino de ingresar la entrada o no.
    bool error = false; //Se inicializa un booleano error, si este es verdadero entonces mostrara un mensaje indicando que el usuario se equivoco al ingresar el nombre.
    string entrada = "";
    while(bandera){ //Ciclo que siempre esta presente hasta que el usuario ingres eun nombre valido.
        limpiarPantalla(); //Se limpia la pantalla.
        cout << mensaje; //Se imprime el mensaje que se le quiere mostrar al usuario
        //De la linea 50 a 52 se discierne entre mostrarle al usuario un mensaje indicando que ingrese la entrada, o uno que le haga saber que se equivoco y que debe ingresar un nombre valido.
        if(!error) cout << "Ingrese el nombre de la linea a crear: ";
        else cout << "Ingreso una linea que ya existe o el nombre es invalido vuelva a ingresar el nombre de la linea: ";
        getline(cin, entrada); //Se obtiene la entrada del usuario
        if(!red->buscarLinea(entrada) && entrada.size() > 0){ //Se valida que el nombre de la linea no exista en la red y no sea nulo el mensaje.
            return entrada; //Se devuelve la entrada que el usuario ingreso.
        }
        else error = true; //Si la entrada no es valida se activa el booleano error.
    }
}

/**
 * Breve descripción de la función menuNombre.
 *
 * Permite al usuario ingresar el nombre de una estacion nueva para crear.
 *
 * @param mensaje Contiene un mensaje que se le va a mostrar al usuario, permite orientarlo en su decision.
 * @param linea Puntero a la linea actual, que sirve para verificar si el nombre que el usuario va a ingresar se encuentra disponible o no.
 * @return Devuelve el nombre valido que el usuario ingreso.
 */

string menuNombre(string mensaje, linea *linea){
    bool bandera = true; //Se inicializa una bandera que indica si el usuario termino ingresar el nombre o no.
    bool error = false; //Se inicializa un booleano error, si este es verdadero entonces mostrara un mensaje indicando que el usuario se equivoco al ingresar el nombre.
    string entrada = "";
    while(bandera){ //Ciclo que siempre esta presente hasta que el usuario escoja una opcion valida.
        limpiarPantalla(); //Se limpia la pantalla.
        cout << mensaje; //Se imprime el mensaje que se le quiere mostrar al usuario
        //De la linea 50 a 52 se discierne entre mostrarle al usuario un mensaje indicando que ingrese la entrada, o uno que le haga saber que se equivoco y que debe escribir un nombre valido.
        if(!error) cout << "Ingrese el nombre de la estacion a crear: ";
        else cout << "Ingreso una estacion que ya existe o el nombre es invalido, vuelva a ingresar el nombre de la estacion: ";
        getline(cin, entrada); //Se obtiene la entrada del usuario
        if(!linea->buscarEstacion(entrada) && entrada.size() > 0){ //Se valida que el nombre no pertenezca a la linea y la longitud de la entrada sea mayor a cero.
            return entrada; //Se devuelve la entrada valida que el usuario ingreso.
        }
        else error = true; //Si la entrada no es valida se activa el booleano error.
    }
}

/**
 * Breve descripción de la función menuNombre.
 *
 * Permite al usuario ingresar el nombre de una estacion y verifica si pertenece a una linea dada.
 *
 * @param linea Puntero a la linea actual, que sirve para verificar si el nombre que el usuario va a ingresar se encuentra en las estaciones o no.
 * @param mensaje Contiene un mensaje que se le va a mostrar al usuario, permite orientarlo en su decision.
 * @return Devuelve true si la estacion esta en la linea, sino devuelve false.
 */

bool menuNombre(linea *linea, string mensaje){
    bool bandera = true; //Se inicializa una bandera que indica si el usuario termino de escoger o no.
    bool error = false; //Se inicializa un booleano error, si este es verdadero entonces mostrara un mensaje indicando que el usuario se equivoco al escoger la opcion.
    string entrada = "";
    while(bandera){ //Ciclo que siempre esta presente hasta que el usuario escoja una opcion valida.
        limpiarPantalla(); //Se limpia la pantalla.
        cout << mensaje; //Se imprime el mensaje que se le quiere mostrar al usuario
        //De la linea 50 a 52 se discierne entre mostrarle al usuario un mensaje indicando que ingrese la entrada, o uno que le haga saber que se equivoco y que debe escoger una opcion valida.
        if(!error) cout << "Ingrese el nombre de la estacion a buscar: ";
        else cout << "Ingreso una opcion incorrecta, vuelva a ingresar el nombre de la estacion: ";
        getline(cin, entrada); //Se obtiene la entrada del usuario
        if(entrada.length() != 0){ //Se valida que la entrada tenga longitud positiva.
            return linea->buscarEstacion(entrada); //Se entrega el resultado de la busqueda de la estacion.
        }
        else error = true; //Si la entrada no es valida se activa el booleano error.
    }
}
