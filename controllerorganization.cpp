#include "controllerorganization.h"

ControllerOrganization::ControllerOrganization(MainWindow& main,QSqlDatabase& dataBase)
{
    m_organizationModel= new Organisation(main,dataBase);
    m_addOrganizationDialog = new AddOrganizationDialog(&main);
}

void ControllerOrganization::addOrganization()
{
    int r = m_addOrganizationDialog->exec();
    if(r == QDialog::Accepted)
    {
        int organizationId;
        QString name;
        m_addOrganizationDialog->dataOrganization(organizationId,name);
        m_organizationModel->addOrganisation(organizationId,name);
    }
}

QSqlTableModel* ControllerOrganization::getModels()
{
    return m_organizationModel->getOrganisationModel();
}


void ControllerOrganization::deleteOrganization(QModelIndex &index)
{
    m_organizationModel->removeOrganisation(index);
}

void ControllerOrganization::selectQuery()
{
    m_organizationModel->selectQuery();
}
