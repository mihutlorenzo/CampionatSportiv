#include "controlleretapa.h"

ControllerEtapa::ControllerEtapa(MainWindow& main,QSqlDatabase& dataBase)
{
    m_etapa= new Etapa(main,dataBase);

}

void ControllerEtapa::addEtapa()
{


}

QSqlTableModel* ControllerEtapa::getModels()
{
    return m_etapa->getEtapaModel();
}


void ControllerEtapa::selectQuery()
{
    m_etapa->selectQuery();
}
