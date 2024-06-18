#include "modifier_fournisseur.h"
#include "ui_modifier_fournisseur.h"
#include <QtSql>
#include <QDateTime>
#include <QMessageBox>
modifier_fournisseur::modifier_fournisseur(QWidget *parent,const QString& id)
    : QDialog(parent)
    , ui(new Ui::modifier_fournisseur),m_id(id)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("SELECT nom, prenom, email, numero FROM users WHERE id = :id");
    query.bindValue(":id", m_id);
    if (query.exec() && query.next()) {
        ui->name_user->setText(query.value(0).toString());
    }
    ui->label_date->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));
    ui->lineEdit_Nom_fournisseur->hide();
    ui->lineEdit_addresse_fournisseur->hide();
    ui->lineEdit_Numero_Telephone->hide();
    ui->lineEdit_Code_Med->hide();
    ui->label_10->hide();
    ui->label_11->hide();
    ui->label_13->hide();
    ui->label_14->hide();
}

modifier_fournisseur::~modifier_fournisseur()
{
    delete ui;
}
QString modifier_fournisseur::getId() const
{
    return m_id;
}


void modifier_fournisseur::on_pushButton_valider_modification_clicked()
{
    // Validate input fields before updating
    if (ui->lineEdit_Nom_fournisseur->text().isEmpty() ||
        ui->lineEdit_addresse_fournisseur->text().isEmpty() ||
        ui->lineEdit_Numero_Telephone->text().isEmpty() ||
        ui->lineEdit_Code_Med->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return;
    }
    QString id_four= ui->lineEdit_ID_Fournisseur->text();
    // Update fournisseur information in the database
    QSqlQuery query;
    query.prepare("UPDATE Fournisseurs SET Nom_f = :nom, Adresse = :adresse, Telephone = :numero, id_Med = :code_med WHERE id_f = :id_four");

    query.bindValue(":nom", ui->lineEdit_Nom_fournisseur->text());
    query.bindValue(":adresse", ui->lineEdit_addresse_fournisseur->text());
    query.bindValue(":numero", ui->lineEdit_Numero_Telephone->text());
    query.bindValue(":code_med", ui->lineEdit_Code_Med->text());
    query.bindValue(":id_four",id_four );

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Les informations du fournisseur ont été mises à jour.");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la mise à jour des informations du fournisseur.");
    }
}


void modifier_fournisseur::on_pushButton_Precedent_clicked()
{

    this->hide();
    gestion_fournisseur gestion_fournisseur(nullptr, getId());
    gestion_fournisseur.setModal(true);
    gestion_fournisseur.exec();
}


void modifier_fournisseur::clearFields()
{
    ui->lineEdit_Nom_fournisseur->clear();
    ui->lineEdit_addresse_fournisseur->clear();
    ui->lineEdit_Numero_Telephone->clear();
    ui->lineEdit_Code_Med->clear();

    ui->lineEdit_Nom_fournisseur->hide();
    ui->lineEdit_addresse_fournisseur->hide();
    ui->lineEdit_Numero_Telephone->hide();
    ui->lineEdit_Code_Med->hide();
    ui->pushButton_valider_modification->hide();

    ui->name_user->hide();
}

void modifier_fournisseur::on_pushButton_Recherche_idfour_clicked()
{
    QString id_four= ui->lineEdit_ID_Fournisseur->text();
    QSqlQuery query;
    query.prepare("SELECT Nom_f, Adresse, Telephone,id_Med FROM Fournisseurs WHERE id_f = :id_four");
    query.bindValue(":id_four", id_four);

    if (query.exec() && query.next()) {
        ui->lineEdit_Nom_fournisseur->setText(query.value(0).toString());
        ui->lineEdit_addresse_fournisseur->setText(query.value(1).toString());
        ui->lineEdit_Numero_Telephone->setText(query.value(2).toString());
        ui->lineEdit_Code_Med->setText(query.value(3).toString());

        // Show all fields and buttons now
        ui->lineEdit_Nom_fournisseur->show();
        ui->lineEdit_addresse_fournisseur->show();
        ui->lineEdit_Numero_Telephone->show();
        ui->lineEdit_Code_Med->show();
        ui->pushButton_valider_modification->show();
        ui->pushButton_Recherche_idfour->hide();
        ui->label_10->show();
        ui->label_11->show();
        ui->label_13->show();
        ui->label_14->show();

    } else {
        QMessageBox::warning(this, "Erreur", "Fournisseur non trouvé.");
        clearFields();
    }
}


void modifier_fournisseur::on_pushButton_6_clicked()
{
   exit(1);
}

