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
        estacion(string nombre);
        estacion(string nombre, string sufijo);
        string getNombre();
        void setNombre(string nombre);
        string getNombreFull();
        bool getTransferencia();
        void setTransferencia(bool transferencia);
        int getTiempoSgt();
        void setTiempoSgt(int tiempoSgt);
        int getTiempoAnt();
        void setTiempoAnt(int tiempoAnt);
};

#endif // ESTACION_H
