#include "experiencecategory.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

ExperienceCategory::ExperienceCategory(MainWindow& main,QSqlDatabase& dataBase)
{
    m_experienceCategoryModel = new QSqlTableModel(&main,dataBase);
    m_experienceCategoryModel->setTable("Categorie_Experienta");
    m_experienceCategoryModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    m_experienceCategoryModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_Experienta"));
    m_experienceCategoryModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Experienta"));
    m_experienceCategoryModel->select();

}

ExperienceCategory::~ExperienceCategory()
{
    delete m_experienceCategoryModel;
}

QSqlTableModel* ExperienceCategory::getExperienceCategoryModel()
{
    return m_experienceCategoryModel;
}

void ExperienceCategory::addExperienceCategory(const int &id, const QString &age)
{
    QSqlQuery query;
    query.prepare("insert into Categorie_Experienta values (:id,:age);");
    query.bindValue(":id", id);
    query.bindValue(":age", age);
    if(!query.exec())
    {
        qDebug() << query.lastError();
    }
    m_experienceCategoryModel->select();
}


void ExperienceCategory::removeExperienceCategory(QModelIndex &index)
{
    int row = index.row();
    int id = m_experienceCategoryModel->itemData(index.sibling(row, 0))[Qt::EditRole].toInt();
    QSqlQuery query;
    query.prepare("delete from Categorie_Experienta where Id_Experienta = :id");
    query.bindValue(":id", id);
    if(!query.exec())
    {
        qDebug() << query.lastError();
    }
    m_experienceCategoryModel->select();
}

void ExperienceCategory::selectQuery()
{
    m_experienceCategoryModel->select();
}
