
#ifndef ALISTADORES_H
#define ALISTADORES_H

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <thread>
#include "calcularTiempo.h"

using namespace std;


//Se crea la clase de UN ALISTADOR

class Alistador {
public:
    int id;
    bool libre;
    string ubicacion_pedido;
    int tiempo_asignado;
    int tiempo_restante;
    int pedido_asignado;

    Alistador(int i) {
        id = i;
        libre = true;
        ubicacion_pedido = " ";
        tiempo_asignado = 0;
        tiempo_restante = 0;
        pedido_asignado = 0;
    }

    void asignar_pedido(int pedido, string ubicacion) {
        ubicacion_pedido = ubicacion;
        pedido_asignado = pedido;
        tiempo_asignado = tiempo(ubicacion);  //El tiempo que el mae dura es llamando a tiempo que está creada en header calcularTiempo.h
        tiempo_restante = tiempo_asignado;
        libre = false;
    }

    void completar_pedido() {
        pedido_asignado = 0;
        tiempo_asignado = 0;
        tiempo_restante = 0;
        libre = true;
    }

    void actualizar_tiempo() {
        if (!libre) {
            tiempo_restante--;
            if (tiempo_restante == 0) {
                cout << "Alistador numero " << id << " completa el pedido numero " << pedido_asignado << endl;
                completar_pedido();
            } else {
                cout << "Alistador numero " << id << " esta ocupado con el pedido numero " << pedido_asignado << endl;
            }
        }
    }
};

//Se crea la clase que es una lista la ayuda de un vector, una una lista de ALISTADORES

class Alistadores {
public:
    queue<int> pedidos; // Esta se crea GENERICAMENTE, ***** hay que borrarla *****
    vector<Alistador*> lista;
    vector<thread> threads;

    Alistadores() {
        // crear la lista de 6 alistadores
        for (int i = 0; i <6; i++) {
            lista.push_back(new Alistador(i+1));
        }
    }

    //Esto es mientras está ocupado o libre (si es así, revisa a ver si hay pendientes)

    void trabajar(Alistador* alistador) {
        while (true) {
            if (alistador->libre) {
                // si el alistador está libre, revisar si hay pedidos pendientes en la cola
                if (!pedidos.empty()) {
                    alistador->asignar_pedido(pedidos.front(), "A01");
                    pedidos.pop();
                    continue;
                } else {
                    // si no hay pedidos pendientes, no hay nada que hacer en este hilo
                    this_thread::sleep_for(chrono::seconds(1));
                    continue;
                }
            }
            if (alistador->tiempo_restante > 0) {
                cout << "3Alistador numero " << alistador->id << " esta ocupado con el pedido numero " << alistador->pedido_asignado << endl;
                this_thread::sleep_for(chrono::seconds(1));
                alistador->tiempo_restante--;
            } else {
                cout << "4Alistador numero " << alistador->id << " completó el pedido numero " << alistador->pedido_asignado << endl;
                                                                                                                                  alistador->completar_pedido();
                // revisar si hay pedidos pendientes en la cola
                if (!pedidos.empty()) {
                    alistador->asignar_pedido(pedidos.front(),"A01");
                    pedidos.pop();
                    continue;
               } else {
                    break;
               }
            }
        }
    }

    //se le asigna un pedido al primer alistador que haya libre

    void asignar_pedido(int pedido, string ubicacion) {
        // encontrar al primer alistador libre
        Alistador* alistador_libre = nullptr;
        for (Alistador* alistador : lista) {
            if (alistador->libre) {
                alistador_libre = alistador;
                break;
            }
        }

        // si no hay alistadores libres, poner el pedido en la cola
        if (alistador_libre == nullptr) {
            cout << "No hay alistadores disponibles en este momento. El pedido " << pedido << " se pondrá en cola." << endl;
             pedidos.push(pedido);
            return;
        }

        // asignar el pedido al alistador libre
        alistador_libre->asignar_pedido(pedido, ubicacion);

        // crear un hilo para que el alistador trabaje en el pedido asignado
        threads.push_back(thread(&Alistadores::trabajar, this, alistador_libre));
    }

    //se revisa la cola a ver si hay algun pedido y además si hay un alistador libre
    //No sé si está de más este método porque se parece al de trabajar en cierta parte

    void revisar_cola() {
        while (!pedidos.empty()) {
            // encontrar al primer alistador libre
            Alistador* alistador_libre = nullptr;
            for (Alistador* alistador : lista) {
                if (alistador->libre) {
                    alistador_libre = alistador;
                    break;
                }
            }

            // si no hay alistadores libres, salir del ciclo y volver a revisar la cola más tarde
            if (alistador_libre == nullptr) {
                cout << "No hay alistadores disponibles en este momento. El pedido " << pedidos.front() << " seguira en cola"<<endl;
                    break;
            }

            // asignar el pedido al alistador libre
            alistador_libre->asignar_pedido(pedidos.front(), "A01");

            // sacar el pedido de la cola
            pedidos.pop();

            // crear un hilo para que el alistador trabaje en el pedido asignado
            threads.push_back(thread(&Alistadores::trabajar, this, alistador_libre));
        }
    }

//Espera hasta que terminen todos los hilos, es decir, que se terminen de procesar todos los pedidos
    void esperar_trabajo_terminado() {
        for (thread& t : threads) {
            t.join();
        }
        threads.clear();
    }

};

#endif // ALISTADORES_H
