#ifndef PROFIL_MODIFIE_H
#define PROFIL_MODIFIE_H
#include "affichervente.h"
#include <QDialog>
#include "profil.h"
namespace Ui {
class profil_modifie;
}

class profil_modifie : public QDialog
{
    Q_OBJECT

public:
    explicit profil_modifie(QWidget *parent = nullptr,const QString& id = "");
    ~profil_modifie();
     QString getId() const;

private slots:
    void on_pushButton_return_profil_clicked();

    void on_pushButton_Valider_Modification_clicked();

    void on_pushButton_quitter_clicked();

    void on_pushButton_afficher_vente_clicked();

private:
    Ui::profil_modifie *ui;
    QString m_id;
};

#endif // PROFIL_MODIFIE_H
