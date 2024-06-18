#include "supprimer_fournisseur.h"
#include "ui_supprimer_fournisseur.h"
#include <QtSql>
#include <QDateTime>
#include <QMessageBox>
Supprimer_fournisseur::Supprimer_fournisseur(QWidget *parent,const QString& id)
    : QDialog(parent)
    , ui(new Ui::Supprimer_fournisseur),m_id(id)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("SELECT nom, prenom, email, numero FROM users WHERE id = :id");
    query.bindValue(":id", m_id);
    if (query.exec() && query.next()) {
        ui->name_user->setText(query.value(0).toString());
    }
    ui->label_date->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));
}

Supprimer_fournisseur::~Supprimer_fournisseur()
{
    delete ui;
}
QString Supprimer_fournisseur::getId() const
{
    return m_id;
}




void Supprimer_fournisseur::on_pushButton_Supprimer_Fournisseur_clicked()
{

    QString code_med = ui->lineEdit_Code_Med->text();
    QString Id_four = ui->lineEdit_ID_Fournisseur->text();
    QString Nom_four = ui->lineEdit_Nom_fournisseur->text();
    QString Adresse_four = ui->lineEdit_addresse_fournisseur->text();
    QString Numero_tele = ui->lineEdit_Numero_Telephone->text();

    if (!code_med.isEmpty() && !Id_four.isEmpty() && !Nom_four.isEmpty() && !Adresse_four.isEmpty() && !Numero_tele.isEmpty())
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM Fournisseurs WHERE id_Med = :code_med AND id_f = :Id_four AND Nom_f = :Nom_four AND Adresse = :Adresse_four AND Telephone = :Numero_tele");
        query.bindValue(":code_med", code_med);
        query.bindValue(":Id_four", Id_four);
        query.bindValue(":Nom_four", Nom_four);
        query.bindValue(":Adresse_four", Adresse_four);
        query.bindValue(":Numero_tele", Numero_tele);

        if (query.exec() && query.next())
        {
            QSqlQuery query1;
            query1.prepare("DELETE FROM Fournisseurs WHERE id_f = :Id_four AND Nom_f = :Nom_four AND Adresse = :Adresse_four AND Telephone = :Numero_tele AND id_Med = :code_med");
            query1.bindValue(":code_med", code_med);
            query1.bindValue(":Id_four", Id_four);
            query1.bindValue(":Nom_four", Nom_four);
            query1.bindValue(":Adresse_four", Adresse_four);
            query1.bindValue(":Numero_tele", Numero_tele);
            if(query1.exec()){
                QMessageBox::information(this, "Succès", "Fournisseur supprimé avec succès.");
            }
        }
        else
        {
            QMessageBox::information(this, "Erreur", "Le fournisseur n'existe pas.");
        }
    }
    else
    {
        QMessageBox::information(this,"Erreur","Tous les champs doivent être remplis.");
    }
}


void Supprimer_fournisseur::on_pushButton_6_clicked()
{
    exit(1);
}


void Supprimer_fournisseur::on_pushButton_Precedent_clicked()
{
    this->hide();
    gestion_fournisseur gestion_fournisseur(nullptr, getId());
    gestion_fournisseur.setModal(true);
    gestion_fournisseur.exec();
}

