#include "controlleragecategory.h"

ControllerAgeCategory::ControllerAgeCategory(MainWindow& main,QSqlDatabase& dataBase)
{
    m_ageCategory = new AgeCategory(main,dataBase);
    m_addAgeCategoryDialog = new AddAgeCategoryDialog(&main);
}


void ControllerAgeCategory::addAgeCategory()
{
    int r = m_addAgeCategoryDialog->exec();
    if(r == QDialog::Accepted)
    {
        int ageCategoryId;
        int age;
        m_addAgeCategoryDialog->dataAgeCategory(ageCategoryId,age);
        m_ageCategory->addAgeCategory(ageCategoryId,age);
    }
}

QSqlTableModel* ControllerAgeCategory::getModels()
{
    return m_ageCategory->getAgeCategoryModel();
}


void ControllerAgeCategory::deleteAgeCategory(QModelIndex &index)
{
    m_ageCategory->removeAgeCategory(index);
}

void ControllerAgeCategory::selectQuery()
{
    m_ageCategory->selectQuery();
}
