#ifndef UTILIDADES_H
#define UTILIDADES_H
#include "importaciones.h"

void limpiarPantalla();
void congelarPantalla();
string mensajes(int parametro);
void mostrarError(string mensaje);
void mostrarExito(string mensaje);
string toLowerCase(string cadena);
string removeSeparator(string cadena, char separador);

#endif // UTILIDADES_H
