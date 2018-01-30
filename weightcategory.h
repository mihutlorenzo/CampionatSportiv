#ifndef WEIGHTCATEGORY_H
#define WEIGHTCATEGORY_H

#include <QSqlTableModel>
#include <mainwindow.h>

class MainWindow;
class QSqlDatabase;

class WeightCategory
{
public:
    explicit WeightCategory(MainWindow& main,QSqlDatabase& dataBase);
    ~WeightCategory();

    QSqlTableModel* getWeightCategoryModel();
    void removeWeightCategory(QModelIndex &index);
    void addWeightCategory(const int& id, const int& age);
    void selectQuery();


private:
    QSqlTableModel* m_weightCategoryModel;
};

#endif // WEIGHTCATEGORY_H
