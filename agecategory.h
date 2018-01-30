#ifndef AGECATEGORY_H
#define AGECATEGORY_H
#include <QSqlTableModel>
#include <mainwindow.h>

class MainWindow;
class QSqlDatabase;

class AgeCategory
{
public:
    explicit AgeCategory(MainWindow& main,QSqlDatabase& dataBase);
    ~AgeCategory();

    QSqlTableModel* getAgeCategoryModel();
    void removeAgeCategory(QModelIndex &index);
    void addAgeCategory(const int& id, const int& age);
    void selectQuery();


private:
    QSqlTableModel* m_ageCategoryModel;
};

#endif // AGECATEGORY_H
