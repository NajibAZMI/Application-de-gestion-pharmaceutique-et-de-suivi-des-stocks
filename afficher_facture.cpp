#include "afficher_facture.h"
#include "ui_afficher_facture.h"
#include<QSqlError>
#include<QSqlQuery>
#include <QSql>
#include <QDate>
#include<QString>
#include <QPixmap>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
afficher_facture::afficher_facture(QWidget *parent, const QString& id,const QString& id_client)
    : QDialog(parent)
    , ui(new Ui::afficher_facture),m_id(id),m_idC(id_client)
{
    ui->setupUi(this);
    QSqlQuery query;
    QSqlQuery query1;

    ui->label_Nclient->setText(id_client);

    query.prepare("SELECT nom, prenom FROM users WHERE id = :id");
    query.bindValue(":id", m_id);
    if (query.exec() && query.next()) {
        ui->label_nom->setText(query.value(0).toString());
        ui->label_prenom->setText(query.value(1).toString());
    }
    query1.prepare("SELECT MAX(id_vent), MAX(date_vent) FROM ventes WHERE id_user = :id");
    query1.bindValue(":id", m_id);
    if (query1.exec() && query1.next()) {
        ui->label_Nfacture->setText(query1.value(0).toString());
        ui->label_datefact->setText(query1.value(1).toDate().toString("yyyy-MM-dd"));
    }
    QSqlQuery query3;
    query3.prepare("SELECT m.nom_Med, v.quantite_vent, m.prix, m.TVA FROM Ventes v INNER JOIN Medicament m ON v.id_Med = m.id_Med WHERE v.id_client = :id_client AND date_vent = date('now')");
    query3.bindValue(":id_client", id_client); // Lier la valeur de l'ID client à la requête
    double TOTAL_HT = 0.0;
    double TOTAL_TVA = 0.0;
    double PRIX_TVA = 0.0;
    if (query3.exec()) {
        // Définir le nombre de lignes du tableau en fonction du nombre de résultats de la requête
        int rowCount = 0;


        while (query3.next()) {
            rowCount++;
        }
        ui->tableWidgetfacture->setRowCount(rowCount);

        // Remplir le tableau avec les données de la requête
        int row = 0; // Commencez à partir de 0
        query3.first(); // Retourner au début de la requête
        do {
            for (int i = 0; i < 5; i++) {
                qDebug() << "Valeur de la colonne" << i << ":" << query3.value(i).toString();
            }

            QString nom_Med = query3.value(0).toString();
            int quantite_vent = query3.value(1).toInt();
            double prix = query3.value(2).toDouble();
            double TVA = query3.value(3).toDouble();

            // Calculer le total hors taxe
            double total_ht = prix * quantite_vent;
            TOTAL_HT+=total_ht;
            PRIX_TVA=total_ht*TVA;
            TOTAL_TVA+=PRIX_TVA;
            ui->tableWidgetfacture->setItem(row, 0, new QTableWidgetItem(nom_Med)); // Colonne 0
            ui->tableWidgetfacture->setItem(row, 1, new QTableWidgetItem(QString::number(quantite_vent))); // Colonne 1
            ui->tableWidgetfacture->setItem(row, 2, new QTableWidgetItem(QString::number(prix))); // Colonne 2
            ui->tableWidgetfacture->setItem(row, 3, new QTableWidgetItem(QString::number(TVA))); // Colonne 3 (TVA)
            ui->tableWidgetfacture->setItem(row, 4, new QTableWidgetItem(QString::number(total_ht))); // Colonne 4 (TOTAL HT)
            ui->tableWidgetfacture->setItem(row, 5, new QTableWidgetItem(QString::number(PRIX_TVA))); // Colonne 4 (TOTAL HT)

            row++;
        } while (query3.next());
    }
    else {
        // Afficher un message d'erreur en cas d'échec de l'exécution de la requête
        QMessageBox::critical(this, tr("Erreur"), tr("Échec de la récupération des données de vente: %1").arg(query3.lastError().text()));
    }
    double TOTA_TTC=TOTAL_HT+TOTAL_TVA;
    ui->TOTAL_TH->setText(QString::number(TOTAL_HT));
    ui->TOTAL_TVA->setText(QString::number(TOTAL_TVA));
    ui->TOTAL_TTC->setText(QString::number(TOTA_TTC));

}

afficher_facture::~afficher_facture()
{
    delete ui;
}
QString afficher_facture::getId() const
{
    return m_id;
}

QString afficher_facture::getId_client() const {
    return m_idC;
}
void afficher_facture::on_downloadbutton_clicked()
{

    ui->downloadbutton->setVisible(false);


    QPixmap pixmap(size());
    render(&pixmap);


    ui->downloadbutton->setVisible(true);


    QString filePath = QFileDialog::getSaveFileName(this, tr("Sauvegarder l'image"), QDir::homePath(), tr("Images (*.png *.jpg *.jpeg)"));


    if (filePath.isEmpty()) {
        return;
    }


    if (!pixmap.save(filePath)) {
        QMessageBox::critical(this, tr("Erreur"), tr("Impossible de sauvegarder l'image."));
        return;
    }
}
