#ifndef LINEA_H
#define LINEA_H

#include "importaciones.h"
#include "estacion.h"
#include "lista.h"
#include "utilidades.h"
class linea{
    private:
        lista<estacion*> estaciones;
        lista<estacion*> transferencia;
        string nombre;
        int nroEstaciones;
        int nroTransf;
    public:
        linea(string nombre);
        ~linea();
        void insertar(estacion *estacion, int indice);
        void insertar(estacion *estacion);
        void insertarTransferencia(estacion *estacion);
        void eliminar(int indice);
        string *generarOpciones();
        string strEstaciones();
        string strTransferencia();
        bool buscarEstacion(string nombre);
        int calcularTrayecto(int origen, int destino);
        lista<estacion*> &getTransferencia();
        void setTransferencia(lista<estacion*> &transferencia);
        string getNombre();
        void setNombre(string nombre);
        void setNroEstaciones(int nroEstaciones);
        int getNroEstaciones();
        lista<estacion*> &getEstaciones();
        void setEstaciones(lista<estacion*> &estaciones);
        int getNroTransf();
        void setNroTransf(int nroTransf);
};

#endif // LINEA_H
