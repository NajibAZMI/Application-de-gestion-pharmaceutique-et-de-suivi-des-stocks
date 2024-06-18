#ifndef CONSULTER_STOCK_H
#define CONSULTER_STOCK_H
#include "affichervente.h"
#include <QDialog>
#include "profil.h"
#include"recherchermed_emp.h"
#include"ajoutervente.h"
namespace Ui {
class consulter_stock;
}

class consulter_stock : public QDialog
{
    Q_OBJECT

public:
   explicit consulter_stock(QWidget *parent = nullptr, const QString& id = "");
    ~consulter_stock();
    QString getId() const;

private slots:
    void on_ButtonProfil_2_clicked();

    void on_pushButton_quitter_clicked();

    void on_pushButton_affiche_vente_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::consulter_stock *ui;
     QString m_id;
};

#endif // CONSULTER_STOCK_H
