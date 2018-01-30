#ifndef ADDEXPERIENCECATEGORYDIALOG_H
#define ADDEXPERIENCECATEGORYDIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class AddExperienceCategoryDialog;
}

class AddExperienceCategoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddExperienceCategoryDialog(QWidget *parent = 0);
    ~AddExperienceCategoryDialog();

    void dataExperienceCategory(int &id, QString& experience);

protected:
    void accept() override;

private:
    Ui::AddExperienceCategoryDialog *ui;
};

#endif // ADDEXPERIENCECATEGORYDIALOG_H
