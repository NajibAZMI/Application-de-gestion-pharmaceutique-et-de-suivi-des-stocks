#ifndef PROFIL_H
#define PROFIL_H
#include"profil_modifie.h"
#include <QDialog>
#include "consulter_stock.h"
#include "ajoutervente.h"
#include "affichervente.h"
#include"recherchermed_emp.h"
namespace Ui {
class profil;
}

class profil : public QDialog
{
    Q_OBJECT

public:
    explicit profil(QWidget *parent = nullptr,const QString& id = "");
    ~profil();
    QString getId() const;

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_GotoModifier_clicked();

    void on_pushButton_stock_clicked();

    void on_pushButton_ajouter_Vente_clicked();

    void on_pushButton_afficher_vente_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::profil *ui;
    QString m_id;
};

#endif // PROFIL_H
