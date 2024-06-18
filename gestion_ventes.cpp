#include "gestion_ventes.h"
#include "ui_gestion_ventes.h"
#include<QDateTime>
#include<QSqlQuery>
#include<QMessageBox>
#include<QErrorMessage>
#include<QDebug>
#include<QSqlError>

gestion_ventes::gestion_ventes(QWidget *parent,const QString& id)
    : QDialog(parent)
    , ui(new Ui::gestion_ventes),m_id(id)
{
    ui->setupUi(this);
    ui->label_date->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));
    QSqlQuery query0;
    query0.prepare("SELECT nom FROM users WHERE id =:id");
    query0.bindValue(":id",id);
    if(query0.exec() && query0.next()){
        ui->nome_user->setText(query0.value(0).toString());
    }
    QSqlQuery query;
    query.prepare("SELECT id_vent, quantite_vent, date_vent, id_Med, id_user,id_Client FROM Ventes");
    query.bindValue(":id", id); // Lier la valeur de l'ID utilisateur à la requête
    if (query.exec()) {
        // Définir le nombre de lignes du tableau en fonction du nombre de résultats de la requête
        int rowCount = 0;
        while (query.next()) {
            rowCount++;
        }
        ui->tableventeWidget->setRowCount(rowCount);

        // Remplir le tableau avec les données de la requête
        int row = 0; // Commencez à partir de 0
        query.first(); // Retourner au début de la requête
        do {
            for (int i = 0; i < 5; i++) {
                qDebug() << "Valeur de la colonne" << i << ":" << query.value(i).toString();
            }

            ui->tableventeWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // Colonne 0
            ui->tableventeWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // Colonne 1
            ui->tableventeWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // Colonne 2
            ui->tableventeWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // Colonne 3
            ui->tableventeWidget->setItem(row, 4, new QTableWidgetItem(query.value(4).toString())); // Colonne 4
            ui->tableventeWidget->setItem(row, 5, new QTableWidgetItem(query.value(5).toString())); // Colonne 4
            row++;
        } while (query.next());
    }
    else {
        // Afficher un message d'erreur en cas d'échec de l'exécution de la requête
        QMessageBox::critical(this, tr("Erreur"), tr("Échec de la récupération des données de vente: %1").arg(query.lastError().text()));
    }
}

gestion_ventes::~gestion_ventes()
{
    delete ui;
}
QString gestion_ventes::getId() const
{
    return m_id;
}

void gestion_ventes::on_pushButtonquitter_clicked()
{
   exit(1);
}


void gestion_ventes::on_pushButton_Recherchevente_clicked()
{
    QString codeMedicament = ui->lineEdit_codeMed->text();
    int Quantite = ui->lineEdit_Quantit->text().toInt();
    QString Code_client = ui->lineEdit_idClient->text();
    int identifiant = ui->lineEdit_id_vente->text().toInt();
    QDate DATE = QDate::fromString(ui->lineEdit_date_vente->text(), "dd/MM/yyyy");
    QString Code_user = ui->lineEdit_ID_user->text();

    QString queryCondition = "SELECT * FROM Ventes WHERE 1=1"; // Ensures we can safely append AND conditions

    if (!codeMedicament.isEmpty()) {
        queryCondition += " AND id_Med = :codeMedicament";
    }

    if (Quantite != 0) {
        queryCondition += " AND quantite_vent = :Quantite";
    }

    if (!DATE.isNull()) {
        queryCondition += " AND date_vent = :DATE";
    }

    if (!Code_client.isEmpty()) {
        queryCondition += " AND id_Client = :Code_client";
    }

    if (identifiant != 0) {
        queryCondition += " AND id_vent = :identifiant";
    }

    if (!Code_user.isEmpty()) {
        queryCondition += " AND id_user = :Code_user";
    }

    QSqlQuery rechercheQuery;
    rechercheQuery.prepare(queryCondition);

    // Bind values only if the condition is met
    if (!codeMedicament.isEmpty()) {
        rechercheQuery.bindValue(":codeMedicament", codeMedicament);
    }
    if (Quantite != 0) {
        rechercheQuery.bindValue(":Quantite", Quantite);
    }
    if (!DATE.isNull()) {
        rechercheQuery.bindValue(":DATE", DATE);
    }
    if (!Code_client.isEmpty()) {
        rechercheQuery.bindValue(":Code_client", Code_client);
    }
    if (identifiant != 0) {
        rechercheQuery.bindValue(":identifiant", identifiant);
    }
    if (!Code_user.isEmpty()) {
        rechercheQuery.bindValue(":Code_user", Code_user);
    }

    if (rechercheQuery.exec()) {
        ui->tableventeWidget->clearContents();
        ui->tableventeWidget->setRowCount(0);

        int row = 0;
        while (rechercheQuery.next()) {
            ui->tableventeWidget->insertRow(row);
            ui->tableventeWidget->setItem(row, 0, new QTableWidgetItem(rechercheQuery.value(0).toString())); // ID vente
            ui->tableventeWidget->setItem(row, 1, new QTableWidgetItem(rechercheQuery.value(1).toString())); // Quantité
            ui->tableventeWidget->setItem(row, 2, new QTableWidgetItem(rechercheQuery.value(2).toString())); // Date de vente
            ui->tableventeWidget->setItem(row, 3, new QTableWidgetItem(rechercheQuery.value(3).toString())); // Code médicament
            ui->tableventeWidget->setItem(row, 4, new QTableWidgetItem(rechercheQuery.value(4).toString())); // Code client
            ui->tableventeWidget->setItem(row, 5, new QTableWidgetItem(rechercheQuery.value(5).toString())); // Code user
            row++;
        }
    }
}

void gestion_ventes::on_pushButton_Ajouter_fournisseur_clicked()
{
    this->hide();
    Ajouter_vente_by_gerant Ajouter_vente_by_gerant(nullptr,getId());
    Ajouter_vente_by_gerant.setModal(true);
    Ajouter_vente_by_gerant.exec();
}


void gestion_ventes::on_pushButton_supprimer_fournisseur_clicked()
{

    this->hide();
    Ajouter_vente_by_gerant Ajouter_vente_by_gerant(nullptr,getId());
    Ajouter_vente_by_gerant.setModal(true);
    Ajouter_vente_by_gerant.exec();

}


void gestion_ventes::on_pushButton_accueilgerat_clicked()
{
    this->hide();
    accueil_gerant accueil_gerant(nullptr,getId());
    accueil_gerant.setModal(true);
    accueil_gerant.exec();
}


void gestion_ventes::on_ButtonProfil_gerant_clicked()
{
    this->hide();
    profil_gerant profil_gerant(nullptr,getId());
    profil_gerant.setModal(true);
    profil_gerant.exec();
}


void gestion_ventes::on_pushButton_gerer_fournisseur_clicked()
{
    this->hide();
    gestion_fournisseur gestion_fournisseur(nullptr,getId());
    gestion_fournisseur.setModal(true);
    gestion_fournisseur.exec();

}


void gestion_ventes::on_pushButton_gerer_stock_clicked()
{
    this->hide();
    gerer_stock gerer_stock(nullptr,getId());
    gerer_stock.setModal(true);
    gerer_stock.exec();
}


void gestion_ventes::on_pushButton_gerer_utilisateurs_clicked()
{
    this->hide();
    gestion_utilisateurs gestion_utilisateurs(nullptr,getId());
    gestion_utilisateurs.setModal(true);
    gestion_utilisateurs.exec();
}


void gestion_ventes::on_pushButton_Modifier_fournisseur_clicked()
{

}

