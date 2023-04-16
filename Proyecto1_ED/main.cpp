#include "includes.h"
#include "CargarClientesMemoria.h"
#include "SubirAMemoriaArticulos.h"


int main(int argc, char *argv[])
{
    //Se muestra la ventana con la interfaz gráfica
    QApplication a(argc, argv);
    Proyecto_ED w;
    w.show();

    //Cargar CLientes Memoria.h
    list<Cliente> listaClientes;
    LeerClientes(listaClientes);
    cout<<"hola"<<endl;

    //Subir a Memoria Articulos.h
    list<Articulo> articulos;
    subirArticulos(articulos);

    // Imprimir la lista de artículos del txt
    for (const auto& articulo : articulos) {
        cout << articulo.codigo << '\t' << articulo.cantidad << '\t'
             << articulo.tiempo << '\t' << articulo.categoria << '\t'
             << articulo.ubicacion << endl;
    }

    return a.exec();

}
