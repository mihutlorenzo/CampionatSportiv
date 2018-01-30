#ifndef EXPERIENCECATEGORY_H
#define EXPERIENCECATEGORY_H


#include <QSqlTableModel>
#include <mainwindow.h>

class MainWindow;
class QSqlDatabase;

class ExperienceCategory
{
public:
    explicit ExperienceCategory(MainWindow& main,QSqlDatabase& dataBase);
    ~ExperienceCategory();

    QSqlTableModel *getExperienceCategoryModel();
    void removeExperienceCategory(QModelIndex &index);
    void addExperienceCategory(const int& id, const QString& age);
    void selectQuery();


private:
    QSqlTableModel *m_experienceCategoryModel;
};


#endif // EXPERIENCECATEGORY_H
