#include "agecategory.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

AgeCategory::AgeCategory(MainWindow& main,QSqlDatabase& dataBase)
{
    m_ageCategoryModel = new QSqlTableModel(&main,dataBase);
    m_ageCategoryModel->setTable("Categorie_Varsta");
    m_ageCategoryModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    m_ageCategoryModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_Varsta"));
    m_ageCategoryModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Varsta"));
    m_ageCategoryModel->select();

}

AgeCategory::~AgeCategory()
{
    delete m_ageCategoryModel;
}

QSqlTableModel* AgeCategory::getAgeCategoryModel()
{
    return m_ageCategoryModel;
}

void AgeCategory::addAgeCategory(const int &id, const int &age)
{
    QSqlQuery query;
    query.prepare("insert into Categorie_Varsta values (:id,:age);");
    query.bindValue(":id", id);
    query.bindValue(":age", age);
    if(!query.exec())
    {
        qDebug() << query.lastError();
    }
    m_ageCategoryModel->select();

    if(!m_ageCategoryModel->submitAll())
    {
        qDebug() << "Values not submitted to remote database.";
    }
    else
    {
        qDebug() << "Values submitted to remote database.";
    }
}


void AgeCategory::removeAgeCategory(QModelIndex &index)
{
    int row = index.row();
    int id = m_ageCategoryModel->itemData(index.sibling(row, 0))[Qt::EditRole].toInt();
    QSqlQuery query;
    query.prepare("delete from Categorie_Varsta where Id_Varsta = :id");
    query.bindValue(":id", id);
    if(!query.exec())
    {
        qDebug() << query.lastError();
    }
    m_ageCategoryModel->select();
}

void AgeCategory::selectQuery()
{
    m_ageCategoryModel->select();
}
