#ifndef AJOUTER_STOCK_MED_H
#define AJOUTER_STOCK_MED_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include"gerer_stock.h"
#include "gestion_fournisseur.h"
#include"accueil_gerant.h"
#include"profil_gerant.h"
#include"gestion_ventes.h"
#include"gestion_fournisseur.h"
#include"gestion_utilisateurs.h"

namespace Ui {
class ajouter_stock_med;
}

class ajouter_stock_med : public QDialog
{
    Q_OBJECT

public:
    explicit ajouter_stock_med(QWidget *parent = nullptr,const QString &id = "");
    ~ajouter_stock_med();
    QString getId() const;


private slots:
    void on_saveButton_clicked();

    void on_Button_precedent_clicked();

    void on_pushButton_accueilgerat_clicked();
    void on_ButtonProfil_clicked();
    void on_pushButton_gere_vente_clicked();

    void on_pushButton_gerer_stock_clicked();

    void on_pushButton_gerer_fournisseur_clicked();

    void on_pushButton_gerer_utilisateurs_clicked();



    void on_pushButton_6_clicked();

private:
    Ui::ajouter_stock_med *ui;
    QString  m_id;
};

#endif // AJOUTER_STOCK_MED_H
