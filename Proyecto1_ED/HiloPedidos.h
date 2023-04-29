
#ifndef HILOPEDIDOS_H
#define HILOPEDIDOS_H
#include <QThread>
#include "timeStamp.h"
#include "BalanceadorDecisiones.h"
#include "CargarClientesMemoria.h"
#include "articulos.h"
#include "auxiliaries.h"
#include "pedidos.h"

#include <filesystem> //https://en.cppreference.com/w/cpp/filesystem/directory_iterator
#include <iostream>
#include <string>
#include <fstream>

struct nodoArc;
struct listaProcesados;

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
        listaProcesados* listaProc;
        int contadorLineas = 0; //Declaracion y un valor para evitar faults
        int numPedido = 0;
        int numCliente;
        while (true){
            for(const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
                if(entry.is_regular_file()){
                    ifstream file = (entry.path());
                    string rutaActual = entry.path().string();
                    contadorLineas = 0; //Se reinicia el counter por cada archivo
                    if(!listaProc->procesado(rutaActual)){ //Si el archivo no se ha procesado, haga
                        cout << "Leyendo: " << rutaActual << endl;
                        if(file.is_open()){
                            string line;
                            while(getline(file, line)){

                                //Primer linea, numero de pedido
                                if(contadorLineas == 0){
                                    if(!isInt(line)){
                                        continue;
                                        //Error de que el num de pedido no es int
                                    }
                                    else{
                                        numPedido = stoi(line);
                                    }
                                }
                                //Segunda linea, cod de cliente
                                else if (contadorLineas == 1){
                                    if(isInt(line)){
                                        bool existe = clientes.existeCodigo(stoi(line));
                                        if(!existe){
                                            //Error de no existe
                                            continue;
                                        }
                                        else{
                                            numCliente = stoi(line);
                                        }
                                    }
                                    else{
                                        //Error de codigo
                                        continue;
                                    }
                                }
                                //Todas las lineas que vengan debajo, las cuales se suponen son ya los pedidos
                                else{
                                    size_t pos1 = 0;
                                    size_t pos2 = line.find('\t', pos1);
                                    string codigoP = line.substr(pos1, pos2-pos1);
                                    pos1 = pos2 + 1;
                                    pos2 = line.find('\t', pos1);
                                    string cantidad = line.substr(pos1, pos2-pos1);

                                    //cout << "Codigo: " << codigoP << " Cantidad: " << cantidad <<endl;

                                    //revisa que el producto exista
                                    if(!articulos.exists(codigoP)){
                                        //Tira la vara a errores
                                        cout << "Mae la vara no existe" <<endl;
                                        continue;
                                    }
                                    //revisa que la cantidad que se le paso sea entera y positiva
                                    if(!isInt(cantidad)){
                                        //Tira la vara a errores
                                        cout << "Mae no mando un entero de cantidad" <<endl;
                                        continue;
                                    }
                                    else{
                                        if(stoi(cantidad) < 0){
                                            cout << "Valor negativo" <<endl;
                                            continue;
                                        } //else no importa
                                    }

                                    //cuando ya pasa toda verificacion
                                    listaPares* lista = new listaPares();
                                    parOrdenado* par = new parOrdenado(codigoP, stoi(cantidad));
                                    lista->insertar(par);

                                }
                                contadorLineas +=1;
                            }

                            nodoArc* nodoProc = new nodoArc(rutaActual); //La ruta del archivo
                            listaProc->insertar(nodoProc);
                            //Aqui armar el pedido con toda la data
                        }
                    }
                }
            }
            QThread::sleep(5); //Valor en segundos de cada cuanto se revisa el directorio en busqueda de nuevos pedidos
        }
    }

    //struct nodo para la lista de archivos procesados
    struct nodoArc{
        string nombre;
        nodoArc* sig;
        nodoArc(string _nombre){
            nombre = _nombre;
            sig = NULL;
        }
    };

    struct listaProcesados{
        nodoArc* primerNodo = NULL; //Por si acaso
        listaProcesados(){
            primerNodo = NULL;
        }

        void insertar(nodoArc* nuevo){
            if(primerNodo==NULL){
                primerNodo = nuevo;
            }
            else{
                nodoArc* tmp = primerNodo;
                while(tmp->sig!=NULL){
                    tmp = tmp->sig;
                }
                tmp->sig = nuevo;
            }
        }

        bool procesado(string archivo){
            if(primerNodo!=NULL){
                nodoArc* tmp = primerNodo;
                while(tmp->sig!=NULL){
                    if(tmp->nombre == archivo){
                        return true;
                    }
                    tmp = tmp->sig;
                }
            }
            return false;
        }

    };

private:
    listaSimple clientes;
    listaDoble articulos;
};




#endif // HILOPEDIDOS_H
