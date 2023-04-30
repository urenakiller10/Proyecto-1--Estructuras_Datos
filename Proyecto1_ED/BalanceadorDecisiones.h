#ifndef BALANCEADORDECISIONES_H
#define BALANCEADORDECISIONES_H

#include <QThread>
#include "ColaFabricas.h"

#include <QThread>
#include "timeStamp.h"
#include "colaPedidos.h"
#include "CargarClientesMemoria.h"
#include "articulos.h"
#include "auxiliaries.h"
#include "pedidos.h"
#include "QMutex"

#include <filesystem> //https://en.cppreference.com/w/cpp/filesystem/directory_iterator
#include <iostream>
#include <string>
#include <fstream>

//***OJOOO****: Para aquí agregar a la cola de de alistados una vez que el balanceador toma decisión:
// ColaAlisto cola;
// cola.agregarElemento (aquí se pasa el pedido listo)

//Creo tambien le va a tener que pasar la lista suya


//Se crean las colas de tipo Artículo de cada tipo fabrica

class Balanceador : public QThread
{
public:

    Balanceador(){}
    Balanceador(colaFabricas colaA, colaFabricas colaB, colaFabricas colaC, colaFabricas colaX, listaDoble _productos, colaPedidos* _colaPed, QMutex* mutex){
        this->colaFabricaA = colaA;
        this->colaFabricaB = colaB;
        this->colaFabricaC = colaC;
        this->colaFabricaComodin = colaX;
        this->productos = _productos;
        this->colaPed = _colaPed;
        this->mutex = mutex;
        cout << "Se crea instancia de balanceador" << endl;
    }

    void run() override{
        //cout << "Llego al hilo del balanceador de alguna forma";
        while(true){

            mutex->lock();
            if(!colaPed->isEmpty()){
                cout << "Hay un pedido por atender"<<endl;
                pedido nuevoPedido = colaPed->dequeue();
                cout << nuevoPedido.toString() <<endl;
                mutex->unlock();
                listaPares* listaActual = nuevoPedido.lista;
                QThread::sleep(1); //Que dure un segundo en procesar el nuevo pedido

                parOrdenado* par = listaActual->primero;
                while(par->sig != NULL){
                    string codProd = par->codigoProducto;
                    int cantidad = par->cantidad;
                    if(productos.suficiente(codProd, cantidad)){
                        cout << "Hay suficiente de " << codProd <<endl;
                    }
                    else{
                        cout << "Hay suficiente de " << codProd << " a fabrica" <<endl;
                    }
                }

            }
            else{
                mutex->unlock();
            }
            QThread::sleep(1);
        }
    }

private:
    colaFabricas colaFabricaA;
    colaFabricas colaFabricaB;
    colaFabricas colaFabricaC;
    colaFabricas colaFabricaComodin;
    listaDoble productos;
    colaPedidos* colaPed;
    QMutex* mutex;
};





/*




void BalanceadorDecisiones() {
    //list<Articulo*> listarticulos = new listarticulos(listarticulos);


    colaFabricas colaFabricaA;
    colaFabricas colaFabricaB;
    colaFabricas colaFabricaC;
    colaFabricas colaFabricaComodin;

    while (true) {
        queue<string> pedidos;
        procesarPedidos(pedidos);

        while (!pedidos.empty()) {
            string pedido = pedidos.front();
            pedidos.pop();

            if (verificarExistencias(pedido, listarticulos)) {

                cout<<"Cantidad suficiente, va a la cola de alisto"<<endl;
            }
            else {
                cout<<"Cantidad insuficiente, va a la cola de las fabricas "<<endl;

                //Primero pregunte si es A o B, si es A y A tiene cola tiene mas pequeña (NO) va a la comodin B y viceversa.

                // Buscar el artículo en la lista de artículos
                for (auto& articulo : listarticulos) {
                    if (articulo->codigo == "A") {
                        if(colaFabricaA.size() <= colaFabricaComodin.size()) {

                            colaFabricaA.enqueue(*articulo);
                            cout << "Va a la cola de la Fabrica A" << endl;
                        }
                        else {
                            colaFabricaComodin.enqueue(*articulo);
                            cout << "Va a la cola de la Fabrica Comodin" << endl;
                        }
                        break;
                    }
                    else if (articulo->codigo =="B"){

                        if (colaFabricaB.size() <= colaFabricaComodin.size()) {

                            colaFabricaB.enqueue(*articulo);
                            cout << "Va a la cola de la Fabrica B" << endl;
                        }
                        else {
                            colaFabricaComodin.enqueue(*articulo);
                            cout << "Va a la cola Fabrica Comodin" << endl;
                        }
                    }

                    else if (articulo->codigo =="C"){

                        colaFabricaC.enqueue(*articulo);
                        cout << "Va a la cola de Fabrica C" << endl;
                        break;
                    }

                    else{
                        cout << "La Categoría del producto es inválida, debe de ser A, B o C" << endl;
                            break;
                    }
                }

                //                        }
                //                switch (articulos->codigo) {
                //                case 'A':
                //                    if (colaFabricaA.size() <= colaFabricaComodin.size()) {

                //                        colaFabricaA.enqueue(*articulo);
                //                        cout << "Va a la cola de la Fabrica A" << endl;

                //                    } else {
                //                        colaFabricaComodin.enqueue(*articulo);
                //                        cout << "Va a la cola de la Fabrica Comodin" << endl;
                //                    }
                //                    break;
                //                case 'B':
                //                    if (colaFabricaB.size() <= colaFabricaComodin.size()) {

                //                        colaFabricaB.enqueue(*articulo);
                //                        cout << "Va a la cola de la Fabrica B" << endl;

                //                    } else {
                //                        colaFabricaComodin.enqueue(*articulo);
                //                        cout << "Va a la cola Fabrica Comodin" << endl;
                //                    }
                //                    break;
                //                case 'C':

                //                    colaFabricaC.enqueue(*articulo);
                //                    cout << "Va a la cola de Fabrica C" << endl;
                //                    break;

                //                default:
                //                    cout << "La Categoría del producto es inválida, debe de ser A, B o C" << endl;
                //                        break;
                //                }

                //        }
            }
        }


        // Esperar un tiempo antes de procesar nuevos pedidos
        QThread::sleep(1);
    }
}
*/
#endif // BALANCEADORDECISIONES_H

