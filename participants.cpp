#include "participants.h"
#include "QAbstractTableModel"
#include <QtSql/QSqlField>
#include <QtSql/QSqlRecord>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>



Participants::Participants(MainWindow& main,QSqlDatabase& dataBase)
{
    m_participantsModel = new QSqlRelationalTableModel(&main,dataBase);
    m_participantsModel->setTable("Participant");

    m_participantsModel->setRelation(3, QSqlRelation("Categorie_Varsta", "Id_Varsta", "varsta"));
    m_participantsModel->setRelation(4, QSqlRelation("Categorie_Greutate", "Id_Greutate", "greutate"));
   m_participantsModel->setRelation(5, QSqlRelation("Categorie_Experienta", "Id_Experienta", "experienta"));
    m_participantsModel->setRelation(6, QSqlRelation("Organizatie", "Id_Organizatie", "nume"));

    m_participantsModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_participantsModel->setHeaderData(0, Qt::Horizontal, QObject::tr("CNP"));
    m_participantsModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Nume"));
    m_participantsModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenume"));
    m_participantsModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Varsta"));
    m_participantsModel->setHeaderData(4, Qt::Horizontal, QObject::tr("Greutate"));
    m_participantsModel->setHeaderData(5, Qt::Horizontal, QObject::tr("Experienta"));
    m_participantsModel->setHeaderData(6, Qt::Horizontal, QObject::tr("Organizatie"));
    m_participantsModel->select();
}

Participants::~Participants()
{
    delete m_participantsModel;
}

void Participants::addParticipant(const QString& otherId,const QString& otherFirstName, const QString& otherLastName, const int& otherCategoryAgeId,const int& otherCategoryWeightId,const int& otherCategoryExperienceId, const int& otherOrganisationId)
{
    /*QSqlField idField("Id", QVariant::Int);
    QSqlField firstNameField("FirstName", QVariant::String);
    QSqlField lastNameField("LastName", QVariant::String);
    QSqlField categoryAgeIdField("CategoryAgeId", QVariant::Int);
    QSqlField categoryWeightIdField("CategoryWeightId", QVariant::Int);
    QSqlField categoryExperienceIdField("CategoryExperienceId", QVariant::Int);
    QSqlField organisationIdField("OrganisationId", QVariant::Int);
    idField.setValue(otherId);
    firstNameField.setValue(otherFirstName);
    lastNameField.setValue(otherLastName);
    categoryAgeIdField.setValue(otherCategoryAgeId);
    categoryWeightIdField.setValue(otherCategoryWeightId);
    categoryExperienceIdField.setValue(otherCategoryExperienceId);
    organisationIdField.setValue(otherOrganisationId);
    QSqlRecord record;
    record.append(idField);
    record.append(firstNameField);
    record.append(lastNameField);
    record.append(categoryAgeIdField);
    record.append(categoryWeightIdField);
    record.append(categoryExperienceIdField);
    record.append(organisationIdField);
    m_participantsModel->insertRecord(-1, record);*/

    QSqlQuery query;
    query.prepare("insert into participant values (:cnp,:firstname, :lastname, :idvarsta, :idgreutate, :idexperienta, :idorganizatie);");
    query.bindValue(":cnp", otherId);
    query.bindValue(":firstname", otherFirstName);
    query.bindValue(":lastname", otherLastName);
    query.bindValue(":idexperienta", otherCategoryExperienceId);
    query.bindValue(":idgreutate", otherCategoryWeightId);
    query.bindValue(":idvarsta", otherCategoryAgeId);
    query.bindValue(":idorganizatie", otherOrganisationId);
    if(!query.exec())
    {
        qDebug() << query.lastError();
    }
    m_participantsModel->select();
    if(!m_participantsModel->submitAll())
    {
        qDebug() << "Values not submitted to remote database.";
    }
    else
    {
        qDebug() << "Values submitted to remote database.";
    }
}

QSqlRelationalTableModel* Participants::getParticipants()
{
    return m_participantsModel;
}

void Participants::removeParticipant(QModelIndex &index)
{
    int row = index.row();
    QString cnp = m_participantsModel->itemData(index.sibling(row, 0))[Qt::EditRole].toString();
    QSqlQuery query;
    query.prepare("delete from participant where participant.cnp = :cnp");
    query.bindValue(":cnp", cnp);
    if(!query.exec())
    {
        qDebug() << query.lastError();
    }
    m_participantsModel->select();
}

void Participants::selectQuery()
{
    m_participantsModel->select();
}




