#include "includes.h"
#include "CargarClientesMemoria.h"
#include "HiloPedidos.h"
#include "articulos.h"
#include "BalanceadorDecisiones.h"
#include "ColaFacturacion.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    //Iniciar el hilo de lectura de pedidos
    FileRead hiloPedidos;
    //hiloPedidos.start();


    listaSimple clientes;
    //clientes.LeerClientes();

    listaDoble articulos;
    articulos.cargar();


    QApplication a(argc, argv);
   Proyecto_ED w;
    w.show();



    return a.exec();

}
