#ifndef CONTROLLERWEIGHTCATEGORY_H
#define CONTROLLERWEIGHTCATEGORY_H

#include <QSqlTableModel>
#include "weightcategory.h"
#include "addweightcategorydialog.h"
#include "mainwindow.h"


class WeightCategory;
class AddWeightCategoryDialog;

class ControllerWeightCategory
{
public:
    explicit ControllerWeightCategory(MainWindow& main,QSqlDatabase& dataBase);

    void addWeightCategory();
    QSqlTableModel* getModels();
    void deleteWeightCategory(QModelIndex &index);
    void selectQuery();

private:
     WeightCategory *m_weightCategory;
     AddWeightCategoryDialog *m_addWeightCategoryDialog;
};

#endif // CONTROLLERWEIGHTCATEGORY_H
