#ifndef ADDWEIGHTCATEGORYDIALOG_H
#define ADDWEIGHTCATEGORYDIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class AddWeightCategoryDialog;
}

class AddWeightCategoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddWeightCategoryDialog(QWidget *parent = 0);
    ~AddWeightCategoryDialog();
    void dataWeightCategory(int &id, QString& weight);

protected:
    void accept() override;


private:
    Ui::AddWeightCategoryDialog *ui;
};

#endif // ADDWEIGHTCATEGORYDIALOG_H
