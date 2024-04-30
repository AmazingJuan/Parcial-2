#ifndef ESTACION_H
#define ESTACION_H
#include "importaciones.h"
class estacion{
    private:
        string nombre;
        string sufijo;
        bool transferencia;
        int tiempoSgt;
        int tiempoAnt;
    public:
        estacion();
        estacion(string nombre);
        string getNombre();
        void setNombre(string nombre);

};

#endif // ESTACION_H
