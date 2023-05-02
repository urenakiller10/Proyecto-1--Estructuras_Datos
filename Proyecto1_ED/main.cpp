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
#include <QMessageBox>




int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Proyecto_ED w;
    w.show();

    //Ventana de error de pedidos, el text se cambia por lo que uno quiera. Lo otro es para que cuando se le dé "OK" se cierre todo
/*
    QMessageBox msgBox;
    msgBox.setText("Error en uno de los pedidos");
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.addButton(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);

    QObject::connect(&msgBox, &QMessageBox::buttonClicked, &w, &QWidget::close);

    msgBox.exec();*/

    colaFacturacion miCola;

    miCola.generarFacturas();




    return app.exec();

}
