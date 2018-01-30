#include "addagecategorydialog.h"
#include "ui_addagecategorydialog.h"
#include <QMessageBox>

AddAgeCategoryDialog::AddAgeCategoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAgeCategoryDialog)
{
    ui->setupUi(this);
}

AddAgeCategoryDialog::~AddAgeCategoryDialog()
{
    delete ui;
}

void AddAgeCategoryDialog::dataAgeCategory(int &id, int &age)
{
    id = ui->categoryAgeId->text().toInt();
    age = ui->age->text().toInt();
}

void AddAgeCategoryDialog::accept()
{
    bool ok = true;
    ui->categoryAgeId->text().toInt(&ok);

    if(!ok)
    {
        QMessageBox::warning(this, tr("Add Id Error"), tr("Category age id should be a number"));
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

}
