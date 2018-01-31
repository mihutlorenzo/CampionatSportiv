#ifndef CONTROLLERORGANIZATION_H
#define CONTROLLERORGANIZATION_H

#include <QSqlTableModel>
#include "organisation.h"
#include "addorganizationdialog.h"
#include "mainwindow.h"


class Organisation;
class AddOrganizationDialog;

class ControllerOrganization
{
public:
    explicit ControllerOrganization(MainWindow& main,QSqlDatabase& dataBase);

    void addOrganization();
    QSqlTableModel* getModels();
    void deleteOrganization(QModelIndex &index);
    void selectQuery();

private:
     Organisation *m_organizationModel;
     AddOrganizationDialog *m_addOrganizationDialog;
};

#endif // CONTROLLERORGANIZATION_H
