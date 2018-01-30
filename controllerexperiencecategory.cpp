#include "controllerexperiencecategory.h"

ControllerExperienceCategory::ControllerExperienceCategory(MainWindow& main,QSqlDatabase& dataBase)
{
    m_experienceCategory= new ExperienceCategory(main,dataBase);
    m_addExperienceCategoryDialog = new AddExperienceCategoryDialog(&main);
}

void ControllerExperienceCategory::addExperienceCategory()
{
    int r = m_addExperienceCategoryDialog->exec();
    if(r == QDialog::Accepted)
    {
        int experienceCategoryId;
        QString experience;
        m_addExperienceCategoryDialog->dataExperienceCategory(experienceCategoryId,experience);
        m_experienceCategory->addExperienceCategory(experienceCategoryId,experience);
    }
}

QSqlTableModel* ControllerExperienceCategory::getModels()
{
    return m_experienceCategory->getExperienceCategoryModel();
}


void ControllerExperienceCategory::deleteExperienceCategory(QModelIndex &index)
{
    m_experienceCategory->removeExperienceCategory(index);
}

void ControllerExperienceCategory::selectQuery()
{
    m_experienceCategory->selectQuery();
}
