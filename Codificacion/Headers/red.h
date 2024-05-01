#ifndef RED_H
#define RED_H
#include "linea.h"
class red{
    private:
        map<int, linea*> lineas;
        int nroLineas;
        int nroEstaciones;
        vector<string> transferencia;
    public:
        red();
        void insertarLinea(linea *linea);
        void eliminarLinea(int posicion);
        string *generarOpciones();
        string strLineas();
        bool buscarLinea(string nombre);
        void setNroEstaciones(int nroEstaciones);
        int getNroEstaciones();
        void setNroLineas(int nroLineas);
        int getNroLineas();
        map<int, linea*> &getLineas();
        void setLineas(map<int, linea*> &lineas);
};

#endif // RED_H
