#include "ajouter_utilisateurs.h"
#include "ui_ajouter_utilisateurs.h"
#include <QDateTime>
#include <QtSql>
#include <QMessageBox>

ajouter_utilisateurs::ajouter_utilisateurs(QWidget *parent, const QString &id)
    : QDialog(parent)
    , ui(new Ui::ajouter_utilisateurs)
    , m_id(id)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE id = :id");
    query.bindValue(":id", m_id);
    if (query.exec() && query.next()) {
        ui->name_user->setText(query.value(1).toString());
    }
    ui->label_date->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));
}

ajouter_utilisateurs::~ajouter_utilisateurs()
{
    delete ui;
}

QString ajouter_utilisateurs::getId() const {
    return m_id;
}

void ajouter_utilisateurs::on_pushButton_Ajouter_user_clicked()
{
    QString Id_user = ui->lineEdit_ID_user->text();
    QString Nom_user = ui->lineEdit_Nom_user->text();
    QString Prenom_user = ui->lineEdit_Prenom_user->text();
    QString Identifier_user = ui->lineEdit_Identifiant_user->text();
    QString Modpass_user = ui->lineEdit_Motdepasse_user->text();
    QString Email_user = ui->lineEdit_Email_user->text();
    QString Etat_user = ui->lineEdit_Etat_user->text();
    QString Telephone_user = ui->lineEdit_Numero_user->text();

    if (!Id_user.isEmpty() && !Nom_user.isEmpty() && !Prenom_user.isEmpty() && !Identifier_user.isEmpty() && !Modpass_user.isEmpty() && !Email_user.isEmpty() && !Etat_user.isEmpty() && !Telephone_user.isEmpty()) {

        QSqlQuery query1;
        query1.prepare("SELECT * FROM users WHERE id = :Id_user OR identifiant = :Identifier_user OR email = :Email_user OR numero = :Telephone_user");
        query1.bindValue(":Id_user", Id_user);
        query1.bindValue(":Identifier_user", Identifier_user);
        query1.bindValue(":Email_user", Email_user);
        query1.bindValue(":Telephone_user", Telephone_user);

        if (query1.exec() && query1.next()) {
            QMessageBox::information(this, "Erreur", "Les données saisies existent déjà dans la table des utilisateurs.");
        } else {
            QSqlQuery query2;
            query2.prepare("INSERT INTO users (id, nom, prenom, identifiant, password, email, etat, numero) VALUES (:Id_user, :Nom_user, :Prenom_user, :Identifier_user, :Modpass_user, :Email_user, :Etat_user, :Telephone_user)");
            query2.bindValue(":Id_user", Id_user);
            query2.bindValue(":Nom_user", Nom_user);
            query2.bindValue(":Prenom_user", Prenom_user);
            query2.bindValue(":Identifier_user", Identifier_user);
            query2.bindValue(":Modpass_user", Modpass_user);
            query2.bindValue(":Email_user", Email_user);
            query2.bindValue(":Etat_user", Etat_user);
            query2.bindValue(":Telephone_user", Telephone_user);

            if (query2.exec()) {
                QMessageBox::information(this, "Succès", "Utilisateur ajouté avec succès.");
            } else {
                QMessageBox::critical(this, "Erreur", "Échec de l'ajout de l'utilisateur : " + query2.lastError().text());
            }
        }
    } else {
        QMessageBox::information(this, "Erreur", "Tous les champs doivent être remplis.");
    }
}

void ajouter_utilisateurs::on_pushButton_Precedent_clicked()
{
    this->hide();
    gestion_utilisateurs gestion_utilisateurs(nullptr, getId());
    gestion_utilisateurs.setModal(true);
    gestion_utilisateurs.exec();
}


void ajouter_utilisateurs::on_pushButton_6_clicked()
{
    exit(1);
}

