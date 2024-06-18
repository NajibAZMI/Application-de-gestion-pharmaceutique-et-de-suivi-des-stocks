#include "gerer_stock.h"
#include "ui_gerer_stock.h"
#include <QMessageBox>
#include <QtSql>
gerer_stock::gerer_stock(QWidget *parent, const QString &id)
    : QDialog(parent)
    , ui(new Ui::gerer_stock)
    , m_id(id)
    , model(new QSqlQueryModel(this))
    , currentMedicineId("")
{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("SELECT nom FROM users WHERE id = :id");
    query.bindValue(":id", m_id);
    if (query.exec() && query.next()) {
        ui->nome_user->setText(query.value(0).toString());
    }
    ui->label_date->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));
    loadMedicines();
    connect(ui->tableWidget_MED->selectionModel(), &QItemSelectionModel::selectionChanged, this, &gerer_stock::on_tableWidget_MED_itemSelectionChanged);
    connect(ui->searchLineEdit, &QLineEdit::textChanged, this, &gerer_stock::on_searchLineEdit_textChanged);
}

gerer_stock::~gerer_stock()
{
    delete ui;
}

QString gerer_stock::getId() const
{
    return m_id;
}

void gerer_stock::loadMedicines(const QString &filter)
{
    QSqlQuery query;
    QString queryStr = "SELECT * FROM Medicament"; //WHERE Date_Med > DATE('now') AND Quantite > 0

    if (!filter.isEmpty()) {
        queryStr += " WHERE (nom_Med LIKE '%" + filter + "%' OR id_Med LIKE '%" + filter + "%' OR Date_Med LIKE '%" + filter + "%'"
                                                                                                                               " OR Quantite LIKE '%" + filter + "%' OR prix LIKE '%" + filter + "%' OR TVA LIKE '%" + filter + "%')";
    }                                                                                                                              // AND (nom_Med LIKE '%" + filter + "%' OR id_Med LIKE '%" + filter + "%')

    query.prepare(queryStr);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête SQL:" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'exécution de la requête SQL.");
        return;
    }

    ui->tableWidget_MED->clearContents();
    ui->tableWidget_MED->setRowCount(0);

    int row = 0;
    while (query.next()) {
        ui->tableWidget_MED->insertRow(row);
        ui->tableWidget_MED->setItem(row, 0, new QTableWidgetItem(query.value("id_Med").toString()));
        ui->tableWidget_MED->setItem(row, 1, new QTableWidgetItem(query.value("nom_Med").toString()));
        ui->tableWidget_MED->setItem(row, 2, new QTableWidgetItem(query.value("Date_Med").toString()));
        ui->tableWidget_MED->setItem(row, 3, new QTableWidgetItem(query.value("Quantite").toString()));
        ui->tableWidget_MED->setItem(row, 4, new QTableWidgetItem(query.value("prix").toString()));
        ui->tableWidget_MED->setItem(row, 5, new QTableWidgetItem(query.value("TVA").toString()));

        row++;
    }
    for (int i = 0; i <= 5; i++)
        ui->tableWidget_MED->setColumnWidth(i, 150);
}

void gerer_stock::on_tableWidget_MED_itemSelectionChanged()
{
    QModelIndexList indexes = ui->tableWidget_MED->selectionModel()->selectedIndexes();
    if (!indexes.isEmpty()) {
        int selectedRow = indexes.at(0).row();
        currentMedicineId = ui->tableWidget_MED->item(selectedRow, 0)->text();
        qDebug() << "Selected Medicine ID:" << currentMedicineId;
    } else {
        currentMedicineId = "";
    }
}

void gerer_stock::on_pushButton_Ajouter_Med_clicked()
{
    this->hide();
    ajouter_stock_med ajouter_stock_med(nullptr, getId());
    ajouter_stock_med.setModal(true);
    ajouter_stock_med.exec();
}

void gerer_stock::on_searchLineEdit_textChanged(const QString &text)
{
    loadMedicines(text);
}

void gerer_stock::on_pushButton_Supprimer_Med_clicked()
{
    if (currentMedicineId.isEmpty()) {
        QMessageBox::warning(this, "Selection Error", "Please select a medicine to delete.");
        return;
    }

    QMessageBox::StandardButton confirmDelete = QMessageBox::question(this, "Confirm Delete",
                                                                      "Are you sure you want to delete the selected medicine?", QMessageBox::Yes | QMessageBox::No);

    if (confirmDelete == QMessageBox::Yes) {
        QSqlQuery query;
        query.prepare("DELETE FROM Medicament WHERE id_Med=:currentMedicineId");
        query.bindValue(":currentMedicineId", currentMedicineId);

        if (!query.exec()) {
            qDebug() << "Erreur lors de la suppression de l'enregistrement:" << query.lastError().text();
        } else {
            qDebug() << "Enregistrement supprimé avec succès";
        }
    }
}

void gerer_stock::on_pushButton_Modifier_Med_clicked()
{
    if (currentMedicineId.isEmpty()) {
        QMessageBox::warning(this, "Selection Error", "Please select a medicine to modify.");
        return;
    }
    qDebug() << "Passing Medicine ID to Modifier:" << currentMedicineId;
    this->hide();
    modifier_stock_med modifier_stock_med(this, currentMedicineId, getId());
    modifier_stock_med.setModal(true);
    modifier_stock_med.exec();
    this->show();
    loadMedicines();
}

void gerer_stock::on_pushButton_accueilgerat_clicked()
{
    this->hide();
    accueil_gerant gestion_fournisseur(nullptr, getId());
    gestion_fournisseur.setModal(true);
    gestion_fournisseur.exec();
}


void gerer_stock::on_ButtonProfil_clicked()
{
    this->hide();
    profil_gerant profil_gerant(nullptr, getId());
    profil_gerant.setModal(true);
    profil_gerant.exec();
}


void gerer_stock::on_pushButton_gere_vente_clicked()
{
    this->hide();
    gestion_ventes gestion_ventes(nullptr, getId());
    gestion_ventes.setModal(true);
    gestion_ventes.exec();
}


void gerer_stock::on_ButtongererStock_gerant_clicked()
{
    this->hide();
    gerer_stock gerer_stock(nullptr, getId());
    gerer_stock.setModal(true);
    gerer_stock.exec();
}


void gerer_stock::on_pushButton_gerer_fournisseur_clicked()
{
    this->hide();
    gestion_fournisseur gestion_fournisseur(nullptr, getId());
    gestion_fournisseur.setModal(true);
    gestion_fournisseur.exec();
}


void gerer_stock::on_pushButton_gerer_utilisateurs_clicked()
{
    this->hide();
    gestion_utilisateurs gestion_utilisateurs(nullptr, getId());
    gestion_utilisateurs.setModal(true);
    gestion_utilisateurs.exec();
}


void gerer_stock::on_pushButton_6_clicked()
{
    exit(1);
}

