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



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Proyecto_ED w;
    w.show();




    return app.exec();

}
