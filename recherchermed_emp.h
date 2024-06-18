#ifndef RECHERCHERMED_EMP_H
#define RECHERCHERMED_EMP_H

#include <QDialog>
#include <QDialog>
#include <QtSql>
#include"profil.h"
#include"consulter_stock.h"
#include"affichervente.h"
#include"ajoutervente.h"
#include"mainwindow.h"




namespace Ui {
class recherchermed_emp;
}

class recherchermed_emp : public QDialog
{
    Q_OBJECT

public:
    explicit recherchermed_emp(QWidget *parent = nullptr,const QString& id = "");
    ~recherchermed_emp();
    QString getId() const;

private:
    Ui::recherchermed_emp *ui;
    QSqlDatabase mydb;
    QString m_id;

    /******/

private slots:
    void on_pushButton_Recherche_clicked();

    /******/
    void on_ButtonProfil_clicked();
    void on_pushButton_afficher_vente_clicked();
    void on_pushButton_ajouter_vente_clicked();
    void on_pushButton_Consulter_stock_clicked();
    void on_pushButton_6_clicked();
};



#endif // RECHERCHERMED_EMP_H

