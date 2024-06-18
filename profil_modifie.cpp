#include "profil_modifie.h"
#include "ui_profil_modifie.h"
#include <QtSql>
#include <QMessageBox>
#include <QDateTime>
profil_modifie::profil_modifie(QWidget *parent,const QString& id)
    : QDialog(parent)
    , ui(new Ui::profil_modifie),
            m_id(id)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("SELECT*FROM users WHERE id = :id");
    query.bindValue(":id", m_id);
    if (query.exec() && query.next()) {
        ui->lineEdit_nom->setText(query.value(1).toString());
        ui->lineEdit_prenom->setText(query.value(2).toString());
        ui->lineEdit_email->setText(query.value(5).toString());
        ui->lineEdit_numero->setText(query.value(6).toString());
        ui->lineEdit_identifiant->setText(query.value(3).toString());
        ui->nome_user_bar->setText(query.value(1).toString());
    }



    ui->label_date->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));
}

profil_modifie::~profil_modifie()
{
    delete ui;
}
QString profil_modifie::getId() const
{
    return m_id;
}

void profil_modifie::on_pushButton_return_profil_clicked()
{

    this->hide();

    profil profil(nullptr, getId()); // Pass the ID to the profil constructor
    profil.setModal(true);
    profil.exec();
}


void profil_modifie::on_pushButton_Valider_Modification_clicked()
{
    QString nom_M = ui->lineEdit_nom->text();
    QString prenom_M = ui->lineEdit_prenom->text();
    QString email_M = ui->lineEdit_email->text();
    QString numero_M = ui->lineEdit_numero->text();
    QString identifiant_M = ui->lineEdit_identifiant->text();
    QSqlQuery query;
    QString id = getId();
    query.prepare("UPDATE users SET nom = :nom_M, prenom = :prenom_M, email = :email_M, numero = :numero_M, identifiant = :identifiant_M WHERE id = :id");
    query.bindValue(":nom_M", nom_M);
    query.bindValue(":prenom_M", prenom_M);
    query.bindValue(":email_M", email_M);
    query.bindValue(":numero_M", numero_M);
    query.bindValue(":identifiant_M", identifiant_M);
    query.bindValue(":id", id);
    if (query.exec()) {
        // La mise à jour a réussi
        QMessageBox::information(this, tr("Succès"), tr("Profil mis à jour avec succès."));
        QString id;
        this->hide();

        profil_modifie profil_modifie(nullptr, getId()); // Pass the ID to the profil constructor
        profil_modifie.setModal(true);
        profil_modifie.exec();

    } else {
        // Une erreur s'est produite
        QMessageBox::critical(this, tr("Erreur"), tr("Échec de la mise à jour du profil: %1").arg(query.lastError().text()));
    }
}



void profil_modifie::on_pushButton_quitter_clicked()
{
    exit(1);
}


void profil_modifie::on_pushButton_afficher_vente_clicked()
{

    this->hide();
    affichervente affichervente (nullptr, getId());
        // Pass the ID to the profil constructor
    affichervente.setModal(true);
    affichervente.exec();
}

