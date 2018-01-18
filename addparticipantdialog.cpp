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

void AddParticipantDialog::data(int &id, QString &firstName, QString &lastName, QString &nationality, int &age, float &weight, QString &experience)
{
    id = ui->id->text().toInt();
    firstName = ui->firstName->text();
    lastName = ui->lastName->text();
    nationality = ui->nationality->text();
    age = ui->age->text().toInt();
    weight = ui->weight->text().toFloat();
    experience = ui->experience->text();
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
