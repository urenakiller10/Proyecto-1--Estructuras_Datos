#ifndef PROYECTO_ED_H
#define PROYECTO_ED_H

#include "includes.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Proyecto_ED; }
QT_END_NAMESPACE

class Proyecto_ED : public QMainWindow

{
    Q_OBJECT

public:
    Proyecto_ED(QWidget *parent = nullptr);
    ~Proyecto_ED();

private:
    Ui::Proyecto_ED *ui;
};

#endif // PROYECTO_ED_H
