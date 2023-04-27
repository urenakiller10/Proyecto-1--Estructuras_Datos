#include "includes.h"
#ifndef AUXILIARIES_H
#define AUXILIARIES_H

//retonar -1 si falla
bool isInt(string cadena){

    try {
        int n = stoi(cadena);
    }
    catch (...) {return false;}
    return true;
}





#endif // AUXILIARIES_H
