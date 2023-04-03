
#include "proyecto_ed.h"
#include "./ui_proyecto_ed.h"


Proyecto_ED::Proyecto_ED(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Proyecto_ED)
{
    ui->setupUi(this);
}

Proyecto_ED::~Proyecto_ED()
{
    delete ui;
}


