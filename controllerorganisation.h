#ifndef CONTROLLERORGANISATION_H
#define CONTROLLERORGANISATION_H

#include "organisation.h"
#include "addorganizationdialog.h"
#include <QSqlTableModel>
#include "mainwindow.h"

class Organisation;

class ControllerOrganisation
{
public:
    explicit ControllerOrganisation(MainWindow& main,QSqlDatabase& dataBase);

    void addOrganization();
    QSqlTableModel* getModels();
    void deleteOrganization(QModelIndex &index);
    void selectQuery();

private:
     Organisation *m_organization;
     AddOrganizationDialog *m_addOrganizationDialog;
};

#endif // CONTROLLERORGANISATION_H
