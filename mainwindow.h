#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QSqlQueryModel>
#include "participants.h"
#include "controller.h"
namespace Ui {
class MainWindow;
}
class AddParticipantDialog;
class Controller;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void addParticipant();

private:
    Ui::MainWindow *ui;
    AddParticipantDialog *m_addParticipantDialog;
    Controller* m_controller;

};

#endif // MAINWINDOW_H
