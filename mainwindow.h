#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QSqlQueryModel>
#include "participants.h"
#include "controller.h"
#include <QSqlDatabase>
#include "controlleragecategory.h"
#include "controllerweightcategory.h"
#include "controllerorganization.h"
#include "controllerexperiencecategory.h"

namespace Ui {
class MainWindow;
}

class Controller;
class QActionGroup;
class ControllerAgeCategory;
class ControllerWeightCategory;
class ControllerOrganization;
class ControllerExperienceCategory;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setupTables();
    void readSettings(QString &hostName, QString &databaseName, QString &userName, QString &password);
    bool connectToDatabase();

public slots:
    void addParticipant();
    void addAgeCategory();
    void addWeightCategory();
    void addOrganization();
    void addExperienceCategory();


    void removeParticipant();
    void removeAgeCategory();
    void removeWeightCategory();
    void removeOrganization();
    void removeExperienceCategory();

    void onTableActionsTriggered(QAction *action);
    void onRefreshDB();

private:
    Ui::MainWindow *ui;
    QSqlDatabase dataBase;
    QActionGroup *m_tableActions;
    Controller* m_participantController;
    ControllerAgeCategory *m_ageCategoryController;
    ControllerWeightCategory *m_weightCategoryController;
    ControllerExperienceCategory *m_experienceCategoryController;
    ControllerOrganization*  m_organizationController;


};

#endif // MAINWINDOW_H
