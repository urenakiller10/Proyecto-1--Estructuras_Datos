#include <QList>
#include <QDebug>
#include<QObject>
#include <iostream>
#include "articulo.h"

#ifndef COLAFABRICAS_H
#define COLAFABRICAS_H


template <typename T>

struct colaFabricas{

public:

    void enqueue(Articulo value)
    {
        cola.append(value);
    }

    Articulo dequeue()
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
        for (Articulo value : cola) {
            value.imprimir();
        }

    }

    QString _toString()
    {
        QString result;
        for (int i = cola.size() - 1; i >= 0; --i) {
            if (i < cola.size() - 1) {
                result.append('-');
            }
            Articulo actual = cola.at(i);
            result.append(actual.toString());

        }
        return result;
    }


private:
    QList<Articulo> cola;

};
