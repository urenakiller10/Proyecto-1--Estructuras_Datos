
#ifndef COLAALISTADOS_H
#define COLAALISTADOS_H

#include <queue>
#include <string>

class colaAlistados {
public:
    colaAlistados();
    ~colaAlistados();

    void agregarAlista(std::string elemento);

private:
    std::queue<std::string> listaAlistados;
};

colaAlistados::colaAlistados() {}
colaAlistados::~colaAlistados() {}

void colaAlistados::agregarAlista(std::string elemento) {
    listaAlistados.push(elemento);
}

#endif // COLAALISTADOS_H
