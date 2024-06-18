#ifndef AJOUTER_FOURNISSEUR_H
#define AJOUTER_FOURNISSEUR_H
#include "gestion_fournisseur.h"
#include"accueil_gerant.h"
#include"profil_gerant.h"
#include"gestion_ventes.h"
#include"gerer_stock.h"
#include"gestion_fournisseur.h"
#include"gestion_utilisateurs.h"






#include <QDialog>

namespace Ui {
class Ajouter_fournisseur;
}

class Ajouter_fournisseur : public QDialog
{
    Q_OBJECT

public:
    explicit Ajouter_fournisseur(QWidget *parent = nullptr,const QString& id = "");
    ~Ajouter_fournisseur();
      QString getId() const;

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_Precedent_clicked();

    void on_pushButton_Ajouter_Fournisseur_clicked();

    void on_pushButton_accueilgerat_clicked();

    void on_ButtonProfil_clicked();

    void on_pushButton_gere_vente_clicked();

    void on_pushButton_gerer_stock_clicked();

    void on_pushButton_gerer_fournisseur_clicked();

    void on_pushButton_gerer_utilisateurs_clicked();

private:
    Ui::Ajouter_fournisseur *ui;
    QString m_id;
};

#endif // AJOUTER_FOURNISSEUR_H
