#ifndef CONTROLLERAGECATEGORY_H
#define CONTROLLERAGECATEGORY_H
#include "agecategory.h"
#include "addagecategorydialog.h"
#include <QSqlTableModel>
#include "mainwindow.h"

class ControllerAgeCategory
{
public:
    explicit ControllerAgeCategory(MainWindow& main,QSqlDatabase& dataBase);

    void addAgeCategory();
    QSqlTableModel* getModels();
    void deleteAgeCategory(QModelIndex &index);
    void selectQuery();

private:
     AgeCategory *m_ageCategory;
     AddAgeCategoryDialog *m_addAgeCategoryDialog;
};

#endif // CONTROLLERAGECATEGORY_H
