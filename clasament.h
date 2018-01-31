#ifndef CLASAMENT_H
#define CLASAMENT_H

#include "qstring.h"
#include <QsqlRelationalTableModel>

#include <QSqlDatabase>
#include "mainwindow.h"
#include <QtSql/QSqlRelationalTableModel>


class MainWindow;
class QSqlDatabase;

class Clasament
{
public:
    explicit Clasament(MainWindow& main,QSqlDatabase& dataBase);

    void addDataInClasament(const int& idMeci,const int& punctaj, const int& idEtapa, const QString& CNP);
    QSqlRelationalTableModel* getClasamentTable();
    void selectQuery();


private:
    QSqlRelationalTableModel* m_clasamentModel;
};

#endif // CLASAMENT_H
