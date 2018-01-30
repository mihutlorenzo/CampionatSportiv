#include "controllerorganisation.h"

ControllerOrganisation::ControllerOrganisation(MainWindow& main,QSqlDatabase& dataBase)
{
    m_organization = new Organisation(main,dataBase);
    m_addOrganizationDialog = new AddOrganizationDialog(&main);
}


void ControllerOrganisation::addOrganization()
{
    int r = m_addOrganizationDialog->exec();
    if(r == QDialog::Accepted)
    {
        int ageCategoryId;
        QString name;
        m_addOrganizationDialog->dataOrganization(ageCategoryId,name);
        m_organization->addOrganisation(ageCategoryId,name);
    }
}

QSqlTableModel* ControllerOrganisation::getModels()
{
    return m_organization->getOrganisationModel();
}


void ControllerOrganisation::deleteOrganization(QModelIndex &index)
{
    m_organization->removeOrganisation(index);
}

void ControllerOrganisation::selectQuery()
{
    m_organization->selectQuery();
}
