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

    void dataParticipant(int &id, QString &firstName, QString &lastName,
                         int &categoryAgeId, int &categoryWeightId, int &categoryExperienceId,int &organizationId);
    void setTextFieldForParticipant();
protected:
    void accept() override;


private:
    Ui::AddParticipantDialog *ui;
};

#endif // ADDPARTICIPANTDIALOG_H
