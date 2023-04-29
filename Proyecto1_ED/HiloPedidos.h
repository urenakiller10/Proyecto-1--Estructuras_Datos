
#ifndef HILOPEDIDOS_H
#define HILOPEDIDOS_H
#include <QThread>
#include "timeStamp.h"
#include "BalanceadorDecisiones.h"
#include "CargarClientesMemoria.h"
#include "articulos.h"
#include "auxiliaries.h"

#include <filesystem> //https://en.cppreference.com/w/cpp/filesystem/directory_iterator
#include <iostream>
#include <string>
#include <fstream>

struct nodo;
struct listaLeidos;

class FileRead : public QThread
{
public:

    //Builder
    FileRead(listaSimple clientes, listaDoble articulos){
        this->clientes = clientes;
        this->articulos = articulos;
    }


    void run() override{
        //En este punto puedo tirar lo que sea una sola vez xd
        filesystem::path directoryPath("../pedidos");
        int contadorLineas = 0;
        while (true){
            for(const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
                if(entry.is_regular_file()){
                    ifstream file = (entry.path());
                    contadorLineas = 0;

                    if(file.is_open()){
                        string line;
                        while(getline(file, line)){

                            //Primer linea, numero de pedido
                            if(contadorLineas == 0){

                            }
                            //Segunda linea, cod de cliente
                            else if (contadorLineas == 1){
                                if(isInt(line)){
                                    bool existe = clientes.existeCodigo(stoi(line));
                                    if(!existe){
                                        //Error de no existe
                                    }
                                }
                                else{
                                    //Error de codigo
                                }
                            }

                            contadorLineas +=1;
                        }
                    }
                }
            }
            QThread::sleep(5); //Valor en segundos de cada cuanto se revisa el directorio en busqueda de nuevos pedidos
        }
    }

private:
    listaSimple clientes;
    listaDoble articulos;
};

//struct nodo para la lista de archivos procesados
struct nodo{
    string nombre;
    nodo* sig;
    nodo(string _nombre){
        nombre = _nombre;
        sig = NULL;
    }
};


#endif // HILOPEDIDOS_H
