//#include "HiloPedidos.h"
#include "CargarClientesMemoria.h"
#include "articulos.h"
#include "ColaFabricas.h"


    //Creo tambien le va a tener que pasar la lista suya


    //Se crean las colas de tipo Artículo de cada tipo fabrica

colaFabricas<Articulo> colaFabricaA;
colaFabricas<Articulo> colaFabricaB;
colaFabricas<Articulo> colaFabricaC;
colaFabricas<Articulo> colaFabricaComodin;



void procesar(ifstream pedidoValidado){

}
void BalanceadorDecisiones() {

    //Primero pregunte si es A o B, si es A y A tiene cola tiene mas pequeña (NO) va a la comodin B y viceversa.

    //                switch (articulo->codigo) {
    // Buscar el artículo en la lista de artículos
    for (auto& articulo : articulos) {
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
    //                        return " Va a la cola de la Fabrica A";

    //                        colaFabricaA.enqueue(*articulo);
    //                        cout << "Va a la cola de la Fabrica A" << endl;

    //                    } else {
    //                        return "Va a la cola de la Fabrica Comodin";
    //                        colaFabricaComodin.enqueue(*articulo);
    //                        cout << "Va a la cola de la Fabrica Comodin" << endl;
    //                    }
    //                    break;
    //                case 'B':
    //                    if (colaFabricaB.size() <= colaFabricaComodin.size()) {
    //                        return "Va a la cola de la Fabrica B";

    //                        colaFabricaB.enqueue(*articulo);
    //                        cout << "Va a la cola de la Fabrica B" << endl;

    //                    } else {
    //                        return " Va a la cola Fabrica Comodin";
    //                        colaFabricaComodin.enqueue(*articulo);
    //                        cout << "Va a la cola Fabrica Comodin" << endl;
    //                    }

    //                    break;
    //                case 'C':
    //                    return "Va a la cola de Fabrica C";
    //                default:
    //                    return "La Categoría del producto es inválida";
    //                }
///}


//                    colaFabricaC.enqueue(*articulo);
//                    cout << "Va a la cola de Fabrica C" << endl;
//                    break;

//                default:
//                    cout << "La Categoría del producto es inválida, debe de ser A, B o C" << endl;
//                        break;
//                }

//        }
//*
//}
//}


// Esperar un tiempo antes de procesar nuevos pedidos
QThread::sleep(1);
}

