#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "affichervente.h"
#include <QDialog>
#include "profil.h"
#include "consulter_stock.h"
#include "ajoutervente.h"
#include"recherchermed_emp.h"
namespace Ui {
class Employee;
}

class Employee : public QDialog
{
    Q_OBJECT

public:
    explicit Employee(QWidget *parent = nullptr, const QString& id = "", const QString& username = "", const QString& password = "");
    ~Employee();

    // Method to retrieve username
    QString getUsername() const;

    // Method to retrieve password
    QString getPassword() const;
    QString getId() const;

private slots:


    void on_ButtonProfil_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_Consulter_stock_clicked();





    void on_pushButton_ajouter_vente_clicked();

    void on_pushButton_afficher_vente_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Employee *ui;
    QString m_username;
    QString m_password;
    QString m_id;
};

#endif // EMPLOYEE_H
