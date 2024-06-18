#include "affichervente.h"
#include "ui_affichervente.h"
#include <QDateTime>
#include <QtSql>
affichervente::affichervente(QWidget *parent,const QString& id)
    : QDialog(parent)
    , ui(new Ui::affichervente), m_id(id)
{
    ui->setupUi(this);
    ui->label_date->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));

    // Récupérer et afficher le nom de l'utilisateur
    QSqlQuery query;
    query.prepare("SELECT nom FROM users WHERE id = :id");
    query.bindValue(":id", m_id);
    if (query.exec() && query.next()) {
        ui->nome_username->setText(query.value(0).toString());
    }

    // Définir les noms des colonnes
    QStringList columnNames;
    columnNames << "ID Vente" << "Quantité" << "Date de Vente" << "Code Médicament" << "Code Client";
    ui->tablestock->setColumnCount(columnNames.size());
    ui->tablestock->setHorizontalHeaderLabels(columnNames);

    // Récupérer et afficher les données de vente
    QSqlQuery venteQuery;
    venteQuery.prepare("SELECT * FROM ventes WHERE id_user = :id");
    venteQuery.bindValue(":id", m_id);
    if (venteQuery.exec()) {
        int row = 0;
        while (venteQuery.next()) {
            // Insérer les données dans le tableau des ventes
            ui->tablestock->insertRow(row);
            ui->tablestock->setItem(row, 0, new QTableWidgetItem(venteQuery.value(0).toString())); // ID vente
            ui->tablestock->setItem(row, 1, new QTableWidgetItem(venteQuery.value(1).toString())); // Quantité
            ui->tablestock->setItem(row, 2, new QTableWidgetItem(venteQuery.value(2).toString())); // Date de vente
            ui->tablestock->setItem(row, 3, new QTableWidgetItem(venteQuery.value(3).toString())); // Code médicament
            ui->tablestock->setItem(row, 4, new QTableWidgetItem(venteQuery.value(5).toString())); // Code client
            row++;
        }
    }
    ui->tablestock->setColumnWidth(0, 150); // ID Vente
    ui->tablestock->setColumnWidth(1, 150); // Quantité
    ui->tablestock->setColumnWidth(2, 170); // Date de Vente
    ui->tablestock->setColumnWidth(3, 160); // Code Médicament
    ui->tablestock->setColumnWidth(4, 160); // Code Client

}


affichervente::~affichervente()
{
    delete ui;
}


QString affichervente::getId() const
{
    return m_id;
}

void affichervente::on_pushButton_profil_clicked()
{
    this->hide();
    profil profil(nullptr, getId()); // Pass the ID to the profil constructor
    profil.setModal(true);
    profil.exec();
}




void affichervente::on_pushButton_Recherche_clicked()
{
    QString codeMedicament = ui->lineEdit_codeMed->text();
    int Quantite = ui->lineEdit_Quantit->text().toInt();
    QString Code_client = ui->lineEdit_idClient->text();
    int identifiant = ui->lineEdit_id_vente->text().toInt();
    QDate DATE = QDate::fromString(ui->lineEdit_date_vente->text(), "dd/MM/yyyy");

    QString queryCondition = "SELECT *FROM Ventes WHERE id_user=:id";

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

    QSqlQuery rechercheQuery;
    rechercheQuery.prepare(queryCondition);
    rechercheQuery.bindValue(":id", m_id);
    rechercheQuery.bindValue(":codeMedicament", codeMedicament);
    rechercheQuery.bindValue(":Quantite", Quantite);
    rechercheQuery.bindValue(":DATE", DATE);
    rechercheQuery.bindValue(":Code_client", Code_client);
    rechercheQuery.bindValue(":identifiant", identifiant);

    if (rechercheQuery.exec()) {
        ui->tablestock->clearContents();
        ui->tablestock->setRowCount(0);

        int row = 0;
        while (rechercheQuery.next()) {
            ui->tablestock->insertRow(row);
            ui->tablestock->setItem(row, 0, new QTableWidgetItem(rechercheQuery.value(0).toString())); // ID vente
            ui->tablestock->setItem(row, 1, new QTableWidgetItem(rechercheQuery.value(1).toString())); // Quantité
            ui->tablestock->setItem(row, 2, new QTableWidgetItem(rechercheQuery.value(2).toString())); // Date de vente
            ui->tablestock->setItem(row, 3, new QTableWidgetItem(rechercheQuery.value(3).toString())); // Code médicament
            ui->tablestock->setItem(row, 4, new QTableWidgetItem(rechercheQuery.value(5).toString())); // Code client
            row++;

        }
    }
}


void affichervente::on_pushButton_consultervente_clicked()
{
    this->hide();
    affichervente affichervente(nullptr, getId());
    affichervente.setModal(true);
    affichervente.exec();

}


void affichervente::on_pushButton_ajoute_vente_clicked()
{
    this->hide();
    ajouterVente ajouterVente(nullptr, getId());
    ajouterVente.setModal(true);
    ajouterVente.exec();

}


void affichervente::on_pushButton_consulter_stock_clicked()
{
    this->hide();
    consulter_stock consulter_stock(nullptr, getId());
    consulter_stock.setModal(true);
    consulter_stock.exec();

}


void affichervente::on_pushButton_chercher_med_clicked()
{
    this->hide();
    recherchermed_emp recherchermed_emp(nullptr, getId());
    recherchermed_emp.setModal(true);
    recherchermed_emp.exec();
}


void affichervente::on_pushButton_quitter_clicked()
{
    exit(0);
}

