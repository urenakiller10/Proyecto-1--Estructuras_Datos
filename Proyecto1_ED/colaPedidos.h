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
        //cout << "Se crea la cola de pedidos " <<endl;
        this->clientes = clientes;
    }

    void enqueue(pedido* value)
    {
        cola.append(value);
    }


    pedido* dequeue()
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
        for (pedido* value : cola) {
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
            pedido* actual = cola.at(i);
            result.append(actual->toString());

        }
        return result;
    }


private:
    QList<pedido*> cola;
    listaSimple clientes;
};

#endif // COLAPEDIDOS_H
