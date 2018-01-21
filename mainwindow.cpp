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
    m_controller = new Controller(*this);
    bool ok = m_controller->connectToDatabase();
    if(!ok)
    {
        ui->statusBar->showMessage(tr("Database not connected!"));
    }
    else
    {
        ui->statusBar->showMessage(tr("Database connected!"));
    }
    m_addParticipantDialog =new AddParticipantDialog(this);
    connect(ui->addButton,&QPushButton::clicked,this,&MainWindow::addParticipant);
    QSqlTableModel* participantsModel;
    m_controller->getModels(participantsModel);
    ui->personsTableView->setModel(participantsModel);

}

MainWindow::~MainWindow()
{
    delete ui;
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
        bool recordSuccesfull = m_controller->addParticipant(id,firstName,lastName,nationality,age,weight,experience);
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
