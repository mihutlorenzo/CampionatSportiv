#ifndef ORGANISATION_H
#define ORGANISATION_H


#include <QSqlTableModel>
#include <mainwindow.h>

class MainWindow;
class QSqlDatabase;

class Organisation
{
public:
    explicit Organisation(MainWindow& main,QSqlDatabase& dataBase);
    ~Organisation();

    QSqlTableModel* getOrganisationModel();
    void removeOrganisation(QModelIndex &index);
    void addOrganisation(const int& id, const QString& name);
    void selectQuery();


private:
    QSqlTableModel* m_OrganisationModel;
};


#endif // ORGANISATION_H
