#include "organisation.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

Organisation::Organisation(MainWindow& main,QSqlDatabase& dataBase)
{
    m_OrganisationModel = new QSqlTableModel(&main,dataBase);
    m_OrganisationModel->setTable("Organizatie");
    m_OrganisationModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    m_OrganisationModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_Organizatie"));
    m_OrganisationModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Nume"));
    m_OrganisationModel->select();

}

Organisation::~Organisation()
{
    delete m_OrganisationModel;
}

QSqlTableModel* Organisation::getOrganisationModel()
{
    return m_OrganisationModel;
}

void Organisation::addOrganisation(const int &id, const QString &age)
{
    QSqlQuery query;
    query.prepare("insert into Organizatie values (:id,:name);");
    query.bindValue(":id", id);
    query.bindValue(":name", age);
    if(!query.exec())
    {
        qDebug() << query.lastError();
    }
    m_OrganisationModel->select();
}


void Organisation::removeOrganisation(QModelIndex &index)
{
    int row = index.row();
    int id = m_OrganisationModel->itemData(index.sibling(row, 0))[Qt::EditRole].toInt();
    QSqlQuery query;
    query.prepare("delete from Organizatie where Id_Organizatie = :id");
    query.bindValue(":id", id);
    if(!query.exec())
    {
        qDebug() << query.lastError();
    }
    m_OrganisationModel->select();
}

void Organisation::selectQuery()
{
    m_OrganisationModel->select();
}
