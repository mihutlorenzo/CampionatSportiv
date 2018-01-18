/********************************************************************************
** Form generated from reading UI file 'addparticipantdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPARTICIPANTDIALOG_H
#define UI_ADDPARTICIPANTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddParticipantDialog
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *id;
    QLabel *label_2;
    QLineEdit *firstName;
    QLabel *label_3;
    QLineEdit *lastName;
    QLabel *label_4;
    QLineEdit *nationality;
    QLabel *label_5;
    QLineEdit *age;
    QLabel *label_6;
    QLineEdit *weight;
    QLabel *label_7;
    QLineEdit *experience;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddParticipantDialog)
    {
        if (AddParticipantDialog->objectName().isEmpty())
            AddParticipantDialog->setObjectName(QStringLiteral("AddParticipantDialog"));
        AddParticipantDialog->resize(531, 268);
        formLayout = new QFormLayout(AddParticipantDialog);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(AddParticipantDialog);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        id = new QLineEdit(AddParticipantDialog);
        id->setObjectName(QStringLiteral("id"));

        formLayout->setWidget(0, QFormLayout::FieldRole, id);

        label_2 = new QLabel(AddParticipantDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        firstName = new QLineEdit(AddParticipantDialog);
        firstName->setObjectName(QStringLiteral("firstName"));

        formLayout->setWidget(1, QFormLayout::FieldRole, firstName);

        label_3 = new QLabel(AddParticipantDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lastName = new QLineEdit(AddParticipantDialog);
        lastName->setObjectName(QStringLiteral("lastName"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lastName);

        label_4 = new QLabel(AddParticipantDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        nationality = new QLineEdit(AddParticipantDialog);
        nationality->setObjectName(QStringLiteral("nationality"));

        formLayout->setWidget(3, QFormLayout::FieldRole, nationality);

        label_5 = new QLabel(AddParticipantDialog);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        age = new QLineEdit(AddParticipantDialog);
        age->setObjectName(QStringLiteral("age"));

        formLayout->setWidget(4, QFormLayout::FieldRole, age);

        label_6 = new QLabel(AddParticipantDialog);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        weight = new QLineEdit(AddParticipantDialog);
        weight->setObjectName(QStringLiteral("weight"));

        formLayout->setWidget(5, QFormLayout::FieldRole, weight);

        label_7 = new QLabel(AddParticipantDialog);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        experience = new QLineEdit(AddParticipantDialog);
        experience->setObjectName(QStringLiteral("experience"));

        formLayout->setWidget(6, QFormLayout::FieldRole, experience);

        buttonBox = new QDialogButtonBox(AddParticipantDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(7, QFormLayout::FieldRole, buttonBox);


        retranslateUi(AddParticipantDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddParticipantDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddParticipantDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddParticipantDialog);
    } // setupUi

    void retranslateUi(QDialog *AddParticipantDialog)
    {
        AddParticipantDialog->setWindowTitle(QApplication::translate("AddParticipantDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("AddParticipantDialog", "Id", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddParticipantDialog", "First Name", Q_NULLPTR));
        label_3->setText(QApplication::translate("AddParticipantDialog", "Last Name", Q_NULLPTR));
        label_4->setText(QApplication::translate("AddParticipantDialog", "Nationality", Q_NULLPTR));
        label_5->setText(QApplication::translate("AddParticipantDialog", "Age", Q_NULLPTR));
        label_6->setText(QApplication::translate("AddParticipantDialog", "Weight", Q_NULLPTR));
        label_7->setText(QApplication::translate("AddParticipantDialog", "Experience", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddParticipantDialog: public Ui_AddParticipantDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPARTICIPANTDIALOG_H
