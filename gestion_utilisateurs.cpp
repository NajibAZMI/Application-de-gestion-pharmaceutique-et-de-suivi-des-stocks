
#include "gestion_utilisateurs.h"
#include "ui_gestion_utilisateurs.h"
#include <QtSql>
#include <QDateTime>

gestion_utilisateurs::gestion_utilisateurs(QWidget *parent, const QString& id)
    : QDialog(parent)
    , ui(new Ui::gestion_utilisateurs)
    , m_id(id)
{
    ui->setupUi(this);

    // Afficher la date et l'heure actuelle
    ui->label_date->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));

    // Afficher le nom de l'utilisateur
    QSqlQuery query;
    query.prepare("SELECT nom FROM users WHERE id = :id");
    query.bindValue(":id", id);
    if (query.exec() && query.next()) {
        ui->nome_user->setText(query.value(0).toString());
    }

    // Configuration des en-têtes du tableau
    QStringList columnNames;
    columnNames << "ID Utilisateur" <<"Prenom Utilisateur"<< "Nom Utilisateur" << "Email" << "Téléphone";
    ui->tableView_utilisateurs->setColumnCount(columnNames.size());
    ui->tableView_utilisateurs->setHorizontalHeaderLabels(columnNames);

    // Remplir le tableau avec les utilisateurs
    QSqlQuery utilisateursQuery;
    utilisateursQuery.prepare("SELECT prenom,nom,id,email,numero FROM users");

    if (utilisateursQuery.exec()) {
        int row = 0;
        while (utilisateursQuery.next()) {
            ui->tableView_utilisateurs->insertRow(row);
            ui->tableView_utilisateurs->setItem(row, 0, new QTableWidgetItem(utilisateursQuery.value(2).toString()));
            ui->tableView_utilisateurs->setItem(row, 1, new QTableWidgetItem(utilisateursQuery.value(0).toString()));
            ui->tableView_utilisateurs->setItem(row, 2, new QTableWidgetItem(utilisateursQuery.value(1).toString()));
            ui->tableView_utilisateurs->setItem(row, 3, new QTableWidgetItem(utilisateursQuery.value(3).toString()));
            ui->tableView_utilisateurs->setItem(row, 4, new QTableWidgetItem(utilisateursQuery.value(4).toString()));
            row++;
        }
    }

    // Ajuster la taille des colonnes
    ui->tableView_utilisateurs->setColumnWidth(0, 120);
    ui->tableView_utilisateurs->setColumnWidth(1, 170);
    ui->tableView_utilisateurs->setColumnWidth(2, 170);
    ui->tableView_utilisateurs->setColumnWidth(3, 170);
    ui->tableView_utilisateurs->setColumnWidth(3, 170);
}

gestion_utilisateurs::~gestion_utilisateurs()
{
    delete ui;
}

QString gestion_utilisateurs::getId() const
{
    return m_id;
}
void gestion_utilisateurs::on_pushButton_Recherche_fournisseur_clicked()
{
    QString id_user = ui->lineEdit_id_employer->text();
    QString Nom_user = ui->lineEdit_Nom_employe ->text();
    QString Prenom_user = ui->LineEdit_prenom_employe->text();
    QString email = ui->lineEdit_email_employe->text();
    QString telephone = ui->lineEdit_telephone->text();


    QString queryCondition = "SELECT * FROM users WHERE 1=1";

    if (!id_user.isEmpty()) {
        queryCondition += " AND id = :id_user";
    }

    if (!Nom_user.isEmpty()) {
        queryCondition += " AND nom = :Nom_user";
    }
    if (!Prenom_user.isEmpty()) {
        queryCondition += " AND prenom = :Prenom_user";
    }

    if (!email.isEmpty()) {
        queryCondition += " AND email = :email";
    }

    if (!telephone.isEmpty()) {
        queryCondition += " AND numero = :telephone";
    }
    QSqlQuery rechercheQuery;
    rechercheQuery.prepare(queryCondition);

    rechercheQuery.bindValue(":id_user", id_user);
    rechercheQuery.bindValue(":Nom_user", Nom_user);
    rechercheQuery.bindValue(":Prenom_user", Prenom_user);
    rechercheQuery.bindValue(":email", email);
    rechercheQuery.bindValue(":telephone", telephone);

    if (rechercheQuery.exec()) {
        ui->tableView_utilisateurs->clearContents();
        ui->tableView_utilisateurs->setRowCount(0);

        int row = 0;
        while (rechercheQuery.next()) {
            ui->tableView_utilisateurs->insertRow(row);
            ui->tableView_utilisateurs->setItem(row, 0, new QTableWidgetItem(rechercheQuery.value(0).toString()));
            ui->tableView_utilisateurs->setItem(row, 1, new QTableWidgetItem(rechercheQuery.value(1).toString()));
            ui->tableView_utilisateurs->setItem(row, 2, new QTableWidgetItem(rechercheQuery.value(2).toString()));
            ui->tableView_utilisateurs->setItem(row, 3, new QTableWidgetItem(rechercheQuery.value(3).toString()));
            ui->tableView_utilisateurs->setItem(row, 4, new QTableWidgetItem(rechercheQuery.value(4).toString()));
            row++;
        }
    }
}


void gestion_utilisateurs::on_pushButton_Ajouter_fournisseur_clicked()
{
    this->hide();
    ajouter_utilisateurs  ajouter_utilisateurs (nullptr,getId());
    ajouter_utilisateurs.setModal(true);
    ajouter_utilisateurs.exec();
}


void gestion_utilisateurs::on_pushButton_Modifier_fournisseur_clicked()
{
    this->hide();
    modifier_utilisateurs  modifier_utilisateurs (nullptr,getId());
    modifier_utilisateurs.setModal(true);
    modifier_utilisateurs.exec();

}


void gestion_utilisateurs::on_pushButton_supprimer_fournisseur_clicked()
{
    this->hide();
    supprimer_utilisateurs  supprimer_utilisateurs (nullptr,getId());
    supprimer_utilisateurs.setModal(true);
    supprimer_utilisateurs.exec();

}


void gestion_utilisateurs::on_pushButton_accueilgerat_clicked()
{
    this->hide();
    accueil_gerant  accueil_gerant (nullptr,getId());
    accueil_gerant.setModal(true);
    accueil_gerant.exec();
}


void gestion_utilisateurs::on_ButtonProfil_gerant_clicked()
{
    this->hide();
    profil_gerant  profil_gerant (nullptr,getId());
    profil_gerant.setModal(true);
    profil_gerant.exec();
}


void gestion_utilisateurs::on_pushButton_gere_vente_clicked()
{
    this->hide();
    gestion_ventes  gestion_ventes (nullptr,getId());
    gestion_ventes.setModal(true);
    gestion_ventes.exec();
}


void gestion_utilisateurs::on_pushButton_gerer_stock_clicked()
{
    this->hide();
    gerer_stock  gerer_stock (nullptr,getId());
    gerer_stock.setModal(true);
    gerer_stock.exec();
}


void gestion_utilisateurs::on_pushButton_gerer_fournisseur_clicked()
{
    this->hide();
    gestion_fournisseur  gestion_fournisseur (nullptr,getId());
    gestion_fournisseur.setModal(true);
    gestion_fournisseur.exec();
}


void gestion_utilisateurs::on_pushButton_gerer_rupture_clicked()
{
    this->hide();
    gestion_utilisateurs  gestion_utilisateurs (nullptr,getId());
    gestion_utilisateurs.setModal(true);
    gestion_utilisateurs.exec();
}


void gestion_utilisateurs::on_pushButton_6_clicked()
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

