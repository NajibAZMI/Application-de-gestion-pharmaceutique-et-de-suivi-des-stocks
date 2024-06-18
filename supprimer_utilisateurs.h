#ifndef SUPPRIMER_UTILISATEURS_H
#define SUPPRIMER_UTILISATEURS_H

#include <QDialog>
#include"gestion_utilisateurs.h"
namespace Ui {
class supprimer_utilisateurs;
}

class supprimer_utilisateurs : public QDialog
{
    Q_OBJECT

public:
    explicit supprimer_utilisateurs(QWidget *parent = nullptr,const QString& id = "");
    ~supprimer_utilisateurs();
     QString getId() const;

private slots:
    void on_pushButton_supprimer_user_clicked();

    void on_pushButton_Rechercher_user_clicked();

    void on_pushButton_Precedent_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::supprimer_utilisateurs *ui;
     QString m_id;
};

#endif // SUPPRIMER_UTILISATEURS_H
