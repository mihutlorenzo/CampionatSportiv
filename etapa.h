#ifndef ETAPA_H
#define ETAPA_H

#include <QSqlTableModel>
#include "mainwindow.h"
#include <QSqlDatabase>

class Etapa
{
public:
    explicit Etapa(MainWindow& main,QSqlDatabase& dataBase);
    ~Etapa();

    QSqlTableModel* getEtapaModel();
    void addEtapa(const int& id, const QString& denumire);
    void selectQuery();


private:
    QSqlTableModel* m_EtapaModel;
};

#endif // ETAPA_H
