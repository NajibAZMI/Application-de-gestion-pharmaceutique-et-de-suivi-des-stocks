#include "profil.h"
#include "ui_profil.h"
#include <QtSql>
#include <QDateTime>
profil::profil(QWidget *parent,const QString& id)
    : QDialog(parent)
    , ui(new Ui::profil),
        m_id(id)
{
    ui->setupUi(this);

    QSqlQuery query;
    query.prepare("SELECT*FROM users WHERE id = :id");
    query.bindValue(":id", m_id);
    if (query.exec() && query.next()) {
        ui->label_nom->setText(query.value(1).toString());
        ui->label_prenom->setText(query.value(2).toString());
        ui->label_email->setText(query.value(5).toString());
        ui->label_numero->setText(query.value(6).toString());
        ui->label_etat->setText(query.value(7).toString());
        ui->label_identifiant->setText(query.value(3).toString());
        ui->nome_user->setText(query.value(1).toString());
    }


    ui->label_date->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));

}

profil::~profil()
{
    delete ui;
}
QString profil::getId() const
{
    return m_id;
}

void profil::on_pushButton_6_clicked()
{
    exit(1);
}


void profil::on_pushButton_GotoModifier_clicked()
{

    this->hide();

    profil_modifie profil_modifie(nullptr, getId()); // Pass the ID to the profil constructor
    profil_modifie.setModal(true);
    profil_modifie.exec();
}


void profil::on_pushButton_stock_clicked()
{

    this->hide();
    consulter_stock consulter_stock(nullptr, getId());
    // Pass the ID to the profil constructor
    consulter_stock .setModal(true);
    consulter_stock .exec();
}


void profil::on_pushButton_ajouter_Vente_clicked()
{

    this->hide();
    ajouterVente ajouterVente(nullptr, getId());
    // Pass the ID to the profil constructor
    ajouterVente.setModal(true);
    ajouterVente .exec();
}


void profil::on_pushButton_afficher_vente_clicked()
{

    this->hide();
    affichervente affichervente (nullptr, getId());
    affichervente.setModal(true);
    affichervente.exec();
}


void profil::on_pushButton_4_clicked()
{
    this->hide();
    recherchermed_emp recherchermed_emp (nullptr, getId());
    recherchermed_emp.setModal(true);
    recherchermed_emp.exec();

}

