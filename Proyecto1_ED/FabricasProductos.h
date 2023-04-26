
#ifndef FABRICASPRODUCTOS_H
#define FABRICASPRODUCTOS_H
#include "SubirAMemoriaArticulos.h"
#include <iostream>
#include <iostream>
#include <string>
#include <list>

using namespace std;

int calcularTiempoFabricacion(const Articulo& articulo) {
    return articulo.cantidad * articulo.tiempo;
}

#endif // FABRICASPRODUCTOS_H
