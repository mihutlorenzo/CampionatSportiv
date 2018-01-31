#include "controlleretapa.h"

ControllerEtapa::ControllerEtapa(MainWindow& main,QSqlDatabase& dataBase)
{
    m_etapa= new Etapa(main,dataBase);
    //m_addEtapaDialog = new AddEtapaDialog(&main);
}

void ControllerEtapa::addEtapa()
{


}

QSqlTableModel* ControllerEtapa::getModels()
{
    return m_etapa->getEtapaModel();
}


//void ControllerExperienceCategory::deleteExperienceCategory(QModelIndex &index)
//{
//    m_experienceCategory->removeExperienceCategory(index);
//}

void ControllerEtapa::selectQuery()
{
    m_etapa->selectQuery();
}
