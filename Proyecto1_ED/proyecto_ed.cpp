#include "includes.h"



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


