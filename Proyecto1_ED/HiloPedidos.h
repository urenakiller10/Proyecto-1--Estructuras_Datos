
#ifndef HILOPEDIDOS_H
#define HILOPEDIDOS_H
#include <QThread>
#include "timeStamp.h"
#include "BalanceadorDecisiones.h"

#include <filesystem> //https://en.cppreference.com/w/cpp/filesystem/directory_iterator
#include <iostream>
#include <string>
#include <fstream>

class FileRead : public QThread

{
    void run() override{
        cout << "Cuantas veces voy a ver esta linea" << endl;
        //En este punto puedo tirar lo que sea una sola vez xd
        while (true){
            std::filesystem::path directory_path("../pedidos");

            for (const auto& entry : std::filesystem::directory_iterator(directory_path)) {
                QThread::sleep(5); /*El numero se modifica por la cantidad de segundos que se quiera
                esperar antes de leer de nuevo */
                if (entry.is_regular_file()) {
                    //Aqui pregunto si el archivo ya fue procesado (esto en basi a su nombre)
                    std::ifstream file(entry.path());

                    string ruta = entry.path().string(); //Preparo la ruta como string si hay que mover xd
                    const char* rutaC = ruta.c_str();
                    const char* nombreArchivo = strrchr(rutaC, '\\');
                    string nombre = string(nombreArchivo).erase(0,1);
                    cout << "ARCHIVO ACTUAL: " <<nombre <<endl;
                    string nuevaRuta = "..\\malos\\" + nombre;

                    if (file.is_open()) {
                        string line;

                        //leer cada linea del archivo actual
                        while (getline(file, line)) { //Cada linea es un pedido
                            list<string> lista;
                            size_t pos = 0;
                            string delimiter = "\t";
                            string token;

                            while ((pos = line.find(delimiter)) != string::npos) {
                                token = line.substr(0, pos);
                                lista.push_back(token);
                                line.erase(0, pos + delimiter.length());
                            }
                            lista.push_back(line);

                            //Primera verificacion, cantidad de parametros correcta
                            //std::cout << lista.size() << std::endl;
                            if (lista.size() != 4){
                                std::cout<<"ERROR EN CANTIDAD DE PARAMETROS" <<std::endl;
                                ofstream archivoMalo(entry.path(),ofstream::app);
                                archivoMalo << "\n" << getTimeDate(false) << " " <<"ERROR EN CANTIDAD DE PARAMETROS";

                                //Aqui se mueve el archivo
                                archivoMalo.close();
                                break;
                            }
                            else {
                                //std::cout<< "Cantidad nice" <<std::endl;
                            }
                            //cout << lista <<endl;
                            list<string>::iterator it = lista.begin();


                            //Segunda verificacion
                            //Verificar que el numero de pedido sea entero

                            try {
                                int num = stoi(*it);
                                if(num < 0){
                                    cout << "ERROR, NUMERO DE PEDIDO NO PUEDE SER NEGATIVO";
                                    ofstream archivoMalo(entry.path(),ofstream::app);
                                    archivoMalo << "\n" << getTimeDate(false) << " " <<"ERROR, NUMERO DE PEDIDO NO PUEDE SER NEGATIVO";

                                    //Aqui se mueve el archivo
                                    archivoMalo.close();
                                    break;
                                }
                                else{
                                    //Piola :D
                                }
                            } catch (...) {
                                ofstream archivoMalo(entry.path(),ofstream::app);
                                archivoMalo << "\n" << getTimeDate(false) << " " <<"ERROR, NUMERO DE PEDIDO INVALIDO";

                                //Aqui se mueve el archivo
                                archivoMalo.close();
                                break;
                                cout << "ERROR, NUMERO DE PEDIDO INVALIDO";
                            }

                            //Tercera verificacion
                            //Verificar que el codigo de cliente exista en memoria
                            advance(it,1);


                            //archivoMalo << "\n" << getTimeDate(false) << " " <<"ERROR, CLIENTE NO EXISTENTE";


                            //Cuarta verificacion
                            //Verificar que el codigo de producto exista
                            advance(it,1);
                            //archivoMalo << "\n" << getTimeDate(false) << " " <<"ERROR, PRODUCTO NO EXISTENTE";

                            //Quinta verificacion
                            //Verificar que sea un entero y mayor a 0
                            advance(it,1);
                            try {
                                int num = stoi(*it);
                                if(num < 0){
                                    cout << "ERROR, LA CANTIDAD DE PRODUCTO NO PUEDE SER NEGATIVA";
                                    ofstream archivoMalo(entry.path(),ofstream::app);
                                    archivoMalo << "\n" << getTimeDate(false) << " " <<"ERROR, LA CANTIDAD DE PRODUCTO NO PUEDE SER NEGATIVA";

                                    //Aqui se mueve el archivo
                                    archivoMalo.close();
                                    break;
                                }
                                else{
                                    //Piola :D
                                }
                            } catch (...) {
                                ofstream archivoMalo(entry.path(),ofstream::app);
                                archivoMalo << "\n" << getTimeDate(false) << " " <<"ERROR, CANTIDAD DE PRODUCTO NO ES UN NUMERO";

                                //Aqui se mueve el archivo
                                archivoMalo.close();
                                break;
                                cout << "ERROR, CANTIDAD DE PRODUCTO NO ES UN NUMERO";
                            }
                            //archivoMalo << "\n" << getTimeDate(false) << " " <<"ERROR, CANTIDAD SOLICITADA INVALIDA";
                            cout << "LINEA PASO TODO " <<endl;
                        }
                    }
                    //procesar(std::ifstream(entry.path()));
                    cout << "ARCHIVO PASO TODO -> PROCEDE A ENVIAR AL BALANCEADOR"<<endl;


                }
            }
        }
    }
};



#endif // HILOPEDIDOS_H
