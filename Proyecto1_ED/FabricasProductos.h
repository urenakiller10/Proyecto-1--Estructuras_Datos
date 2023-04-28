#include <QtCore>
#include "ColaFabricas.h"
#ifndef FABRICASPRODUCTOS_H
#define FABRICASPRODUCTOS_H
#include "articulos.h"
#include <iostream>
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Fabrica : public QThread
{
public:
    Fabrica(colaFabricas<Articulo> queue){
        this->queue = queue;
        running = true;
    }


    void run(){

        while(running){

            if(!queue.isEmpty()){
                Articulo articulo = queue.dequeue();
                int cantidad = articulo.cantidad;
                cout << "Procesando el articulo: " << articulo.codigo <<" Se tardara: " << articulo.segundosFabricacion
                     << " Se ocupan " << cantidad << " unidades"<<endl;

                while(cantidad!=0){
                QThread:sleep(articulo.segundosFabricacion);
                    cantidad--;
                    cout << "Se proceso una unidad de" << articulo.codigo << " se procede a enviar" <<endl;
                }


                cout << "Todas las unidades procesadas" <<endl;
            }



        }
    }

private:
    int delay;
    bool running;
    colaFabricas<Articulo> queue;
};


#endif // FABRICASPRODUCTOS_H
