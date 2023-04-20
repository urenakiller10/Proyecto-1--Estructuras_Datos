
#ifndef COLADEALISTO_H
#define COLADEALISTO_H

#include <queue>

class ColaAlisto {
public:

    //Nos va a funcionar para agregar a la cola un elemento

    void agregarElemento(int elemento) {
        cola.push(elemento);
    }

    //Ojo con esta, nos va a servir para recuperar y procesar(ir pasando a la bodega de alisto) los elementos en el orden que se fueron agregando a la cola
    int obtenerProximoElemento() {
        int elemento = cola.front();
        cola.pop();
        return elemento;
    }

    bool estaVacia() {
        return cola.empty();
    }

private:
    std::queue<int> cola;
};

#endif // COLADEALISTO_H
