
#ifndef CALCULARTIEMPO_H
#define CALCULARTIEMPO_H
#include <iostream>
#include <string>
using namespace std;
//se recibe CXX
//A = 65, maybe se resta 64?)
int tiempo(string ubicacion) {
    //string str = "A02"; //Lugar de la bodega, se pasa por parametro
    string cNum = ubicacion.substr(1, 2); //Captura los dos numeros

    int cantidadX = int(ubicacion[0]) - 64; //Diferencia entre el caracter leido y el del "A" en la tabla ascii
    cout << cantidadX <<endl; //Impresion de prueba
    int cantidadY = stoi(cNum); //Convierte los dos string numericos a int
    cout << cantidadY <<endl; //Impresion de prueba

    int segundosMovimiento = ((cantidadX + cantidadY)  * 2);
    segundosMovimiento = segundosMovimiento - 1; //Se resta 1 porque ya se encuentra ubicado en A01
    segundosMovimiento = segundosMovimiento - 1; //Este porque para que no se cuente doble cuando llega al destino
    segundosMovimiento = segundosMovimiento - 1; //Se resta uno del eje Y ya que se encuentra inicialmente en Y=1
    cout << "Tiempo total de movimiento " << segundosMovimiento;

    return segundosMovimiento;
}
#endif // CALCULARTIEMPO_H
