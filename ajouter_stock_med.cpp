#include "ajouter_stock_med.h"
#include "ui_ajouter_stock_med.h"

ajouter_stock_med::ajouter_stock_med(QWidget *parent, const QString &id)
    : QDialog(parent)
    , ui(new Ui::ajouter_stock_med)
    ,m_id(id)
{
    ui->setupUi(this);
}

ajouter_stock_med::~ajouter_stock_med()
{
    delete ui;
}

QString ajouter_stock_med:: getId()const{
    return m_id;
}


void ajouter_stock_med::on_saveButton_clicked()
{
    QString id = ui->codemedlineEdit->text();
    QString nom = ui->libellelineEdit->text();
    QDate dateMed = ui->dateEdit->date();
    int quantite = ui->spinBoxquantite->value();
    QString prix = ui->prixmedlineEdit->text();
    QString tva = ui->tvamedlineEdit->text();

    if (id.isEmpty() || nom.isEmpty() || quantite <= 0 || prix.isEmpty() || tva.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill all the fields correctly.");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO Medicament (id_Med, nom_Med, Date_Med, Quantite, prix, TVA) "
                  "VALUES (:id, :nom, :dateMed, :quantite, :prix, :tva)");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":dateMed", dateMed);
    query.bindValue(":quantite", quantite);
    query.bindValue(":prix", prix);
    query.bindValue(":tva", tva);

    if (!query.exec()) {
        qDebug() << "Error adding medicine:" << query.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to add the medicine.");
    } else {
        QMessageBox::information(this, "Success", "Medicine added successfully.");

    }
}


void ajouter_stock_med::on_Button_precedent_clicked()
{
    this->hide();
    gerer_stock gerer_stock(nullptr, getId());
    gerer_stock.setModal(true);
    gerer_stock.exec();
}



void ajouter_stock_med::on_pushButton_accueilgerat_clicked()
{
    this->hide();
    accueil_gerant accueil_gerant(nullptr, getId());
    accueil_gerant.setModal(true);
    accueil_gerant.exec();
}


void ajouter_stock_med::on_ButtonProfil_clicked()
{
    this->hide();
    profil_gerant profil_gerant(nullptr, getId());
    profil_gerant.setModal(true);
    profil_gerant.exec();

}


void ajouter_stock_med::on_pushButton_gere_vente_clicked()
{
    this->hide();
    gestion_ventes gestion_ventes(nullptr, getId());
    gestion_ventes.setModal(true);
    gestion_ventes.exec();

}


void ajouter_stock_med::on_pushButton_gerer_stock_clicked()
{
    this->hide();
    gerer_stock gerer_stock(nullptr, getId());
    gerer_stock.setModal(true);
    gerer_stock.exec();

}


void ajouter_stock_med::on_pushButton_gerer_fournisseur_clicked()
{
    this->hide();
    gestion_fournisseur gestion_fournisseur(nullptr, getId());
    gestion_fournisseur.setModal(true);
    gestion_fournisseur.exec();

}



void ajouter_stock_med::on_pushButton_gerer_utilisateurs_clicked()
{
    this->hide();
    gestion_utilisateurs gestion_utilisateurs(nullptr, getId());
    gestion_utilisateurs.setModal(true);
    gestion_utilisateurs.exec();

}


void ajouter_stock_med::on_pushButton_6_clicked()
{
    exit(1);
}

