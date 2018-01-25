#include "participants.h"
#include "QAbstractTableModel"
#include <QtSql/QSqlField>
#include <QtSql/QSqlRecord>
#include <QSqlQuery>
#include <QSqlError>


Participants::Participants(MainWindow& main,QSqlDatabase& dataBase)
{
    m_participantsModel = new QSqlTableModel(&main,dataBase);
    m_participantsModel->setTable("Participants");
    m_participantsModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    m_participantsModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    m_participantsModel->setHeaderData(1, Qt::Horizontal, QObject::tr("First Name"));
    m_participantsModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Last Name"));
    m_participantsModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Nationality"));
    m_participantsModel->setHeaderData(4, Qt::Horizontal, QObject::tr("Age"));
    m_participantsModel->setHeaderData(5, Qt::Horizontal, QObject::tr("Weight"));
    m_participantsModel->setHeaderData(6, Qt::Horizontal, QObject::tr("Experience"));
    m_participantsModel->select();
}

Participants::~Participants()
{
    delete m_participantsModel;
}

bool Participants::addParticipant(const int &otherId, const QString &otherFirstName, const QString &otherLastName, const QString &otherNationality, const int &otherAge, const float &otherWeight, const QString &otherExperience)
{
    QSqlField idField("id", QVariant::Int);
    QSqlField firstNameField("firstname", QVariant::String);
    QSqlField lastNameField("lastname", QVariant::String);
    QSqlField nationalityField("nationality", QVariant::String);
    QSqlField ageField("age", QVariant::Int);
    QSqlField weightField("weight", QVariant::Double);
    QSqlField experienceField("experience", QVariant::String);
    idField.setValue(otherId);
    firstNameField.setValue(otherFirstName);
    lastNameField.setValue(otherLastName);
    nationalityField.setValue(otherNationality);
    ageField.setValue(otherAge);
    weightField.setValue(otherWeight);
    experienceField.setValue(otherExperience);
    QSqlRecord record;
    record.append(idField);
    record.append(firstNameField);
    record.append(lastNameField);
    record.append(nationalityField);
    record.append(ageField);
    record.append(weightField);
    record.append(experienceField);
    m_participantsModel->insertRecord(-1, record);

    return m_participantsModel->submitAll();
}

QSqlTableModel* Participants::getParticipants()
{
    return m_participantsModel;
}

void Participants::removeParticipant(QModelIndex &index)
{
    int row = index.row();
    QString cnp = m_participantsModel->itemData(index.sibling(row, 0))[Qt::EditRole].toString();
    QSqlQuery query;
    query.prepare("delete from participants where participants.cnp = :cnp");
    query.bindValue(":cnp", cnp);
    if(!query.exec())
    {
        qDebug() << query.lastError();
    }
    m_participantsModel->select();
}




