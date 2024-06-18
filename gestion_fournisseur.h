#ifndef GESTION_FOURNISSEUR_H
#define GESTION_FOURNISSEUR_H
#include"accueil_gerant.h"
#include <QDialog>
#include "ajouter_fournisseur.h"
#include "modifier_fournisseur.h"
#include"gestion_fournisseur.h"
#include"gerer_stock.h"
#include"gestion_ventes.h"
#include"gestion_utilisateurs.h"
namespace Ui {
class gestion_fournisseur;
}

class gestion_fournisseur : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_fournisseur(QWidget *parent = nullptr,const QString& id = "");
    ~gestion_fournisseur();
     QString getId() const;

private slots:
    void on_pushButton_Recherche_fournisseur_clicked();

    void on_pushButton_6_clicked();








    void on_pushButton_accueilgerat_clicked();



    void on_pushButton_Ajouter_fournisseur_clicked();

    void on_pushButton_supprimer_fournisseur_clicked();

    void on_pushButton_Modifier_fournisseur_clicked();

    void on_ButtonProfil_gerant_clicked();

    void on_pushButton_gere_vente_clicked();

    void on_pushButton_gerer_stock_clicked();

    void on_pushButton_gerer_fournisseur_clicked();

    void on_pushButton_gerer_utilisateurs_clicked();

private:
    Ui::gestion_fournisseur *ui;
    QString m_id;
};

#endif // GESTION_FOURNISSEUR_H
