#include "controller.h"
#include <QSettings>
#include <QDebug>
#include <QString>
#include <QSqlError>
#include <QApplication>
#include <QtSql>

Controller::Controller(MainWindow& main)
{

   m_participants = new Participants(main,dataBase);

}

bool Controller::addParticipant(const int &otherId, const QString &otherFirstName, const QString &otherLastName, const QString &otherNationality, const int &otherAge, const float &otherWeight, const QString &otherExperience)
{
    return m_participants->addParticipant(otherId,otherFirstName,otherLastName,otherNationality,otherAge,otherWeight,otherExperience);
}

bool Controller::connectToDatabase()
{
    dataBase = QSqlDatabase::addDatabase("PSQL");
    QString hostName;
    QString databaseName;
    QString userName;
    QString password;
   // readSettings(hostName, databaseName, userName, password);
    dataBase.setHostName("baasu.db.elephantsql.com (baasu-01)");
    dataBase.setDatabaseName("obfjdotn");
    dataBase.setUserName("obfjdotn");
    dataBase.setPassword("OPKvhOuHOffso2ZoBuYUD9yQkQnkzMyd");
    if( !dataBase.open() )
    {
       qDebug() << dataBase.lastError();
        qFatal( "Failed to connect." );
    }

    qDebug( "Connected!" );
    return dataBase.open();

}

void Controller::readSettings(QString &hostName, QString &databaseName, QString &userName, QString &password)
{
    qDebug() << "App dir path " << qApp->applicationDirPath();
    QSettings s(qApp->applicationDirPath() + "/Championship.conf", QSettings::IniFormat);
    hostName = s.value("HOSTNAME").toString();
    databaseName = s.value("DATABASENAME").toString();
    userName = s.value("USERNAME").toString();
    password = s.value("PASSWORD").toString();
    qDebug() << "Settings file name " << s.fileName();
}

void Controller::getModels(QSqlTableModel * &model)
{
    model = m_participants->getParticipants();
}


void Controller::deleteParticipant(QModelIndex &index)
{
    m_participants->removeParticipant(index);
}


