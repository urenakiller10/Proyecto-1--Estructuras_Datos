#include <QList>
#include <QDebug>
#include<QObject>
#include <iostream>
#include "pedidos.h"
#include "CargarClientesMemoria.h"

#ifndef COLAPEDIDOS_H
#define COLAPEDIDOS_H

struct colaPedidos{

public:

    colaPedidos(){}

    colaPedidos(listaSimple clientes){
        this->clientes = clientes;
    }

    void enqueue(pedido value)
    {
        //Obtener las prios
        if(!isEmpty()){ //Si existe algo para poder tomarlo
            pedido primero = cola.constFirst();
            int primerPrio = clientes.prioridadCliente(primero.codCliente);
            int prioActual = clientes.prioridadCliente(value.codCliente);

            if(prioActual > primerPrio){
                cola.insert(0, value);
            }
            else{
                cola.append(value); //Si el primero de la cola es el de mayor prioridad, se va al final
            }
        }
        else{
            cola.append(value); //Si no hay nada en la lista, se va de primero
        }
    }

    void enqueueFirst(pedido value){

    }

    pedido dequeue()
    {
        Q_ASSERT(!cola.isEmpty());
        return cola.takeFirst();
    }

    bool isEmpty() const
    {
        return cola.isEmpty();
    }

    int size() const
    {
        return cola.size();
    }

    void print()
    {
        qDebug() << "Queue size:" << size();
        qDebug() << "Queue contents:";
        for (pedido value : cola) {
            cola.insert(0,value);
            //value.imprimir();
        }

    }

    QString _toString()
    {
        QString result;
        for (int i = cola.size() - 1; i >= 0; --i) {
            if (i < cola.size() - 1) {
                result.append('-');
            }
            pedido actual = cola.at(i);
            //result.append(actual.toString());

        }
        return result;
    }


private:
    QList<pedido> cola;
    listaSimple clientes;
};

#endif // COLAPEDIDOS_H
