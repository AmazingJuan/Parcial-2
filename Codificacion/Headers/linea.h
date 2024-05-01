#ifndef LINEA_H
#define LINEA_H

#include "importaciones.h"
#include "estacion.h"
#include "utilidades.h"
class linea{
    private:
        map<int, estacion*> estaciones;
        map<int, estacion*> transferencia;
        string nombre;
        int nroEstaciones;
        int nroTransf;
    public:
        linea(string nombre);
        void insertar(estacion *estacion, int posicion);
        void insertar(estacion  *estacion);
        void eliminar(int posicion);
        string *generarOpciones();
        string strEstaciones();
        string strTransferencia();
        bool buscarEstacion(string nombre);
        int calcularTrayecto(int origen, int destino);
        map<int, estacion*> &getTransferencia();
        void setTransferencia(map<int, estacion*> &transferencia);
        string getNombre();
        void setNombre(string nombre);
        void setNroEstaciones(int nroEstaciones);
        int getNroEstaciones();
        map<int, estacion*> &getEstaciones();
        void setEstaciones(map<int, estacion*> &estaciones);
        int getNroTransf();
        void setNroTransf(int nroTransf);
};

#endif // LINEA_H
