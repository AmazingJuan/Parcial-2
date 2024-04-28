#include <iostream>
#include <map>
#include "Headers/estacion.h"
#include "Headers/linea.h"
using namespace std;

int main()
{
    linea line;
    line.insertar(new estacion());
    line.insertar(new estacion());
    line.insertar(new estacion());
    line.getEstaciones()[1]->setNombre("mimado");
    line.getEstaciones()[2]->setNombre("foker");
    line.getEstaciones()[3]->setNombre("marikong");
    line.insertar(new estacion());
    cout << line.strEstaciones();
    return 0;
}
