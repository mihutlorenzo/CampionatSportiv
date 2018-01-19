#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "qstring.h"
#include <QAbstractTableModel>
//#include <QStandardItemModel>
#include <QtSql/QSqlDatabase>
#include "mainwindow.h"
#include <QtSql/QSqlTableModel>

class MainWindow;
class QSqlDatabase;

class Participants
{

public:
    explicit Participants(MainWindow& main,QSqlDatabase& dataBase);
    ~Participants();
    bool addParticipant(const int& otherId,const QString& otherFirstName, const QString& otherLastName, const QString& otherNationality,const int& otherAge,const float& otherWeight, const QString& otherExperience);
    QSqlTableModel* getParticipants();
private:
    QSqlTableModel* m_participantsModel;
};

#endif // PARTICIPANT_H
