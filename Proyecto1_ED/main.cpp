#include "includes.h"
#include "CargarClientesMemoria.h"
#include "SubirAMemoriaArticulos.h"
#include "HiloPedidos.h"
#include "BalanceadorDecisiones.h"


int main(int argc, char *argv[])
{
    //Se muestra la ventana con la interfaz gráfica
    QApplication a(argc, argv);
    Proyecto_ED w;
    w.show();

    //Iniciar el hilo de lectura de pedidos
    FileRead hiloPedidos;
    hiloPedidos.start(); //A este hilo tengo que pasarle ambas listas para luego poder verfiicar

    //Cargar CLientes Memoria.h
    listaSimple clientes;
    clientes.LeerClientes();
    //clientes.imprimir();


    //list<Cliente> listaClientes;
    //LeerClientes(listaClientes);

    //Subir a Memoria Articulos.h
    list<Articulo> articulos;
    //subirArticulos(articulos);

    // Imprimir la lista de artículos del txt
    /*for (const auto& articulo : articulos) {
        cout << articulo.codigo << '\t' << articulo.cantidad << '\t'
             << articulo.tiempo << '\t' << articulo.categoria << '\t'
             << articulo.ubicacion << endl;
    }*/

    //Llamado del BalanceadorDecisiones

    //BalanceadorDecisiones();

    return a.exec();

}
