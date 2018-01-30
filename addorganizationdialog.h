#ifndef ADDORGANIZATIONDIALOG_H
#define ADDORGANIZATIONDIALOG_H

#include <QDialog>

namespace Ui {
class AddOrganizationDialog;
}

class AddOrganizationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddOrganizationDialog(QWidget *parent = 0);
    ~AddOrganizationDialog();

    void dataOrganization(int &id, QString& name);

protected:
    void accept() override;

private:
    Ui::AddOrganizationDialog *ui;
};

#endif // ADDORGANIZATIONDIALOG_H
