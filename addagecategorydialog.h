#ifndef ADDAGECATEGORYDIALOG_H
#define ADDAGECATEGORYDIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class AddAgeCategoryDialog;
}

class AddAgeCategoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddAgeCategoryDialog(QWidget *parent = 0);
    ~AddAgeCategoryDialog();

    void dataAgeCategory(int &id, int& age);

protected:
    void accept() override;

private:
    Ui::AddAgeCategoryDialog *ui;
};

#endif // ADDAGECATEGORYDIALOG_H
