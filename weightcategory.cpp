#include "weightcategory.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

WeightCategory::WeightCategory(MainWindow& main,QSqlDatabase& dataBase)
{
    m_weightCategoryModel = new QSqlTableModel(&main,dataBase);
    m_weightCategoryModel->setTable("Weight Category");
    m_weightCategoryModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    m_weightCategoryModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    m_weightCategoryModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Age"));
    m_weightCategoryModel->select();

}

WeightCategory::~WeightCategory()
{
    delete m_weightCategoryModel;
}

QSqlTableModel* WeightCategory::getWeightCategoryModel()
{
    return m_weightCategoryModel;
}

void WeightCategory::addWeightCategory(const int &id, const int &age)
{
    QSqlQuery query;
    query.prepare("insert into Categorie_Greutate values (:id,:age);");
    query.bindValue(":id", id);
    query.bindValue(":age", age);
    if(!query.exec())
    {
        qDebug() << query.lastError();
    }
    m_weightCategoryModel->select();
}


void WeightCategory::removeWeightCategory(QModelIndex &index)
{
    int row = index.row();
    int id = m_weightCategoryModel->itemData(index.sibling(row, 0))[Qt::EditRole].toInt();
    QSqlQuery query;
    query.prepare("delete from Categorie_Greutate where Id_Greutate = :id");
    query.bindValue(":id", id);
    if(!query.exec())
    {
        qDebug() << query.lastError();
    }
    m_weightCategoryModel->select();
}

void WeightCategory::selectQuery()
{
    m_weightCategoryModel->select();
}

