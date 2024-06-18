#include "consulter_stock.h"
#include "ui_consulter_stock.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
consulter_stock::consulter_stock(QWidget *parent, const QString& id)
    : QDialog(parent)
    , ui(new Ui::consulter_stock)
    , m_id(id)
{
    ui->setupUi(this);
    QSqlQuery query1;
    query1.prepare("SELECT nom FROM users WHERE id = :id");
    query1.bindValue(":id", m_id);
    if (query1.exec() && query1.next()) {
      ui->label_nom->setText(query1.value(0).toString());
    }
    // Créer un modèle pour stocker les données de la table Medicament
    QSqlQueryModel *model = new QSqlQueryModel(this);
   ui->label_date->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));
    // Exécuter une requête SQL pour récupérer les données de la table Medicament
    QSqlQuery query;
    query.prepare("SELECT id_Med, nom_Med, Date_Med, Quantite, prix FROM Medicament");
    if (query.exec()) {
        // Définir la requête sur le modèle
        model->setQuery(query);

        // Configurer les en-têtes de colonne
        model->setHeaderData(0, Qt::Horizontal, tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, tr("Date d'expiration")); // Au lieu de "Date"

        model->setHeaderData(3, Qt::Horizontal, tr("Quantité"));
        model->setHeaderData(4, Qt::Horizontal, tr("Prix"));

        // Ajouter les données du modèle à la QTableWidget
        ui->tablestock->setRowCount(model->rowCount());
        ui->tablestock->setColumnCount(model->columnCount());
        for (int row = 0; row < model->rowCount(); ++row) {
            for (int column = 0; column < model->columnCount(); ++column) {
                QModelIndex index = model->index(row, column);
                ui->tablestock->setItem(row, column, new QTableWidgetItem(model->data(index).toString()));
            }
        }ui->tablestock->verticalHeader()->setVisible(false);
        ui->tablestock->setStyleSheet("QTableView::verticalHeader { border: none; }");
        // Configurer les en-têtes de colonne de la QTableWidget
        ui->tablestock->setHorizontalHeaderLabels({tr("ID"), tr("Nom"), tr("Date d'expiration "), tr("Quantité"), tr("Prix (DH)")});
        // Augmenter la taille de chaque colonne
        ui->tablestock->setColumnWidth(0, 100); // ID
        ui->tablestock->setColumnWidth(1, 180); // Nom
        ui->tablestock->setColumnWidth(2, 180); // Date
        ui->tablestock->setColumnWidth(3, 180); // Quantité
        ui->tablestock->setColumnWidth(4, 180); // Prix
        // Augmenter la hauteur de chaque ligne
        for (int row = 0; row < model->rowCount(); ++row) {
            ui->tablestock->setRowHeight(row, 30); // 50 pixels de hauteur pour chaque ligne
        }
    } else {
        qDebug() << "Query failed:" << query.lastError().text();
    }
}

consulter_stock::~consulter_stock()
{
    delete ui;
}

QString consulter_stock::getId() const
{
    return m_id;
}

void consulter_stock::on_ButtonProfil_2_clicked()
{
    QString id;
    this->hide();

    profil profil(nullptr, getId()); // Pass the ID to the profil constructor
    profil.setModal(true);
    profil.exec();
}


void consulter_stock::on_pushButton_quitter_clicked()
{
    exit(1);
}


void consulter_stock::on_pushButton_affiche_vente_clicked()
{
    this->hide();

    affichervente affichervente(nullptr, getId()); // Pass the ID to the profil constructor
    affichervente.setModal(true);
    affichervente.exec();
}


void consulter_stock::on_pushButton_10_clicked()
{

    this->hide();

   ajouterVente ajoutervente(nullptr, getId());
    ajoutervente.setModal(true);
    ajoutervente.exec();

}


void consulter_stock::on_pushButton_5_clicked()
{
    this->hide();

    recherchermed_emp recherchermed_emp(nullptr, getId());
    recherchermed_emp.setModal(true);
    recherchermed_emp.exec();
}

