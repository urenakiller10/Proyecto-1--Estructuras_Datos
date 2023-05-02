
#ifndef COLAFACTURACION_H
#define COLAFACTURACION_H
#include <fstream>
#include <queue>
#include <string>
#include <QDir>
#include "proyecto_ed.h"
#include "CargarClientesMemoria.h"
#include <cstdlib>  // Para la función rand()
#include <ctime>    // Para la función time()

class colaFacturacion {
public:

//    listaSimple* clientes =new listaSimple();
//    clientes->leerClientes();

    void generarFacturas() {
        srand(time(nullptr));
        QDir::setCurrent(QCoreApplication::applicationDirPath());
        int numFactura = 1;
        while (!pedidos.empty() && numFactura <= 4 ) {
            // Obtener el siguiente pedido de la cola
            std::string pedido = pedidos.front();
            pedidos.pop();

            // Construir el nombre del archivo de texto
            std::string nombreArchivo = "Factura" + std::to_string(numFactura) + ".txt";
            int numAlistador = rand() % 6 + 1;

            // Crear el archivo de texto y escribir el contenido
            std::ofstream archivo(nombreArchivo);
            archivo << "Pedido: " << numFactura << std::endl;
            archivo << "Cliente: "<<cl->getName(numFactura)<< std::endl;
            archivo << "Codigo del cliente: "<<cl->getId(numFactura)<< std::endl;
            archivo << "Prioridad del cliente: "<<cl->getPrioridad(numFactura)<< std::endl;
            archivo << "----------------------------------------------------------------" << std::endl;
            archivo << "En cola: " << std::endl;
            archivo << "Balanceador: " << std::endl;
            archivo << "A fabrica: " << std::endl;
            archivo << "A alisto: " << std::endl;
            archivo << "A empaque: " << std::endl;
            archivo << "Finalizado: " << std::endl;
            archivo << "----------------------------------------------------------------" << std::endl;
            archivo << "FABRICA" << std::endl;
            archivo << "Articulo: " << std::endl;
            archivo << "Cantidad: " << std::endl;
            archivo << "Inicio: " << std::endl;
            archivo << "Final: " << std::endl;
            archivo << "--------------------------------------------------------------" << std::endl;
            archivo << "ALISTO" << std::endl;
            archivo << "Alistador:" <<numAlistador<< std::endl;
            archivo << "Codigo articulo: / Ubicación: / Tiempo" << std::endl;


            // Incrementar el número de factura para el próximo archivo
            numFactura++;
        }
    }

    colaFacturacion() {
        // Inicializar la cola con tres pedidos
        pedidos.push("Pedido1");
        pedidos.push("Pedido2");
        pedidos.push("Pedido3");
        pedidos.push("Pedido4");
        cl->LeerClientes();
    }

private:
    std::queue<std::string> pedidos;

    listaSimple* cl;


};








#endif // COLAFACTURACION_H
