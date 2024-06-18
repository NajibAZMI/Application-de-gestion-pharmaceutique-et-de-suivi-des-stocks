#ifndef AJOUTER_UTILISATEURS_H
#define AJOUTER_UTILISATEURS_H

#include <QDialog>
#include"gestion_utilisateurs.h"

namespace Ui {
class ajouter_utilisateurs;
}

class ajouter_utilisateurs : public QDialog
{
    Q_OBJECT

public:
    explicit ajouter_utilisateurs(QWidget *parent = nullptr,const QString &id = "");
    ~ajouter_utilisateurs();
    QString getId() const;

private slots:

    void on_pushButton_Ajouter_user_clicked();

    void on_pushButton_Precedent_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::ajouter_utilisateurs *ui;
    QString  m_id;
};

#endif // AJOUTER_UTILISATEURS_H
