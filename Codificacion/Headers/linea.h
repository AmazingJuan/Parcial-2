#ifndef LINEA_H
#define LINEA_H

#include "importaciones.h"
#include "estacion.h"
#include "utilidades.h"
class linea{
    private:
        map<int, estacion*> estaciones;
        string nombre;
        int nroEstaciones;
        bool tieneTransf;
    public:
        linea(string nombre);
        void insertar(estacion *estacion, int posicion);
        void eliminar(int posicion);
        string *generarOpciones();
        string strEstaciones();
        bool buscarEstacion(string nombre);
        string getNombre();
        void setNombre(string nombre);
        void setNroEstaciones(int nroEstaciones);
        int getNroEstaciones();
        map<int, estacion*> &getEstaciones();
        void setEstaciones(map<int, estacion*> &estaciones);
        bool getTieneTransf();
        void setTieneTransf(bool tieneTransf);
};

#endif // LINEA_H
