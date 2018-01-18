#ifndef ADDPARTICIPANTDIALOG_H
#define ADDPARTICIPANTDIALOG_H

#include <QDialog>

namespace Ui {
class AddParticipantDialog;
}

class AddParticipantDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddParticipantDialog(QWidget *parent = 0);
    ~AddParticipantDialog();

    void data(int& id,QString& firstName, QString& lastName, QString& nationality, int& age, float& weight, QString& experience);
    void setData(const int& id,const QString& firstName, const QString& lastName, const QString& nationality,const int& age,const float& weight, const QString& experience);
protected:
    void accept() override;


private:
    Ui::AddParticipantDialog *ui;
};

#endif // ADDPARTICIPANTDIALOG_H
