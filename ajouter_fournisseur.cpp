#include "ajouter_fournisseur.h"
#include "ui_ajouter_fournisseur.h"
#include <QtSql>
#include <QDateTime>
#include <QMessageBox>
Ajouter_fournisseur::Ajouter_fournisseur(QWidget *parent,const QString& id)
    : QDialog(parent)
    , ui(new Ui::Ajouter_fournisseur),m_id(id)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("SELECT*FROM users WHERE id = :id");
    query.bindValue(":id", m_id);
    if (query.exec() && query.next()) {
        ui->name_user->setText(query.value(1).toString());
    }
ui->label_date->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));
}

Ajouter_fournisseur::~Ajouter_fournisseur()
{
    delete ui;
}
QString Ajouter_fournisseur::getId() const
{
    return m_id;
}

void Ajouter_fournisseur::on_pushButton_6_clicked()
{
    exit(1);
}


void Ajouter_fournisseur::on_pushButton_Precedent_clicked()
{
    this->hide();
    gestion_fournisseur gestion_fournisseur(nullptr, getId());
    gestion_fournisseur.setModal(true);
    gestion_fournisseur.exec();
}


void Ajouter_fournisseur::on_pushButton_Ajouter_Fournisseur_clicked()
{
    QString code_med = ui->lineEdit_Code_Med->text();
    QString Id_four = ui->lineEdit_ID_Fournisseur->text();
    QString Nom_four = ui->lineEdit_Nom_fournisseur->text();
    QString Adresse_four = ui->lineEdit_addresse_fournisseur->text();
    QString Numero_tele = ui->lineEdit_Numero_Telephone->text();

    if (!code_med.isEmpty() && !Id_four.isEmpty() && !Nom_four.isEmpty() && !Adresse_four.isEmpty() && !Numero_tele.isEmpty())
    {

        QSqlQuery query;
        query.prepare("SELECT * FROM fournisseur WHERE id_Med = :code_med OR id_f = :Id_four OR Nom_f = :Nom_four OR Adresse = :Adresse_four OR Telephone = :Numero_tele");
        query.bindValue(":code_med", code_med);
        query.bindValue(":Id_four", Id_four);
        query.bindValue(":Nom_four", Nom_four);
        query.bindValue(":Adresse_four", Adresse_four);
        query.bindValue(":Numero_tele", Numero_tele);

        if (query.exec() && query.next())
        {
             QMessageBox::information(this, "Erreur", "Les données saisies existent déjà dans la table des fournisseurs.");
        }
        else
        {

            QSqlQuery query1;
            query1.prepare("INSERT INTO Fournisseurs (id_f,Nom_f,Adresse,Telephone,id_Med) VALUES(:Id_four,:Nom_four,:Adresse_four,:Numero_tele,:code_med)");
            query1.bindValue(":code_med", code_med);
            query1.bindValue(":Id_four", Id_four);
            query1.bindValue(":Nom_four", Nom_four);
            query1.bindValue(":Adresse_four", Adresse_four);
            query1.bindValue(":Numero_tele", Numero_tele);
            if(query1.exec()){
                 QMessageBox::information(this, "Succès", " fournisseur ajouté avec succès.");
            }
        }
    }
    else
    {
        QMessageBox::information(this,"Erreur","Tous les champs doivent être remplis.");
    }
}


void Ajouter_fournisseur::on_pushButton_accueilgerat_clicked()
{
    this->hide();
    accueil_gerant accueil_gerant(nullptr, getId());
    accueil_gerant.setModal(true);
    accueil_gerant.exec();
}


void Ajouter_fournisseur::on_ButtonProfil_clicked()
{
    this->hide();
    profil_gerant profil_gerant(nullptr, getId());
    profil_gerant.setModal(true);
    profil_gerant.exec();

}


void Ajouter_fournisseur::on_pushButton_gere_vente_clicked()
{
    this->hide();
    gestion_ventes gestion_ventes(nullptr, getId());
    gestion_ventes.setModal(true);
    gestion_ventes.exec();

}


void Ajouter_fournisseur::on_pushButton_gerer_stock_clicked()
{
    this->hide();
    gerer_stock gerer_stock(nullptr, getId());
    gerer_stock.setModal(true);
    gerer_stock.exec();

}


void Ajouter_fournisseur::on_pushButton_gerer_fournisseur_clicked()
{
    this->hide();
    gestion_fournisseur gestion_fournisseur(nullptr, getId());
    gestion_fournisseur.setModal(true);
    gestion_fournisseur.exec();

}


void Ajouter_fournisseur::on_pushButton_gerer_utilisateurs_clicked()
{
    this->hide();
    gestion_utilisateurs gestion_utilisateurs(nullptr, getId());
    gestion_utilisateurs.setModal(true);
    gestion_utilisateurs.exec();

}

