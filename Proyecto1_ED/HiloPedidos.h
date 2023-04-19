
#ifndef HILOPEDIDOS_H
#define HILOPEDIDOS_H
#include <QThread>

#include <filesystem> //https://en.cppreference.com/w/cpp/filesystem/directory_iterator
#include <iostream>
#include <string>
#include <fstream>

class FileRead : public QThread
{
    void run() override{
        while (true){
            //std::cout<<"Inicia lectura" <<std::endl;
            std::filesystem::path directory_path("../pedidos");
            for (const auto& entry : std::filesystem::directory_iterator(directory_path)) {
                QThread::sleep(5); /*El numero se modifica por la cantidad de segundos que se quiera
                esperar antes de leer de nuevo */
                if (entry.is_regular_file()) {
                    //Aqui pregunto si el archivo ya fue procesado (esto en basi a su nombre)
                    std::ifstream file(entry.path());

                    if (file.is_open()) {
                        /*aqui lo tira a validar que este correcto
                        Se espera un booleano, si da true, se agrega a la lista de procesados
                        Si no, se tira el error y se maneja lo que se debe hacer */

                        //bool archivoValido = procesarArchivo(file);
                        /*if(archivoValido){
                           //aqui se envia a procesar al balanceador
                            //aqui se agrega el nombre del archivo a una lista de procesados
                            //para que no se vuelva a leer luego
                        }
                        else{
                            //procesar el error, annadir su descripcion y pasarlo a la carpeta de fallidos
                        }
                        */
                    }
                }
            }
        }
    }
};

#endif // HILOPEDIDOS_H
