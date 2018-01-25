#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QSqlDatabase>
#include <QMainWindow>
#include <QSqlTableModel>
#include "participants.h"
#include "mainwindow.h"
#include <QSettings>
#include <QDebug>
#include <QString>

class Participants;
class MainWindow;
class Controller
{
public:
    explicit Controller(MainWindow& main);
    bool addParticipant(const int& otherId,const QString& otherFirstName, const QString& otherLastName, const QString& otherNationality,const int& otherAge,const float& otherWeight, const QString& otherExperience);
    bool connectToDatabase();
    void readSettings(QString &hostName, QString &databaseName, QString &userName, QString &password);
    void getModels(QSqlTableModel * & model);
    void deleteParticipant(QModelIndex &index);

private:
    Participants *m_participants;
    QSqlDatabase dataBase;
};

#endif // CONTROLLER_H
