#include "includes.h"
#ifndef PEDIDOS_H
#define PEDIDOS_H


struct pedido;
struct parOrdenado;
struct listaPares;

struct pedido{
    int id = 0;
    int codCliente = 0;
    listaPares* lista;

    pedido(int _id, int _codCliente, listaPares* _lista){
        id = _id;
        codCliente = _codCliente;
        lista = _lista;
    }

    string toString(){
        string r = "Id: " + to_string(id) + " cod cliente " + to_string(codCliente);
        return r;
    }

};


struct parOrdenado{

    parOrdenado* sig = NULL;

    string codigoProducto = "";
    int cantidad = 0;
    parOrdenado(string _codProd, int _cantidad){
        sig = NULL;
        codigoProducto = _codProd;
        cantidad = _cantidad;
    }

    string toString(){
        string result = "Articulo: " + codigoProducto + " Cantidad: " + to_string(cantidad);
        return result;
    }

};

//parOrdenado->codigo
//parOrdenado->cantidad

struct listaPares{
    parOrdenado* primero = NULL;

    listaPares(){
        primero = NULL;
    }

    void insertar(parOrdenado* par){
        if (primero == NULL){
            primero = par;
        }
        else{
            parOrdenado* tmp = primero;
            while(tmp->sig!=NULL){
                tmp = tmp->sig;
            }
            tmp->sig = par;
        }
    }
};

#endif // PEDIDOS_H
