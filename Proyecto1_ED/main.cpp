#include "includes.h"
#include "CargarClientesMemoria.h"
#include "HiloPedidos.h"
#include "articulos.h"
#include "BalanceadorDecisiones.h"
#include "ColaFacturacion.h"
#include "colaPedidos.h"
#include "ColaFabricas.h"
#include "QMutex"
#include "alistadores.h"
#include "proyecto_ed.h"
#include <QApplication>





int main(int argc, char *argv[])
{
    QApplication app(argc, argv);



    listaSimple clientesR;
    listaDoble articulosR;

    bool clientesCargados = clientesR.LeerClientes();
    bool articulosCargados = articulosR.cargar();
    bool arranque = true;

    if(clientesCargados){
        cout << "Se cargaron los clientes" <<endl;
    }
    else
    {
        cout << "NO se cargaron los clientes" <<endl;
        arranque = arranque&&false;
    }

    if(articulosCargados){
        cout << "Se cargaron los articulos" <<endl;
    }
    else
    {
        cout << "NO se cargaron los articulos" <<endl;
        arranque = arranque&&false;
    }




        //app.quit();
    if(arranque){
        Proyecto_ED w;
        w.show();
    } else{return 0;}

    //Ventana de error de pedidos, el text se cambia por lo que uno quiera. Lo otro es para que cuando se le dé "OK" se cierre todo



    return app.exec();

}
