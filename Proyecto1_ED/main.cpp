#include "includes.h"
#include "CargarClientesMemoria.h"
#include "SubirAMemoriaArticulos.h"
#include "HiloPedidos.h"
#include "BalanceadorDecisiones.h"
#include "ColaFacturacion.h"
#include "Alistadores.h"

int main(int argc, char *argv[]){
    //QApplication app(argc, argv);


//     //----------------------------Se muestra la ventana con la interfaz gráfica
//    QApplication a(argc, argv);
//    Proyecto_ED w;
//    w.show();

//    //-----------------------------Cargar los clientes a la memoria -> (CargarClientesMemoria.h)
//    listaSimple clientes;
//    clientes.LeerClientes();
//    clientes.imprimir();

//    //------------------------------Subir a la memoria los artículos -> (SubirAMemoriaArticulos.h)
//    list<Articulo*> articulos;
//    subirArticulos(articulos);
//    repetidos(articulos);

//    //------------------------------Imprimir la lista de artículos del txt ->
//    for (Articulo* a : articulos) {
//        cout << "Codigo: " << a->codigo << endl;
//        cout << "Cantidad: " << a->cantidad << endl;
//        cout << "Tiempo: " << a->tiempo << endl;
//        cout << "Categoria: " << a->categoria << endl;
//        cout << "Ubicacion: " << a->ubicacion << endl;
//        cout << "------------------------------------"<<endl;
//    }

//    //-----------------------------Iniciar el hilo de lectura de pedidos -> (HiloPedidos.h)
//    FileRead hiloPedidos;
//    hiloPedidos.start(); //A este hilo tengo que pasarle ambas listas para luego poder verfiicar






    //Llamado del BalanceadorDecisiones

    //BalanceadorDecisiones();



    // Se llama al encargado de facturar la cola de alistados -> (ColaFacturacion)


//    colaFacturacion cola;
//    cola.generarFacturas();


    //cout<<"hola"<<endl;
    Alistadores alistadores;

    // asignar 8 pedidos
    alistadores.asignar_pedido(1, "A01");
    alistadores.asignar_pedido(2, "B01");
    alistadores.asignar_pedido(3, "C01");
    alistadores.asignar_pedido(4, "D01");
    alistadores.asignar_pedido(5, "E01");
    alistadores.asignar_pedido(6, "F01");
    alistadores.asignar_pedido(7, "A02");
    alistadores.asignar_pedido(8, "C04");
    alistadores.asignar_pedido(9, "X04");
    alistadores.asignar_pedido(10, "Y04");

    // revisar la cola de pedidos
    alistadores.revisar_cola();


    // esperar a que todos los trabajos terminen

    alistadores.esperar_trabajo_terminado();


    return 0;

}



