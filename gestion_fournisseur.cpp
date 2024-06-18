#include "gestion_fournisseur.h"
#include "ui_gestion_fournisseur.h"
#include "Supprimer_fournisseur.h"
#include <QtSql>
#include <QDateTime>
gestion_fournisseur::gestion_fournisseur(QWidget *parent,const QString& id)
    : QDialog(parent)
    , ui(new Ui::gestion_fournisseur),m_id(id)
{
    ui->setupUi(this);
     ui->label_date->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));
     QSqlQuery query;
    query.prepare("SELECT nom FROM users WHERE id =:id");
     query.bindValue(":id",id);
    if(query.exec() && query.next()){
        ui->nome_user->setText(query.value(0).toString());
    }
    QStringList columnNames;
    columnNames << "ID Fournisseur" << "Nom Fournisseur" << "Adresse" << "Numéro de Téléphone" << "Code Médicament";
    ui->tablestock->setColumnCount(columnNames.size());
    ui->tablestock->setHorizontalHeaderLabels(columnNames);


    QSqlQuery   FournisseurQuery;
    FournisseurQuery.prepare("SELECT * FROM Fournisseurs     ");

    if (FournisseurQuery.exec()) {
        int row = 0;
        while (FournisseurQuery.next()) {

            ui->tablestock->insertRow(row);
            ui->tablestock->setItem(row, 0, new QTableWidgetItem(FournisseurQuery.value(0).toString()));
            ui->tablestock->setItem(row, 1, new QTableWidgetItem(FournisseurQuery.value(1).toString()));
            ui->tablestock->setItem(row, 2, new QTableWidgetItem(FournisseurQuery.value(2).toString()));
            ui->tablestock->setItem(row, 3, new QTableWidgetItem(FournisseurQuery.value(3).toString()));
            ui->tablestock->setItem(row, 4, new QTableWidgetItem(FournisseurQuery.value(4).toString()));

            row++;
        }
    }
    ui->tablestock->setColumnWidth(0, 120);
    ui->tablestock->setColumnWidth(1, 170);
    ui->tablestock->setColumnWidth(2, 170);
    ui->tablestock->setColumnWidth(3, 170);
    ui->tablestock->setColumnWidth(4, 180);

}

gestion_fournisseur::~gestion_fournisseur()
{
    delete ui;
}

void gestion_fournisseur::on_pushButton_Recherche_fournisseur_clicked()
{
    QString id_fournisseur = ui->LineEdit_id_fournisseur->text();
    QString Nom_fournisseur = ui->lineEdit_Nom_fournisseur->text();
    QString telephone = ui->lineEdit_telephone->text();
    QString code_med= ui->lineEdit_codeMed_fournisseur->text();
    QString address = ui->lineEdit_adresse_fournisseur->text();

    QString queryCondition = "SELECT * FROM Fournisseurs WHERE 1=1";

    if (!id_fournisseur.isEmpty()) {
        queryCondition += " AND id_f = :id_fournisseur";
    }

    if (!Nom_fournisseur.isEmpty()) {
        queryCondition += " AND Nom_f = :Nom_fournisseur";
    }

    if (!telephone.isEmpty()) {
        queryCondition += " AND Telephone = :telephone";
    }

    if (!code_med.isEmpty()) {
        queryCondition += " AND id_Med = :code_med";
    }
    if (! address.isEmpty()) {
        queryCondition += " AND Adresse = :address";
    }
    QSqlQuery rechercheQuery;
    rechercheQuery.prepare(queryCondition);

    rechercheQuery.bindValue(":id_fournisseur", id_fournisseur);
    rechercheQuery.bindValue(":Nom_fournisseur", Nom_fournisseur);
    rechercheQuery.bindValue(":telephone", telephone);
    rechercheQuery.bindValue(":code_med", code_med);
    rechercheQuery.bindValue(":address", address);

    if (rechercheQuery.exec()) {
        ui->tablestock->clearContents();
        ui->tablestock->setRowCount(0);

        int row = 0;
        while (rechercheQuery.next()) {
            ui->tablestock->insertRow(row);
            ui->tablestock->setItem(row, 0, new QTableWidgetItem(rechercheQuery.value(0).toString()));
            ui->tablestock->setItem(row, 1, new QTableWidgetItem(rechercheQuery.value(1).toString()));
            ui->tablestock->setItem(row, 2, new QTableWidgetItem(rechercheQuery.value(2).toString()));
            ui->tablestock->setItem(row, 3, new QTableWidgetItem(rechercheQuery.value(3).toString()));
            ui->tablestock->setItem(row, 4, new QTableWidgetItem(rechercheQuery.value(4).toString()));
            row++;
        }
    }
}


QString gestion_fournisseur::getId() const
{
    return m_id;
}

void gestion_fournisseur::on_pushButton_6_clicked()
{
    exit(1);
}




void gestion_fournisseur::on_pushButton_accueilgerat_clicked()
{
    this->hide();
    QString id = getId();

    accueil_gerant accueil_gerant(nullptr, id);
    accueil_gerant.setModal(true);
    accueil_gerant.exec();
}




void gestion_fournisseur::on_pushButton_Ajouter_fournisseur_clicked()
{
    this->hide();
     Ajouter_fournisseur  Ajouter_fournisseur(nullptr,getId());
     Ajouter_fournisseur.setModal(true);
     Ajouter_fournisseur.exec();
}


void gestion_fournisseur::on_pushButton_supprimer_fournisseur_clicked()
{
    this->hide();
    Supprimer_fournisseur  Supprimer_fournisseur(nullptr,getId());
    Supprimer_fournisseur.setModal(true);
   Supprimer_fournisseur.exec();
}


void gestion_fournisseur::on_pushButton_Modifier_fournisseur_clicked()
{
    this->hide();
    modifier_fournisseur  modifier_fournisseur(nullptr,getId());
    modifier_fournisseur.setModal(true);
    modifier_fournisseur.exec();

}


void gestion_fournisseur::on_ButtonProfil_gerant_clicked()
{
    this->hide();
    profil_gerant  profil_gerant(nullptr,getId());
    profil_gerant.setModal(true);
    profil_gerant.exec();
}


void gestion_fournisseur::on_pushButton_gere_vente_clicked()
{
    this->hide();
    gestion_ventes  gestion_ventes(nullptr,getId());
    gestion_ventes.setModal(true);
    gestion_ventes.exec();
}


void gestion_fournisseur::on_pushButton_gerer_stock_clicked()
{
    this->hide();
    gerer_stock  gerer_stock(nullptr,getId());
    gerer_stock.setModal(true);
    gerer_stock.exec();
}


void gestion_fournisseur::on_pushButton_gerer_fournisseur_clicked()
{
    this->hide();
    gestion_fournisseur  gestion_fournisseur(nullptr,getId());
    gestion_fournisseur.setModal(true);
    gestion_fournisseur.exec();
}


void gestion_fournisseur::on_pushButton_gerer_utilisateurs_clicked()
{
    this->hide();
    gestion_utilisateurs  gestion_utilisateurs(nullptr,getId());
    gestion_utilisateurs.setModal(true);
    gestion_utilisateurs.exec();
}

