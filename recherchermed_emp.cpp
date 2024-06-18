#include "recherchermed_emp.h"
#include "ui_recherchermed_emp.h"
#include <QtSql>
#include <QMessageBox>
#include <QDateTime>

recherchermed_emp::recherchermed_emp(QWidget *parent,const QString& id)
    : QDialog(parent)
    , ui(new Ui::recherchermed_emp)
    ,m_id(id)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("SELECT nom FROM users WHERE id = :id");
    query.bindValue(":id", m_id);
    if (query.exec() && query.next()) {
        ui->nome_user->setText(query.value(0).toString());
    }
    ui->label_date->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));
    ui->Table_affichageMed->setVisible(false);
}

recherchermed_emp::~recherchermed_emp()
{
    delete ui;
}

QString recherchermed_emp::getId() const
{
    return m_id;
}

void recherchermed_emp::on_pushButton_Recherche_clicked()
{
    QString idMed = ui->lineEdit_rechercheMedID->text();
    QString nameMed= ui->lineEdit_rechercheMedNOM ->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM Medicament WHERE id_Med = :idMed OR nom_Med = :nameMed");
    query.bindValue(":idMed", idMed);
    query.bindValue(":nameMed", nameMed);


    if (query.exec() && query.next()){
        // QMessageBox::information(this, "Connexion réussie", "Bienvenue !");

        // Rendez la table visible si elle ne l'est pas déjà
        ui->Table_affichageMed->setVisible(true);
        // Effacez tout contenu précédent de la table
        ui->Table_affichageMed->clearContents();
        ui->Table_affichageMed->setRowCount(0); // Assurez-vous qu'il n'y a pas de lignes existantes

        // Ajoutez une nouvelle ligne au tableau
        int row = ui->Table_affichageMed->rowCount();
        ui->Table_affichageMed->insertRow(row);

        // Remplissez les cellules de la ligne avec les valeurs du résultat de la requête
        ui->Table_affichageMed->setItem(row, 0, new QTableWidgetItem(query.value("id_Med").toString()));
        ui->Table_affichageMed->setItem(row, 1, new QTableWidgetItem(query.value("nom_Med").toString()));
        ui->Table_affichageMed->setItem(row, 2, new QTableWidgetItem(query.value("Date_Med").toString()));
        ui->Table_affichageMed->setItem(row, 3, new QTableWidgetItem(query.value("Quantite").toString()));
        ui->Table_affichageMed->setItem(row, 4, new QTableWidgetItem(query.value("prix").toString()));

        // QMessageBox::information(this, "Détails du médicament", "Médicament trouvé et affiché dans le tableau !");


    }
    else{
        QMessageBox::information(this, "Aucun résultat", "Aucun médicament trouvé avec cet ID et ce nom.");
    }


}


void recherchermed_emp::on_ButtonProfil_clicked()
{
     this->hide();
    profil profil(nullptr, getId());
    profil.setModal(true);
    profil.exec();
}


void recherchermed_emp::on_pushButton_afficher_vente_clicked()
{
    this->hide();
    affichervente  affichervente(nullptr, getId());
    affichervente.setModal(true);
    affichervente.exec();
}


void recherchermed_emp::on_pushButton_ajouter_vente_clicked()
{

    this->hide();
    ajouterVente ajoutervente (nullptr, getId());
    ajoutervente.setModal(true);
    ajoutervente.exec();

}


void recherchermed_emp::on_pushButton_Consulter_stock_clicked()
{

    this->hide();
    consulter_stock consulter_stock (nullptr, getId());
   consulter_stock.setModal(true);
    consulter_stock.exec();

}


void recherchermed_emp::on_pushButton_6_clicked()
{
    // Hide the current window
    this->hide();

    // Create and show the MainWindow
    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();

    // Optionally, delete the current window if it is no longer needed
    // This is to ensure that the application does not leak memory
    this->deleteLater();
}


