#include "accueil_gerant.h"
#include "gestion_fournisseur.h"
#include "ui_accueil_gerant.h"
#include <QtSql>
#include <QDateTime>
accueil_gerant::accueil_gerant(QWidget *parent, const QString& id) :
    QDialog(parent),
    ui(new Ui::accueil_gerant), m_id(id)
{
    ui->setupUi(this);
     QSqlQuery query;
    query.prepare("SELECT nom FROM users WHERE id = :id");
    query.bindValue(":id", m_id);
    if (query.exec() && query.next()) {
        ui->nome_user->setText(query.value(0).toString());
    }
    ui->label_date->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));
}

accueil_gerant::~accueil_gerant()
{
    delete ui;
}

QString accueil_gerant::getId() const
{
    return m_id;
}

void accueil_gerant::on_ButtonProfil_clicked()
{

    this->hide();

    profil_gerant profil_gerant(nullptr, getId()); // Pass the ID to the profil constructor
    profil_gerant.setModal(true);
     profil_gerant.exec();

}







void accueil_gerant::on_pushButton_gerer_fournisseur_clicked()
{
    this->hide();
    gestion_fournisseur gestion_fournisseur(nullptr, getId());
    gestion_fournisseur.setModal(true);
    gestion_fournisseur.exec();
}


void accueil_gerant::on_ButtongererStock_gerant_clicked()
{
    this->hide();
    gerer_stock gerer_stock(nullptr,getId());
    gerer_stock.setModal(true);
    gerer_stock.exec();
}





void accueil_gerant::on_pushButton_gere_vente_clicked()
{
    this->hide();
    gestion_ventes gestion_ventes(nullptr,getId());
    gestion_ventes.setModal(true);
    gestion_ventes.exec();
}


void accueil_gerant::on_pushButton_gerer_utilisateurs_clicked()
{
    this->hide();
    gestion_utilisateurs gestion_utilisateurs(nullptr,getId());
    gestion_utilisateurs.setModal(true);
    gestion_utilisateurs.exec();

}


void accueil_gerant::on_pushButton_accueilgerat_clicked()
{
    this->hide();
    accueil_gerant accueil_gerant(nullptr,getId());
    accueil_gerant.setModal(true);
    accueil_gerant.exec();

}


void accueil_gerant::on_pushButton_6_clicked()
{
     this->hide();
}

