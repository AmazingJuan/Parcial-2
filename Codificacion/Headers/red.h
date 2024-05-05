#ifndef RED_H
#define RED_H
#include "linea.h"
class red{
    private:
        lista<linea*> lineas;
        int nroLineas;
        int nroEstaciones;
    public:
        red();
        ~red();
        void insertarLinea(linea* linea, int indice);
        void insertarLinea(linea *linea);
        void eliminarLinea(int indice);
        string *generarOpciones();
        string strLineas();
        bool buscarLinea(string nombre);
        void setNroEstaciones(int nroEstaciones);
        int getNroEstaciones();
        void setNroLineas(int nroLineas);
        int getNroLineas();
        lista<linea*> &getLineas();
        void setLineas(lista<linea*> &lineas);
};

#endif // RED_H
