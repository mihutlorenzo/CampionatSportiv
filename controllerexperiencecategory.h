#ifndef CONTROLLEREXPERIENCECATEGORY_H
#define CONTROLLEREXPERIENCECATEGORY_H

#include <QSqlTableModel>
#include "experiencecategory.h"
#include "addexperiencecategorydialog.h"
#include "mainwindow.h"

class ExperienceCategory;
class AddExperienceCategoryDialog;

class ControllerExperienceCategory
{
public:
    //ControllerExperienceCategory();
    explicit ControllerExperienceCategory(MainWindow& main,QSqlDatabase& dataBase);

    void addExperienceCategory();
    QSqlTableModel* getModels();
    void deleteExperienceCategory(QModelIndex &index);
    void selectQuery();

private:
     ExperienceCategory *m_experienceCategory;
     AddWeightCategoryDialog *m_addExperienceCategoryDialog;
};

#endif // CONTROLLEREXPERIENCECATEGORY_H
