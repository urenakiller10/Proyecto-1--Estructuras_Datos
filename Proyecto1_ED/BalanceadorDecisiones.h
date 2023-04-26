
#ifndef BALANCEADORDECISIONES_H
#define BALANCEADORDECISIONES_H

#include <queue>
//#include "HiloPedidos.h"
#include "CargarClientesMemoria.h"
#include "SubirAMemoriaArticulos.h"


//***OJOOO****: Para aquí agregar a la cola de de alistados una vez que el balanceador toma decisión:
// ColaAlisto cola;
// cola.agregarElemento (aquí se pasa el pedido listo)

//Creo tambien le va a tener que pasar la lista suya
void procesar(ifstream pedidoValidado){
   //Aqui procesa lo que ocupes
}



void procesarPedidos(queue<string>& pedidos) {
    list<Cliente> listaClientes;
    //LeerClientes(listaClientes);

    for (const auto& cliente : listaClientes) {
        string archivo = "../pedidos/" + to_string(cliente.codigo) + ".txt";
        ifstream file(archivo);

        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                pedidos.push(line + " " + to_string(cliente.prioridad));
            }
        }
    }
}

bool verificarExistencias(const string& pedido, list<Articulo>& articulos) {
    // Extraer información del pedido
    istringstream iss(pedido);
    string codigo;
    int cantidad;
    iss >> codigo >> cantidad;

    // Buscar el artículo en la lista de artículos
    for (auto& articulo : articulos) {
        if (articulo.codigo == codigo) {
            if (articulo.cantidad >= cantidad) {
                articulo.cantidad -= cantidad;
                return true;
            }
            else {
                return false;
            }
        }
    }

    return false;
}

void BalanceadorDecisiones() {
    list<Articulo> articulos;
    subirArticulos(articulos);

    while (true) {
        queue<string> pedidos;
        procesarPedidos(pedidos);

        while (!pedidos.empty()) {
            string pedido = pedidos.front();
            pedidos.pop();

            if (verificarExistencias(pedido, articulos)) {

                cout<<"Cantidad suficiente, va a la cola de alisto"<<endl;
            }
            else {
                cout<<"Cantidad insuficiente, va a la cola de las fabricas "<<endl;
                //Primero pregunte si es A o B, si es A y A tiene cola tiene mas pequeña (NO) va a la comodin B y viceversa.
            }
        }

        // Esperar un tiempo antes de procesar nuevos pedidos
        QThread::sleep(1);
    }
}

#endif // BALANCEADORDECISIONES_H

