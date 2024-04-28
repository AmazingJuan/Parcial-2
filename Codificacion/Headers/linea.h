#ifndef LINEA_H
#define LINEA_H

#include "importaciones.h"
#include "estacion.h"
class linea{
    private:
        map<int, estacion*> estaciones;
        int nroEstaciones;
    public:
        linea();
        void insertar(estacion *estacion);
        string strEstaciones();
        void setNroEstaciones(int nroEstaciones);
        int getNroEstaciones();
        map<int, estacion*> getEstaciones();
        void setEstaciones(map<int, estacion*> &estaciones);
};

#endif // LINEA_H
