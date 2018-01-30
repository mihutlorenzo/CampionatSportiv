#include "controllerweightcategory.h"

ControllerWeightCategory::ControllerWeightCategory(MainWindow& main,QSqlDatabase& dataBase)
{
    m_weightCategory= new WeightCategory(main,dataBase);
    m_addWeightCategoryDialog = new AddWeightCategoryDialog(&main);
}

void ControllerWeightCategory::addWeightCategory()
{
    int r = m_addWeightCategoryDialog->exec();
    if(r == QDialog::Accepted)
    {
        int weightCategoryId;
        QString weight;
        m_addWeightCategoryDialog->dataWeightCategory(weightCategoryId,weight);
        m_weightCategory->addWeightCategory(weightCategoryId,weight);
    }
}

QSqlTableModel* ControllerWeightCategory::getModels()
{
    return m_weightCategory->getWeightCategoryModel();
}


void ControllerWeightCategory::deleteWeightCategory(QModelIndex &index)
{
    m_weightCategory->removeWeightCategory(index);
}

void ControllerWeightCategory::selectQuery()
{
    m_weightCategory->selectQuery();
}
