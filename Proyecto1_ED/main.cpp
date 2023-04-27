#include "includes.h"
#include "CargarClientesMemoria.h"
#include "SubirAMemoriaArticulos.h"
#include "HiloPedidos.h"
#include "BalanceadorDecisiones.h"
#include "ColaFacturacion.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    //Iniciar el hilo de lectura de pedidos
    FileRead hiloPedidos;
    hiloPedidos.start(); //A este hilo tengo que pasarle ambas listas para luego poder verfiicar

    //Cargar CLientes Memoria.h
    listaSimple clientes;
    clientes.LeerClientes();
    clientes.imprimir();


    //list<Cliente> listaClientes;
    //LeerClientes(listaClientes);


//    //Se muestra la ventana con la interfaz gráfica
    QApplication a(argc, argv);
   Proyecto_ED w;
    w.show();

//    //Iniciar el hilo de lectura de pedidos
//    FileRead hiloPedidos;
//    hiloPedidos.start();

//    //Cargar CLientes Memoria.h
//    list<Cliente> listaClientes;
//    LeerClientes(listaClientes);
//    cout<<"hola"<<endl;


    // Se llama al encargado de facturar la cola de alistados


//    colaFacturacion cola;
//    cola.generarFacturas();
//    return 0;


    //Llamado del BalanceadorDecisiones

    //BalanceadorDecisiones();

    return a.exec();

}
