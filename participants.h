#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "qstring.h"
#include <QAbstractTableModel>
//#include <QStandardItemModel>
#include <QtSql/QSqlDatabase>
#include "mainwindow.h"
#include <QtSql/QSqlRelationalTableModel>


class MainWindow;
class QSqlDatabase;

class Participants
{

public:
    explicit Participants(MainWindow& main,QSqlDatabase& dataBase);
    ~Participants();
    void addParticipant(const int& otherId,const QString& otherFirstName, const QString& otherLastName, const int& otherCategoryAgeId,const int& otherCategoryWeightId,const int& otherCategoryExperienceId, const int& otherOrganisationId);
    QSqlRelationalTableModel* getParticipants();
    void removeParticipant(QModelIndex &index);


private:
    QSqlRelationalTableModel* m_participantsModel;
};

#endif // PARTICIPANT_H
