#include "modifier_profil_gerant.h"
#include "ui_modifier_profil_gerant.h"
#include <QMessageBox>
#include <QtSql>
#include <QDateTime>
modifier_profil_gerant::modifier_profil_gerant(QWidget *parent,const QString& id)
    : QDialog(parent)
    , ui(new Ui::modifier_profil_gerant),m_id(id)
{
    ui->setupUi(this);
    ui->label_date->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));
    QSqlQuery query;
    query.prepare("SELECT*FROM users WHERE id = :id");
    query.bindValue(":id", m_id);
    if (query.exec() && query.next()) {
        ui->lineEdit_nom_gerant->setText(query.value(1).toString());
        ui->lineEdit_prenom_gerant->setText(query.value(2).toString());
        ui->lineEdit_email_gerant->setText(query.value(5).toString());
        ui->lineEdit_numero_gerant->setText(query.value(6).toString());
        ui->lineEdit_identifiant_gerant->setText(query.value(3).toString());
        ui->nome_user->setText(query.value(1).toString());
    }
}

modifier_profil_gerant::~modifier_profil_gerant()
{
    delete ui;
}
QString modifier_profil_gerant::getId() const
{
    return m_id;
}


void modifier_profil_gerant::on_Valider_modifier_gerant_clicked()
{

        QString nom_M = ui->lineEdit_nom_gerant->text();
        QString prenom_M = ui->lineEdit_prenom_gerant->text();
        QString email_M = ui->lineEdit_email_gerant->text();
        QString numero_M = ui->lineEdit_numero_gerant->text();
        QString identifiant_M = ui->lineEdit_identifiant_gerant->text();
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

            modifier_profil_gerant modifier_profil_gerant(nullptr, getId()); // Pass the ID to the profil constructor
            modifier_profil_gerant.setModal(true);
            modifier_profil_gerant.exec();

        } else {
            // Une erreur s'est produite
            QMessageBox::critical(this, tr("Erreur"), tr("Échec de la mise à jour du profil: %1").arg(query.lastError().text()));
        }

}


void modifier_profil_gerant::on_pushButton_precedent_profil_clicked()
{
    this->hide();

    profil_gerant profil_gerant(nullptr, getId()); // Pass the ID to the profil constructor
    profil_gerant.setModal(true);
    profil_gerant.exec();
}


void modifier_profil_gerant::on_pushButton_quitter_clicked()
{
    this->close();

    // Show the main window
    MainWindow mainwindow;
    mainwindow.show();
}

