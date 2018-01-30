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

void AddParticipantDialog::dataParticipant(QString &id, QString &firstName, QString &lastName,
                                           int &categoryAgeId, int &categoryWeightId, int &categoryExperienceId,int &organizationId)
{

    id = ui->id->text();
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


    ui->categoryAgeId->text().toInt(&ok);
    if(!ok)
    {
        QMessageBox::warning(this, tr("Add Age Error"), tr("Category age should be a number"));
    }
    else
    {
        QDialog::accept();
    }
    ui->categoryWeightId->text().toInt(&ok);
    if(!ok)
    {
        QMessageBox::warning(this, tr("Add Weight Error"), tr("Category weight should be a number"));
    }
    else
    {
        QDialog::accept();
    }

    ui->categoryExperienceId->text().toInt(&ok);
    if(!ok)
    {
        QMessageBox::warning(this, tr("Add Experience Error"), tr("Category experience should be a number"));
    }
    else
    {
        QDialog::accept();
    }

    ui->organizationId->text().toInt(&ok);
    if(!ok)
    {
        QMessageBox::warning(this, tr("Add Organization Error"), tr("Organization should be a number"));
    }
    else
    {
        QDialog::accept();
    }
}


