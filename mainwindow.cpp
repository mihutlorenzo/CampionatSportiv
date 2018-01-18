#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addparticipantdialog.h"

#include <QSettings>
#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_addParticipantDialog =new AddParticipantDialog(this);
    connect(ui->addButton,&QPushButton::clicked,this,&MainWindow::addParticipant);
    dataBase = QSqlDatabase::addDatabase("PSQL");

    QSqlTableModel *model = new QSqlTableModel(this,dataBase);
    m_participants = new Participants(model);

    QString hostName;
    QString databaseName;
    QString userName;
    QString password;
    readSettings(hostName, databaseName, userName, password);
    dataBase.setHostName("baasu.db.elephantsql.com (baasu-01)");
    dataBase.setDatabaseName("fygaxwgh");
    dataBase.setUserName("fygaxwgh");
    dataBase.setPassword("1eYLca-VNdAvVmfz1InoOT-MEo8wbntN");
    bool ok = dataBase.open();
    if(!ok)
    {
        ui->statusBar->showMessage(tr("Database not connected!"));
    }
    else
    {
        ui->statusBar->showMessage(tr("Database connected!"));
    }
    //setupModel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readSettings(QString &hostName, QString &databaseName, QString &userName, QString &password)
{
    qDebug() << "App dir path " << qApp->applicationDirPath();
    QSettings s(qApp->applicationDirPath() + "/Championship.conf", QSettings::IniFormat);
    hostName = s.value("HOSTNAME").toString();
    databaseName = s.value("DATABASENAME").toString();
    userName = s.value("USERNAME").toString();
    password = s.value("PASSWORD").toString();
    qDebug() << "Settings file name " << s.fileName();
}


void MainWindow::addParticipant()
{
    int r = m_addParticipantDialog->exec();
    if(r == QDialog::Accepted)
    {
        int id;
        QString firstName;
        QString lastName;
        QString nationality;
        int age;
        float weight;
        QString experience;
        m_addParticipantDialog->data(id,firstName,lastName,nationality,age,weight,experience);
        bool recordSuccesfull = m_participants->addParticipant(id,firstName,lastName,nationality,age,weight,experience);
        if(!recordSuccesfull)
        {
            ui->statusBar->showMessage(tr("Values not submitted to remote database!"));
        }
        else
        {
            ui->statusBar->showMessage(tr("Values submitted to remote database."));
        }
    }
}
