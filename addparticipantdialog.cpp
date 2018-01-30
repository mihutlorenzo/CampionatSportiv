#include "addparticipantdialog.h"
#include "ui_addparticipantdialog.h"

#include <QMessageBox>

AddParticipantDialog::AddParticipantDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddParticipantDialog)
{
    ui->setupUi(this);

}

AddParticipantDialog::~AddParticipantDialog()
{
    delete ui;
}

void AddParticipantDialog::dataParticipant(int &id, QString &firstName, QString &lastName,
                                           int &categoryAgeId, int &categoryWeightId, int &categoryExperienceId,int &organizationId)
{

    id = ui->id->text().toInt();
    firstName = ui->firstName->text();
    lastName = ui->lastName->text();
    organizationId = ui->organizationId->text().toInt();
    categoryAgeId = ui->categoryAgeId->text().toInt();
    categoryWeightId = ui->categoryWeightId->text().toInt();
    categoryExperienceId = ui->categoryExperienceId->text().toInt();
}

void AddParticipantDialog::accept()
{
    bool ok = true;
    ui->id->text().toInt(&ok);
    if(!ok)
    {
        QMessageBox::warning(this, tr("Add Id Error"), tr("Id should be a number"));
    }
    else
    {
        QDialog::accept();
    }
    ui->age->text().toInt(&ok);
    if(!ok)
    {
        QMessageBox::warning(this, tr("Add Age Error"), tr("Age should be a number"));
    }
    else
    {
        QDialog::accept();
    }
    ui->weight->text().toFloat(&ok);
    if(!ok)
    {
        QMessageBox::warning(this, tr("Add Weight Error"), tr("Weight should be a number"));
    }
    else
    {
        QDialog::accept();
    }
}

void AddParticipantDialog::setTextFieldForParticipant()
{
    ui->id->setEnabled(true);
    ui->firstName->setEnabled(true);
    ui->lastName->setEnabled(true);
    ui->organizationId->setEnabled(true);
    ui->organizationName->setEnabled(false);
    ui->categoryAgeId->setEnabled(true);
    ui->categoryExperienceId->setEnabled(true);
    ui->categoryWeightId->setEnabled(true);

    ui->age->setEnabled(false);
    ui->weight->setEnabled(false);
    ui->experience->setEnabled(false);
}
