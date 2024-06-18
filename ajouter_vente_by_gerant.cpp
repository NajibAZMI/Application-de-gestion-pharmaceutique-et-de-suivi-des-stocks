#include "ajouter_vente_by_gerant.h"
#include "ui_ajouter_vente_by_gerant.h"
#include <QtSql>
#include <QMessageBox>
#include <QDateTime>
#include <QPdfWriter>
#include <QPainter>
#include <QPrinter>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

#include <QTextDocument>



Ajouter_vente_by_gerant::Ajouter_vente_by_gerant(QWidget *parent,const QString& id)
    : QDialog(parent)
    , ui(new Ui::Ajouter_vente_by_gerant), m_id(id)
{
    ui->setupUi(this);
    QSqlQuery query1;
    query1.prepare("SELECT*FROM users WHERE id = :id");
    query1.bindValue(":id", m_id);
    if (query1.exec() && query1.next()) {
        ui->nome_user->setText(query1.value(1).toString());
    }
    ui->label_date->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));

}
void Ajouter_vente_by_gerant::clearFields_memeClient() {
    ui->lineEdit_code_med->clear();
    ui->lineEdit_Libell->clear();

    ui->spinBox_quantite->setValue(0);
}
void Ajouter_vente_by_gerant::clear_finVente(){
    ui->lineEdit_code_med->clear();
    ui->lineEdit_Libell->clear();
    ui->lineEdit_Id_Client->clear();
    ui->spinBox_quantite->setValue(0);
}

Ajouter_vente_by_gerant::~Ajouter_vente_by_gerant()
{
    delete ui;
}
QString Ajouter_vente_by_gerant::getId() const
{
    return m_id;
}

void Ajouter_vente_by_gerant::on_pushButton_Valider_Venteg_clicked()
{
    QSqlQuery query;
    QString code_med = ui->lineEdit_code_med->text();
    QString Libelle = ui->lineEdit_Libell->text();
    QString Id_Client = ui->lineEdit_Id_Client->text();
    int Quantite_saisie = ui->spinBox_quantite->value();
    int new_Quantite = 0;
    QString id_user=getId();
    int Quantite = 0;
    QDateTime dateTime = QDateTime::currentDateTime();
    QDate currentDate = dateTime.date();

    if (!code_med.isEmpty() && !Libelle.isEmpty() && Quantite_saisie != 0) {
        query.prepare("SELECT * FROM Medicament WHERE id_Med = :code_med AND nom_Med = :Libelle");
        query.bindValue(":code_med", code_med);
        query.bindValue(":Libelle", Libelle);
        if (query.exec() && query.next()) {
            Quantite = query.value(3).toInt();
            if (Quantite_saisie <= Quantite) {
                new_Quantite = Quantite - Quantite_saisie;
                query.prepare("UPDATE Medicament SET Quantite = :new_Quantite WHERE id_Med = :code_med");
                query.bindValue(":new_Quantite", new_Quantite);
                query.bindValue(":code_med", code_med);
                if (query.exec()) {
                    QSqlQuery query1;
                    query1.prepare("INSERT INTO Ventes(quantite_vent, date_vent, id_Med, id_user, id_Client) VALUES (:Quantite_saisie, :currentDate, :code_med, :id_user, :Id_Client)");
                    query1.bindValue(":Quantite_saisie", Quantite_saisie);
                    query1.bindValue(":currentDate", currentDate);
                    query1.bindValue(":code_med", code_med);
                    query1.bindValue(":id_user", id_user); // Assurez-vous de lier cette valeur
                    query1.bindValue(":Id_Client", Id_Client);
                    if (query1.exec()) {
                        QMessageBox::information(this, tr("Succès"), tr("Vente ajoutée avec succès."));
                        clearFields_memeClient();
                    } else {
                        QMessageBox::critical(this, tr("Erreur"), tr("Échec de l'ajout de la vente : %1").arg(query1.lastError().text()));
                    }
                } else {
                    QMessageBox::critical(this, tr("Erreur"), tr("Échec de la mise à jour du médicament : %1").arg(query.lastError().text()));
                }
            } else {
                QMessageBox::critical(this, tr("Erreur"), tr("Quantité insuffisante en stock."));
            }
        } else {
            QMessageBox::critical(this, tr("Erreur"), tr("Le médicament n'existe pas."));
        }
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("Veuillez remplir tous les champs."));
    }
}


void Ajouter_vente_by_gerant::on_pushButton_telechargerventes_clicked()
{
    // Créez un objet QTextDocument pour le contenu du PDF
    QTextDocument document;

    // Construisez le HTML pour le document
    QString html = "<h1>Table des Ventes</h1>";
    html += "<table border='1' cellspacing='0' cellpadding='2'>";
    html += "<tr>"
            "<th>ID Vente</th>"
            "<th>Quantité</th>"
            "<th>Date</th>"
            "<th>ID Médicament</th>"
            "<th>ID Utilisateur</th>"
            "<th>ID Client</th>"
            "</tr>";

    // Récupération des données de la table Ventes
    QSqlQuery query("SELECT * FROM Ventes");
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête:" << query.lastError();
        return;
    }

    // Parcourez les résultats et ajoutez-les au HTML
    while (query.next()) {
        html += "<tr>";
        html += "<td>" + query.value("id_vent").toString() + "</td>";
        html += "<td>" + query.value("quantite_vent").toString() + "</td>";
        html += "<td>" + query.value("date_vent").toString() + "</td>";
        html += "<td>" + query.value("id_Med").toString() + "</td>";
        html += "<td>" + query.value("id_user").toString() + "</td>";
        html += "<td>" + query.value("id_Client").toString() + "</td>";
        html += "</tr>";
    }

    html += "</table>";

    // Configurez le document avec le HTML
    document.setHtml(html);

    // Créez un objet QPrinter pour générer le PDF
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("C:/Users/hamza/Documents/sans_titre8/factures/Ventes.pdf");  // Définissez le chemin du fichier PDF

    // Imprimez le document dans le PDF
    document.print(&printer);

    // Optionnel : affichez un message pour indiquer que le PDF a été généré
    QMessageBox::information(this, "Téléchargement terminé", "Le fichier PDF a été téléchargé avec succès dans C:/Users/hp/Desktop/sans_titre8/Facture & Ventes.");
}


void Ajouter_vente_by_gerant::on_pushButton_Abandonner_clicked()
{
    this->hide();
}


void Ajouter_vente_by_gerant::on_pushButton_6_clicked()
{
    exit(1);
}

