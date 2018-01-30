#include "controller.h"
#include "addagecategorydialog.h"
#include "agecategory.h"
#include <QSettings>
#include <QDebug>
#include <QString>
#include <QSqlError>
#include <QApplication>
#include <QtSql>

Controller::Controller(MainWindow& main,QSqlDatabase& dataBase)
{

   m_participants = new Participants(main,dataBase);
   m_addParticipantDialog =new AddParticipantDialog(&main);


}

void Controller::addParticipant()
{
    int r = m_addParticipantDialog->exec();
    if(r == QDialog::Accepted)
    {
        QString id;
        QString firstName;
        QString lastName;
        int organisationId;
        int categoryAgeId;
        int categoryWeightId;
        int categoryExperienceId;
        m_addParticipantDialog->dataParticipant(id,firstName,lastName,categoryAgeId,categoryWeightId,categoryExperienceId,organisationId);
        m_participants->addParticipant(id,firstName,lastName,categoryAgeId,categoryWeightId,categoryExperienceId,organisationId);
    }
}



/*void Controller::getModels(QSqlRelationalTableModel * &model)
{
    return m_participants->getParticipants();
}*/

QSqlTableModel* Controller::getModels()
{
    return m_participants->getParticipants();
}


void Controller::deleteParticipant(QModelIndex &index)
{
    m_participants->removeParticipant(index);
}


