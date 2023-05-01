
#ifndef HILOPEDIDOS_H
#define HILOPEDIDOS_H
#include <QThread>
#include "timeStamp.h"
#include "BalanceadorDecisiones.h"
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

struct nodoArc;
struct listaProcesados;


class FileRead : public QThread
{
public:

    //Builder
    FileRead(listaSimple clientes, listaDoble articulos, colaPedidos* _colaPed, QMutex* mutex){
        this->clientes = clientes;
        this->articulos = articulos;
        this->colaPed = _colaPed;
        this->mutex = mutex;
    }


    void run() override{
        //En este punto puedo tirar lo que sea una sola vez xd
        //cout << "Arranca el hilo de lectura de pedidos" << endl;
        filesystem::path directoryPath("../pedidos");
        listaProcesados* listaProc = new listaProcesados;
        int contadorLineas = 0; //Declaracion y un valor para evitar faults
        int numPedido = 0;
        int numCliente;
        while (true){
            //cout << "Leyendo pedidos" <<endl;
            for(const auto& entry : filesystem::directory_iterator(directoryPath)) {
                if(entry.is_regular_file()){

                    ifstream file = (entry.path());
                    string rutaActual = entry.path().string();
                    string r = rutaActual;

                    contadorLineas = 0; //Se reinicia el counter por cada archivo
                    if(!listaProc->procesado(rutaActual)){ //Si el archivo no se ha procesado, haga
                        //cout << "Leyendo: " << rutaActual << endl;
                        //cout << "Nombre archivo: " << getFileName(rutaActual) <<endl;

                        if(file.is_open()){
                            string line;
                            listaPares* lista = new listaPares();
                            while(getline(file, line)){

                                //Primer linea, numero de pedido
                                if(contadorLineas == 0){
                                    if(!isInt(line)){
                                        //Meta lo que ocupa al archivo
                                        file.close();
                                        ofstream archivoMalo(entry.path(),ofstream::app);
                                        archivoMalo << "\n" << getTimeDate(false) << " " <<"El numero de pedido no es un valor entero";
                                        //Cierre el archivo
                                        archivoMalo.close();
                                        //Invoque a mover
                                        moverArchivos(getFileName(r));
                                        break;
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
                                            file.close();
                                            ofstream archivoMalo(entry.path(),ofstream::app);
                                            archivoMalo << "\n" << getTimeDate(false) << " " <<"El numero de cliente no existe";
                                            //Cierre el archivo
                                            archivoMalo.close();
                                            //Invoque a mover
                                            moverArchivos(getFileName(r));
                                            break;
                                        }
                                        else{
                                            numCliente = stoi(line);
                                        }
                                    }
                                    else{
                                        //Error de codigo
                                        file.close();
                                        ofstream archivoMalo(entry.path(),ofstream::app);
                                        archivoMalo << "\n" << getTimeDate(false) << " " <<"El numero de cliente no es un entero";
                                        //Cierre el archivo
                                        archivoMalo.close();
                                        //Invoque a mover
                                        moverArchivos(getFileName(r));
                                        break;
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
                                        file.close();
                                        ofstream archivoMalo(entry.path(),ofstream::app);
                                        archivoMalo << "\n" << getTimeDate(false) << " " <<"El codigo de producto "<< codigoP << " no existe";
                                        //Cierre el archivo
                                        archivoMalo.close();
                                        //Invoque a mover
                                        moverArchivos(getFileName(r));
                                        break;
                                    }
                                    //revisa que la cantidad que se le paso sea entera y positiva
                                    if(!isInt(cantidad)){
                                        //Tira la vara a errores
                                        cout << "Mae no mando un entero de cantidad" <<endl;
                                        file.close();
                                        ofstream archivoMalo(entry.path(),ofstream::app);
                                        archivoMalo << "\n" << getTimeDate(false) << " " <<"La cantidad del producto no es entero";
                                        //Cierre el archivo
                                        archivoMalo.close();
                                        //Invoque a mover
                                        moverArchivos(getFileName(r));
                                        break;
                                    }
                                    else{
                                        if(stoi(cantidad) < 0){
                                            cout << "Valor negativo" <<endl;
                                            file.close();
                                            ofstream archivoMalo(entry.path(),ofstream::app);
                                            archivoMalo << "\n" << getTimeDate(false) << " " <<"La cantidad del producto es negativa";
                                            //Cierre el archivo
                                            archivoMalo.close();
                                            //Invoque a mover
                                            moverArchivos(getFileName(r));
                                            break;
                                        } //else no importa
                                    }

                                    //cuando ya pasa toda verificacion

                                    parOrdenado* par = new parOrdenado(codigoP, stoi(cantidad));
                                    lista->insertar(par);

                                }
                                contadorLineas +=1;
                            }

                            nodoArc* nodoProc = new nodoArc(r); //La ruta del archivo
                            listaProc->insertar(nodoProc);
                            //Aqui armar el pedido con toda la data
                            //cout << "Se va a crear el pedido" << endl;

                            mutex->lock();
                            pedido* nuevo = new pedido(numPedido, numCliente, lista);
                            colaPed->enqueue(nuevo);
                            mutex->unlock();
                        }
                    }
<<<<<<< HEAD
                    procesar(std::ifstream(entry.path()));
                    cout << "ARCHIVO PASAQ TODO -> PROCEDE A ENVIAR AL BALANCEADOR"<<endl;


=======
>>>>>>> fusion
                }
            }
            QThread::sleep(5); //Valor en segundos de cada cuanto se revisa el directorio en busqueda de nuevos pedidos
        }
    }

    //struct nodo para la lista de archivos procesados
    struct nodoArc{
        string nombre = "";
        nodoArc* sig = NULL;
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

    //Esto es la mamadelamamadelamamademama, pero se ocupa
    string getFileName(string ruta){
        const char* rutaC = ruta.c_str();
        const char* nombreArchivo = strrchr(rutaC, '\\');
        string nombre = string(nombreArchivo).erase(0,1);
        cout << "ARCHIVO ACTUAL: " <<nombre <<endl;
        return nombre;
    }

    void moverArchivos(string nombreArchivo){
        string fuente = "../Pedidos/" + nombreArchivo;
        string destino = "../malos/" + nombreArchivo;
        cout << "Fuente: " << fuente << " Destino: " << destino << endl;
        try {
            filesystem::rename(fuente, destino);
            cout << "Archivo movido exitosamente" << endl;
        } catch (...) {
            cout << "Error al mover el archivo: " << endl;
        }
    }


private:
    listaSimple clientes;
    listaDoble articulos;
    colaPedidos* colaPed;
    QMutex* mutex;
};




#endif // HILOPEDIDOS_H
