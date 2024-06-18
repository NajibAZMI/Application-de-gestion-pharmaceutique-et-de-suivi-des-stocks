#ifndef ACCUEIL_GERANT_H
#define ACCUEIL_GERANT_H
#include "profil_gerant.h"
#include <QDialog>
#include"gestion_fournisseur.h"
#include"gerer_stock.h"
#include"gestion_ventes.h"
#include"gestion_utilisateurs.h"

namespace Ui {
class accueil_gerant;
}

class accueil_gerant : public QDialog
{
    Q_OBJECT

public:
    explicit accueil_gerant(QWidget *parent = nullptr, const QString& id = "");
    ~accueil_gerant();

    QString getId() const;
private slots:
    void on_ButtonProfil_clicked();





    void on_pushButton_gerer_fournisseur_clicked();

    void on_ButtongererStock_gerant_clicked();



    void on_pushButton_gere_vente_clicked();

    void on_pushButton_gerer_utilisateurs_clicked();

    void on_pushButton_accueilgerat_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::accueil_gerant *ui;

    QString m_id;
};

#endif // ACCUEIL_GERANT_H
