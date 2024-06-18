#include "ajoutervente.h"
#include "ui_ajoutervente.h"
#include <QtSql>

#include <QMessageBox>
#include <QDateTime>
ajouterVente::ajouterVente(QWidget *parent,const QString& id)
    : QDialog(parent)
    , ui(new Ui::ajouterVente), m_id(id)

{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("SELECT nom, prenom, email, numero FROM users WHERE id = :id");
    query.bindValue(":id", m_id);
    if (query.exec() && query.next()) {
        ui->nome_user->setText(query.value(1).toString());
    }
    ui->label_date->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));
}
void ajouterVente::clearFields_memeClient() {
    ui->lineEdit_code_med->clear();
    ui->lineEdit_Libell->clear();

    ui->spinBox_quantite->setValue(0);
}
void ajouterVente::clear_finVente(){
    ui->lineEdit_code_med->clear();
    ui->lineEdit_Libell->clear();
    ui->lineEdit_Id_Client->clear();
    ui->spinBox_quantite->setValue(0);
}
ajouterVente::~ajouterVente()
{
    delete ui;
}
QString ajouterVente::getId() const
{
    return m_id;
}


void ajouterVente::on_pushButton_Valider_Vente_clicked()
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



void ajouterVente::on_ButtonProfil_clicked()
{

    this->hide();

    profil profil(nullptr, getId()); // Pass the ID to the profil constructor
    profil.setModal(true);
    profil.exec();
}


void ajouterVente::on_pushButton_Consulter_stock_clicked()
{

    this->hide();
    consulter_stock consulter_stock(nullptr, getId());
    // Pass the ID to the profil constructor
    consulter_stock .setModal(true);
    consulter_stock .exec();
}


void ajouterVente::on_pushButton_affiche_vente_clicked()
{
    this->hide();
    affichervente affichervente(nullptr, getId());
    // Pass the ID to the profil constructor
    affichervente.setModal(true);
    affichervente.exec();
}


void ajouterVente::on_pushButton_FiVente_Affiche_facture_clicked()
{
    this->hide();
    QString id_client=ui->lineEdit_Id_Client->text();
    afficher_facture afficher_facture(nullptr, getId(),id_client);
    // Pass the ID to the profil constructor
    afficher_facture.setModal(true);
    afficher_facture.exec();
}


void ajouterVente::on_pushButton_6_clicked()
{
    exit(1);
}


void ajouterVente::on_pushButton_4_clicked()
{
    this->hide();
    recherchermed_emp recherchermed_emp(nullptr, getId());
    recherchermed_emp.setModal(true);
    recherchermed_emp.exec();
}

