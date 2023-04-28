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

private slots:
    void on_B_FabricaComodin_clicked();

    void on_B_ColaPedidos_clicked();

    void on_B_ColaFacturacion_clicked();

    void on_B_ColaAlistados_clicked();

    void on_B_ColaAlisto_clicked();

    void on_B_FabricaC_clicked();

    void on_B_FabricaB_clicked();

    void on_B_FabricaA_clicked();

    void on_B_Balanceador_clicked();

    void on_B_Alistadores_clicked();

private:
    Ui::Proyecto_ED *ui;
};

#endif // PROYECTO_ED_H
