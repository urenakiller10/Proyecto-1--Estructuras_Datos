
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
                    std::ifstream file(entry.path());

                    if (file.is_open()) {
                        //std::cout << "Contenido de " << entry.path().filename() << ":" << std::endl;

                        std::string line;
                        while (std::getline(file, line)) {
                            std::cout << line << std::endl;
                        }

                        std::cout << std::endl;
                    }
                }
        }
        }
    }
};

#endif // HILOPEDIDOS_H