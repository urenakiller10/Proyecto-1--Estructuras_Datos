#include "includes.h"
#ifndef TIMESTAMP_H
#define TIMESTAMP_H
string getTimeDate(bool archive){

    int tamanno = 80;
    char buffer [tamanno] = {0}; //Este array se puede reducir en daño, pero para evitar petadas no moverle
    //NO MOVER NADA DE ACA; SOLO DIOS SABE COMO SIRVE
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    //FIN DE LA ZONA DE PELIGRO

    // CheatGuide de los flags: https://cplusplus.com/reference/ctime/strftime/
    strftime (buffer,tamanno,"%c",timeinfo);
    std::string s = buffer; //String temporal a la que le cae lo del buffer para formatearlo

    //Caso en que el string se necesite para renombrar un archivo
    if (archive){
        //Te recontra amo expresiones regulares
        string output = regex_replace(s, regex("\\/"), "-"); //Cambia los / por - ;A Bill Gates no le gustaba
        output = regex_replace(output, regex("\\:"), "_"); //Cambia los : por _ ;A Bill Gates no le gustaba
        //Linea para poner el debuger sobre lo que va a devolver la funcion, por si croma

        return output;
    }
    else{
        return s;
    }
}
#endif
