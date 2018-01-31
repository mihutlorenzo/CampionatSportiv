#include "controllerclasament.h"

ControllerClasament::ControllerClasament(MainWindow& main,QSqlDatabase& dataBase)
{
    m_clasamentModel = new Clasament(main,dataBase);
}

void ControllerClasament::addDataInClasament()
{

}

QSqlRelationalTableModel* ControllerClasament::getModels()
{
    return m_clasamentModel->getClasamentTable();
}

void ControllerClasament::selectQuery()
{
    m_clasamentModel->selectQuery();
}
