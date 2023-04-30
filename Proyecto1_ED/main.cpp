#include "includes.h"
#include "CargarClientesMemoria.h"
#include "HiloPedidos.h"
#include "articulos.h"
#include "BalanceadorDecisiones.h"
#include "ColaFacturacion.h"
#include "colaPedidos.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //Se leen los clientes

    listaSimple clientes;
    clientes.LeerClientes();

    //Se cargan los artículos

    listaDoble articulos;
    articulos.cargar();

    colaPedidos colaPed(clientes);

    //Se leen los pedidos
    FileRead hiloPedidos(clientes, articulos, colaPed);
    hiloPedidos.start();

    QApplication a(argc, argv);
   Proyecto_ED w;
    w.show();

    // Para probar lo que hay de alistadores:

//    alistadores.asignar_pedido(1,"A01");
//    alistadores.asignar_pedido(2,"B01");
//    alistadores.asignar_pedido(3,"C01");
//    alistadores.asignar_pedido(4,"D01");
//    alistadores.asignar_pedido(5,"S01");
//    alistadores.asignar_pedido(6,"F01");
//    alistadores.asignar_pedido(7,"X01");
//    alistadores.asignar_pedido(8,"A02");
//    alistadores.asignar_pedido(1,"B05");

//    alistadores.revisar_cola();

//    alistadores.esperar_trabajo_terminado();




    return a.exec();

}
