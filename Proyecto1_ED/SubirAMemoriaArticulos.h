#ifndef SUBIRAMEMORIAARTICULOS_H
#define SUBIRAMEMORIAARTICULOS_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

struct Articulo {

    string codigo;
    int cantidad;
    int tiempo;
    char categoria;
    string ubicacion;

    //Punteros
    Articulo* siguiente;
    Articulo* anterior;

    Articulo(string codigo, int cantidad, int tiempo, char categoria, string ubicacion) :
        codigo(codigo), cantidad(cantidad), tiempo(tiempo), categoria(categoria), ubicacion(ubicacion),
        siguiente(nullptr), anterior(nullptr) {}

    string toString(){}

    std::string to_String() const {
        std::ostringstream oss;
        oss << "Código: " << codigo << " ";
        oss << "Cantidad: " << cantidad << " ";
        oss << "Tiempo: " << tiempo << " ";
        oss << "Categoría: " << categoria << " ";
        oss << "Ubicación: " << ubicacion << " ";
        return oss.str();

    }

    void imprimir(){}

};

void subirArticulos(list<Articulo*>& articulos) {
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

        // Crear el artículo y agregarlo a la lista
        Articulo* articulo = new Articulo(codigo, cantidad, tiempo, categoria, ubicacion);
        if (!articulos.empty()) {
            articulos.back()->siguiente = articulo;
            articulo->anterior = articulos.back();
        }
        articulos.push_back(articulo);
    }
    archivo.close();
}

void repetidos(list<Articulo*>& articulos) {
    for (Articulo* a1 : articulos) {
        for (Articulo* a2 : articulos) {
            if (a1 == a2) {
                continue;
            }
            if (a1->codigo == a2->codigo) {
                cout << "Artículos repetidos: " << a1->codigo << endl;
                    return;
            }
        }
    }
}



#endif SUBIRAMEMORIAARTICULOS_H
