#ifndef MENUS_H
#define MENUS_H

#include "utilidades.h"
#include "validacion.h"
#include "red.h"
#include "linea.h"
#include "importaciones.h"

int menuOpcion(string mensaje, string* opciones, int lenOpcion);
int menuNumero(string mensaje, string tipoEntrada);
string menuNombre(string mensaje, red *red);
string menuNombre(string mensaje, linea *linea);

#endif // MENUS_H
