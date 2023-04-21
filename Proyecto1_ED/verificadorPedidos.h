#include "includes.h"
#include <list>
#ifndef VERIFICADORPEDIDOS_H
#define VERIFICADORPEDIDOS_H

bool pedidoValido(ifstream file){

    if (file.is_open()) {
        string line;
        while (getline(file, line)) { //Cada linea es un pedido
            list<string> lista;
            size_t pos = 0;
            string delimiter = ",";
            string token;

            while ((pos = line.find(delimiter)) != string::npos) {
                token = line.substr(0, pos);
                lista.push_back(token);
                line.erase(0, pos + delimiter.length());
            }
            lista.push_back(line);
            for (auto it = lista.begin(); it != lista.end(); ++it) {
                std::cout <<"[" <<*it << "]";
            }
        }

    }


    return true;
}



#endif // VERIFICADORPEDIDOS_H
/*
            //intentar convertir a int
            try {
                nPedido = stoi(numPedido);
            } catch (...) {
                cout << "Bad number";
                //Enviar al error
            }
1 898

*/
