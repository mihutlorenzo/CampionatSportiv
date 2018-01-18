#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "participants.h"
namespace Ui {
class MainWindow;
}
class AddParticipantDialog;
class Participants;

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
    Participants *m_participants;
    QSqlDatabase dataBase;
};

#endif // MAINWINDOW_H
