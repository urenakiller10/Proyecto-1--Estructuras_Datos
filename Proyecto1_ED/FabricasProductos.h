
#ifndef FABRICASPRODUCTOS_H
#define FABRICASPRODUCTOS_H
#include "SubirAMemoriaArticulos.h"
#include <iostream>
#include <iostream>
#include <string>
#include <list>

using namespace std;


string obtenerFabrica(const Articulo& articulo) {
    switch (articulo.categoria) {
    case 'A':

        return "Fabrica A";
    case 'B':
        return "Fabrica B";
    case 'C':
        return "Fabrica C";
    default:
        return "Categoría inválida";
    }
}

int calcularTiempoFabricacion(const Articulo& articulo) {
    return articulo.cantidad * articulo.tiempo;
}

#endif // FABRICASPRODUCTOS_H
