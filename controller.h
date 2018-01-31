#ifndef CONTROLLER_H
#define CONTROLLER_H


#include <QMainWindow>
#include <QSqlRelationalTableModel>
#include "participants.h"
#include "mainwindow.h"
#include "addparticipantdialog.h"
#include <QSettings>
#include <QDebug>
#include <QString>

class Participants;
class MainWindow;
class AddAgeCategoryDialog;
class AgeCategory;
 class AddParticipantDialog ;


class Controller
{
public:
    explicit Controller(MainWindow& main,QSqlDatabase& dataBase);
    void addParticipant();
    //void getModels(QSqlRelationalTableModel * & model);
    QSqlTableModel* getModels();
    void deleteParticipant(QModelIndex &index);
    void selectQuery();


private:
    Participants *m_participants;
    AddParticipantDialog *m_addParticipantDialog;

};

#endif // CONTROLLER_H
