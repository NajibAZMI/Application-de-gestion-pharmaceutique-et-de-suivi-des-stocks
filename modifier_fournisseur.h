#ifndef MODIFIER_FOURNISSEUR_H
#define MODIFIER_FOURNISSEUR_H

#include <QDialog>
#include "gestion_fournisseur.h"
namespace Ui {
class modifier_fournisseur;
}

class modifier_fournisseur : public QDialog
{
    Q_OBJECT

public:
    explicit modifier_fournisseur(QWidget *parent = nullptr,const QString& id = "");
    ~modifier_fournisseur();
    QString getId() const;

private slots:
    void on_pushButton_valider_modification_clicked();

    void on_pushButton_Precedent_clicked();

    void on_pushButton_Recherche_idfour_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::modifier_fournisseur *ui;
    QString m_id;
    void loadFournisseurData();
    void clearFields();
};

#endif // MODIFIER_FOURNISSEUR_H
