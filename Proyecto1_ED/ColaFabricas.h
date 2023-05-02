#include <QList>
#include <QDebug>
#include<QObject>
#include <iostream>
#include "articulos.h"
#include "pedidos.h"

#ifndef COLAFABRICAS_H
#define COLAFABRICAS_H

struct colaFabricas{

public:

    void enqueue(parOrdenado* value)
    {
        cola.append(value);
    }

    parOrdenado* dequeue()
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
        for (parOrdenado* value : cola) {
//            value.imprimir();
        }

    }

    QString _toString()
    {
        QString result;
        for (int i = cola.size() - 1; i >= 0; --i) {
            if (i < cola.size() - 1) {
                result.append('-');
            }
            parOrdenado* actual= cola.at(i);
            result.append(actual->toString());

        }
        return result;
    }


private:
    QList<parOrdenado*> cola;
};

#endif // COLAFABRICAS_H
