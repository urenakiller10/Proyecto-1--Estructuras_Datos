
#ifndef CARGARCLIENTESMEMORIA_H
#define CARGARCLIENTESMEMORIA_H

#include <fstream>
#include <iostream>
#include <list>
using namespace std;
struct cliente;
struct listaSimple;

struct Cliente {
    //Data section
    int codigo;
    string nombre;
    int prioridad;

    //Pointer section
    Cliente* siguiente;

    //Builder
    Cliente(int _codigo, string _nombre, int _prioridad){
        codigo = _codigo;
        nombre = _nombre;
        prioridad = _prioridad;
        siguiente = NULL;
    }

    Cliente(){}

    void imprimir(){
        cout << "Codigo: " << codigo << " .Nombre: " << nombre << " .Prioridad: " << prioridad <<endl;
    }

};

struct listaSimple{
    //Pointer section
    Cliente* primerCliente;

    //Builder
    listaSimple(){
        primerCliente = NULL;
    }

    //Functions

    void insertar(Cliente* cliente){
        if (primerCliente == NULL){
            primerCliente = cliente;
        }
        else{
            Cliente* ultimo = primerCliente;
            while(ultimo->siguiente != NULL){
                ultimo = ultimo->siguiente;
            }
            ultimo->siguiente = cliente;
        }
    }

    void imprimir(){
        if(largo() == 0){
            return;
        }
        Cliente* tmp = primerCliente;
        if(tmp == NULL){
            cout << "LLEGO NULL" <<endl;
        }

        while(tmp->siguiente != NULL){
            cout << "Llego aca2" <<endl;
            tmp->imprimir();
            tmp = tmp->siguiente;
        }
    }

    bool existeCodigo(int code){
        Cliente* tmp = primerCliente;
        while(tmp->siguiente != NULL){
            if(tmp->codigo == code){
                return true;
            }
            tmp = tmp->siguiente;
        }
        return false;
    }

    int largo(){
        Cliente* tmp = primerCliente;
        int contador = 0;
        while(tmp->siguiente != NULL){
            tmp = tmp->siguiente;
            contador += 1;
        }
        return contador;
    }

    void LeerClientes(){
        ifstream archivo("../Clientes.txt");
        if(!archivo){
            cout << "No se pudo abrir clientes";
            return;
        }

        string linea;
        while (getline(archivo, linea)){
            size_t pos1 = 0;
            size_t pos2 = linea.find('\t', pos1);
            string codigo = linea.substr(pos1, pos2 - pos1);
            pos1 = pos2 + 1;
            pos2 = linea.find('\t', pos1);
            string nombre = linea.substr(pos1, pos2 - pos1);
            pos1 = pos2 + 1;
            string prio = linea.substr(pos1);

            Cliente* nuevo = new Cliente(stoi(codigo), nombre, stoi(prio));
            insertar(nuevo);
        }
    }

};


/*
void LeerClientes(list<Cliente>& listaClientes) {
    ifstream archivo("../Clientes.txt");
    if (!archivo) {
        cout << "Error al abrir el archivo clientes\n";
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        Cliente cliente;
        istringstream iss(linea);
        iss >> cliente.codigo;
        iss.ignore();
        getline(iss, cliente.nombre, '\t');
        iss >> cliente.prioridad;
        listaClientes.push_back(cliente);
    }

    archivo.close();
}
*/
#endif // CARGARCLIENTESMEMORIA_H
