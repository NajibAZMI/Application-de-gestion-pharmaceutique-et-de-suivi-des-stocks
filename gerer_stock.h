#ifndef GERER_STOCK_H
#define GERER_STOCK_H

#include <QDialog>
#include <QtSql>
#include <QItemSelection>
#include "ajouter_stock_med.h"
#include "modifier_stock_med.h"
#include"accueil_gerant.h"
#include"gestion_fournisseur.h"
#include"gerer_stock.h"
#include"gestion_ventes.h"
#include"gestion_utilisateurs.h"
namespace Ui {
class gerer_stock;
}

class gerer_stock : public QDialog
{
    Q_OBJECT

public:
    explicit gerer_stock(QWidget *parent = nullptr, const QString &id = "");
    ~gerer_stock();
    QString getId() const;

private slots:
    void on_pushButton_Ajouter_Med_clicked();
    void on_pushButton_Supprimer_Med_clicked();
    void on_pushButton_Modifier_Med_clicked();
    void on_searchLineEdit_textChanged(const QString &text);
    void loadMedicines(const QString &filter = QString());
    void on_tableWidget_MED_itemSelectionChanged();

    void on_pushButton_accueilgerat_clicked();

    void on_ButtonProfil_clicked();

    void on_pushButton_gere_vente_clicked();

    void on_ButtongererStock_gerant_clicked();

    void on_pushButton_gerer_fournisseur_clicked();

    void on_pushButton_gerer_utilisateurs_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::gerer_stock *ui;
    QString m_id;
    QSqlQueryModel *model;
    QString currentMedicineId;
};

#endif // GERER_STOCK_H
