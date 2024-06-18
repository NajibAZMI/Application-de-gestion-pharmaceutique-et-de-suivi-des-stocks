#include "profil_gerant.h"
#include "ui_profil_gerant.h"
#include <QtSql>
#include <QDateTime>
#include "modifier_profil_gerant.h"
profil_gerant::profil_gerant(QWidget *parent,const QString& id)
    : QDialog(parent)
    , ui(new Ui::profil_gerant),m_id(id)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("SELECT*FROM users WHERE id = :id");
    query.bindValue(":id", m_id);
    if (query.exec() && query.next()) {
        ui->label_nom_gerant->setText(query.value(1).toString());
        ui->label_prenom_gerant->setText(query.value(2).toString());
        ui->label_email_gerant->setText(query.value(5).toString());
        ui->label_numero_gerant->setText(query.value(6).toString());
        ui->label_etat_gerant->setText(query.value(7).toString());
        ui->label_identifiant_gerant->setText(query.value(3).toString());
        ui->nome_user->setText(query.value(1).toString());
    }
    ui->label_date->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));
}

profil_gerant::~profil_gerant()
{
    delete ui;
}





QString profil_gerant::getId() const
{
    return m_id;
}










void profil_gerant::on_pushButton_aller_a_modifier_gerant_clicked()
{
    this->hide();

    modifier_profil_gerant modifier_profil_gerant(nullptr, getId()); // Pass the ID to the profil constructor
    modifier_profil_gerant.setModal(true);
    modifier_profil_gerant.exec();

}


void profil_gerant::on_pushButton_gerer_fournisseur_clicked()
{
    this->hide();
    gestion_fournisseur gestion_fournisseur(nullptr, getId());
    gestion_fournisseur.setModal(true);
    gestion_fournisseur.exec();
}


void profil_gerant::on_pushButton_quitter_clicked()
{
   exit(1);
}


void profil_gerant::on_pushButton_accueilgerat_clicked()
{
    this->hide();
   accueil_gerant gestion_fournisseur(nullptr, getId());
    gestion_fournisseur.setModal(true);
    gestion_fournisseur.exec();
}


void profil_gerant::on_pushButton_gere_vente_clicked()
{
    this->hide();
    gestion_ventes gestion_ventes(nullptr, getId());
    gestion_ventes.setModal(true);
    gestion_ventes.exec();
}


void profil_gerant::on_pushButton_gerer_stock_clicked()
{
    this->hide();
    gerer_stock gerer_stock(nullptr, getId());
    gerer_stock.setModal(true);
    gerer_stock.exec();

}


void profil_gerant::on_pushButton_gerer_rupture_2_clicked()
{
}


void profil_gerant::on_pushButton_gerer_utilisateurs_clicked()
{

    this->hide();
    gestion_utilisateurs gestion_utilisateurs(nullptr, getId());
    gestion_utilisateurs.setModal(true);
    gestion_utilisateurs.exec();
}

