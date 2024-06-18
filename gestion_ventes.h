#ifndef GESTION_VENTES_H
#define GESTION_VENTES_H

#include <QDialog>
#include "ajouter_vente_by_gerant.h"
#include"gestion_fournisseur.h"
#include"gerer_stock.h"
#include"gestion_ventes.h"
#include"gestion_utilisateurs.h"
#include"profil_gerant.h"
namespace Ui {
class gestion_ventes;
}

class gestion_ventes : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_ventes(QWidget *parent = nullptr,const QString& id = "");

    QString getId() const;
    ~gestion_ventes();

private slots:
    void on_pushButtonquitter_clicked();

    void on_pushButton_Recherchevente_clicked();

    void on_pushButton_Ajouter_fournisseur_clicked();

    void on_pushButton_supprimer_fournisseur_clicked();

    void on_pushButton_accueilgerat_clicked();

    void on_ButtonProfil_gerant_clicked();

    void on_pushButton_gerer_fournisseur_clicked();

    void on_pushButton_gerer_stock_clicked();

    void on_pushButton_gerer_utilisateurs_clicked();

    void on_pushButton_Modifier_fournisseur_clicked();

private:
    Ui::gestion_ventes *ui;
    QString m_id;
};

#endif // GESTION_VENTES_H
