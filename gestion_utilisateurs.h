#ifndef GESTION_UTILISATEURS_H
#define GESTION_UTILISATEURS_H

#include <QDialog>
#include"ajouter_utilisateurs.h"
#include"modifier_utilisateurs.h"
#include"supprimer_utilisateurs.h"
#include "profil.h"
#include"gestion_fournisseur.h"
#include"gerer_stock.h"
#include"gestion_ventes.h"
#include"gestion_utilisateurs.h"

namespace Ui {
class gestion_utilisateurs;
}

class gestion_utilisateurs : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_utilisateurs(QWidget *parent = nullptr,const QString& id = "");
    ~gestion_utilisateurs();
    QString getId() const;

private slots:
    void on_pushButton_Recherche_fournisseur_clicked();

    void on_pushButton_Ajouter_fournisseur_clicked();

    void on_pushButton_Modifier_fournisseur_clicked();

    void on_pushButton_supprimer_fournisseur_clicked();

    void on_pushButton_accueilgerat_clicked();

    void on_ButtonProfil_gerant_clicked();

    void on_pushButton_gere_vente_clicked();

    void on_pushButton_gerer_stock_clicked();

    void on_pushButton_gerer_fournisseur_clicked();

    void on_pushButton_gerer_rupture_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::gestion_utilisateurs *ui;
     QString m_id;
};

#endif // GESTION_UTILISATEURS_H
