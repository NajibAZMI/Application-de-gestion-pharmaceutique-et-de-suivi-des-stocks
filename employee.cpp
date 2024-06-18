#include "employee.h"
#include "ui_employee.h"
#include <QtSql>
Employee::Employee(QWidget *parent, const QString& id, const QString& username, const QString& password) :
    QDialog(parent),
    ui(new Ui::Employee),
    m_id(id),
    m_username(username),
    m_password(password)
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

Employee::~Employee()
{
    delete ui;
}

QString Employee::getUsername() const
{
    return m_username;
}

QString Employee::getPassword() const
{
    return m_password;
}
QString Employee::getId() const
{
    return m_id;
}




void Employee::on_ButtonProfil_clicked()
{

    this->hide();

         profil profil(nullptr, getId()); // Pass the ID to the profil constructor
         profil.setModal(true);
         profil.exec();
}


void Employee::on_pushButton_6_clicked()
{
    exit(1);
}


void Employee::on_pushButton_Consulter_stock_clicked()
{


    this->hide();
    consulter_stock consulter_stock(nullptr, getId());
    // Pass the ID to the profil constructor
    consulter_stock .setModal(true);
    consulter_stock .exec();
}







void Employee::on_pushButton_ajouter_vente_clicked()
{

    this->hide();
    ajouterVente ajouterVente(nullptr, getId());
    // Pass the ID to the profil constructor
    ajouterVente .setModal(true);
    ajouterVente .exec();
}


void Employee::on_pushButton_afficher_vente_clicked()
{

    this->hide();
   affichervente affichervente (nullptr, getId());
   affichervente.setModal(true);
   affichervente.exec();
}


void Employee::on_pushButton_4_clicked()
{
    this->hide();
    recherchermed_emp recherchermed_emp (nullptr, getId());
    recherchermed_emp.setModal(true);
    recherchermed_emp.exec();
}

