#include "etapa.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

Etapa::Etapa(MainWindow &main, QSqlDatabase &dataBase)
{
    m_EtapaModel = new QSqlTableModel(&main,dataBase);
    m_EtapaModel->setTable("Etapa");
    m_EtapaModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    m_EtapaModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_Etapa"));
    m_EtapaModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Denumire"));
    m_EtapaModel->select();
}

Etapa::~Etapa()
{
    delete m_EtapaModel;
}

QSqlTableModel* Etapa::getEtapaModel()
{
    return m_EtapaModel;
}

void Etapa::addEtapa(const int &id, const QString &denumire)
{
    QSqlQuery query;
    query.prepare("insert into Etapa values (:id,:denumire);");
    query.bindValue(":id", id);
    query.bindValue(":denumire", denumire);
    if(!query.exec())
    {
        qDebug() << query.lastError();
    }
    m_EtapaModel->select();
}
void Etapa::selectQuery()
{
    m_EtapaModel->select();
}
