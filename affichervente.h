#ifndef AFFICHERVENTE_H
#define AFFICHERVENTE_H

#include <QDialog>
#include "profil.h"
#include"recherchermed_emp.h"
#include"consulter_stock.h"
#include"ajoutervente.h"

namespace Ui {
class affichervente;
}

class affichervente : public QDialog
{
    Q_OBJECT

public:
    explicit affichervente(QWidget *parent = nullptr,const QString& id = "");
    ~affichervente();
     QString getId() const;

private slots:
    void on_pushButton_profil_clicked();




    void on_pushButton_Recherche_clicked();

    void on_pushButton_consultervente_clicked();

    void on_pushButton_ajoute_vente_clicked();

    void on_pushButton_consulter_stock_clicked();

    void on_pushButton_chercher_med_clicked();

    void on_pushButton_quitter_clicked();

private:
    Ui::affichervente *ui;
     QString m_id;
};

#endif // AFFICHERVENTE_H
