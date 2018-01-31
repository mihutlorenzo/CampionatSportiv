#ifndef CONTROLLERETAPA_H
#define CONTROLLERETAPA_H

#include "etapa.h"
#include <QSqlTableModel>
#include "mainwindow.h"

class Etapa;

class ControllerEtapa
{
public:
    explicit ControllerEtapa(MainWindow& main,QSqlDatabase& dataBase);

    void addEtapa();
    QSqlTableModel* getModels();
    void selectQuery();

private:
     Etapa *m_etapa;
};

#endif // CONTROLLERETAPA_H
