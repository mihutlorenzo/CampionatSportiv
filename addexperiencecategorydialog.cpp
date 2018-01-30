#include "addexperiencecategorydialog.h"
#include "ui_addexperiencecategorydialog.h"
#include <QMessageBox>

AddExperienceCategoryDialog::AddExperienceCategoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddExperienceCategoryDialog)
{
    ui->setupUi(this);
}

AddExperienceCategoryDialog::~AddExperienceCategoryDialog()
{
    delete ui;
}

void AddExperienceCategoryDialog::dataExperienceCategory(int &id, QString &experience)
{
    id = ui->experienceCategoryId->text().toInt();
    experience = ui->experience->text();
}

void AddExperienceCategoryDialog::accept()
{
    bool ok = true;
    ui->experienceCategoryId->text().toInt(&ok);

    if(!ok)
    {
        QMessageBox::warning(this, tr("Add Id Error"), tr("Category experience id should be a number"));
    }
    else
    {
        QDialog::accept();
    }

}
