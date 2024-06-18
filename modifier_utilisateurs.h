#ifndef MODIFIER_UTILISATEURS_H
#define MODIFIER_UTILISATEURS_H

#include <QDialog>
#include"gestion_utilisateurs.h"

namespace Ui {
class modifier_utilisateurs;
}

class modifier_utilisateurs : public QDialog
{
    Q_OBJECT

public:
    explicit modifier_utilisateurs(QWidget *parent = nullptr,const QString& id = "");
    ~modifier_utilisateurs();
    QString getId() const;

private slots:
    void on_pushButton_Modifier_user_clicked();

    void on_pushButton_Rechercher_user_clicked();

    void on_pushButton_Precedent_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::modifier_utilisateurs *ui;
    QString m_id;
};

#endif // MODIFIER_UTILISATEURS_H
