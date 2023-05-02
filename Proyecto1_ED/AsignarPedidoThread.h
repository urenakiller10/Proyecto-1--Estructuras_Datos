
#ifndef ASIGNARPEDIDOTHREAD_H
#define ASIGNARPEDIDOTHREAD_H
#include <QThread>
#include "Alistadores.h"
#include "colaFacturacion.h"

class AsignarPedidoThread : public QThread {
public:
    void run() {
        Alistadores alistadores;
        alistadores.asignar_pedido(1, "A01");
        alistadores.asignar_pedido(2, "A03");
        alistadores.asignar_pedido(3, "A02");
        alistadores.revisar_cola();
        alistadores.esperar_trabajo_terminado();
    }
};

class GenerarFacturasThread : public QThread {
public:
    void run() {
        colaFacturacion miCola;
        miCola.generarFacturas();
    }
};

#endif // ASIGNARPEDIDOTHREAD_H
