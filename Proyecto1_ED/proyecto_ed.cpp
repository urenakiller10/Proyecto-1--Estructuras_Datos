#include "includes.h"
#include "pedidos.h"
#include "articulos.h"
#include "HiloPedidos.h"
#include "QMutex"




Proyecto_ED::Proyecto_ED(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Proyecto_ED)
{
    ui->setupUi(this);

    //Leer los clientes y subirlos a memoria
    clientes.LeerClientes();

    //Leer los articulos y subirlos a memoria
    articulos.cargar();


    colaP = new colaPedidos();
    FileRead* hiloPedidos = new FileRead(clientes, articulos, colaP, &mutexPedidos);
    hiloPedidos->start();

}

Proyecto_ED::~Proyecto_ED()
{
    delete ui;
}
//BOTONES DE LAS COLAS

//----------------------------------------------------ColaPedidos-------------------------------------------------------
void Proyecto_ED::on_B_ColaPedidos_clicked()

{
    //Leer los pedidos
    colaP->print();
}

//------------------------------------------------------Balanceador-----------------------------------------------------
void Proyecto_ED::on_B_Balanceador_clicked()
{
    qDebug() << "Muestra la cola del Balanceador";
}

// *******Decide si va a cola de alisto o a las fabrica:****


//***ColaAlisto
void Proyecto_ED::on_B_ColaAlisto_clicked()
{
    qDebug() << "Muestra la cola de Cola de Alisto";
}

//***Fabricas
void Proyecto_ED::on_B_FabricaA_clicked()
{
    qDebug() << "Muestra la cola de Fabrica A";
}

void Proyecto_ED::on_B_FabricaB_clicked()
{
    qDebug() << "Muestra la cola de Fabrica B";
}

void Proyecto_ED::on_B_FabricaC_clicked()
{
    qDebug() << "Muestra la cola de Fabrica C";
}

void Proyecto_ED::on_B_FabricaComodin_clicked()
{
    qDebug() << "Muestra la cola de Comodin";
}

//-----------------------------------------------------ColaAlistados------------------------------------------------------------
void Proyecto_ED::on_B_ColaAlistados_clicked()
{
    qDebug() << "Muestra la cola de Alistados";
}

//-----------------------------------------------------ColaFacturacion----------------------------------------------------------
void Proyecto_ED::on_B_ColaFacturacion_clicked()
{
    qDebug() << "Muestra la cola de la Facturacion";
}

//------------------------------------------------------Alistadores--------------------------------------------------------

void Proyecto_ED::on_B_Alistadores_clicked()
{
    qDebug() << "Muestra la cola de los alistadores";
}


void Proyecto_ED::on_B_Clientes_clicked()
{
    clientes.imprimir();

}
void Proyecto_ED::on_B_articulos_clicked()
{

    articulos.imprimirLista();
}


