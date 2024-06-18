#ifndef MODIFIER_PROFIL_GERANT_H
#define MODIFIER_PROFIL_GERANT_H
#include "mainwindow.h"
#include <QDialog>
#include "profil_gerant.h"
namespace Ui {
class modifier_profil_gerant;
}

class modifier_profil_gerant : public QDialog
{
    Q_OBJECT

public:
    explicit modifier_profil_gerant(QWidget *parent = nullptr,const QString& id = "");
    ~modifier_profil_gerant();
     QString getId() const;

private slots:


    void on_Valider_modifier_gerant_clicked();

    void on_pushButton_precedent_profil_clicked();

    void on_pushButton_quitter_clicked();

private:
    Ui::modifier_profil_gerant *ui;
      QString m_id;
};

#endif // MODIFIER_PROFIL_GERANT_H
