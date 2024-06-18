#ifndef AJOUTERVENTE_H
#define AJOUTERVENTE_H
#include "profil.h"
#include "consulter_stock.h"
#include "affichervente.h"
#include <QDialog>
#include "afficher_facture.h"
#include"recherchermed_emp.h"
namespace Ui {
class ajouterVente;
}

class ajouterVente : public QDialog
{
    Q_OBJECT

public:
    explicit ajouterVente(QWidget *parent = nullptr,const QString& id = "");
    ~ajouterVente();
    QString getId() const;

private slots:
    void on_pushButton_Valider_Vente_clicked();

    void on_ButtonProfil_clicked();

    void on_pushButton_Consulter_stock_clicked();







    void on_pushButton_FiVente_Affiche_facture_clicked();

    void on_pushButton_affiche_vente_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::ajouterVente *ui;
    QString m_id;
    void clearFields_memeClient();
    void clear_finVente();
};

#endif // AJOUTERVENTE_H

