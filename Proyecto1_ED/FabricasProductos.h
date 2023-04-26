#include <QtCore>
#include "SubirAMemoriaArticulos.h"
#include "ColaFabricas.h"
#ifndef FABRICASPRODUCTOS_H
#define FABRICASPRODUCTOS_H
#include "SubirAMemoriaArticulos.h"
#include <iostream>
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Fabrica : public QThread
{
public:
    Fabrica(colaFabricas<Articulo> queue, string type){
        this->type = type;
        this->queue = queue;
        running = true;
    }


    void run(){

        while(running){

            if(!queue.isEmpty()){
                Articulo articulo = queue.dequeue();
                int cantidad = articulo.cantidad;
                cout << "Procesando el articulo: " << articulo.codigo <<" Se tardara: " << articulo.tiempo
                     << " Se ocupan " << cantidad << " unidades"<<endl;

                while(cantidad!=0){
                QThread:sleep(articulo.tiempo);
                    cantidad--;
                    cout << "Se proceso una unidad de" << articulo.codigo << " se procede a enviar" <<endl;
                }


                cout << "Todas las unidades procesadas" <<endl;
            }


            //si la cola no esta vacia
            /*
            if(!queue->isEmpty()){
                Articulo articulo = queue->dequeue();
                cout << "Procesando articulo " << articulo.codigo << endl;
                cout << "Se tardara " << articulo.tiempo << endl;
                QThread::sleep(articulo.tiempo);
            }*/
            //Articulo art = cola.dequeue()
            //QThread.sleep(art->tiempo)
            //enviar a alisto
        }
    }

private:
    int delay;
    bool running;
    string type;
    colaFabricas<Articulo> queue;
};


#endif // FABRICASPRODUCTOS_H
