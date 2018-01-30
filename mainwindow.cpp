#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addparticipantdialog.h"
#include "addagecategorydialog.h"
#include <QSettings>
#include <QDebug>
#include <QString>
#include <QApplication>
#include <QSqlError>
#include <QtSql>
#include <QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bool ok = connectToDatabase();
    if(!ok)
    {
        ui->statusBar->showMessage(tr("Database not connected!"));
    }
    else
    {
        ui->statusBar->showMessage(tr("Database connected!"));
    }

    m_participantController = new Controller(*this,dataBase);
    m_ageCategoryController = new ControllerAgeCategory(*this,dataBase);
    m_weightCategoryController = new ControllerWeightCategory(*this,dataBase);
    m_experienceCategoryController = new ControllerExperienceCategory(*this,dataBase);
    m_organizationController = new ControllerOrganisation(*this,dataBase);

    m_tableActions = new QActionGroup(this);
    m_tableActions->addAction(ui->actionParticipants);
    m_tableActions->addAction(ui->actionAge_Category);
    m_tableActions->addAction(ui->actionWeight_Category);
    m_tableActions->addAction(ui->actionExperience_Category);
    m_tableActions->addAction(ui->actionOrganization);

    connect(m_tableActions, &QActionGroup::triggered, this, &MainWindow::onTableActionsTriggered);
    connect(ui->actionRefresh,&QAction::triggered, this, &MainWindow::onRefreshDB);
    connect(ui->addParticipantButton,&QPushButton::clicked,this,&MainWindow::addParticipant);
    connect(ui->removeParticipantButton,&QPushButton::clicked,this,&MainWindow::removeParticipant);
    connect(ui->addAgeCategoryButton,&QPushButton::clicked,this,&MainWindow::addAgeCategory);
    connect(ui->deleteAgeCategoryButton,&QPushButton::clicked,this,&MainWindow::removeAgeCategory);
    connect(ui->addWeightCategoryButton,&QPushButton::clicked,this,&MainWindow::addWeightCategory);
    connect(ui->deleteWeightCategoryButton,&QPushButton::clicked,this,&MainWindow::removeWeightCategory);
    connect(ui->addExperienceCategoryButton,&QPushButton::clicked,this,&MainWindow::addExperienceCategory);
    connect(ui->deleteExperienceCategoryButton,&QPushButton::clicked,this,&MainWindow::removeExperienceCategory);
    connect(ui->addOrganizationButton,&QPushButton::clicked,this,&MainWindow::addOrganization);
    connect(ui->deleteOrganizationButton,&QPushButton::clicked,this,&MainWindow::removeOrganization);

    setupTables();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readSettings(QString &hostName, QString &databaseName, QString &userName, QString &password)
{
    qDebug() << "App dir path " << qApp->applicationDirPath();
    QFileInfo fi(qApp->applicationDirPath() + "/Championship.conf");
    if(!fi.exists())
    {
        qDebug() << "Settings file not found - " << fi.absoluteFilePath();
    }
    else
    {
        qDebug() << "Settings file found.";
    }
    QSettings s(qApp->applicationDirPath() + "/Championship.conf", QSettings::IniFormat);
    hostName = s.value("HOSTNAME").toString();
    databaseName = s.value("DATABASENAME").toString();
    userName = s.value("USERNAME").toString();
    QVariant string = s.value("PASSWORD");
    if (string.type() == QVariant::StringList) {
      password = string.toStringList().join(",");
    } else {
      password = string.toString();
    }
    qDebug() << "Settings file name " << s.fileName();
}

bool MainWindow::connectToDatabase()
{

    dataBase = QSqlDatabase::addDatabase("QPSQL");
    QString hostName;
    QString databaseName;
    QString userName;
    QString password;
    readSettings(hostName, databaseName, userName, password);
    dataBase.setHostName(hostName);
    dataBase.setDatabaseName(databaseName);
    dataBase.setUserName(userName);
    dataBase.setPassword(password);
    return dataBase.open();

}

void MainWindow::addParticipant()
{

    m_participantController->addParticipant();
}

void MainWindow::addAgeCategory()
{
    m_ageCategoryController->addAgeCategory();
}

void MainWindow::addWeightCategory()
{
    m_weightCategoryController->addWeightCategory();
}

