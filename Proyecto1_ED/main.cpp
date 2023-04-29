#include "includes.h"
#include "CargarClientesMemoria.h"
#include "HiloPedidos.h"
#include "articulos.h"
#include "BalanceadorDecisiones.h"
#include "ColaFacturacion.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    listaSimple clientes;
    clientes.LeerClientes();

    listaDoble articulos;
    articulos.cargar();

    //Iniciar el hilo de lectura de pedidos
    FileRead hiloPedidos(clientes, articulos);
    hiloPedidos.start();

    QApplication a(argc, argv);
   Proyecto_ED w;
    w.show();



    return a.exec();

}
