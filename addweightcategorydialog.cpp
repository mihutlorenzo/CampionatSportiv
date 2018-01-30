#include "addweightcategorydialog.h"
#include "ui_addweightcategorydialog.h"
#include <QMessageBox>

AddWeightCategoryDialog::AddWeightCategoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWeightCategoryDialog)
{
    ui->setupUi(this);
}

AddWeightCategoryDialog::~AddWeightCategoryDialog()
{
    delete ui;
}

void AddWeightCategoryDialog::dataWeightCategory(int &id, QString &weight)
{
    id = ui->categoryWeightId->text().toInt();
    weight = ui->weight->text();
}

void AddWeightCategoryDialog::accept()
{
    bool ok = true;
    ui->categoryWeightId->text().toInt(&ok);

    if(!ok)
    {
        QMessageBox::warning(this, tr("Add Id Error"), tr("Category weight id should be a number"));
    }
    else
    {
        QDialog::accept();
    }
    ui->weight->text().toInt(&ok);
    if(!ok)
    {
        QMessageBox::warning(this, tr("Add Age Error"), tr("Weight should be a number"));
    }
    else
    {
        QDialog::accept();
    }
}
