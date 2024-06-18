#include "supprimer_utilisateurs.h"
#include "ui_supprimer_utilisateurs.h"
#include <QtSql>
#include <QDateTime>
#include <QMessageBox>

supprimer_utilisateurs::supprimer_utilisateurs(QWidget *parent,const QString& id)
    : QDialog(parent)
    , ui(new Ui::supprimer_utilisateurs)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("SELECT nom, prenom, email, numero FROM users WHERE id = :id");
    query.bindValue(":id", m_id);
    if (query.exec() && query.next()) {
        ui->name_user->setText(query.value(0).toString());
    }
    ui->label_date->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));
    ui->lineEdit_Email_user->hide();
    ui->lineEdit_Etat_user->hide();
    ui->lineEdit_Identifiant_user->hide();
    ui->lineEdit_Motdepasse_user->hide();
    ui->lineEdit_Nom_user->hide();
    ui->lineEdit_Numero_user->hide();
    ui->lineEdit_Prenom_user->hide();
    ui->label_10->hide();
    ui->label_11->hide();
    ui->label_13->hide();
    ui->label_18->hide();
    ui->label_16->hide();
    ui->label_14->hide();
    ui->label_17->hide();
}

supprimer_utilisateurs::~supprimer_utilisateurs()
{
    delete ui;
}

QString supprimer_utilisateurs::getId() const
{
    return m_id;
}

void supprimer_utilisateurs::on_pushButton_supprimer_user_clicked()
{
    if (ui->lineEdit_Nom_user->text().isEmpty() ||
        ui->lineEdit_Email_user->text().isEmpty() ||
        ui->lineEdit_Etat_user->text().isEmpty() ||
        ui->lineEdit_Identifiant_user->text().isEmpty() ||
        ui->lineEdit_ID_user->text().isEmpty() ||
        ui->lineEdit_Motdepasse_user->text().isEmpty() ||
        ui->lineEdit_Numero_user->text().isEmpty() ||
        ui->lineEdit_Prenom_user->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return;
    }

    QString id_user = ui->lineEdit_ID_user->text();

    QSqlQuery query;
    query.prepare("DELETE FROM users WHERE  nom = :nom  AND email = :email AND etat = :etat AND identifiant = :identifiant AND password = :motdepasse AND numero = :numero AND prenom = :prenom AND id = :id_user");

    query.bindValue(":nom", ui->lineEdit_Nom_user->text());
    query.bindValue(":email", ui->lineEdit_Email_user->text());
    query.bindValue(":etat", ui->lineEdit_Etat_user->text());
    query.bindValue(":identifiant", ui->lineEdit_Identifiant_user->text());
    query.bindValue(":motdepasse", ui->lineEdit_Motdepasse_user->text());
    query.bindValue(":numero", ui->lineEdit_Numero_user->text());
    query.bindValue(":prenom", ui->lineEdit_Prenom_user->text());
    query.bindValue(":id_user",ui->lineEdit_ID_user->text());

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Les informations de l'utilisateur ont supprimer avec succes.");
        this->hide();
        supprimer_utilisateurs supprimer_utilisateurs(nullptr, getId());
        supprimer_utilisateurs.setModal(true);
        supprimer_utilisateurs.exec();
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la mise à jour des informations de l'utilisateur.");
    }
}


void supprimer_utilisateurs::on_pushButton_Rechercher_user_clicked()
{
    QString id_user= ui->lineEdit_ID_user->text();
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE id = :id_user");
    query.bindValue(":id_user", id_user);

    if (query.exec() && query.next()) {

        // Remplir les QLineEdit avec les données de la base de données
        ui->lineEdit_Nom_user->setText(query.value("nom").toString());
        ui->lineEdit_Email_user->setText(query.value("email").toString());
        ui->lineEdit_Etat_user->setText(query.value("etat").toString());
        ui->lineEdit_Identifiant_user->setText(query.value("identifiant").toString());
        ui->lineEdit_Motdepasse_user->setText(query.value("password").toString());
        ui->lineEdit_Numero_user->setText(query.value("numero").toString());
        ui->lineEdit_Prenom_user->setText(query.value("prenom").toString());

        // Show all fields and buttons now
        ui->lineEdit_Email_user->show();
        ui->lineEdit_Etat_user->show();
        ui->lineEdit_Identifiant_user->show();
        ui->lineEdit_Motdepasse_user->show();
        ui->lineEdit_Nom_user->show();
        ui->lineEdit_Numero_user->show();
        ui->lineEdit_Prenom_user->show();
        ui->pushButton_supprimer_user->show();
        ui->label_10->show();
        ui->label_11->show();
        ui->label_13->show();
        ui->label_18->show();
        ui->label_16->show();
        ui->label_14->show();
        ui->label_17->show();
        ui->pushButton_Rechercher_user->hide();

    } else {
        QMessageBox::warning(this, "Erreur", "Utilisateur non trouvé.");

    }
}


void supprimer_utilisateurs::on_pushButton_Precedent_clicked()
{
    this->hide();
    gestion_utilisateurs gestion_utilisateurs(nullptr, getId());
    gestion_utilisateurs.setModal(true);
    gestion_utilisateurs.exec();

}


void supprimer_utilisateurs::on_pushButton_6_clicked()
{
    exit(1);
}

