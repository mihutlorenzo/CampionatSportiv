#include "clasament.h"
#include <QSqlRelationalTableModel>
#include <QtSql/QSqlField>
#include <QtSql/QSqlRecord>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Clasament::Clasament(MainWindow& main,QSqlDatabase& dataBase)
{
    m_clasamentModel = new QSqlRelationalTableModel(&main,dataBase);
    m_clasamentModel->setTable("Clasament");
    m_clasamentModel->setRelation(2, QSqlRelation("Etapa", "Id_Etapa", "denumire"));
    m_clasamentModel->setRelation(3, QSqlRelation("Participant", "CNP", "nume"));
    m_clasamentModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_clasamentModel->setHeaderData(0, Qt::Horizontal,  QObject::tr("Id_Meci"));
    m_clasamentModel->setHeaderData(1, Qt::Horizontal,  QObject::tr("Punctaj"));
    m_clasamentModel->setHeaderData(2,Qt::Horizontal,  QObject::tr("Denumire Etapa"));
    m_clasamentModel->setHeaderData(3,Qt::Horizontal,  QObject::tr("Nume concurent"));
    m_clasamentModel->select();
}

void Clasament::addDataInClasament(const int &idMeci, const int &punctaj, const int &idEtapa, const QString &CNP)
{
    QSqlQuery query;
    query.prepare("insert into Clasament values (:idMeci,:punctaj, :idEtapa, :cnp);");
    query.bindValue(":idMeci", idMeci);
    query.bindValue(":punctaj", punctaj);
    query.bindValue(":idEtapa", idEtapa);
    query.bindValue(":cnp", CNP);
    if(!query.exec())
    {
        qDebug() << query.lastError();
    }
    m_clasamentModel->select();
    if(!m_clasamentModel->submitAll())
    {
        qDebug() << "Values not submitted to remote database.";
    }
    else
    {
        qDebug() << "Values submitted to remote database.";
    }
}

QSqlRelationalTableModel* Clasament::getClasamentTable()
{
    return m_clasamentModel;
}

void Clasament::selectQuery()
{
    m_clasamentModel->select();
}


