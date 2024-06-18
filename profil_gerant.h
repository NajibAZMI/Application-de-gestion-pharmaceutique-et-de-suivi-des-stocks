#ifndef PROFIL_GERANT_H
#define PROFIL_GERANT_H

#include <QDialog>
#include "modifier_profil_gerant.h"
#include "gestion_fournisseur.h"
#include "accueil_gerant.h"
#include "gestion_ventes.h"
#include"gerer_stock.h"
#include"gestion_utilisateurs.h"
namespace Ui {
class profil_gerant;
}

class profil_gerant : public QDialog
{
    Q_OBJECT

public:
    explicit profil_gerant(QWidget *parent = nullptr,const QString& id = "");
    ~profil_gerant();
    QString getId() const;

private slots:





    void on_pushButton_aller_a_modifier_gerant_clicked();

    void on_pushButton_gerer_fournisseur_clicked();

    void on_pushButton_quitter_clicked();

    void on_pushButton_accueilgerat_clicked();

    void on_pushButton_gere_vente_clicked();

    void on_pushButton_gerer_stock_clicked();

    void on_pushButton_gerer_rupture_2_clicked();

    void on_pushButton_gerer_utilisateurs_clicked();

private:
    Ui::profil_gerant *ui;
     QString m_id;
};

#endif // PROFIL_GERANT_H
