#include "afficherfacture.h"
#include "ui_afficherfacture.h"
#include <QtSql>
afficherfacture::afficherfacture(QWidget *parent,const QString& id,const QString& id_client,const QDate& currentDate)
    : QDialog(parent)
    , ui(new Ui::afficherfacture),m_id(id),m_idC(id_client),m_currentDate(currentDate)

{
    ui->setupUi(this);
    QSqlQuery query,query1;
    query.prepare("SELECT nom,prenom FROM users where id=:id");
    query.bindValue(":id",id);
    query.exec();
    query.next();

    QString nom = query.value(0).toString();
    QString prenom = query.value(1).toString();
    QString nom_prenom = nom + " " + prenom;
    ui->label_NOM_prenom->setText(nom_prenom);
    query1.prepare("SELECT max(id_vent) FROM Ventes WHERE id_user=:id");
    query1.bindValue(":id",id);
    query1.exec();

    if(query1.next()) {
        ui->label_Num_facture->setText(query1.value(0).toString());
    } else {
        // Gérer le cas où aucun résultat n'est retourné ou s'il y a une erreur lors de l'exécution de la requête
    }

    ui->label_date_facture->setText(currentDate.toString("dd-MM-yyyy"));

}

afficherfacture::~afficherfacture()
{
    delete ui;
}
QString afficherfacture::getId() const{
    return m_id;
}
QString afficherfacture::getId_client()const{
    return m_idC;
}
QDate ::currentDate()const{
    return m_currentDate;
}
