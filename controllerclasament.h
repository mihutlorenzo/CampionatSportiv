#ifndef CONTROLLERCLASAMENT_H
#define CONTROLLERCLASAMENT_H

#include <QSqlRelationalTableModel>
#include "clasament.h"
#include "QSqlDatabase"
#include "mainwindow.h"
class Clasament;

class ControllerClasament
{
public:
    ControllerClasament(MainWindow& main,QSqlDatabase& dataBase);
    void addDataInClasament();
    QSqlRelationalTableModel* getModels();
    void selectQuery();

private:
    Clasament *m_clasamentModel;
};

#endif // CONTROLLERCLASAMENT_H
