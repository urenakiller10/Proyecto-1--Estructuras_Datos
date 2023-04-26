#ifndef SUBIRAMEMORIAARTICULOS_H
#define SUBIRAMEMORIAARTICULOS_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

struct Articulo;

struct Articulo {
    //Data section
    string codigo;
    int cantidad;
    int tiempo;
    char categoria;
    string ubicacion;

    //Pointer section
    Articulo* siguiente;

    //Builder
    Articulo(string _codigo, int _cantidad, int _tiempo, char _categoria, string _ubicacion){
        codigo = _codigo;
        cantidad = _cantidad;
        tiempo = _tiempo;
        categoria = _categoria;
        ubicacion = _ubicacion;
        siguiente = NULL;

    }
    void imprimir(){
        cout << "Codigo: " << codigo << " Cantidad: " << cantidad << " Tiempo: " << tiempo << " Categoria: " << categoria << endl;
    }

    string toString(){
        return "Codigo: " + codigo + " Cantidad: " + to_string(cantidad) + " Tiempo: " + to_string(tiempo) + " Categoria" + categoria;
    }

};

/*
struct listaSimple{
    //Pointer section
    Articulo* primerNodo;

//Builders
    listaSimple(){
        primerNodo = NULL;
    }

    //Functions

    void insertar(Articulo* nuevo){

        if (primerNodo == NULL){
            primerNodo = nuevo;
        }
        else{
            Articulo* ultimo = primerNodo;
            while(ultimo->siguiente != NULL){
                ultimo = ultimo->siguiente;
            }
            ultimo->siguiente = nuevo;
        }
    }

    void imprimir(){
        Articulo* tmp = primerNodo;
        while(tmp->siguiente != NULL){
            tmp->imprimir();
        }
    }

    bool esta(){
        Articulo* tmp = primerNodo;
        return false;
    }

};
*/

void subirArticulos(list<Articulo>& articulos) {
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
        int cantidad = stoi(linea.substr(pos1, pos2 - pos1)); //Ojo con estas lineas, el stoi se puede caer
        pos1 = pos2 + 1;
        pos2 = linea.find('\t', pos1);
        int tiempo = stoi(linea.substr(pos1, pos2 - pos1));
        pos1 = pos2 + 1;
        pos2 = linea.find('\t', pos1);
        char categoria = linea[pos1];
        pos1 = pos2 + 1;
        string ubicacion = linea.substr(pos1);

        // Verificar que los datos sean válidos
        if (cantidad == 0 || tiempo == 0 || (categoria != 'A' && categoria != 'B' && categoria != 'C')) {
            cerr << "Error en la línea: " << linea << endl;
                continue;
        }

        // Verificar que no haya artículos repetidos
        bool encontrado = false;
        for (const auto& articulo : articulos) {
            if (articulo.codigo == codigo) {
                cerr << "Error: artículo repetido: " << codigo << endl;
                        encontrado = true;
                break;
            }
        }
        if (encontrado) {
            continue;
        }

        // Crear el artículo y agregarlo a la lista
        Articulo articulo = {codigo, cantidad, tiempo, categoria, ubicacion};
        articulos.push_back(articulo);
    }
    archivo.close();
}
#endif // SUBIRAMEMORIAARTICULOS_H
