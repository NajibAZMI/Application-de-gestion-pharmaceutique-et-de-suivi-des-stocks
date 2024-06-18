#ifndef SUPPRIMER_FOURNISSEUR_H
#define SUPPRIMER_FOURNISSEUR_H

#include <QDialog>
#include "gestion_fournisseur.h"
namespace Ui {
class Supprimer_fournisseur;
}

class Supprimer_fournisseur : public QDialog
{
    Q_OBJECT

public:
    explicit Supprimer_fournisseur(QWidget *parent = nullptr,const QString& id = "");
    ~Supprimer_fournisseur();
      QString getId() const;
private slots:

      void on_pushButton_Supprimer_Fournisseur_clicked();

    void on_pushButton_6_clicked();

      void on_pushButton_Precedent_clicked();

  private:
    Ui::Supprimer_fournisseur *ui;
    QString m_id;
};

#endif // SUPPRIMER_FOURNISSEUR_H
