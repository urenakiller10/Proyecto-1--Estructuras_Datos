
#include "proyecto_ed.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Proyecto_ED w;
    w.show();
    return a.exec();
}
