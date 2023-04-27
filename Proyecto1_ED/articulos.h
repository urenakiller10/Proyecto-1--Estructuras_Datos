#include "includes.h"#
#include "auxiliaries.h"
#ifndef ARTICULOS_H
#define ARTICULOS_H

//Esta wea se va a encargar de mantener la bodega

struct articulo{
    //Data section
    string codigo;
    int existencias;
    int segundosFabricacion;
    string categoria;
    string ubicacion;

    //Pointer section
    articulo* anterior;
    articulo* siguiente;

    //Builder
    articulo(string _codigo, int _cantidadAlmacen, int _segundosFabricacion, string _categoria, string _ubicacion){
        codigo = _codigo;
        existencias = _cantidadAlmacen;
        segundosFabricacion = _segundosFabricacion;
        categoria = _categoria;
        ubicacion = _ubicacion;
    }

    int getExistencias(){
        return existencias;
    }

    string getCat(){
        return categoria;
    }

    string getUbicacion(){
        return ubicacion;
    }
};

struct listaDoble{
    //Pointer section
    articulo* primerNodo;
    articulo* ultimoNodo;

    //Builder

    listaDoble(){
        primerNodo = ultimoNodo = NULL;
    }

    //inserta un articulo al final de la lista doble
    //aka mete varas en la bodega
    void insertar(articulo* nuevo){
        if(primerNodo == NULL){
            primerNodo = ultimoNodo = nuevo;
        }
        else{
            articulo* actual = primerNodo;
            while(actual->siguiente!=NULL){
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
            nuevo->anterior = actual;
        }
    }

    //Metodo para ver si ya el articulo existe en la lista doble
    /*Esto sirve para ver si esta repetido a la hora de cargar en memoria
o para ver si existe cuando se procesa un pedido*/
    bool exists(string _codigo){
        articulo* actual = primerNodo;
        while(actual->siguiente!=NULL){
            if(actual->codigo == _codigo){
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }

    //Metodo para ver si hay suficientes existencias de un producto en bodega
    bool suficiente(string _codigo, int cantidad){
        articulo* actual = primerNodo;
        while(actual->siguiente!=NULL){
            if(actual->codigo == _codigo){ //se que se puede un and pero tengo pereza
                if (actual->getExistencias() >= cantidad){
                    return true;
                }
            }
            actual = actual->siguiente;
        }
        return false;
    }

    bool ubicacionOcupada(string _ubicacion){
        articulo* actual = primerNodo;
        while(actual->siguiente!=NULL){
            if(actual->getUbicacion() == _ubicacion){
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }

    void cargar(){
        ifstream archivo("../Articulos.txt");
        if (!archivo.is_open()) {
            cerr << "No se pudo abrir el archivo Articulos.txt" << endl;
            return;
        }
        string linea;
        while (getline(archivo, linea)) {
            // Separar la línea en campos usando el tabulador como separador
            size_t pos1 = 0;
            size_t pos2 = linea.find('\t', pos1);
            string codigo = linea.substr(pos1, pos2 - pos1);
            pos1 = pos2 + 1;
            pos2 = linea.find('\t', pos1);
            string cantidad = linea.substr(pos1, pos2 - pos1); //Esta
            pos1 = pos2 + 1;
            pos2 = linea.find('\t', pos1);
            string tiempo = linea.substr(pos1, pos2 - pos1); //Esta
            pos1 = pos2 + 1;
            pos2 = linea.find('\t', pos1);
            string categoria = linea.substr(pos1, pos2-pos1);
            pos1 = pos2 + 1;
            string ubicacion = linea.substr(pos1);

            //Tratar de convertir a enteros
            if(isInt(cantidad)){
                int cantidadAlm = stoi(cantidad);
            }else{
                //Aqui tira el error y croma todo
            }
        }
    }
};

#endif // ARTICULOS_H
