
#ifndef COLAFACTURACION_H
#define COLAFACTURACION_H

#include <fstream>
#include <queue>
#include <string>
#include <QDir>

class colaFacturacion {
public:


    void generarFacturas() {
        QDir::setCurrent(QCoreApplication::applicationDirPath());
        int numFactura = 1;
        while (!pedidos.empty() && numFactura <= 4 ) {
            // Obtener el siguiente pedido de la cola
            std::string pedido = pedidos.front();
            pedidos.pop();

            // Construir el nombre del archivo de texto
            std::string nombreArchivo = "Factura" + std::to_string(numFactura) + ".txt";

            // Crear el archivo de texto y escribir el contenido
            std::ofstream archivo(nombreArchivo);
            archivo << "Pedido: " << numFactura << std::endl;
            archivo << "Cliente: " << std::endl;
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
            archivo << "Alistador: 4" << std::endl;
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
    }

private:
    std::queue<std::string> pedidos;




};








#endif // COLAFACTURACION_H
