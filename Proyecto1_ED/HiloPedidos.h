
#ifndef HILOPEDIDOS_H
#define HILOPEDIDOS_H
#include <QThread>
#include "verificadorPedidos.h"
#include "timeStamp.h"

#include <filesystem> //https://en.cppreference.com/w/cpp/filesystem/directory_iterator
#include <iostream>
#include <string>
#include <fstream>

class FileRead : public QThread
{
    void run() override{
        while (true){
            std::cout<<"Inicia lectura" <<std::endl;
            std::filesystem::path directory_path("../pedidos");
            for (const auto& entry : std::filesystem::directory_iterator(directory_path)) {
                QThread::sleep(5); /*El numero se modifica por la cantidad de segundos que se quiera
                esperar antes de leer de nuevo */
                if (entry.is_regular_file()) {
                    //Aqui pregunto si el archivo ya fue procesado (esto en basi a su nombre)
                    std::ifstream file(entry.path());

                    if (file.is_open()) {
                        string line;
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
                                string momento = getTimeDate();
                                archivoMalo << "\n" << momento << " " <<"ERROR EN CANTIDAD DE PARAMETROS";
                                archivoMalo.close();
                                //Aqui se mueve el archivo
                            }
                            else {
                                std::cout<< "Cantidad nice" <<std::endl;
                            }
                        }
                        //Segunda verificacion


                    }
                }
            }
        }
    }
};

#endif // HILOPEDIDOS_H