void MainWindow::addExperienceCategory()
{
    m_experienceCategoryController->addExperienceCategory();
}

void MainWindow::addOrganization()
{
    m_organizationController->addOrganization();
}

void MainWindow::setupTables()
{

    ui->participantsTableView->setModel(m_participantController->getModels());
    ui->ageCategoryTableView->setModel(m_ageCategoryController->getModels());

    ui->weightCategoryTableView->setModel(m_weightCategoryController->getModels());
    ui->experienceCategoryTableView->setModel(m_experienceCategoryController->getModels());
    ui->organizationTableView->setModel(m_organizationController->getModels());

    /*QSqlQueryModel *m_workingHoursJoinPersonsModel = new QSqlQueryModel(this);
    QSqlQuery query("SELECT * from Categorie_Varsta");
    m_workingHoursJoinPersonsModel->setQuery(query);
    m_workingHoursJoinPersonsModel->setHeaderData(0, Qt::Horizontal, tr("Id"));
    m_workingHoursJoinPersonsModel->setHeaderData(1, Qt::Horizontal, tr("Varsta"));

    ui->ageCategoryTableView->setModel(m_workingHoursJoinPersonsModel);*/

}

void MainWindow::removeParticipant()
{
    QItemSelectionModel *selModel = ui->participantsTableView->selectionModel();
    QModelIndexList selIndexes = selModel->selectedIndexes();
    if(selIndexes.count() == 0)
    {
        return;
    }
    QModelIndex index = selIndexes[0];
    m_participantController->deleteParticipant(index);

}

void MainWindow::removeAgeCategory()
{
    QItemSelectionModel *selModel = ui->ageCategoryTableView->selectionModel();
    QModelIndexList selIndexes = selModel->selectedIndexes();
    if(selIndexes.count() == 0)
    {
        return;
    }
    QModelIndex index = selIndexes[0];
    m_ageCategoryController->deleteAgeCategory(index);
}

void MainWindow::removeWeightCategory()
{
    QItemSelectionModel *selModel = ui->weightCategoryTableView->selectionModel();
    QModelIndexList selIndexes = selModel->selectedIndexes();
    if(selIndexes.count() == 0)
    {
        return;
    }
    QModelIndex index = selIndexes[0];
    m_weightCategoryController->deleteWeightCategory(index);
}

void MainWindow::removeExperienceCategory()
{
    QItemSelectionModel *selModel = ui->experienceCategoryTableView->selectionModel();
    QModelIndexList selIndexes = selModel->selectedIndexes();
    if(selIndexes.count() == 0)
    {
        return;
    }
    QModelIndex index = selIndexes[0];
    m_experienceCategoryController->deleteExperienceCategory(index);
}

void MainWindow::removeOrganization()
{
    QItemSelectionModel *selModel = ui->organizationTableView->selectionModel();
    QModelIndexList selIndexes = selModel->selectedIndexes();
    if(selIndexes.count() == 0)
    {
        return;
    }
    QModelIndex index = selIndexes[0];
    m_organizationController->deleteOrganization(index);
}

void MainWindow::onTableActionsTriggered(QAction *action)
{
    if(action == ui->actionParticipants)
    {
        //ui->stackedWidget->setCurrentWidget(ui->tablePersons);
        ui->stackedWidget->setCurrentIndex(0);
    }
    if(action == ui->actionAge_Category)
    {
        //ui->stackedWidget->setCurrentWidget(ui->tableWorkingHours);
        ui->stackedWidget->setCurrentIndex(1);
       //ui->participantsTableView->selectionModel()->clearSelection();
    }
    if(action == ui->actionExperience_Category)
    {
        ui->stackedWidget->setCurrentIndex(2);
        //ui->tablePersons->selectionModel()->clearSelection();
    }
    if(action == ui->actionOrganization)
    {
        ui->stackedWidget->setCurrentIndex(3);
        //ui->tablePersons->selectionModel()->clearSelection();
    }
    if(action == ui->actionWeight_Category)
    {
        ui->stackedWidget->setCurrentIndex(4);
        //ui->tablePersons->selectionModel()->clearSelection();
    }
}

void MainWindow::onRefreshDB()
{
    m_ageCategoryController->selectQuery();
}
