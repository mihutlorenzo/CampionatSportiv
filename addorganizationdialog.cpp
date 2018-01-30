#include "addorganizationdialog.h"
#include "ui_addorganizationdialog.h"
#include <QMessageBox>

AddOrganizationDialog::AddOrganizationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddOrganizationDialog)
{
    ui->setupUi(this);
}

AddOrganizationDialog::~AddOrganizationDialog()
{
    delete ui;
}

void AddOrganizationDialog::dataOrganization(int &id, QString& name)
{
    id = ui->organizationId->text().toInt();
    name = ui->name->text();

}

void AddOrganizationDialog::accept()
{
    bool ok = true;
    ui->organizationId->text().toInt(&ok);

    if(!ok)
    {
        QMessageBox::warning(this, tr("Add Id Error"), tr("Organization id should be a number"));
    }
    else
    {
        QDialog::accept();
    }


}
